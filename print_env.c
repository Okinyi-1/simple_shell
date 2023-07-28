#include "main.h"

/**
 * print_environment - Displays the external environment
 *
 * Return: 0 Success
 */

void print_environment(void)
{
	char **env_var = environ;

	while (*env_var != NULL)
	{
		size_t len = strlen(*env_var);
		write(STDOUT_FILENO, *env_var, len);
		write(STDOUT_FILENO, "\n", 1);
		env_var++;
	}
}
