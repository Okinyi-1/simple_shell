#include "main.h"

/**
 * exit_shell - terminates shell runtime
 */

void exit_shell(void)
{
	const char *message = "Exiting the shell.\n";
	write(STDOUT_FILENO, message, strlen(message));
	exit(EXIT_SUCCESS);
}
