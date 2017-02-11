#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>

int main(void)
{
	int32_t status;
	pid_t child_pid;
	FILE *logfile_handle = fopen("lab3aoutput.txt", "w");
	assert(logfile_handle != NULL);

	status = fprintf(logfile_handle, "Parent pid: %d\n", getpid());
	assert(status != EOF);

	for (uint32_t num_forked = 0;
	     num_forked < 8;
	     ++num_forked) {
		child_pid = fork();
		assert(child_pid >= 0);

		if (child_pid == 0)
			_exit(EXIT_SUCCESS);

		status = fprintf(logfile_handle,
				 "Fork %u pid: %d\n",
				 num_forked,
				 child_pid);
		assert(status != EOF);

		status = wait(NULL);
		assert(status >= 0);
	}

	status = fclose(logfile_handle);
	assert(status != EOF);

	exit(EXIT_SUCCESS);
}
