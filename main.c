/*
 * Author: Luan Tran
 * Date: 8/6/18
 * Description: Main function takes in arguments to create a certain number of
 * keys in hexadecimal. This function is mainly used to demonstrate the BBS
 * functions.
 *
 */
#include "BBS.h"
#define NUMARGS 4
#define BYTE 8
#define SIZE 1028

void usage();
int isNumeric();

int main( int argc,  char * argv[]){
   
   //Check for arguments
   if( argc != NUMARGS){
      printf("Incorrect number of arguments, expected three arguments.\n",stderr);
      usage();
      exit(0);
   }
   
   //Test if correct arguments were passed
   char * end;
   int numKeys = strtol(argv[2],&end,10);
   int test = strtol(argv[3],&end,10);
   
   if(numKeys == 0L || numKeys == 0){
      fprintf(stderr,"Enter a positive number for second argument\n");
      usage();
      exit(0);
   }
   else if(end == argv[3] || test > 1 || test < 0){
      fprintf(stderr, "Enter either 0 or 1 for third argument\n");
      usage();
      exit(0);
   }
   else if( test == 1){
      testPRNG();
      exit(0);
   }

   //Create keys 
   char * randSeed;
   if( strcmp("0",argv[1]) == 0){

      //Construct random string based on time
      time_t currTime;
      struct tm * info;
      time( &currTime);
      info = localtime(&currTime);
      randSeed = asctime(info);
   }
   else{
      randSeed = argv[1];
   }

   //Array of keys
   BIGNUM * arrKeys[numKeys];

   for(int i=0; i <+ numKeys; i++){
      arrKeys[i] = generateKey(randSeed,SIZE);
      printBN(arrKeys[i]);
      BN_free(arrKeys[i]);
      printf("\n");
   }
   

   return 0;
}


void usage(){

   fprintf(stderr,"\nProgram takes in three commands\n");
   fprintf(stderr,"-S a random string for entropy, if user enters 0,"\
   "time will be used as random string\n");
   fprintf(stderr, "-K the number of keys to generate\n");
   fprintf(stderr, "-T enter 0 for no testing, 1 for testing \n");

}


