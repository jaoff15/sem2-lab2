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

// Valid number: 1234098743217895
// Invalid number: 4321543265437654

class Card {
public:
	Card();
	virtual ~Card();

	bool checkValidity(const string card_number);

};

#endif /* CARD_H_ */
