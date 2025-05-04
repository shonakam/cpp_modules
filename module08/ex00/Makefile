# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/09 03:21:52 by shonakam          #+#    #+#              #
#    Updated: 2025/05/04 11:35:26 by shonakam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --== Files ==--
# main.cpp
#

NAME := easyfind

INC_DIR := .
SRCS_DIR := .
OBJS_DIR := objs
SRCS := $(shell find $(SRCS_DIR) -type f | grep "\.cpp$$")
OBJS := $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "Target[$(NAME)] compiled!!"

$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

# Any non-standard extensions (such as GNU-specific features) are treated as errors.
debug: CXXFLAGS	= -std=c++98 -pedantic-errors -I$(INC_DIR)
debug: re; valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) && make fclean

.PHONY: all clean fclean re debug
