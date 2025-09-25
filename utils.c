/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:59:22 by guisanto          #+#    #+#             */
/*   Updated: 2025/09/25 15:10:00 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_absolute_path(char *cmd)
{
	if (ft_strchr(cmd, '/') != NULL)
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	return (NULL);
}

char	**get_path_dirs(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	if (!envp[i])
		return (NULL);
	return (ft_split(envp[i] + 5, ':'));
}

char	*search_in_paths(char *cmd, char **paths)
{
	char	*part_path;
	char	*path;
	int		i;

	i = -1;
	while (paths[++i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
	}
	return (NULL);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;

	path = check_absolute_path(cmd);
	if (path)
		return (path);
	paths = get_path_dirs(envp);
	if (!paths)
		return (NULL);
	path = search_in_paths(cmd, paths);
	ft_free(paths);
	return (path);
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

void	execute_command(char **cmd, char *path, char **envp)
{
	execve(path, cmd, envp);
	free(path);
	ft_free(cmd);
	error();
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
	execute_command(cmd, path, envp);
}
