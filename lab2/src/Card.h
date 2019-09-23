/*
 * Card.h
 *
 *  Created on: Sep 18, 2019
 *      Author: jacoboffersen
 */

#ifndef CARD_H_
#define CARD_H_

#include <iostream>
#include "stdio.h"
#include <ctime>

using namespace std;

//#define PRINT_VALIDITY true

// Valid number: 1234098743217895
// Invalid number: 4321543265437654

class Card {
public:
	string card_number;
	bool card_number_valid;

	Card();
	virtual ~Card();

	bool checkCard(string card_number) {
		this->card_number = card_number;
		this->card_number_valid = this->checkValidity();
		return this->card_number_valid;
//		if (PRINT_VALIDITY) {
//			this->printResult();
//		}
	}

private:
	bool checkValidity() {
		// Performs the Luhn algorithm to check if the
		// specified card number is valid
		// Resource: https://en.wikipedia.org/wiki/Luhn_algorithm

		int size = card_number.size();
		int sum = card_number[size - 1] - '0';
		int card_digits = size;
		int parity = card_digits % 2;
		for (int i = 0; i <= card_digits - 2; i++) {
			int digit = card_number[i] - '0';
			if (i % 2 == parity) {
				digit = digit * 2;
			}
			if (digit > 9) {
				digit = digit - 9;
			}
			sum = sum + digit;
		}
		return !(sum % 10) == 0;
	}

//	void printResult() {
//		// Prints 'good' or 'bad' to the terminal depending on the
//		// card validity. Useful for debugging.
//		// Can be turned on/off with the global variable 'PRINT_VALIDITY'
//
//		if (card_number_valid) {
//			this->printDate();
//
//			//			cout << " Error! Invalid card number: " << card_number.c_str()
//		<< endl;
//
//	} else {
//		cout << card_number.c_str() << endl;
//	}
//}
//void printDate() {
//	char time_string[1000];
//	time_t time_variable = time(NULL);
//	struct tm *p = localtime(&time_variable);
//	strftime(time_string, 1000, "%A, %B %d %Y", p);
//	cout << time_string;
//}
};

#endif /* CARD_H_ */
