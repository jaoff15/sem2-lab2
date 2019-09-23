/*
 * File.cpp
 *
 *  Created on: Sep 23, 2019
 *      Author: jacoboffersen
 */

#include "File.h"

namespace std {

File::File(string file_name) {
	// TODO Auto-generated constructor stub
	this->file_name = file_name;
}

void File::write(string data) {
	ofstream file;
	file.open(this->file_name, ios_base::app);
	file << getTime();
	file << " ";
	file << data;
	file.close();
}

File::~File() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
