/*
 * File.h
 *
 *  Created on: Sep 23, 2019
 *      Author: jacoboffersen
 */

#ifndef FILE_H_
#define FILE_H_

#include <iostream>
#include <fstream>

namespace std {

class File {
public:
	File(string file_name);
	virtual ~File();

	string file_name;

	void write(string data);
private:
	string getTime() {
		char time_string[1000];
		time_t time_variable = time(NULL);
		struct tm *p = localtime(&time_variable);
		strftime(time_string, 1000, "%A, %B %d %Y", p);
		return time_string;
	}
};

} /* namespace std */

#endif /* FILE_H_ */
