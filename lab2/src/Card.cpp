/*
 * Card.cpp
 *
 *  Created on: Sep 18, 2019
 *      Author: jacoboffersen
 */
#include "Card.h"

Card::Card() {
}

Card::~Card() {
}

bool Card::checkValidity(const string card_number) {
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
