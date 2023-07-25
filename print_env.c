#include "main.h"

/**
 * print_environment - Displays the external environment
 *
 * @environ: pointer to the environment
 * @env_var: pointer to environ
 */

extern char **environ;

void print_environment(void)
{
	char **env_var = environ;

	while (*env_var != NULL)
	{
		printf("%s\n", *env_var);
		env_var++;
	}
}
