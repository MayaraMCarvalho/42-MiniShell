/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:06:57 by macarval          #+#    #+#             */
/*   Updated: 2023/06/03 18:38:58 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	c_local(t_shell shell)
{
	if (shell.content == NULL && ft_strchr(shell.command, '='))
	{
		shell.content = shell.command;
		apart_args(shell, ' ', add_local);
		return (1);
	}
	return (0);
}

int	add_local(t_shell shell)
{
	t_lst	*node;
	char	*var;
	char	*msg;

	var = strchr_rev(shell.content, '=');
	if (!var)
		var = ft_strdup(shell.content);
	msg = strchr_mod(shell.content, '=');
	node = find_arg(shell, var);
	add_node(shell, node, var, msg, LOCAL);
	return (0);
}

int	is_args_local(char	**split)
{
	int	i;

	i = -1;
	while (split[++i])
	{
		if (ft_strchr (split[i], '=') == NULL)
		{
			printf("%s: command not found\n", split[i]);
			return (1);
		}
	}
	return (0);
}