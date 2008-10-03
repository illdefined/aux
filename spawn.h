#pragma once
#ifndef AUX_SPAWN_H
#define AUX_SPAWN_H

#include <stdlib.h>
#include <unistd.h>

static pid_t spawn(const char *file, char *const argv[]) {
	pid_t pid = fork();

	if (pid == 0) {
		execvp(file, argv);
		_exit(EXIT_FAILURE);
	}

	return pid;
}

#endif
