#include <stdio.h>

#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

void saveFile(
  const char* FILE_NAME,
  const void* VALUE,
  int typeSize,
  int lenght,
  const bool printErrors
) {
  FILE* file = fopen(FILE_NAME, "wb");

  if (file != NULL) {
    fwrite(VALUE, typeSize, lenght, file);
    fclose(file);
  } else if (printErrors) {
    printf("\aError: unable to save to file '%s'\n", FILE_NAME);
  }
}

void loadFile(
  const char* FILE_NAME,
  void* value,
  int typeSize,
  int lenght,
  const bool printErrors
) {
  FILE* file = fopen(FILE_NAME, "rb");

  if (file != NULL) {
    fread(value, typeSize, lenght, file);
    fclose(file);
  } else if (printErrors) {
    printf("\aError: unable to read from file '%s'\n", FILE_NAME);
  }
}

#endif