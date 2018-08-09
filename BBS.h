#include <stdio.h>
#include <string.h>
#include <openssl/bio.h>
#include <openssl/bn.h>
#include <openssl/ssl.h>
#include <openssl/rand.h>
#include <openssl/err.h>
#include <math.h>

//Generate a key
BIGNUM * generateKey(char * randSeed,int length);

//Print BIGNUM for testing
void printBN(BIGNUM * number);

