/*
 * Pin.h
 *
 *  Created on: Sep 23, 2019
 *      Author: jacoboffersen
 */

#ifndef PIN_H_
#define PIN_H_

#include <stdio.h>
#include <iostream>
#include <string.h>

class Pin {
public:
	Pin();
	virtual ~Pin();

	bool pinValid(const std::string pin);
};

#endif /* PIN_H_ */
