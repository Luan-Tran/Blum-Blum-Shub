#include <stdio.h>
#include <string.h>
#include <openssl/bio.h>
#include <openssl/bn.h>
#include <openssl/rand.h>

#define LENGTH 512
#define NUMARGS 3

int main( int argc,  char * argv[]){
   
   //Check for arguments
   if( argc != NUMARGS){
      printf("Incorrect number of arguments, expected two arguments.\n",stderr);
      exit(0);
   }
   
   char * randSeed;
   if( strcmp("0",argv[1]) == 0){
      randSeed = "This is a random seed to generate large primes";
   }
   else{
      randSeed = argv[1];
   }


   //Generate two prime numbers
   BIGNUM *primeP = BN_new();
   BIGNUM *primeQ = BN_new();
   BN_CTX *ctx = BN_CTX_new();
   BN_ULONG four = 4;
   RAND_seed(randSeed, sizeof(randSeed));
   
   //Check primeP is congruent 3 mod 4
   BN_generate_prime_ex(primeP,LENGTH,0, NULL,NULL,NULL);
   while(  BN_mod_word(primeP,four) != 3){
      BN_generate_prime_ex(primeP,LENGTH,0, NULL,NULL,NULL);
   }

   //Check primeQ is congruent 3 mod 4 and not equal to PrimeP
   BN_generate_prime_ex(primeQ,LENGTH,0,NULL,NULL,NULL);
   while( BN_mod_word(primeQ,four) != 3 & BN_cmp(primeP,primeQ) != 0){
      BN_generate_prime_ex(primeQ,LENGTH,0,NULL,NULL,NULL);
   }
   
   //Create Blum integer
   BIGNUM * blumInt = BN_new();
   BN_mul(blumInt,primeP,primeQ,ctx);

   
   //Create x, where gcd(x,blumInt) == 1
   BIGNUM * seed = BN_new();
   BIGNUM * rem = BN_new();
   BN_generate_prime_ex(seed,LENGTH,0,NULL,NULL,NULL);
   BN_gcd(rem,seed,blumInt,ctx);
   while( BN_is_one(rem) != 1){
      BN_generate_prime_ex(seed,LENGTH,0,NULL,NULL,NULL);
      BN_gcd(rem,seed,blumInt,ctx);
   
      

  
  /*
   BIO * file = BIO_new(BIO_s_file());
   if(file == NULL){

   }

   if(BIO_append_filename(file,"test43.txt") == 0){

   }
   BN_print(file, primeP);
   BIO_free(file);
   */

   return 0;

}
