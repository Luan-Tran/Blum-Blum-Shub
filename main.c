/*
 * Author: Luan Tran
 * Date: 8/6/18
 * Description: Main function takes in arguments to create a certain number of
 * keys in BIGNUM format. Keys are written to file, with each key seperated by
 * newline char. User inputs filename, number of keys, and 0 for no testing and
 * 1 for testing. Testing will not write any keys to file.
 *
 */
#include "BBS.h"
#define BYTE 8
#define SIZE 1028

void usage();

int main( int argc,  char * argv[]){
   
   int testARG = 1;
   int keyARG = 4;
   //Check for arguments
   if( argc != testARG && argc != keyARG ){
      printf("[-] Incorrect number of arguments\n",stderr);
      usage();
      exit(0);
   }
   
   if(argc == testARG){
      printf("[+] Begin Testing: \n");
      testPRNG();
      exit(0);
   }

   //Test if correct arguments were passed
   char * end;
   int lengthOfKey = strtol(argv[3],&end,10);
   int numKeys = strtol(argv[2],&end,10);
   
   if(numKeys == 0L || numKeys == 0){
      fprintf(stderr,"[-] Enter a positive number for second argument\n");
      usage();
      exit(1);
   }
   else if( end == argv[3] || lengthOfKey < 128 || lengthOfKey > 2048){
      fprintf(stderr, "[-] Enter a number between 128 and 2048 for key length\n");
      usage();
      exit(1);
   }

   //Open file
   FILE * file = fopen(argv[1],"w");
   if( file == NULL){
      fprintf(stderr,"Error opening file: %s\n",strerror(errno));
      usage();
      exit(1);
   }


   //Construct random string based on time
   char * randSeed;
   time_t currTime;
   struct tm * info;
   time( &currTime);
   info = localtime(&currTime);
   randSeed = asctime(info);
   
   //Make Keys and print to file
   for(int i=0; i <+ numKeys; i++){
      BIGNUM * currKey = generateKey(randSeed,lengthOfKey);
      BN_print_fp(file, currKey);
      fprintf(file,"\n");
      BN_free(currKey);
   }
   
   fclose(file);

   return 0;
}


void usage(){

   fprintf(stderr,"\nProgram takes in three commands\n");
   fprintf(stderr,"-F the file to write too\n");
   fprintf(stderr, "-K the number of keys to generate\n");
   fprintf(stderr, "-L the length of keys\n");

}


