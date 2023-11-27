/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:40:33 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/23 16:41:09 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include "libft.h"

int main(void)
{
	char	*str;
	
	str = ft_strppd_c(NULL, 'c');
	printf("%s\n", str);
	free(str);
	return 0;
}

// int	main(void)
// {
//     int number    =  5;
//     char *pointer = "little";

//     printf("Here is a number-%4d-and a-%10s-word.\n", number, pointer);
// }

// int	main(void)
// {
//     int number=5;

//     printf("---%*d----\n", 6, number);
// 	printf(" %-10d\n", number);
//     printf(" %010d\n", number);
//     printf(" %#-10x\n", number);  
//     printf(" %#x\n", number);
// }

// int	main(void)
// {
// 	t_field	*test;

// 	test = ft_newfield();
// 	free(test);
// }