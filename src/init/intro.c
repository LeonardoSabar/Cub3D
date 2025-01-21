/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:47:13 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/21 14:59:47 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define DELAY_ITERATIONS 50000000

static void busy_wait_delay(void)
{
    volatile unsigned long i = 0;
    while (i < DELAY_ITERATIONS)
        i++;
}

static void run_columns_intro(void)
{
    char *intro[] = {
        "  /$$$$$$            /$$        /$$$$$$        /$$ ",
        " /$$__  $$          | $$       /$$__  $$      | $$ ",
        "| $$  \\__/ /$$   /$$| $$$$$$$ |__/  \\ $$  /$$$$$$$ ",
        "| $$      | $$  | $$| $$__  $$   /$$$$$/ /$$__  $$ ",
        "| $$      | $$  | $$| $$  \\ $$  |___  $$| $$  | $$ ",
        "| $$    $$| $$  | $$| $$  | $$ /$$  \\ $$| $$  | $$ ",
        "|  $$$$$$/|  $$$$$$/| $$$$$$$/|  $$$$$$/|  $$$$$$$ ",
        " \\______/  \\______/ |_______/  \\______/  \\_______/ "
    };

    int intro_height = sizeof(intro) / sizeof(char *);
    int intro_width = strlen(intro[0]);

    int col;
    int row;

    col = 0;
    while (col <= intro_width)
    {
        printf(O"\033[H\033[J");
        row = 0;
        while (row < intro_height)
        {
            int i = 0;
            while (i < col && i < intro_width)
            {
                putchar(intro[row][i]);
                i++;
            }
            printf("\n");
            row++;
        }
        busy_wait_delay();
        col++;
    }
}

void    intro(void)
{
    run_columns_intro();
    printf(B "\n_____________________ Welcome to the Cub3D project!\n\n" RST);
}