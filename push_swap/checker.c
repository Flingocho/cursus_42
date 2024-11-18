/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:53:32 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/11/06 21:12:10 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

char	**read_comands(void)
{
	char	c;
	char	*temp;
	char	**movements;

	temp = ft_strdup("");
	while (read(0, &c, 1) != 0)
		temp = ft_joinchar(temp, c);
	movements = ft_split(temp, '\n');
	free(temp);
	return (movements);
}

int	peasoifses(char **movements, t_stack_node **a, t_stack_node **b)
{
	int	i;

	i = 0;
	while (movements[i])
	{
		if (!ft_strncmp(movements[i], "sa", 3))
			sa(a, true);
		else if (!ft_strncmp(movements[i], "sb", 3))
			sb(b, true);
		else if (!ft_strncmp(movements[i], "ss", 3))
			ss(a, b, true);
		else if (!ft_strncmp(movements[i], "ra", 3))
			ra(a, true);
		else if (!ft_strncmp(movements[i], "rb", 3))
			rb(b, true);
		else if (!ft_strncmp(movements[i], "rr", 3))
			rr(a, b, true);
		else
			peasoifses2(movements[i], a, b);
		i++;
	}
	return (0);
}

void	peasoifses2(char *move, t_stack_node **a, t_stack_node **b)
{
	if (!ft_strncmp(move, "pa", 3))
		pa(a, b, true);
	else if (!ft_strncmp(move, "pb", 3))
		pb(b, a, true);
	else if (!ft_strncmp(move, "rra", 3))
		rra(a, true);
	else if (!ft_strncmp(move, "rrb", 3))
		rrb(b, true);
	else if (!ft_strncmp(move, "rrr", 3))
		rrr(a, b, true);
}

void	ft_free_ps(char **movements, t_stack_node **a)
{
	int	i;

	i = 0;
	while (movements[i])
	{
		free(movements[i]);
		i++;
	}
	free(movements);
	free_stack(a);
}

int	main(int argc, char **argv)
{
	char			**movements;
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		init_stack_a(&a, argv);
	}
	else
		init_stack_a(&a, argv + 1);
	movements = read_comands();
	peasoifses(movements, &a, &b);
	if (stack_sorted(a) == true && stack_len(b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_ps(movements, &a);
	return (0);
}
