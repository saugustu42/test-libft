#include <stdio.h>
#include "./eval-libft/libft.h"
#include <string.h>
#include "print_output.h"

char	test(unsigned int i, char c)
{
	return c + (i % 2);
}

int		main(void)
{

	print_tester_name();

	print_title("ATOI");

	char num[12];
	sprintf(num, "%d", ft_atoi("000000000000000000000042"));
	printf("checking atoi crutch\n");
	print_result("42", num);
	printf("checking basic case\n");
	sprintf(num, "%d", ft_atoi("-------++---42"));
	print_result("0", num);




	print_title("STRNSTR");

	printf("checking basic case\n");
	print_result("123", ft_strnstr("000000123", "123", 9));




	print_title("SPLIT");

	printf("checking split with a string containing only delimiters\n");
	char **splited;
	splited = ft_split("    ", ' ');
	if (splited == NULL)
		print_result("\033[31m :( expected array of pointers with one element pointing to NULL\033[0m", "(null)");
	else
		print_result("(null)", *splited);
	printf("\nchecking split with empty string\n");
	splited = ft_split("", ' ');
	if (splited == NULL)
		print_result("\033[31m :( expected array of pointers with one element pointing to NULL\033[0m", "(null)");
	else
		print_result("(null)", *splited);
	printf("\nchecking split with string and \\0 as delimiter\n");
	splited = ft_split("Hello, world!", '\0');
	if (splited == NULL)
		print_result("Hello, world!", "(null)");
	else
		print_result("Hello, world!", *splited);
	printf("\nchecking split with empty string and \\0 as delimiter\n");
	splited = ft_split("", '\0');
	if (splited == NULL)
		print_result("\033[31m :( expected array of pointers with one element pointing to NULL\033[0m", "(null)");
	else
		print_result("(null)", *splited);




	print_title("SUBSTR");

	printf("checking basic cases\n");
	print_result("RUN!", ft_substr("1 2 3... RUN!", 9, 4));
	print_result("est", ft_substr("test", 1, 8));
	printf("\nchecking substr return when index is out of the string\n");
	char *substr_ret;
	substr_ret = ft_substr("HelloCat", 15, 3);
	if (substr_ret == NULL)
		print_result("\033[31mexpected empty string. it is stupid, but fact :( \033[0m", "(null)" );
	else
		print_result("", substr_ret);




	print_title("STRTRIM");

	printf("checking with empty strings\n");
	print_result("", ft_strtrim("", " "));
	print_result("", ft_strtrim("", ""));
	printf("\nchecking basic cases\n");
	print_result("A**A", ft_strtrim("*@****@**A**A***@*", "*@"));
	print_result("B", ft_strtrim("*@*..****@**@**....B....***@****..*@***", ".*@"));
	print_result("C", ft_strtrim("*@****@*******@*C", "*@"));
	print_result("D", ft_strtrim("D", "123456789"));



	print_title("STRMAPI");

	printf("checking with empty string\n");
	print_result("", ft_strmapi("", test));
}
