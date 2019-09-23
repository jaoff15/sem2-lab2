/*
 * transaction.h
 *
 *  Created on: Sep 23, 2019
 *      Author: jacoboffersen
 */

#ifndef TRANSACTION_H_
#define TRANSACTION_H_

#include <stdio.h>
#include <string.h>

#include "FileHandling.h"

class Transaction {
public:
	Transaction();
	virtual ~Transaction();

	bool sendTransaction(const std::string card_number, const float amount);
};

#endif /* TRANSACTION_H_ */
