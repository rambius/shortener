#include "shortener.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  for (int i = 1; i < argc; i++) {
    int err;
    char *r = b64dec_str(argv[i], &err);
    if (err == 0) {
      printf("%s\n", r);
      free(r);
    } else {
      fprintf(stderr, "Cannot base64 decode %s\n", argv[i]);
    } 
  }
  return 0;
}
