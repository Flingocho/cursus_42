/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:48:15 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/10/23 17:55:02 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void swap(t_stack_node **head)
{
    if(!head || !(*head)->next)
        return ;
    *head = (*head)->next;
    (*head)->prev->prev = *head;
    (*head)->prev->next = (*head)->next;
    if((*head)->next)
        (*head)->next->prev = (*head)->prev;
    (*head)->next = (*head)->prev;
    (*head)->prev = NULL;
}

void sa(t_stack_node **a, bool print)
{
    swap(a);
    if(!print)
        ft_printf("sa\n");
}

void sb(t_stack_node **b, bool print)
{
    swap(b);
    if(!print)
        ft_printf("sb\n");
}

void ss(t_stack_node **a, t_stack_node **b, bool print)
{
    swap(a);
    swap(b);
    if(!print)
        ft_printf("ss\n");
}