#include "shortener.h"
#include <sodium.h>
#include <string.h>

int main() {
  char *text = "hello";
  //unsigned char *hash = (unsigned char *)malloc(crypto_generichash_BYTES);
  unsigned char hash[crypto_generichash_BYTES];
  if (crypto_generichash(hash, sizeof(hash), text, strlen(text), NULL, 0) < 0) {
    fprintf(stderr, "Cannot compute hash");
  }
  int err;
  char *b64hash = b64enc(hash, sizeof(hash), &err);
  printf("%s\n", b64hash);
  free(b64hash);
}
