//============================================================================
// Name        : lab2.cpp
// Author      : Jacob Offersen
// Version     :
// Copyright   : Your copyright notice
// Description : Lab 2
//============================================================================

#include <iostream>
#include "stdio.h"
#include "Card.h"

using namespace std;

int main(int argc, char **argv) {
	Card c;
	string cn = "";

	for (int i = 1; i < argc; ++i)
		cn += argv[i];

	return c.checkCard(cn);

}
