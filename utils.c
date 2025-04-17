/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:59:22 by guisanto          #+#    #+#             */
/*   Updated: 2025/04/16 16:41:00 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*part_path;
	int		i;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (ft_free(paths), path);
		free(path);
	}
	ft_free(paths);
	return (NULL);
}
void	print_error_and_exit(void)
{
	perror("Error\n");
	exit(1);
}

void	validate_command(char **cmd)
{
	if (!cmd || !cmd[0])
	{
		ft_free(cmd);
		print_error_and_exit();
	}
}

/* Function that will look for the path line inside the environment, will
 split and test each command path and then return the right one. */

/* A simple error displaying function. */
void	error(void)
{
	perror("Error\n");
	exit(1);
}

/* Function that take the command and send it to find_path
 before executing it. */
void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	validate_command(cmd);
	path = find_path(cmd[0], envp);
	if (!path)
	{
		ft_free(cmd);
		print_error_and_exit();
	}
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		ft_free(cmd);
		print_error_and_exit();
	}
	free(path);
	ft_free(cmd);
}
