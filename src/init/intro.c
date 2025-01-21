/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:47:13 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/21 16:27:35 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void busy_wait_delay(void)
{
    volatile unsigned long i;
    i = 0;
    while (i < DELAY_ITERATIONS)
        i++;
}

static char **fill_intro(void)
{
    static char *intro[] = {
        "  /$$$$$$            /$$        /$$$$$$        /$$ ",
        " /$$__  $$          | $$       /$$__  $$      | $$ ",
        "| $$  \\__/ /$$   /$$| $$$$$$$ |__/  \\ $$  /$$$$$$$ ",
        "| $$      | $$  | $$| $$__  $$   /$$$$$/ /$$__  $$ ",
        "| $$      | $$  | $$| $$  \\ $$  |___  $$| $$  | $$ ",
        "| $$    $$| $$  | $$| $$  | $$ /$$  \\ $$| $$  | $$ ",
        "|  $$$$$$/|  $$$$$$/| $$$$$$$/|  $$$$$$/|  $$$$$$$ ",
        " \\______/  \\______/ |_______/  \\______/  \\_______/ "
    };

    return (intro);
}

static void run_columns_intro(int i, int j)
{
    char **intro;
    int intro_height;
    int intro_width;
    int col;
    int row;

    intro = fill_intro();
    intro_height = INTRO_HEIGHT;
    intro_width = ft_strlen(intro[0]);
    col = 0;
    while (col <= intro_width)
    {
        printf(RST "\033[H\033[J" O);
        row = 0;
        while (row < intro_height)
        {
            j = i;
            while (j < col && j < intro_width)
                putchar(intro[row][j++]);
            printf("\n");
            row++;
        }
        busy_wait_delay();
        col++;
    }
}

void intro(void)
{
    run_columns_intro(-1, 0);
    printf(RST B"\n____________________ Welcome to the Cub3D project!\n\n"RST);
}