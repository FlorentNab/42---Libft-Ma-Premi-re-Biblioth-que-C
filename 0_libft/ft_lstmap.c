/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FlorentNab <florent.42borntocode@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:15:23 by flonaben          #+#    #+#             */
/*   Updated: 2024/11/27 21:45:44 by FlorentNab       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_node = NULL;
	start = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&start, del);
			return (NULL);
		}
		ft_lstadd_back(&start, new_node);
		lst = lst->next;
	}
	return (start);
}

/* 
gcc ft_lstmap.c ft_lstnew.c ft_lstclear.c ft_lstadd_back.c ft_lstdelone.c 
ft_lstlast.c -o test_program
*/
// #include <stdio.h>

// void	*double_content(void *content)
// {
// 	int	*value = (int *)content;
// 	int	*new_value = malloc(sizeof(int));
// 	if (!new_value)
// 		return (NULL);
// 	*new_value = *value * 2;
// 	return (new_value);
// }

// void	delete_content(void *content)
// {
// 	free(content);
// }

// void	print_list(t_list *lst)
// {
// 	while (lst)
// 	{
// 		printf("%d -> ", *(int *)lst->content);
// 		lst = lst->next;
// 	}
// 	printf("NULL\n");
// }

// int	main(void)
// {
// 	t_list	*original_list = NULL;
// 	t_list	*new_list;
// 	int		a = 1, b = 2, c = 3, d = 4;

// 	// Create original list: 1 -> 2 -> 3 -> 4
// 	ft_lstadd_back(&original_list, ft_lstnew(&a));
// 	ft_lstadd_back(&original_list, ft_lstnew(&b));
// 	ft_lstadd_back(&original_list, ft_lstnew(&c));
// 	ft_lstadd_back(&original_list, ft_lstnew(&d));

// 	printf("Original list: ");
// 	print_list(original_list);

// 	// Map function
// 	new_list = ft_lstmap(original_list, double_content, delete_content);

// 	printf("Mapped list (doubled): ");
// 	print_list(new_list);

// 	// Free both lists
// 	ft_lstclear(&original_list, delete_content);
// 	ft_lstclear(&new_list, delete_content);

// 	return (0);
// }
