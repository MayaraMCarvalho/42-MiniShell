/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:36:32 by macarval          #+#    #+#             */
/*   Updated: 2023/06/03 17:26:04 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	c_unset(t_shell shell)
{
	if (!strcmp_mod(shell.command, "unset"))
	{
		update_(shell);
		apart_args(shell, ' ', exe_unset);
		return (1);
	}
	return (0);
}

int	exe_unset(t_shell shell)
{
	t_lst	*node;

	if (shell.content)
	{
		if (is_args(shell))
		{
			node = find_arg(shell, shell.content);
			if (is_flag_null(shell) && node != NULL && node->type != ENVP)
			{
				if (shell.env == node)
					shell.env = node->next;
				else
					node->prev->next = node->next;
				if (node->next != NULL)
					node->next->prev = node->prev;
				free(node->var);
				free(node->msg);
				free(node);
			}
		}
	}
	return (0);
}
