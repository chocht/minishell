## Makefile for minishell in /home/chauch_p/Repositories/other/minishell
## 
## Made by Pierre Chauchoy
## Login   <chauch_p@epitech.net>
## 
## Started on  Tue May 24 11:01:58 2016 Pierre Chauchoy
## Last update Wed Jun  8 12:19:18 2016 Julien Andreani
##

# ---------- Directories ----------

DIR		= srcs

BUILTINS	= $(DIR)/builtins

REDIRECTIONS	= $(DIR)/redirections

SEPARATIONS	= $(DIR)/separations

LIST		= $(DIR)/list

# ---------- Names ----------

NAME		= 42sh

# ---------- Sources ----------

SRCS		= $(DIR)/main.c \
		  $(DIR)/init_mysh.c \
		  $(DIR)/minishell.c \
		  $(DIR)/minishell2.c \
		  $(DIR)/minishell3.c \
		  $(DIR)/program.c \
		  $(DIR)/at_exit_mysh.c \
		  $(DIR)/at_exit_perso.c \
		  $(DIR)/reload_path.c \
		  $(DIR)/find_env.c \
		  $(DIR)/exec_prgm.c \
		  $(DIR)/my_spipe.c \
		  $(DIR)/my_mpipe.c \
		  $(DIR)/prompt.c \
		  $(DIR)/organize_between.c \
		  $(BUILTINS)/my_cd.c \
		  $(BUILTINS)/my_env.c \
		  $(BUILTINS)/my_setenv.c \
		  $(BUILTINS)/my_unsetenv.c \
		  $(BUILTINS)/my_exit.c \
		  $(BUILTINS)/my_echo.c \
		  $(BUILTINS)/my_echo2.c \
		  $(BUILTINS)/my_echo3.c \
		  $(BUILTINS)/my_echo4.c \
		  $(SEPARATIONS)/my_semicolon.c \
		  $(SEPARATIONS)/my_db_amp.c \
		  $(SEPARATIONS)/my_db_pipe.c \
		  $(SEPARATIONS)/my_pipe.c \
		  $(REDIRECTIONS)/my_leftrd.c \
		  $(REDIRECTIONS)/my_db_leftrd.c \
		  $(REDIRECTIONS)/my_rightrd.c \
		  $(REDIRECTIONS)/my_db_rightrd.c \
		  $(REDIRECTIONS)/open_file.c \
		  $(LIST)/list.c
		  # ENLEVER -G MAKEFILE

# ---------- Objects ----------

OBJS		= $(SRCS:.c=.o)

# ---------- Colors ----------

ECHO		= /bin/echo -e
DEFAULT		= "\033[00m"
GREEN		= "\033[0;32m"
TEAL		= "\033[1;36m"
RED		= "\033[1;31m"

# ---------- Other ----------

CC		= gcc

RM		= rm -f

CFLAGS		+= -I./include/
CFLAGS		+= -lmy -L./lib/
CFLAGS		+= -W -Wall -Werror -Wextra -Wno-unused-parameter

# ---------- Commands ----------

all:		$(NAME)

$(NAME):	$(OBJS)
		@$(CC) -o $(NAME) $(OBJS) $(CFLAGS)
		@$(ECHO) $(GREEN) "[OK]" $(TEAL) $(NAME) $(DEFAULT)

clean:
		@$(RM) $(OBJS)
		@$(ECHO) $(RED) "[DELETED]" $(TEAL) $(OBJS) $(DEFAULT)

fclean:		clean
		@$(RM) $(NAME)
		@$(ECHO) $(RED) "[DELETED]" $(TEAL) $(NAME) $(DEFAULT)

re:		fclean all

.PHONY:		all clean fclean re

.c.o:
		@$(CC) -c $< -o $@ $(CFLAGS)
