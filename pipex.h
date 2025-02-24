/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 23:34:37 by guisanto          #+#    #+#             */
/*   Updated: 2025/02/24 19:11:09 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include <sys/types.h>
#include <sys/wait.h>

# define PIPEX_H
# ifndef PiPEX_H

void    parent_process(char **argv, char **envp, int *fd);
void    babe_pipe(char **argv, char **envp, int *fd);
char    *find_path(char *cmd, char **envp);
void    error(void);
void    execute(char *argv, char **envp);

#endif


