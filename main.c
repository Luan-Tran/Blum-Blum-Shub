#include "BBS.h"

#define NUMARGS 3
#define BYTE 8

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

   int size = 1028; 
   BIGNUM * randNum = generateKey(randSeed,size);
   printf("Main: ");
   //generateKey(randSeed,size,randNum);
   printBN(randNum);
   printf("\n");
   unsigned char * randString = malloc(BN_num_bytes(randNum));
   BN_bn2bin(randNum,randString);
   printf("HERE: %s \n",randString);
   BIGNUM * thing = BN_new();
   thing = BN_bin2bn(randString,BN_num_bytes(randNum),thing);
   printBN(thing);
   printf("\n");
  
   return 0;

}

