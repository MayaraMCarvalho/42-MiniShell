/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:13:26 by macarval          #+#    #+#             */
/*   Updated: 2023/06/03 20:14:58 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

// Passar norminette

int	is_command(t_shell shell)
{
	if (c_echo(shell))
		return (0);
	else if (c_cd(shell))
		return (0);
	else if (c_pwd(shell))
		return (0);
	else if (c_export(shell))
		return (0);
	else if (c_unset(shell))
		return (0);
	else if (c_env(shell))
		return (0);
	else if (c_clear(shell))
		return (0);
	else if (c_exit(shell))
		exit(0);
	else if (c_local(shell))
		return (0);
	return (1);
}

void	update_(t_shell shell)
{
	char	*var;

	if (shell.content == NULL && ft_strchr(shell.command, '='))
		update_var(shell, "_", NULL);
	else
	{
		var = ft_strjoin("/usr/bin/", shell.command);
		update_var(shell, "_", var);
		free(var);
	}
}

int	c_pwd(t_shell shell)
{
	char	buf[256];

	if (!strcmp_mod(shell.command, "pwd"))
	{
		if (!is_flag_null(shell))
			return (1);
		printf("%s\n", getcwd(buf, 256));
		return (1);
	}
	return (0);
}
