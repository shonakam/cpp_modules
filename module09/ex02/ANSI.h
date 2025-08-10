/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ANSI.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 18:25:32 by shonakam          #+#    #+#             */
/*   Updated: 2025/08/10 18:28:17 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANSI_H
#define ANSI_H

// reset
#define ANSI_RESET        "\x1b[0m"

// decoration
#define ANSI_BOLD         "\x1b[1m"
#define ANSI_UNDERLINE    "\x1b[4m"
#define ANSI_REVERSED     "\x1b[7m"

// foreground
#define ANSI_FG_BLACK     "\x1b[30m"
#define ANSI_FG_RED       "\x1b[31m"
#define ANSI_FG_GREEN     "\x1b[32m"
#define ANSI_FG_YELLOW    "\x1b[33m"
#define ANSI_FG_BLUE      "\x1b[34m"
#define ANSI_FG_MAGENTA   "\x1b[35m"
#define ANSI_FG_CYAN      "\x1b[36m"
#define ANSI_FG_WHITE     "\x1b[37m"

// bright foreground
#define ANSI_FG_BRIGHT_BLACK   "\x1b[90m"
#define ANSI_FG_BRIGHT_RED     "\x1b[91m"
#define ANSI_FG_BRIGHT_GREEN   "\x1b[92m"
#define ANSI_FG_BRIGHT_YELLOW  "\x1b[93m"
#define ANSI_FG_BRIGHT_BLUE    "\x1b[94m"
#define ANSI_FG_BRIGHT_MAGENTA "\x1b[95m"
#define ANSI_FG_BRIGHT_CYAN    "\x1b[96m"
#define ANSI_FG_BRIGHT_WHITE   "\x1b[97m"

// background
#define ANSI_BG_BLACK     "\x1b[40m"
#define ANSI_BG_RED       "\x1b[41m"
#define ANSI_BG_GREEN     "\x1b[42m"
#define ANSI_BG_YELLOW    "\x1b[43m"
#define ANSI_BG_BLUE      "\x1b[44m"
#define ANSI_BG_MAGENTA   "\x1b[45m"
#define ANSI_BG_CYAN      "\x1b[46m"
#define ANSI_BG_WHITE     "\x1b[47m"

// bright background
#define ANSI_BG_BRIGHT_BLACK   "\x1b[100m"
#define ANSI_BG_BRIGHT_RED     "\x1b[101m"
#define ANSI_BG_BRIGHT_GREEN   "\x1b[102m"
#define ANSI_BG_BRIGHT_YELLOW  "\x1b[103m"
#define ANSI_BG_BRIGHT_BLUE    "\x1b[104m"
#define ANSI_BG_BRIGHT_MAGENTA "\x1b[105m"
#define ANSI_BG_BRIGHT_CYAN    "\x1b[106m"
#define ANSI_BG_BRIGHT_WHITE   "\x1b[107m"

#endif
