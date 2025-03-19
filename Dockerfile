# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 05:40:11 by shonakam          #+#    #+#              #
#    Updated: 2025/03/19 02:04:54 by shonakam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# docker build -t ubuntu-cpp-min .
# docker run --rm -it -v $(pwd):/usr/src/app ubuntu-cpp-min

FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    zsh \
    make \
    valgrind \
    g++ \
    && rm -rf /var/lib/apt/lists/*

SHELL ["/bin/zsh", "-c"]

WORKDIR /usr/src/app

CMD ["/bin/zsh"]
