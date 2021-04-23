#include "shortener.h"
#include <sodium.h>
#include <stdio.h>
#include <string.h>

char* b64enc(char* in, int ilen) {
  const size_t b64_max_len =
    sodium_base64_encoded_len(ilen, sodium_base64_VARIANT_ORIGINAL);
  // We malloc here, the caller should free, how to let them now about that?
  char *r = (char *)malloc(b64_max_len);
  // If malloc fails, what to do?
  char *er = sodium_bin2base64(r, b64_max_len, in, ilen, sodium_base64_VARIANT_ORIGINAL);
  return er;
}

char* b64enc_str(char *in) {
  return b64enc(in, strlen(in));
}

