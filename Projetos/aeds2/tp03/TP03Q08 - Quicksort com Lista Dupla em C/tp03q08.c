#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <sys/time.h>
#include <time.h>

#define MAX_STRING_LENGTH 1024
#define MAX_MATRIX 16
#define PATH "/tmp/disneyplus.csv"
#define MATRICULA 000000

const char* MONTH_NAMES[] = {
  "January",
  "February",
  "March",
  "April",
  "May",
  "June",
  "July",
  "August",
  "September",
  "October",
  "November",
  "December"
};

char* trim(char* string) {
  if (!string) return NULL;
  int startIndex = 0, endIndex = (int)strlen(string) - 1;

  while (startIndex <= endIndex && isspace(string[startIndex])) startIndex++;
  while (endIndex >= startIndex && isspace(string[endIndex])) endIndex--;

  const int length = endIndex - startIndex + 1;
  memmove(string, string + startIndex, length);
  string[length] = '\0';

  return string;
}

char* removeQuotes(char* string) {
  if (!string) return 0;

  const int length = strlen(string);
  int charIndex = 0;

  for (int i = 0; i < length; i++) {
    if (string[i] != '"') string[charIndex++] = string[i];
  }

  string[charIndex] = '\0';

  return string;
}

char* substring(const char* string, const size_t startIndex, const size_t endIndex) {
  if (!string || startIndex > endIndex || endIndex > strlen(string)) return NULL;

  int length = endIndex - startIndex + 1;

  char* substring = malloc(length + 1);
  if (!substring) return NULL;

  memcpy(substring, string + startIndex, length);
  substring[length] = '\0';

  return removeQuotes(substring);
}

char* readLine() {
  char* line = malloc(MAX_STRING_LENGTH);
  if (!line) return NULL;

  if (!fgets(line, MAX_STRING_LENGTH, stdin)) {
    free(line);
    return NULL;
  }

  return trim(line);;
}

char* fileLine(const int index) {
  if (index <= 0) return NULL;

  FILE* file = fopen(PATH, "r");
  if (!file) return NULL;

  char* line = malloc(MAX_STRING_LENGTH);
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

char* extractField(const char* input, int* index) {
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

int compareStrings(const void* a, const void* b) {
  const char** strA = (const char**)a;
  const char** strB = (const char**)b;
  return strcmp(*strA, *strB);
}

typedef struct {
  int year;
  int month;
  int day;
} Date;

int dateToInt(Date* date) {
  char string[9];

  snprintf(string, 9, "%04d%02d%02d", date->year, date->month, date->day);

  return atoi(string);
}

char* formatedDate(Date* date) {
  if (date->month < 1 || date->month > 12) return NULL;

  char* string = malloc(sizeof(char) * 20);
  if (string == NULL) return NULL;

  snprintf(string, 20, "%s %d, %04d", MONTH_NAMES[date->month - 1], date->day, date->year);

  return string;
}

typedef struct {
  char* show_id;
  char* type;
  char* title;
  char* director; // nullable

  char** cast;
  int cast_size;

  char* country; // nullable
  Date* date_added; // nullable
  int release_year;
  char* rating; // nullable
  char* duration;

  char** listed_in;
  int listed_in_size;
} Show;

void printShow(Show* show) {
  if (!show) return;

  printf("=> %s", show->show_id);
  printf(" ## %s", show->title);
  printf(" ## %s", show->type);
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
  printf(" ## %s", show->date_added ? formatedDate(show->date_added) : "NaN");
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

void freeShow(Show* show) {
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

Show* parseCast(Show* show, char* cast) {
  int nextNameIndex = 0;

  char* tempNames[MAX_MATRIX];
  char* name;

  show->cast_size = 0;
  while ((name = extractField(cast, &nextNameIndex)) != NULL) {
    tempNames[show->cast_size++] = name;
  }

  show->cast = malloc(show->cast_size * sizeof(char*));
  for (int i = 0; i < show->cast_size; i++) {
    name = tempNames[i];

    show->cast[i] = malloc(strlen(name) + 1);
    strcpy(show->cast[i], name);
  }

  qsort(show->cast, show->cast_size, sizeof(char*), compareStrings);

  free(cast);

  return show;
}

Show* parseListedIn(Show* show, char* listedIn) {
  int nextNameIndex = 0;

  char* tempCategories[MAX_MATRIX];
  char* category;

  show->listed_in_size = 0;
  while ((category = extractField(listedIn, &nextNameIndex)) != NULL) {
    tempCategories[show->listed_in_size++] = category;
  }

  show->listed_in = malloc(show->listed_in_size * sizeof(char*));
  for (int i = 0; i < show->listed_in_size; i++) {
    category = trim(tempCategories[i]);

    show->listed_in[i] = malloc(strlen(category) + 1);
    strcpy(show->listed_in[i], category);
  }

  free(listedIn);

  return show;

}

Show* parseDateAdded(Show* show, char* dateAdded) {
  show->date_added = malloc(sizeof(Date));

  int end = 0;

  while (dateAdded[end + 1] != ' ') end++;

  char* monthString = substring(dateAdded, 0, end);
  show->date_added->month = 0;

  for (int i = 0; i < 12; i++) {
    if (strcmp(monthString, MONTH_NAMES[i]) == 0) {
      show->date_added->month = i + 1;
      i = 12;
    }
  }

  int start = end += 2;
  while (dateAdded[end + 1] != ',') end++;
  show->date_added->day = atoi(substring(dateAdded, start, end));

  start = end += 2;
  while (dateAdded[end + 1] != '\0') end++;
  show->date_added->year = atoi(substring(dateAdded, start, end));

  return show;
}

Show* parseShow(const char* input) {
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

  parseDateAdded(show, extractField(input, &nextFieldStart));

  char* year = extractField(input, &nextFieldStart);
  show->release_year = atoi(year);
  free(year);

  show->rating = extractField(input, &nextFieldStart);
  show->duration = extractField(input, &nextFieldStart);

  parseListedIn(show, extractField(input, &nextFieldStart));

  return show;
}

typedef struct ShowNode {
  Show* element;
  struct ShowNode* left;
  struct ShowNode* right;
} ShowNode;

typedef struct {
  ShowNode* start;
  ShowNode* end;
  int comparisons;
  int length;
} ShowList;

void insertIndex(ShowList* list, Show* show, int index) {
  if (index < 0 || index > list->length) return;

  ShowNode* newNode = malloc(sizeof(ShowNode));
  newNode->element = show;
  newNode->right = NULL;
  newNode->left = NULL;

  if (list->length == 0) { // insert first node
    list->start = newNode;
    list->end = newNode;

  } else if (index == 0) { // insert start
    newNode->right = list->start;
    list->start->left = newNode;
    list->start = newNode;

  } else if (index == list->length) { // insert end
    list->end->right = newNode;
    newNode->left = list->end;
    list->end = newNode;

  } else { // insert position
    ShowNode* prevNode = list->start;

    for (int i = 0; i < index - 1; i++) {
      prevNode = prevNode->right;
    }

    ShowNode* nextNode = prevNode->right;

    newNode->left = prevNode;
    newNode->right = nextNode;

    prevNode->right = newNode;
    nextNode->left = newNode;
  }

  list->length++;
}

void insertStart(ShowList* list, Show* show) {
  insertIndex(list, show, 0);
}

void append(ShowList* list, Show* show) {
  insertIndex(list, show, list->length);
}

Show* removeIndex(ShowList* list, int index) {
  if (index < 0 || index >= list->length) return NULL;

  ShowNode* removedNode;
  Show* show;

  if (list->length == 0) { // remove only node
    removedNode = list->start;
    list->start = NULL;
    list->end = NULL;

  } else if (index == 0) { // remove start
    removedNode = list->start;
    list->start = removedNode->right;

  } else if (index == list->length - 1) { // remove end
    removedNode = list->end;
    list->end = removedNode->left;

  } else { // remove position
    if (index < list->length) { // walk from start
      removedNode = list->start;
      for (int i = 0; i < index; i++) {
        removedNode = removedNode->right;
      }

    } else { // walk from end
      removedNode = list->end;
      for (int i = list->length; i > index; i--) {
        removedNode = removedNode->right;
      }
    }

    ShowNode* prevNode = removedNode->left;
    ShowNode* nextNode = removedNode->right;

    prevNode->right = nextNode;
    nextNode->left = prevNode;
  }

  show = removedNode->element;
  free(removedNode);
  list->length--;

  return show;
}

Show* removeStart(ShowList* list) {
  return removeIndex(list, 0);
}

Show* removeEnd(ShowList* list) {
  return removeIndex(list, list->length - 1);
}

void printShowList(ShowList* list) {
  ShowNode* node = list->start;

  for (int i = 0; i < list->length; i++, node = node->right) {
    printShow(node->element);
  }
}

void swap(ShowNode* a, ShowNode* b) {
  Show* temp = a->element;
  a->element = b->element;
  b->element = temp;
}

ShowNode* _partition(ShowList* list, ShowNode* start, ShowNode* end) {
  Show* pivot = end->element;
  ShowNode* i = start->left;

  for (ShowNode* j = start; j != end; j = j->right) {
    list->comparisons++;

    if (dateToInt(j->element->date_added) < dateToInt(pivot->date_added)) {
      i = (i == NULL) ? start : i->right;
      swap(i, j);
    }
  }

  i = (i == NULL) ? start : i->right;
  swap(i, end);
  return i;
}

void _quicksort(ShowList* list, ShowNode* start, ShowNode* end) {
  if (start == NULL
    || end == NULL
    || start == end
    || end->right == start
    ) return;

  ShowNode* pivot = _partition(list, start, end);

  _quicksort(list, start, pivot->left);
  _quicksort(list, pivot->right, end);
}

void sort(ShowList* list) { // by date_added
  list->comparisons = 0;
  _quicksort(list, list->start, list->end);
}

void untie(ShowList* list) { // by title
  for (ShowNode* i = list->start; i != NULL; i = i->right) {
    Show* key = i->element;
    ShowNode* j = i->left;

    while (j &&
      dateToInt(j->element->date_added) == dateToInt(key->date_added) &&
      strcasecmp(j->element->title, key->title) > 0) {

      list->comparisons++;
      j->right->element = j->element;
      j = j->left;
    }
    (j ? j->right : list->start)->element = key;
  }
}

long long now() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return (long long)(tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
}

int main() {
  ShowList list;
  list.length = 0;
  char* line;

  while (strcmp("FIM", line = readLine()) != 0) {
    char* input = fileLine(atoi(line + 1));

    if (input) {
      Show* show = parseShow(input);
      append(&list, show);

      free(input);
    } else {
      printf("\n\aErro ao ler o arquivo.");
    }

    free(line);
  }

  const long long start = now();

  sort(&list);
  untie(&list);

  const long long end = now();

  printShowList(&list);

  FILE* file = fopen("matricula_quicksort.txt", "w");
  fprintf(file, "%d\t%lld\t%d", MATRICULA, end - start, list.comparisons);

  return 0;
}
