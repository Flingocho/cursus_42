/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:01:48 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/11/06 17:27:14 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void push(t_stack_node **dst, t_stack_node **src)
{
    t_stack_node *push_node;
    
    if(!*src)
        return ;
    push_node = *src;
    *src = (*src)->next;
    if(*src)
        (*src)->prev = NULL;
    push_node->prev = NULL;
    if(!*dst)
    {
        *dst = push_node;
        push_node->next = NULL;
    }
    else
    {
        push_node->next = *dst;
        push_node->next->prev = push_node;
        *dst = push_node;
    }
}

void pa(t_stack_node **a, t_stack_node **b, bool print)
{
    push(a, b);
    if(!print)
        ft_printf("pa\n");
}

void pb(t_stack_node **b, t_stack_node **a, bool print)
{
    push(b, a);
    if(!print)
        ft_printf("pb\n");
}