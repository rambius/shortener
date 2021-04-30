#include "shortener.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  for (int i = 1; i < argc; i++) {
    int err;
    char *r = b64enc_str(argv[i], &err);
    if (err == 0) {
      printf("%s\n", r);
      free(r);
    } else {
      fprintf(stderr, "Cannot base64 encode %s\n", argv[i]);
      // if there is an error and er has been malloced already, how can I free it
    } 
  }
  return 0;
}
