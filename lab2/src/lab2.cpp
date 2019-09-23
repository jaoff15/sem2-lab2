//============================================================================
// Name        : lab2.cpp
// Author      : Jacob Offersen
// Version     :
// Copyright   : Your copyright notice
// Description : Lab 2
//============================================================================

#include <stdio.h>
#include <string.h>
#include <sstream>

#include "Card.h"
#include "FileHandling.h"
#include "Pipe.h"
#include "Transaction.h"
#include "Keypad.h"
#include "Pin.h"

bool validNumber(const std::string raw_data_string) {
	return (raw_data_string[0] >= '0' and raw_data_string[0] <= '9');
}

std::string cleanString(const std::string raw_data_string) {
	std::string clean_data_string = "";
	if (raw_data_string[0] >= '0' and raw_data_string[0] <= '9') {
		for (int i = 0; i < raw_data_string.size(); i++) {
			if (raw_data_string[i] >= '0' && raw_data_string[i] <= '9')
				clean_data_string += raw_data_string[i];
			else
				break;
		}
	}
	return clean_data_string;
}

enum State {
	INSERT_CARD,
	WAIT_FOR_CARD,
	VALIDATE_CARD,
	INPUT_PIN,
	APPROVE_AMOUNT,
	TRANSMIT_AMOUNT
} state, old_state;

std::string state_names[6] = { "INSERT_CARD", "WAIT_FOR_CARD", "VALIDATE_CARD",
		"INPUT_PIN", "APPROVE_AMOUNT", "TRANSMIT_AMOUNT" };

std::string insertCard(Pipe pipe) {
	std::string pipe_data = pipe.readPipe();
	std::string raw_data_string(pipe_data);
	if (validNumber(raw_data_string)) {
		return raw_data_string;
	} else {
		return "";
	}
}

std::string validateCard(Card card, const std::string raw_data_string) {
	std::string clean_data_string = cleanString(raw_data_string);
	if (card.checkValidity(clean_data_string)) {
		return clean_data_string;
	} else {
		return "";
	}
}

bool approveAmount(const int amount) {
	std::string currency = "kr";
	std::cout << amount << currency
			<< ". Press 'y' for approving amount, 'n' for canceling purchase"
			<< std::endl;
	std::string reply;
	std::cin >> reply;
	return reply == "y";
}

int main(int argc, char **argv) {
	FileHandling error_file("Error_File.txt");
	FileHandling debug_file("Debug.txt");

	Card card;
	Pipe card_number_pipe;
	Keypad keypad;
	Pin pin;

	std::string raw_card_number;
	std::string card_number;
	std::string state_name;

	float amount = 200;

	while (1) {
		state_name = state_names[state];
		switch (state) {
		case INSERT_CARD:
			std::cout << "Please insert card" << std::endl;
			state = WAIT_FOR_CARD;
			break;
		case WAIT_FOR_CARD:
			raw_card_number = insertCard(card_number_pipe);
			if (raw_card_number != "") {
				// If card is inserted
				state = VALIDATE_CARD;
				debug_file.write("Card inserted\n");
			}
			break;
		case VALIDATE_CARD:
			card_number = validateCard(card, raw_card_number);
			if (card_number != "") {
				// Card valid
				state = INPUT_PIN;
				std::cout << card_number << std::endl;
				debug_file.write("Card valid\n");
			} else {
				// Card invalid
				state = WAIT_FOR_CARD;
				error_file.write(
						"Error! Card number invalid: " + card_number + "\n");
				debug_file.write("Card invalid\n");
			}
			break;
		case INPUT_PIN: {
			std::cout << "Input pin ";
			std::string pin_number = keypad.get();
			debug_file.write("PIN inputtet\n");

			if (pin.pinValid(pin_number)) {
				state = APPROVE_AMOUNT;
				debug_file.write("PIN valid\n");
			} else {
				state = INSERT_CARD;
				error_file.write("Error! PIN invalid\n");
				debug_file.write("PIN invalid\n");
			}

			break;
		}

		case APPROVE_AMOUNT: {
			bool approve = approveAmount(amount);
			if (approve) {
				// Amount approved
				state = TRANSMIT_AMOUNT;
				debug_file.write("Amount approved\n");
			} else {
				// Amount not approved
				state = INSERT_CARD;
				error_file.write("Amount not approved\n");
				debug_file.write("Amount not approved\n");
			}
			break;
		}
		case TRANSMIT_AMOUNT: {
			Transaction transaction;
			bool transaction_approved = transaction.sendTransaction(card_number,
					amount);
			if (!transaction_approved) {
				std::cout << "Transaction error";
				error_file.write("Transaction not approved\n");
				debug_file.write("Transaction not approved\n");
			} else {
				debug_file.write("Transaction approved\n");
			}
			state = INSERT_CARD;

			break;
		}
		default:
			break;
		}

	}

	// Log state changes
	if (old_state != state) {
		debug_file.write("State changed to " + state_name + "\n");
	}
	old_state = state;

	return 0;
}

