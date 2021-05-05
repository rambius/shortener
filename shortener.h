#ifndef SHORTENER_H
#define SHORTENER_H

#define BASE64_ENC_SUCCESS 0
#define BASE64_ENC_MALLOC_ERROR 10001
#define BASE64_ENC_ERROR 10002

#define BASE64_DEC_SUCCESS 0
#define BASE64_DEC_MALLOC_ERROR 10101
#define BASE64_DEC_ERROR 10102

#define BASE64_HASH_SUCCESS 0
#define BASE64_HASH_ERROR 10201
#define BASE64_HASH_ENC_ERROR 10202

char* b64enc(char* in, int ilen, int *err);
char* b64enc_str(char* in, int *err);
char* b64dec_str(char* in, int *err);
char* b64hash_str(char *in, int *err);
#endif
