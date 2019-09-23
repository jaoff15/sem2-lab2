//============================================================================
// Name        : lab2.cpp
// Author      : Jacob Offersen
// Version     :
// Copyright   : Your copyright notice
// Description : Lab 2
//============================================================================

#include <stdio.h>
#include <string.h>

#include "Card.h"
#include "FileHandling.h"
#include "Pipe.h"

bool validNumber(const string raw_data_string) {
	return (raw_data_string[0] >= '0' and raw_data_string[0] <= '9');
}

std::string cleanString(const string raw_data_string) {
	string clean_data_string = "";
// Print the read string and close
	if (raw_data_string[0] >= '0' and raw_data_string[0] <= '9') {
		for (int i = 0; i < raw_data_string.size(); i++) {
			if (raw_data_string[i] >= '0' && raw_data_string[i] <= '9')
				clean_data_string += raw_data_string[i];
		}
	}
	return clean_data_string;
}

int main(int argc, char **argv) {
	Card card;
	FileHandling error_file("Error_File.txt");
	Pipe card_number_pipe;

	while (1) {
		std::string pipe_data = card_number_pipe.readPipe();
		std::string raw_data_string(pipe_data);
		if (validNumber(raw_data_string)) {
			std: string clean_data_string = cleanString(raw_data_string);
			bool card_valid = card.checkValidity(clean_data_string);
			if (card_valid) {
				cout << clean_data_string << endl;
			} else {
				error_file.write(
						"Error! Card number invalid: " + clean_data_string
								+ "\n");
			}
		}

	}
	return 0;
}

