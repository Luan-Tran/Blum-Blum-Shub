#include <stdio.h>
#include <string.h>
#include <openssl/bio.h>
#include <openssl/bn.h>
#include <openssl/ssl.h>
#include <openssl/rand.h>
#include <openssl/err.h>
#include <math.h>
#include <time.h>

//Generate a key 
BIGNUM * generateKey(char * randSeed,int length);

//Generate a random number from start to end, where start is inclusive
//and end is exclusive
int randNum(int start, int end);

//Print BIGNUM for testing
void printBN(BIGNUM * number);

//Simple test for PRNG
void testPRNG();

