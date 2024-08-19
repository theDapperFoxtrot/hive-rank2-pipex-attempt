/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:42:43 by smishos           #+#    #+#             */
/*   Updated: 2024/08/19 19:41:16 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
// Execute the command
void	execute_command(char **cmd, char *path_cmd, char **envp)
{
	if (execve(path_cmd, cmd, envp) == -1) // Execute the command
		error_exit(cmd, 1); // If the command failed to execute, exit with an error
}

char	*get_command_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*full_path;
	int		i;

	while (ft_strnstr(envp[i], "PATH", 4) == 0) // Find the PATH variable
		i++;
	paths = ft_split(envp[i] + 5, ':'); // Split the PATH variable
	i = 0;

	if (!paths)
		error_exit(cmd, 0);
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/"); // Join the path with a slash
		full_path = ft_strjoin(path, cmd); // Join the path with the command
		free(path); // Free the path
		if (access(full_path, X_OK) == 0) // Check if the command is executable
		{
			free_split(paths); // Free the split
			return (full_path); // Return the full path
		}
		free(full_path);
		i++;
	}
	free_split(paths); // Free the split
	error_exit(cmd, 0); // If the command was not found, exit with an error
	return (NULL); // Return NULL
}
int error_checker(char *string)
{
	int i;

	i = 0;
	while (string[i])
	{
		if (string[i] != 0 && (string[i] != '/' || string[i] != '.' || string[i] != ' '))
			i++;
		if (string[i] == '/')
		{
			i = 0;
			while (string[i])
				write(1, &string[i++], 1);
			write(1, ": ", 2);
			error_exit("Is a directory", 0);
		}
		if (string[i] == '.')
		{
			i = 0;
			while (string[i])
				write(1, &string[i++], 1);
			write(1, ": ", 2);
			error_exit("No such file or directory", 0);
		}
		if (string[i] == ' ')
		{
			i = 0;
			while (string[i])
				write(1, &string[i++], 1);
			write(1, ": ", 2);
			error_exit("command not found", 0);
		}
	}
		return (0);
}