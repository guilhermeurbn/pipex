/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 23:34:37 by guisanto          #+#    #+#             */
/*   Updated: 2025/03/11 14:48:57 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define PIPEX_H
#ifndef PiPEX_H

void	parent_process(char **argv, char **envp, int *fd);
void	babe_pipe(char **argv, char **envp, int *fd);
char	*find_path(char *cmd, char **envp);
void	error(void);
void	execute(char *argv, char **envp);

#endif