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
		printf("%s\n", *env_var);
		env_var++;
	}
}
