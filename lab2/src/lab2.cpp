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
	Card card;

	char *myfifo = "pipe";

	// Creating the named file(FIFO)
	// mkfifo(<pathname>,<permission>)
	mkfifo(myfifo, 0666);

	while (1) {
		int pipe_id;
		char pipe_data[80];
		// First open in read only and read
		pipe_id = open(myfifo, O_RDONLY);
		read(pipe_id, pipe_data, 80);

		std::string raw_data_string(pipe_data);
		// Print the read string and close
		if (raw_data_string[0] >= '0' and raw_data_string[0] <= '9') {
			string clean_data_string = "";
			for (int i = 0; i < raw_data_string.size(); i++)
				if (raw_data_string[i] >= '0' && raw_data_string[i] <= '9')
					clean_data_string += raw_data_string[i];
			card.checkCard(clean_data_string);
		}
		close(pipe_id);
	}
	return 0;
}
