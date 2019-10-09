/*
 * Pipe.h
 *
 *  Created on: Sep 23, 2019
 *      Author: jacoboffersen
 */

#ifndef PIPE_H_
#define PIPE_H_

#include <iostream>
#include <fstream>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

class Pipe {
public:
	Pipe();
	virtual ~Pipe();

	std::string readPipe();

private:
	const char *fifo_id;
};

#endif /* PIPE_H_ */
