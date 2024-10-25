/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 13:27:24 by eschmitz          #+#    #+#             */
/*   Updated: 2024/08/30 15:20:24 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		indent;
	int		length_s1;
	int		length_s2;
	char	*string;

	if (s1 && s2)
	{
		length_s1 = ft_strlen(s1);
		length_s2 = ft_strlen(s2);
		string = (char *)malloc(sizeof(char) * (length_s1 + length_s2 + 1));
		if (string == NULL)
			return (NULL);
		indent = -1;
		while (s1[++indent])
			string[indent] = s1[indent];
		indent = -1;
		while (s2[++indent])
			string[length_s1 + indent] = s2[indent];
		string[length_s1 + indent] = '\0';
		return (string);
	}
	return (NULL);
}

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	free_tab(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

int	main(int argc, char **argv)
{
	char	**av;

	av = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2 && argv[1][0] != '\0')
	{
		av = ft_split(ft_strjoin("push_swap ", argv[1]), ' ');
		do_this_shit(argc, av);
	}
	else
		do_this_other_shit(argc, argv);
	return (0);
}
