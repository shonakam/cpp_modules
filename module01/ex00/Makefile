# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/09 03:21:52 by shonakam          #+#    #+#              #
#    Updated: 2025/03/12 13:32:10 by shonakam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := zombie

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS_DIR := .
OBJS_DIR := objs
SRCS := $(shell find $(SRCS_DIR) -type f | grep "\.cpp$$")
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

debug: CXXFLAGS	= -g -std=c++98
debug: re
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

.PHONY: all clean fclean re debug
