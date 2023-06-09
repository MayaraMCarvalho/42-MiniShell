/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:02:28 by macarval          #+#    #+#             */
/*   Updated: 2023/04/07 14:55:31 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;
	char	*text;

	if (argc && argv)
	{}
	shell.envp = envp;
	while (1)
	{
		text = make_text();
		printf("\033[1;35m");
		shell.line = readline(text);
		free(text);
		if (shell.line)
		{
			add_history (shell.line);
			//shell = make_shell(shell.line);

			// Configuração de teste dos builtins
			char	**split;

			split = ft_split(shell.line, ' ');
			if (split[0] == '<')
				// redirections(split);
			shell.command = split[0];
			shell.flag = ft_strdup("-n");
			shell.content = split[1];
			free(split);
			//
			if (shell.command && is_command(shell))
				printf("bash: %s: command not found\n", shell.command);
			free(shell.line);
		}
	}
	return (0);
}

char	*make_text(void)
{
	char	*text;
	char	buf[256];
	char	*path;
	char	*temp1;
	char	*temp2;

	temp1 = ft_strjoin(getenv("LOGNAME"), "@");
	temp2 = ft_strjoin(temp1, getenv("NAME"));
	free(temp1);
	temp1 = ft_strjoin("\033[1;33m", temp2);
	free(temp2);
	temp2 = ft_strjoin(temp1, "\033[1;0m:\033[1;35m~");
	free(temp1);
	path = getcwd(buf, 256);
	path = ft_substr(path, ft_strlen(getenv("HOME")), ft_strlen(path));
	temp1 = ft_strjoin(temp2, path);
	free(path);
	free(temp2);
	text = ft_strjoin(temp1, "\001\033[1;0m\002$\001\033[0m\002 ");
	free(temp1);
	return (text);
}
