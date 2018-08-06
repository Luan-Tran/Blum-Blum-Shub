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
      printf("Incorrect number of arguments\n",stderr);
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
   BN_ULONG four = 4;
   RAND_seed(randSeed, sizeof(randSeed));
   
   //Check primeP is congruent 3 mod 4
   BN_generate_prime_ex(primeP,512,0, NULL,NULL,NULL);
   while(  BN_mod_word(primeP,four) != 3){
      BN_generate_prime_ex(primeP,512,0, NULL,NULL,NULL);
   }

  
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
