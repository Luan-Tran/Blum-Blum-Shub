#include <stdio.h>
#include "BBS.h"

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
   printf("HERE\n");

   int size = 1028; 
   int numBytes= (1028/8) + (1028 % 8);
   unsigned char * key = malloc(numBytes);
   printf("KEY: %s \n",key);
  
   return 0;

}

