/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:40:48 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/10/23 17:47:49 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void rev_rotate(t_stack_node **stack)
{
    t_stack_node *last;
    
    if(!stack || !(*stack)->next)
        return ;
    last = find_last(*stack);
    last->prev->next = NULL;
    last->next = *stack;
    last->prev = NULL;
    *stack = last;
    last->next->prev = last;
}

void rra(t_stack_node **a, bool print)
{
    rev_rotate(a);
    if(!print)
        ft_printf("rra\n");
}

void rrb(t_stack_node **b, bool print)
{
    rev_rotate(b);
    if(!print)
        ft_printf("rrb\n");
}

void rrr(t_stack_node **a, t_stack_node **b, bool print)
{
    rev_rotate(a);
    rev_rotate(b);
    if(!print)
        ft_printf("rra\n");
}