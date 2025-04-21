/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:07:58 by guisanto          #+#    #+#             */
/*   Updated: 2025/04/21 12:06:07 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// apenas para erros e free
void	error(void)
{
	perror("Error\n");
	exit(1);
}

void	ft_free(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
