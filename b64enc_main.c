#include "shortener.h"
#include <sodium.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
  if (sodium_init() < 0) {
    fprintf(stderr, "Cannot init libsodium\n");
    return 1;
  }

  for (int i = 1; i < argc; i++) {
    char *er = b64enc_str(argv[i]);
    if (er == NULL) {
      fprintf(stderr, "Cannot base64 encode %s", argv[i]);
      return 1;
    }
    printf("%s\n", er); 

    free(er);
  }
  return 0;
}
