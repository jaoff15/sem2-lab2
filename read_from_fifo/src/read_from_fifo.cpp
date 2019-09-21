//============================================================================
// Name        : read_from_fifo.cpp
// Author      : Jacob Offersen
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	int fd1;

	// FIFO file path
//	char *myfifo = "/dev/swipe";
	char *myfifo = "pipe";

	// Creating the named file(FIFO)
	// mkfifo(<pathname>,<permission>)
	mkfifo(myfifo, 0666);

	while (1) {
		char str1[80];
		// First open in read only and read
		fd1 = open(myfifo, O_RDONLY);
		read(fd1, str1, 80);

		// Print the read string and close
		if (str1[0] >= '0' and str1[0] <= '9')
			printf("Card number: %s\n", str1);
		close(fd1);

	}
	return 0;
}
