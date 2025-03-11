# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/09 03:21:52 by shonakam          #+#    #+#              #
#    Updated: 2025/03/10 14:26:03 by shonakam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := phonebook

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -I./includes

SRCS := $(shell find srcs -type f | grep "\.cpp$$")
OBJS_DIR := objs
OBJS := $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

debug: CXXFLAGS	= -g -D MEMCHECK -std=c++98
debug: re

.PHONY: all clean fclean re debug
