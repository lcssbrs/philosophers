NAME = philo

SRCS = src/check_args.c src/philo.c src/init.c src/utils.c src/philo_funct.c src/philo_move.c src/utils_philo.c
OBJS = ${SRCS:.c=.o}
HEADER = -Iinclude

#Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#OBJS_BONUS = ${SRCS1:.c=.o}

RM = rm -f

CC = gcc

FLAGS = -Wall -Wextra -Werror

.c.o:
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o}

all: 		${NAME}

${NAME}:	${OBJS}
					@$(CC) ${OBJS} -pthread -o ${NAME}
					@echo "$(GREEN)Philo Compiled!"

clean:
	@${RM} ${OBJS}
	@echo "$(RED)Philo Clean!"
#${OBJS_BONUS}

fclean:    clean
	@${RM} ${NAME}
	@echo "$(BLUE)Philo Fclean!"

re: fclean all

#bonus: ${OBJS_BONUS}
#	ar -rcs ${NAME} ${OBJS_BONUS}

.PHONY: all clean fclean re
