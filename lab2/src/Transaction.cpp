/*
 * transaction.cpp
 *
 *  Created on: Sep 23, 2019
 *      Author: jacoboffersen
 */

#include "Transaction.h"

Transaction::Transaction() {
	// TODO Auto-generated constructor stub

}

Transaction::~Transaction() {
	// TODO Auto-generated destructor stub
}

bool Transaction::sendTransaction(const std::string card_number,
		const float amount) {
	FileHandling purchase_history("purchase_history");
	purchase_history.write(
			std::string(card_number) + ", " + std::to_string(amount) + "\n");
	bool transaction_approved = true;
	return transaction_approved;
}
