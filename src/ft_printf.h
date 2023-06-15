#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>


typedef struct s_flags
{
	// unsigned int	minus : 0;
	// unsigned int	plus : 0;
	// unsigned int	zero : 0;
	// unsigned int	space : 0;
	unsigned int	hashtag;
}	t_flags;



//####################### Main #######################

int	ft_printf(const char *str, ...);

//####################### Specifiers #######################

int	print_base(int arg, int base);
int	print_char(int arg);
int	print_int(int arg);
int print_percent(void);
int print_pointer(void *arg, int base);
int	print_string(char *arg);
int	print_unsign_int(unsigned int arg);
int print_hex_d(unsigned int arg, int uppercase, t_flags flags);

//####################### Utils #######################

int putnbr_ptr(unsigned long int value, int base);
int putnbr_int(unsigned int value, int base);
void	ft_putchar(char c);
void	ft_putchar_int(char c);
void	ft_putchar_hex(char c);

#endif