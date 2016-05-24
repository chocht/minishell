##
## Makefile for minishell in /home/chauch_p/Repositories/other/minishell
## 
## Made by Pierre Chauchoy
## Login   <chauch_p@epitech.net>
## 
## Started on  Tue May 24 11:01:58 2016 Pierre Chauchoy
## Last update Tue May 24 19:44:21 2016 Pierre Chauchoy
##

# ---------- Directories ----------

DIR		= srcs

# ---------- Names ----------

NAME		= mysh

# ---------- Sources ----------

SRCS		= $(DIR)/main.c \
		  $(DIR)/init_mysh.c \
		  $(DIR)/minishell.c \
		  $(DIR)/program.c \
		  $(DIR)/at_exit_mysh.c \
		  $(DIR)/at_exit_perso.c \
		  $(DIR)/reload_path.c \
		  $(DIR)/find_env.c \
		  $(DIR)/exec_prgm.c \
		  $(DIR)/prompt.c \
		  $(DIR)/my_cd.c \
		  $(DIR)/my_env.c \
		  $(DIR)/my_setenv.c \
		  $(DIR)/my_unsetenv.c \
		  $(DIR)/my_exit.c \
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

CC		= gcc -g

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
