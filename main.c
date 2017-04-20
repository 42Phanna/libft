/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 11:35:08 by phanna            #+#    #+#             */
/*   Updated: 2017/04/19 17:31:46 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_atoi.c"
#include "ft_isascii.c"
#include "ft_tolower.c"
#include "ft_toupper.c"
#include "ft_memset.c"
#include "ft_strdup.c"
#include "ft_strcmp.c"
#include "ft_strstr.c"
#include "ft_strchr.c"
#include "ft_strrchr.c"
#include "ft_strcat.c"
#include "ft_memccpy.c"
#include "ft_memchr.c"
#include "ft_memcmp.c"
#include "ft_strncpy.c"
#include "ft_putstr.c"
#include "ft_putchar.c"
#include "ft_strlen.c"


int	main()

{
	unsigned char a[] = "Hello World";
	unsigned char b[] = "BonjourWorld";
	char const i[] = "Bonjour";
	ft_putstr(i);
	ft_putchar('\n');
	printf("%d\n", ft_memcmp((const void *)a, (const void *)b, 5));
	printf("%d\n", memcmp((const void *)a, (const void *)b, 5));
	//printf("%s\n", (unsigned char*)ft_memccpy((void*)a, (void*)b, 87, 2));
	/*printf("my atoi: %d\n", ft_atoi("21474836471"));
	printf("atoi: %d\n", atoi("21474836471"));
	printf("my atoi: %d\n", ft_atoi("-21474836481"));
	printf("atoi: %d\n", atoi("-21474836481"));
	printf("my atoi: %d\n", ft_atoi("        456"));
	printf("atoi: %d\n", atoi("        456"));
	printf("my atoi: %d\n", ft_atoi("qwerty789"));
	printf("atoi: %d\n", atoi("-qwerty789"));
	printf("my atoi: %d\n", ft_atoi("99999999999999999"));
	printf("atoi: %d\n", atoi("99999999999999999"));
	printf("my isascii: %d\n", ft_isascii(-48));
	printf("isascii: %d\n", isascii(-48));
	printf("my isascii: %d\n", ft_isascii(0));
	printf("isascii: %d\n", isascii(0));
	printf("my isascii: %d\n", ft_isascii(48));
	printf("isascii: %d\n", isascii(48));
	printf("myisascii: %d\n", ft_isascii(127));
	printf("isascii: %d\n", isascii(127));
	printf("my isascii: %d\n", ft_isascii(128));
	printf("isascii: %d\n", isascii(128));
	printf("my tolower: %d\n", ft_tolower(48));
	printf("tolower: %d\n", tolower(48));
	printf("my tolower: %d\n", ft_tolower(65));
	printf("tolower: %d\n", tolower(65));
	printf("my tolower: %d\n", ft_tolower(97));
	printf("tolower: %d\n", tolower(97));
	printf("my tolower: %d\n", ft_tolower(32));
	printf("tolower: %d\n", tolower(32));
	printf("my toupper: %d\n", ft_toupper(48));
	printf("toupper: %d\n", toupper(48));
	printf("my toupper: %d\n", ft_toupper(65));
	printf("toupper: %d\n", toupper(65));
	printf("my toupper: %d\n", ft_toupper(97));
	printf("toupper: %d\n", toupper(97));
	printf("my toupper: %d\n", ft_toupper(32));
	printf("toupper: %d\n", toupper(32));
	printf("%s\n", ft_strdup("Hello World!"));
	printf("%d\n", ft_strcmp("", ""));
	printf("%d\n", strcmp("", ""));
	printf("%d\n", ft_strcmp("Hello", ""));
	printf("%d\n", strcmp("Hello", ""));
	printf("%d\n", ft_strcmp("", "Hello"));
	printf("%d\n", strcmp("", "Hello"));
	printf("%d\n", ft_strcmp("a", "b"));
	printf("%d\n", strcmp("a", "b"));
	printf("%d\n", ft_strcmp("Bonjour", "jour"));
	printf("%d\n", strcmp("Bonjour", "jour"));
	printf("%d\n", ft_strcmp("Bonjour", "Bonjar"));
	printf("%d\n", strcmp("Bonjour", "Bonjar"));
	printf("%d\n", ft_strcmp("lolilol", "lollolol"));
	printf("%d\n", strcmp("lolilol", "lollolol"));
	printf("%d\n", ft_strcmp("testcomplet", "testtccomplet"));
	printf("%d\n", strcmp("testcomplet", "testtccomplet"));
	printf("%s\n", ft_strstr("", ""));
	printf("%s\n", strstr("", ""));
	printf("%s\n", ft_strstr("H", ""));
	printf("%s\n", strstr("H", ""));
	printf("%s\n", ft_strstr("", "h"));
	printf("%s\n", strstr("", "h"));*/
//	printf("%s\n", ft_strchr("Bonjour", 106));
//	printf("%s\n", ft_strrchr("Bonjour joyeux joel", 106));
//	printf("%s\n", ft_strcat("Hello", " World"));
//	printf("%s\n", (unsigned char*)ft_memchr((void*)a, 87, 2));
//	printf("%s\n", ft_strncpy(a, b, 5));
	return (0);
}
