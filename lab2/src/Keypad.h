/*
 * Keypad.h
 *
 *  Created on: Sep 23, 2019
 *      Author: jacoboffersen
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <stdio.h>
#include <iostream>
#include <string.h>

class Keypad {
public:
	Keypad();
	virtual ~Keypad();

	bool valid(const std::string pin);
	std::string get();
};

#endif /* KEYPAD_H_ */
