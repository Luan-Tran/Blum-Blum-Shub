CC=gcc

main:
	$(CC) -o BBS BBS.o -lssl -lcrypto

BBS: BBS.h

clean:
	rm *.o BBS 
