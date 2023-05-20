CC := gcc
#CFLAGS := 
DEST := ./build

random: guess_number.c
	mkdir -p $(DEST)
	$(CC) guess_number.c -lcs50 -o $(DEST)/guess_number