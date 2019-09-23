/*
 * Keypad.cpp
 *
 *  Created on: Sep 23, 2019
 *      Author: jacoboffersen
 */

#include "Keypad.h"

Keypad::Keypad() {
	// TODO Auto-generated constructor stub

}

Keypad::~Keypad() {
	// TODO Auto-generated destructor stub
}

std::string Keypad::get() {
	std::string pin;
	std::cin >> pin;
	return pin;
}
