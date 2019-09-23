/*
 * File.cpp
 *
 *  Created on: Sep 23, 2019
 *      Author: jacoboffersen
 */

#include "FileHandling.h"

FileHandling::FileHandling(std::string file_name) :
		file_name(file_name) {
}

FileHandling::~FileHandling() {
}

void FileHandling::write(const std::string data) {
	std::ofstream file;
	file.open(this->file_name, std::ios_base::app);
	file << getTime();
	file << " ";
	file << data;
	file.close();
}

std::string FileHandling::getTime() {
	char time_string[1000];
	time_t time_variable = time(NULL);
	struct tm *p = localtime(&time_variable);
	strftime(time_string, 1000, "%h %m %s, %d %B %Y", p);
	return time_string;
}
