//============================================================================
// Name        : lab2.cpp
// Author      : Jacob Offersen
// Version     :
// Copyright   : Your copyright notice
// Description : Lab 2
//============================================================================

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "Card.h"

//using namespace std;

int main(int argc, char **argv) {
	Card c;

	char *myfifo = "pipe";

	// Creating the named file(FIFO)
	// mkfifo(<pathname>,<permission>)
	mkfifo(myfifo, 0666);

	while (1) {
		int fd1;
		char data[80];
		// First open in read only and read
		fd1 = open(myfifo, O_RDONLY);
		read(fd1, data, 80);

		std::string str1(data);
		// Print the read string and close
		if (str1[0] >= '0' and str1[0] <= '9') {
			string cn = "";
			for (int i = 0; i < str1.size(); i++)
				if (str1[i] >= '0' && str1[i] <= '9')
					cn += str1[i];
			c.checkCard(cn);

		}

		close(fd1);

	}

//	string cn = "";
//
//	for (int i = 1; i < argc; ++i)
//		cn += argv[i];

	return 0;
//	return c.checkCard(cn);

}
