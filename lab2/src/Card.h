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
using namespace std;

#define PRINT_VALIDITY true

class Card {
public:
	string cardNumber;
	bool cardNumberValid;

	Card();
	virtual ~Card();

	void checkCard(string cardNumber) {
		this->cardNumber = cardNumber;
		this->cardNumberValid = this->checkValidity();
		if (PRINT_VALIDITY) {
			this->printResult();
		}
	}

private:
	bool checkValidity() {
		// Performs the Luhn algorithm to check if the
		// specified card number is valid
		// Resource: https://en.wikipedia.org/wiki/Luhn_algorithm

		int size = cardNumber.size();
		int sum = cardNumber[size - 1] - '0';
		int nDigits = size;
		int parity = nDigits % 2;
		for (int i = 0; i <= nDigits - 2; i++) {
			int digit = cardNumber[i] - '0';
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

	void printResult() {
		// Prints 'good' or 'bad' to the terminal depending on the
		// card validity. Useful for debugging.
		// Can be turned on/off with the global variable 'PRINT_VALIDITY'
		if (cardNumberValid) {
			cout << "Bad" << endl;
		} else {
			cout << "Good" << endl;
		}
	}
};

#endif /* CARD_H_ */
