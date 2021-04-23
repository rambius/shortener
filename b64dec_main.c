#include "shortener.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  for (int i = 1; i < argc; i++) {
    char *er = b64dec_str(argv[i]);
    if (er == NULL) {
      fprintf(stderr, "Cannot base64 decode %s\n", argv[i]);
    } else {
      printf("%s\n", er);
      free(er);
    }
  }
  return 0;
}
