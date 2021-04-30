#include "shortener.h"
#include <sodium.h>
#include <stdio.h>
#include <string.h>

#define BASE64_DECODED_LEN(x) ((((x) + 3) / 4) * 3)

// This function mallocs too, if we forget to free in the caller
// how can we check that - static analyzers?
char* b64dec(char *in, int ilen, int *err) {
  size_t b64_dec_len = 
    BASE64_DECODED_LEN(ilen);
  char *r = (char *)malloc(b64_dec_len);
  if (sodium_base642bin(r, b64_dec_len, in, ilen, NULL, &b64_dec_len, NULL,
                        sodium_base64_VARIANT_ORIGINAL) < 0) {
    return NULL;
  };
  // What about the null-terminating byte? 
  *err = 0;
  return r;
}

char* b64dec_str(char *in, int *err) {
  return b64dec(in, strlen(in), err);
}

