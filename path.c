#include "main.h"

/**
 * path_lookup - looking for PATH to an executable
 *
 * @command: pointer to the command entered
 * Return: NULL
 */

char *path_lookup(const char *command)
{
	char *path_env = getenv("PATH");
	char *path = strdup(path_env);
	char *path_entry = strtok(path, ":");
	char cmd_path[MAX_COMMAND_LENGTH];

	if (path_env == NULL)
	{
		return (NULL);
	}
	if (path == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	while (path_entry != NULL)
	{
		snprintf(cmd_path, sizeof(cmd_path), "%s/%s", path_entry, command);
		/* Check if the command exists in the current directory */
		if (access(cmd_path, X_OK) == 0)
		{
			free(path);
			return (strdup(cmd_path));
		}
		path_entry = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
