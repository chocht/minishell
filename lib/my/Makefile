##
## Makefile for lib in /home/chauch_p/librairie/lib/my
## 
## Made by Pierre Chauchoy
## Login   <chauch_p@epitech.net>
## 
## Started on  Mon Feb 15 14:15:38 2016 Pierre Chauchoy
## Last update Thu Jun  2 11:49:59 2016 Pierre Chauchoy
##

# ---------- Directories ----------

EXIT_FREE_MAL	= at_exit_free_malloc

GET_NEXT_LINE	= get_next_line

PRINTF		= printf

STR_AND_NBERS	= string_and_numbers

INC_TARGET	= ../../include/

LIB_TARGET	= ../

# ---------- Names ----------

NAME		= my

LIB		= lib$(NAME).a

INC		= my.h

# ---------- Sources ----------

SRCS		= $(EXIT_FREE_MAL)/at_exit.c \
		  $(EXIT_FREE_MAL)/my_free.c \
		  $(EXIT_FREE_MAL)/my_malloc.c \
		  $(GET_NEXT_LINE)/get_next_line.c \
		  $(PRINTF)/my_printf.c \
		  $(PRINTF)/my_printf_func_1.c \
		  $(PRINTF)/my_printf_func_2.c \
		  $(PRINTF)/my_printf_func_3.c \
		  $(PRINTF)/my_printf_func_4.c \
		  $(PRINTF)/my_printf_func_5.c \
		  $(STR_AND_NBERS)/my_getnbr_base.c \
		  $(STR_AND_NBERS)/my_getnbr.c \
		  $(STR_AND_NBERS)/my_getnbr_float.c \
		  $(STR_AND_NBERS)/my_is_in_str.c \
		  $(STR_AND_NBERS)/my_is_in_wordtab.c \
		  $(STR_AND_NBERS)/my_is_in_inttab.c \
		  $(STR_AND_NBERS)/my_len_wordtab.c \
		  $(STR_AND_NBERS)/my_power_rec.c \
		  $(STR_AND_NBERS)/my_putchar.c \
		  $(STR_AND_NBERS)/my_putnbr_base.c \
		  $(STR_AND_NBERS)/my_put_nbr.c \
		  $(STR_AND_NBERS)/my_put_nbr_float.c \
		  $(STR_AND_NBERS)/my_putstr.c \
		  $(STR_AND_NBERS)/my_revstr.c \
		  $(STR_AND_NBERS)/my_show_wordtab.c \
		  $(STR_AND_NBERS)/my_strcat_char.c \
		  $(STR_AND_NBERS)/my_strcmp.c \
		  $(STR_AND_NBERS)/my_strcmp_overflow.c \
		  $(STR_AND_NBERS)/my_strcpy.c \
		  $(STR_AND_NBERS)/my_strdup.c \
		  $(STR_AND_NBERS)/my_strisalpha.c \
		  $(STR_AND_NBERS)/my_str_isnum.c \
		  $(STR_AND_NBERS)/my_str_isnum_pos.c \
		  $(STR_AND_NBERS)/my_strlen.c \
		  $(STR_AND_NBERS)/my_strncmp.c \
		  $(STR_AND_NBERS)/my_strstr.c \
		  $(STR_AND_NBERS)/my_str_to_wordtab.c \
		  $(STR_AND_NBERS)/my_str_to_wordtab2.c \
		  $(STR_AND_NBERS)/my_wordtabcat_string.c \
		  $(STR_AND_NBERS)/my_wordtab_dup.c

# ---------- Objects ----------

OBJS		= $(SRCS:.c=.o)

# ---------- Colors ----------

ECHO		= /bin/echo -e
DEFAULT		= "\033[00m"
GREEN		= "\033[0;32m"
TEAL		= "\033[1;36m"
RED		= "\033[1;31m"

# ---------- Other ----------

RM		= rm -f

CP		= cp

CFLAGS		+= -I./

all:		$(NAME)

$(RM):
		@$(ECHO) $(RED) "[DELETED]" $(TEAL) $(OBJS) $(DEFAULT)

$(NAME):		$(OBJS)
		@ar rc $(LIB) $(OBJS)
		@$(ECHO) $(GREEN) "[OK]" $(TEAL) $(NAME) $(DEFAULT)
		@ranlib $(LIB)
		@$(ECHO) $(GREEN) "[CREATED]" $(TEAL) $(LIB) $(DEFAULT)
		@$(CP) $(LIB) $(LIB_TARGET)
		@$(ECHO) $(TEAL) $(LIB) $(GREEN) "copied in"\
	$(TEAL) $(LIB_TARGET) $(DEFAULT)
		@$(CP) $(INC) $(INC_TARGET)
		@$(ECHO) $(TEAL) $(INC) $(GREEN) "copied in"\
	$(TEAL) $(INC_TARGET) $(DEFAULT)

clean:
		@$(RM) $(OBJS)
		@$(ECHO) $(RED) ".o [DELETED]" $(DEFAULT)

fclean: 	clean
		@$(RM) $(LIB)
		@$(ECHO) $(RED) "[DELETED]" $(TEAL) $(LIB) $(DEFAULT)

re: 		fclean all

.PHONY: 	all clean fclean re

.c.o:
		@$(CC) -c $< -o $@ $(CFLAGS)
