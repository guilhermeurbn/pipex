/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:59:22 by guisanto          #+#    #+#             */
/*   Updated: 2025/03/12 13:24:31 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Function that will look for the path line inside the environment, will
 split and test each command path and then return the right one. */
char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	i = -1;
	while (paths[++i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
		{
			ft_free(paths);
			return (path);
		}
		free(path);
	}
	ft_free(paths);
	return (NULL);
}

/* A simple error displaying function. */
void	error(void)
{
	perror("Error");
	exit(1);
}

/* Function that take the command and send it to find_path
 before executing it. */
void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;
	
	cmd = ft_split(argv, ' ');
	if (!cmd || !cmd[0])
	{
		ft_free(cmd);
		error();
	}
	path = find_path(cmd[0], envp);
	if (!path)	
	{
		ft_free(cmd);
		error();
	}
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		ft_free(cmd);
		error();
	}
	free(path);
	ft_free(cmd);
}
