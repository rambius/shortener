#include "shortener.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  for (int i = 1; i < argc; i++) {
    char *er = b64enc_str(argv[i]);
    if (er == NULL) {
      fprintf(stderr, "Cannot base64 encode %s\n", argv[i]);
      // if there is an error and er has been malloced already, how can I free it
    } else {
      printf("%s\n", er); 
      free(er);
    }
  }
  return 0;
}
