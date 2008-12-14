#pragma once
#ifndef AUX_SPAWN_H
#define AUX_SPAWN_H

#define _XOPEN_SOURCE 600

#include <stdlib.h>
#include <unistd.h>

/**
 * Spawn process.
 *
 * \param file program file
 * \param argv command line arguments
 * \return PID of the new process or -1 on failure
 */
static pid_t spawn(const char *file, char *const argv[]) {
	pid_t pid = fork();

	if (pid == 0) {
		execvp(file, argv);
		_exit(EXIT_FAILURE);
	}

	return pid;
}


#include <sys/socket.h>

/**
 * Spawn process, capturing its input and output.
 *
 * \param file program file
 * \param argv command line arguments
 * \param sock pointer to an integer array to store socket descriptors
 * \return PID of the new process or -1 on failure
 */
static pid_t pspawn(const char *file, char *const argv[], int *sock) {
	int pair[2];

	if (socketpair(AF_UNIX, SOCK_STREAM, 0, pair))
		return -1;

	pid_t pid = fork();

	if (pid == 0) {
		close(pair[0]);
		for (int fd = 0; fd <= 2; ++fd)
			dup2(pair[1], fd);
		execvp(file, argv);
		_exit(EXIT_FAILURE);
	}

	close(pair[1]);
	*sock = pair[0];
	return pid;
}

#endif
