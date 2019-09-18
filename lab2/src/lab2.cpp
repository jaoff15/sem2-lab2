//============================================================================
// Name        : lab2.cpp
// Author      : Jacob Offersen
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "stdio.h"
#include "Card.h"

using namespace std;

int main() {
	Card c;
	c.checkCard("79927398711");
	c.checkCard("79927398712");
	c.checkCard("79927398713");
	c.checkCard("79927398714");
	c.checkCard("79927398715");
	c.checkCard("79927398716");
	c.checkCard("79927398717");
	c.checkCard("79927398718");
//	check(checkLuhn("79927398711"));
//	check(checkLuhn("79927398712"));
//	check(checkLuhn("79927398713"));
//	check(checkLuhn("79927398714"));
//	check(checkLuhn("79927398715"));
//	check(checkLuhn("79927398716"));
//	check(checkLuhn("79927398717"));
//	check(checkLuhn("79927398718"));
	return 0;
}
