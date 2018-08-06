CC=gcc

BBS: BBS.o
	$(CC) -o BBS BBS.o -lssl -lcrypto


clean:
	rm *.o BBS 
