/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:43:05 by smishos           #+#    #+#             */
/*   Updated: 2024/08/19 19:09:13 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"   // for error_exit()
#include "printf.h"  // for ft_strlen()
#include <unistd.h>    // for write()
#include <string.h>    // for strlen() and strerror()
#include <errno.h>     // for errno
#include <stdlib.h>    // for exit()

void error_exit(char *message, int code)
{
    // Prepend custom message
    write(STDERR_FILENO, message, ft_strlen(message)); // Write the custom message

    // Add a separator (e.g., ": ")
    write(STDERR_FILENO, ": ", 2); // Write the separator

    // Write the system error message from strerror(errno)
    char *error_message = strerror(errno); // Get the system error message
    write(STDERR_FILENO, error_message, ft_strlen(error_message)); // Write the system error message

    // Add a newline at the end
    write(STDERR_FILENO, "\n", 1);

    // Exit with the provided code
    exit(code);
}
