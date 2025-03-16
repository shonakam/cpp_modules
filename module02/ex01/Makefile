# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/09 03:21:52 by shonakam          #+#    #+#              #
#    Updated: 2025/03/15 22:25:54 by shonakam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := a.out

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -I./includes

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

header: HEADERS := $(shell find $(SRCS_DIR) -type f | grep "\.hpp$$")
header:
	@for header in $(HEADERS); do \
		echo "Compiling $$header..."; \
		$(CXX) $(CXXFLAGS) -c $$header -o /dev/null || { echo "❌ Error in $$header"; exit 1; }; \
	done
	@echo "✅ All headers compiled successfully!"

# Any non-standard extensions (such as GNU-specific features) are treated as errors.
debug: CXXFLAGS	= -std=c++98 -I./includes -pedantic-errors
debug: re
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

.PHONY: all clean fclean re debug
