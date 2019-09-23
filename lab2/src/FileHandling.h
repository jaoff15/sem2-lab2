/*
 * File.h
 *
 *  Created on: Sep 23, 2019
 *      Author: jacoboffersen
 */

#ifndef FILEHANDLING_H_
#define FILEHANDLING_H_

#include <iostream>
#include <fstream>
#include <ctime>

class FileHandling {
public:
	FileHandling(std::string file_name);
	virtual ~FileHandling();

	const std::string file_name;

	void write(const std::string data);
private:
	std::string getTime();

};

#endif /* FILEHANDLING_H_ */
