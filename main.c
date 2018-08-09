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
   
   testPRNG();
   return 0;

}

