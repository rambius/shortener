#include "shortener.h"
#include <sodium.h>
#include <stdio.h>
#include <string.h>

char* b64hash(char *in, int ilen, int *err) {
  unsigned char hash[crypto_generichash_BYTES];
  if (crypto_generichash(hash, sizeof(hash), in, ilen, NULL, 0) < 0) {
    *err = BASE64_HASH_ERROR;
    return NULL;
  }
  int b64err;
  char *b64hash = b64enc(hash, sizeof(hash), &b64err);
  if (b64err > 0) {
    *err = BASE64_HASH_ENC_ERROR;
    return NULL;
  }
  *err = BASE64_HASH_SUCCESS;
  return b64hash;
}

char* b64hash_str(char *in, int *err) {
  return b64hash(in, strlen(in), err);
}
