/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:42:43 by smishos           #+#    #+#             */
/*   Updated: 2024/06/25 16:42:45 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void execute_command(char **cmd, char *path_cmd, char **envp)
{
    if (execve(path_cmd, cmd, envp) == -1)
        error_exit("Execution failed");
}

char *get_command_path(char *cmd, char **envp)
{
    char **paths;
    char *path;
    char *full_path;
    int i;

    paths = ft_split(getenv("PATH"), ':');
    if (!paths)
        error_exit("Path error");
    i = 0;
    while (paths[i])
    {
        path = ft_strjoin(paths[i], "/");
        full_path = ft_strjoin(path, cmd);
        free(path);
        if (access(full_path, X_OK) == 0)
        {
            ft_free_split(paths);
            return (full_path);
        }
        free(full_path);
        i++;
    }
    ft_free_split(paths);
    return (NULL);
}
