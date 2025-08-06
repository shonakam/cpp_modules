# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/05 22:14:06 by shonakam          #+#    #+#              #
#    Updated: 2025/08/06 22:02:48 by shonakam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --== Files ==--
# BitcoinExchange.cpp
# main.cpp
#

NAME		:= btc

OS			:= $(shell uname -s | tr A-Z a-z)
ARCH		:= $(shell uname -m)
INC_DIR		:= .
SRCS_DIR	:= .
OBJS_DIR	:= objs
SRCS		:= $(shell find $(SRCS_DIR) -type f | grep "\.cpp$$")
OBJS		:= $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98 -I$(INC_DIR)

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

# --== Docker ==--
IMAGE_NAME		:= $(NAME)-output
DOCKERFILE_IN	:= ../../Dockerfile.in
DOCKERFILE_OUT	:= .dockerfile-$(NAME)
BASEIMAGE		:= ubuntu:20.04

# Arguments for building the Docker image
BUILD_ARG_ENV	:= DEBIAN_FRONTEND=noninteractive
BUILD_ARG_PKGS	:= "make valgrind g++ clang-format"
# ---------------------------------------

prepare:
	cp ../../.clang-format .clang-format

docker-build: prepare $(DOCKERFILE_OUT)
	docker build \
		--build-arg ARG_FROM=$(BASEIMAGE) \
		--build-arg ARG_ENV=$(BUILD_ARG_ENV) \
		--build-arg ARG_PACKAGES=$(BUILD_ARG_PKGS) \
		--build-arg ARG_FROM_SECOND=$(BASEIMAGE) \
		-t $(IMAGE_NAME) -f $(DOCKERFILE_OUT) .
	rm -f .clang-format

docker-stage: prepare $(DOCKERFILE_OUT)
	docker build \
		--build-arg ARG_FROM=$(BASEIMAGE) \
		--build-arg ARG_ENV=$(BUILD_ARG_ENV) \
		--build-arg ARG_PACKAGES=$(BUILD_ARG_PKGS) \
		--build-arg ARG_FROM_SECOND=$(BASEIMAGE) \
		--target builder \
		-t $(IMAGE_NAME)-builder -f $(DOCKERFILE_OUT) .
	rm -f .clang-format

$(DOCKERFILE_OUT): $(DOCKERFILE_IN)
	sed -e 's|{ARG_FROM}|$(BASEIMAGE)|g' \
		-e 's|{ARG_BIN}|$(NAME)|g' \
		-e 's|{ARG_OS}|$(OS)|g' \
		-e 's|{ARG_ARCH}|$(ARCH)|g' \
		-e 's|{ARG_ENV=#}|$(BUILD_ARG_ENV)|g' \
		$< > $@
# Dockerfile.in > .dockerfile-$(BIN)-$(OS)_$(ARCH)

docker-make: docker-stage
	docker run --rm -v $(PWD):/src -w /src \
		$(IMAGE_NAME)-builder sh -c "make all"

docker-run: docker-build
	docker run --rm -v $(PWD):/src -w /src \
		$(IMAGE_NAME) sh -c "make && ./$(NAME)"

docker-format: docker-stage
	docker run --rm -v $(PWD):/src -w /src \
		--entrypoint sh \
		$(IMAGE_NAME)-builder \
		-c "clang-format -i --style=file $(SRCS_DIR)/*.cpp $(SRCS_DIR)/*.hpp"

docker-debug: docker-stage
	docker run --rm -v $(PWD):/src -w /src \
		$(IMAGE_NAME)-builder sh -c "make debug"

# Any non-standard extensions (such as GNU-specific features) are treated as errors.
debug: CXXFLAGS	= -std=c++98 -pedantic-errors -I$(INC_DIR)
debug: re; valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) && make fclean

.PHONY: all clean fclean re debug docker-build docker-debug
