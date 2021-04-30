#ifndef SHORTENER_H
#define SHORTENER_H
void init_sodium_or_die();
char* b64enc_str(char* in, int *err);
char* b64dec_str(char* in, int *err);
#endif
