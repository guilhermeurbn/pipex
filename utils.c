/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:59:22 by guisanto          #+#    #+#             */
/*   Updated: 2025/09/19 14:33:11 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*part_path;
	int		i;

	if (ft_strchr(cmd, '/') != NULL)
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	// Procurar no PATH
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
		if (access(path, X_OK) == 0)
			return (ft_free(paths), path);
		free(path);
	}
	ft_free(paths);
	return (NULL);
}

void	validate_command(char **cmd)
{
	if (!cmd || !cmd[0])
	{
		ft_free(cmd);
		error();
	}
}

char	**parse_command(char *argv)
{
	char	**cmd;
	
	cmd = ft_split(argv, ' ');
	if (!cmd || !cmd[0])
	{
		if (cmd)
			ft_free(cmd);
		return (NULL);
	}
	return (cmd);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = parse_command(argv);
	validate_command(cmd);
	path = find_path(cmd[0], envp);
	if (!path)
	{
		ft_free(cmd);
		error();
	}
	execve(path, cmd, envp);
	free(path);
	ft_free(cmd);
	error();
}
