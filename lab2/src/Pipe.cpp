/*
 * Pipe.cpp
 *
 *  Created on: Sep 23, 2019
 *      Author: jacoboffersen
 */

#include "Pipe.h"

Pipe::Pipe() {
// Creating the named file(FIFO)
// mkfifo(<pathname>,<permission>)
	fifo_id = "swipe";
	mkfifo(fifo_id, 0666);

}

Pipe::~Pipe() {
}

std::string Pipe::readPipe() {
	char pipe_data[80];
	int pipe_id;
	pipe_id = open(fifo_id, O_RDONLY);
	read(pipe_id, pipe_data, 80);
	close(pipe_id);
	return pipe_data;
}
