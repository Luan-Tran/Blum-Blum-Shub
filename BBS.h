/*
 * Author: Luan Tran
 * Date: 8/6/18
 * Description: This a header file for BBS.h
 */

#include <stdio.h>
#include <string.h>
#include <openssl/bio.h>
#include <openssl/bn.h>
#include <openssl/ssl.h>
#include <openssl/rand.h>
#include <openssl/err.h>
#include <math.h>
#include <time.h>
#include <errno.h>

//Generate a key with certain length, return key as BIGNUM
BIGNUM * generateKey(char * randSeed,int length);

//Generate a random number from 0 to end, 0 inclusive, end exclusive
//Creates a random number of 512 bits then mods this number by end
int randNum(int end);

//Test by generating 100,000 random numbers and check percentages
void testPRNG();

//Print BIGNUM for testing
void printBN(BIGNUM * number);



