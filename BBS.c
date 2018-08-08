#include <stdio.h>
#include "BBS.h"

void generateKey(char * randSeed,int length, unsigned char * key){
   
   //If lenght of key is not even return nullptr
   if( (length % 2) != 0){
      return NULL;
   }
   
   //Define length of key
   int LENGTH = length/2;

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
   while( BN_mod_word(primeQ,four) != 3 && BN_cmp(primeP,primeQ) != 0){
      BN_generate_prime_ex(primeQ,LENGTH,0,NULL,NULL,NULL);
   }

   //Create Blum integer
   BIGNUM * blumInt = BN_new();
   BN_mul(blumInt,primeP,primeQ,ctx);

   //Create x, where gcd(x,blumInt) == 1
   BIGNUM * randX = BN_new();
   BIGNUM * rem = BN_new();
   BN_generate_prime_ex(randX,LENGTH,0,NULL,NULL,NULL);
   BN_gcd(rem,randX,blumInt,ctx);
   while( BN_is_one(rem) != 1){
      BN_generate_prime_ex(randX,LENGTH,0,NULL,NULL,NULL);
      BN_gcd(rem,randX,blumInt,ctx);
   }

   //Compute bits
   BIGNUM * finalRandNum = BN_new();
   BN_mod_mul(finalRandNum,randX,randX,blumInt,ctx); 
   BIGNUM * prev = BN_new();
   BN_mod_mul(prev,finalRandNum,finalRandNum,blumInt,ctx);
   
   
   //Go through each bit
   int size = BN_num_bits(finalRandNum);
   int bit = BN_is_bit_set(prev,0);
   for(int idx = 1; idx < size ;idx++){
      
      if(bit == 1){
         BN_set_bit(finalRandNum,idx);
      }
      else{
         BN_clear_bit(finalRandNum,idx);
      }

      BN_mod_mul(prev,prev,prev,blumInt,ctx); 
      bit = BN_is_bit_set(prev,idx);
   }//End of for
   

   BN_bn2bin(finalRandNum, key);
   printf("KEY: %s \n",key);


}


