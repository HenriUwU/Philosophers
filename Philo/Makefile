# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsebille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 17:38:29 by hsebille          #+#    #+#              #
#    Updated: 2023/04/14 14:55:12 by hsebille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CFLAGS = -Wall -Wextra -Werror

NAME = philo

SRCS = core/philo.c core/parsing.c utils/ft_atoi.c utils/ft_calloc.c \
	   core/main.c core/init_philo.c utils/ft_bzero.c core/gettime.c \
	   core/philo_eat.c core/philo_sleep.c \

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -g -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -g -pthread $(OBJS) -o $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
