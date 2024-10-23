/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:51:04 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/10/23 16:23:18 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	return_error(char *str)
{
	ft_printf("Error!\n");
	ft_printf("%s\n", str);
	exit(1);
	return (-1);
}
void	init_list(t_mylist *list)
{
	list->content = 0;
	list->next = NULL;
	list->previous = NULL;
	ft_printf("OK. List setted NULL\n");
}
void	init_piles(t_pile *piles)
{
	piles->a = NULL;
	piles->b = NULL;
	ft_printf("OK. Piles setted NULL\n");
}
int	*atoi_argv(int argc, char **argv)
{
	int	*numbers;
	int	i;

	i = 0;
	numbers = malloc((argc - 1) * sizeof(int));
	if (!numbers)
		return (numbers = NULL);
	while (i < argc - 1)
	{
		numbers[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	ft_printf("OK. atoi_argv completed\n");
	return (numbers);
}
int	check_arguments(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc < 2)
		return (return_error("Invalid  argv!\n"));
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
			if (ft_isdigit(argv[i][j++]) != 1)
				return (return_error("Only digits!"));
	}
	ft_printf("OK. Arguments are valid\n");
	return (0);
}
int	check_repeated(int *numbers, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		while (j < argc - 1)
		{
			if (numbers[i] == numbers[j] && i != j)
			{
				free(numbers);
				numbers = NULL;
				return (return_error("KO. Repeated number!"));
			}
			j++;
		}
		i++;
	}
	ft_printf("OK. No repeated numbers! :D\n");
	return (0);
}
t_mylist	*ft_mylstnew(int content)
{
	t_mylist	*new_node;

	new_node = (t_mylist *)malloc(sizeof(t_mylist));
	if (!new_node)
	{
		free(new_node);
		new_node = NULL;
		return (NULL);
	}
	new_node->content = content;
	new_node->next = NULL;
	new_node->previous = NULL;
	return (new_node);
}

int	main(int argc, char **argv)
{
	t_mylist list;
	t_pile pile;
	int *numbers;

	init_list(&list);
	init_piles(&pile);
	check_arguments(argc, argv);
	numbers = atoi_argv(argc, argv);
	check_repeated(numbers, argc);
	pile.a = ft_mylstnew(numbers[0]);
	printf("node content is %d\n", pile.a->content);

	// Put numbers in pile a
	free(pile.a);
	free(numbers);
	return (0);
}