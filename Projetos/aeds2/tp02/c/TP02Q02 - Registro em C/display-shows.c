#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1024
#define MAX_MATRIX 16
#define PATH "/tmp/disneyplus.csv"

char *trim(char *string) {
  if (!string) return NULL;
  int startIndex = 0, endIndex = (int) strlen(string) - 1;

  while (startIndex <= endIndex && isspace(string[startIndex])) startIndex++;
  while (endIndex >= startIndex && isspace(string[endIndex])) endIndex--;

  const int length = endIndex - startIndex + 1;
  memmove(string, string + startIndex, length);
  string[length] = '\0';

  return string;
}

char *removeQuotes(char *string) {
  if (!string) return 0;

  const int length = strlen(string);
  int charIndex = 0;

  for (int i = 0; i < length; i++) {
    if (string[i] != '"') string[charIndex++] = string[i];
  }

  string[charIndex] = '\0';

  return string;
}

char *substring(const char *string, const size_t startIndex, const size_t endIndex) {
  if (!string || startIndex > endIndex || endIndex > strlen(string)) return NULL;

  int length = endIndex - startIndex + 1;

  char *substring = malloc(length + 1);
  if (!substring) return NULL;

  memcpy(substring, string + startIndex, length);
  substring[length] = '\0';

  return removeQuotes(substring);
}

char *readLine() {
  char *line = malloc(MAX_STRING_LENGTH);
  if (!line) return NULL;

  if (!fgets(line, MAX_STRING_LENGTH, stdin)) {
    free(line);
    return NULL;
  }

  return trim(line);;
}

char *fileLine(const int index) {
  if (index <= 0) return NULL;

  FILE *file = fopen(PATH, "r");
  if (!file) return NULL;

  char *line = malloc(MAX_STRING_LENGTH);
  if (!line) return NULL;

  int i = 0;
  while (fgets(line, MAX_STRING_LENGTH, file)) {
    if (i == index) {
      trim(line);

      fclose(file);
      return line;
    }

    i++;
  }

  fclose(file);
  free(line);
  return NULL;
}

char *extractField(const char *input, int *index) {
  if (!input || !index || *index >= strlen(input)) return NULL;

  int startIndex = *index, endIndex = *index;
  const int length = strlen(input);

  if (input[startIndex] == '"') {
    startIndex++; endIndex++;

    while (
      endIndex < length &&
      !(input[endIndex] == '"' &&
      (input[endIndex + 1] == ',' || input[endIndex + 1] == '\0'))
    ) endIndex++;

    *index = endIndex + 2;
  } else {
    while (endIndex < length && input[endIndex] != ',') endIndex++;

    *index = endIndex + 1;
  }

  if (input[startIndex] == ' ') startIndex++;

  return substring(input, startIndex, endIndex - 1);
}

int compareStrings(const void *a, const void *b) {
  const char **strA = (const char **)a;
  const char **strB = (const char **)b;
  return strcmp(*strA, *strB);
}

typedef struct {
  char *show_id;
  char *type;
  char *title;
  char *director; // nullable

  char **cast;
  int cast_size;

  char *country; // nullable
  char *date_added; // nullable
  int release_year;
  char *rating; // nullable
  char *duration;

  char **listed_in;
  int listed_in_size;
} Show;

void printShow(Show *show) {
  if (!show) return;

  printf("=> %s", show->show_id);
  printf(" ## %s", show->type);
  printf(" ## %s", show->title);
  printf(" ## %s", show->director ? show->director : "NaN");

  /* Cast */
  printf(" ## [");
  if (show->cast_size > 0) {
    printf("%s", show->cast[0]);

    for (int i = 1; i < show->cast_size; i++) {
      printf(", %s", show->cast[i]);
    }
  } else {
    printf("NaN");
  }
  printf("]");

  printf(" ## %s", show->country ? show->country : "NaN");
  printf(" ## %s", show->date_added ? show->date_added : "NaN");
  printf(" ## %d", show->release_year);
  printf(" ## %s", show->rating ? show->rating : "NaN");
  printf(" ## %s", show->duration);

  /* Listed In */
  printf(" ## [");
  if (show->listed_in_size > 0) {
    printf("%s", show->listed_in[0]);

    for (int i = 1; i < show->listed_in_size; i++) {
      printf(", %s", show->listed_in[i]);
    }
  } else {
    printf("NaN");
  }
  printf("] ##\n");
}

void freeShow(Show *show) {
  if (!show) return;

  if (show->show_id) free(show->show_id);
  if (show->type) free(show->type);
  if (show->title) free(show->title);
  if (show->director) free(show->director);

  if (show->cast && show->cast_size > 0) {
    for (int i = 0; i < show->cast_size; i++) free(show->cast[i]);
    free(show->cast);
  }

  if (show->country) free(show->country);
  if (show->date_added) free(show->date_added);
  if (show->rating) free(show->rating);
  if (show->duration) free(show->duration);

  if (show->listed_in && show->listed_in_size > 0) {
    for (int i = 0; i < show->listed_in_size; i++) free(show->listed_in[i]);
    free(show->listed_in);
  }

  free(show);
}

Show *parseCast(Show *show, char *cast) {
  int nextNameIndex = 0;

  char *tempNames[MAX_MATRIX];
  char *name;

  show->cast_size = 0;
  while ((name = extractField(cast, &nextNameIndex)) != NULL) {
    tempNames[show->cast_size++] = name;
  }

  show->cast = malloc(show->cast_size * sizeof(char *));
  for (int i = 0; i < show->cast_size; i++) {
    name = tempNames[i];

    show->cast[i] = malloc(strlen(name) + 1);
    strcpy(show->cast[i], name);
  }

  qsort(show->cast, show->cast_size, sizeof(char *), compareStrings);

  free(cast);

  return show;
}

Show *parseListedIn(Show *show, char *listedIn) {
  int nextNameIndex = 0;

  char *tempCategories[MAX_MATRIX];
  char *category;

  show->listed_in_size = 0;
  while ((category = extractField(listedIn, &nextNameIndex)) != NULL) {
    tempCategories[show->listed_in_size++] = category;
  }

  show->listed_in = malloc(show->listed_in_size * sizeof(char *));
  for (int i = 0; i < show->listed_in_size; i++) {
    category = trim(tempCategories[i]);

    show->listed_in[i] = malloc(strlen(category) + 1);
    strcpy(show->listed_in[i], category);
  }

  free(listedIn);

  return show;

}

Show* parseShow(const char *input) {
  if (!input || strlen(input) == 0) return NULL;

  Show* show = malloc(sizeof(Show));
  if (!show) return NULL;

  int nextFieldStart = 0;

  show->show_id = extractField(input, &nextFieldStart);
  show->type = extractField(input, &nextFieldStart);
  show->title = extractField(input, &nextFieldStart);
  show->director = extractField(input, &nextFieldStart);

  parseCast(show, extractField(input, &nextFieldStart));

  show->country = extractField(input, &nextFieldStart);
  show->date_added = extractField(input, &nextFieldStart);

  char *year = extractField(input, &nextFieldStart);
  show->release_year = atoi(year);
  free(year);

  show->rating = extractField(input, &nextFieldStart);
  show->duration = extractField(input, &nextFieldStart);

  parseListedIn(show, extractField(input, &nextFieldStart));

  return show;
}

int main() {
  char* line;

  while (strcmp("FIM", line = readLine()) != 0) {
    char* input = fileLine(atoi(line + 1));

    if (input) {
      Show* show = parseShow(input);
      printShow(show);

      freeShow(show);
      free(input);
    }

    free(line);
  }

  free(line);
  return 0;
}
