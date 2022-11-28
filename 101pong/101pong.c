/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** 101pong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void angle(float distance2, float distance1)
{
    float cos;

    cos = acos(distance2 / distance1);
    cos *= 180 / 3.14159265359;
    if (__isnanf(cos)) {
        printf("The incidence angle is:\n");
        printf("0.00 degrees\n");
    } else {
        printf("The incidence angle is:\n");
        printf("%.2f degrees\n", cos);
    }
}

int is_float(char *str)
{
    int i = 0;
    int dot = 0;

    if (str[i] == '-')
        i++;
    while (str[i] != '\0') {
        if (str[i] == '.' && dot == 1)
            return (0);
        if (str[i] == '.')
            dot = 1;
        if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '.')
            return (0);
        i++;
    }
    return (1);
}

int handling_error(int ac, char **av)
{
    if (ac != 8)
        return (84);
    if (av[7][0] == '-')
        return (84);
    int i = 1;
    for (; i < ac; i++) {
        for (int j = 0; av[i][j] != '\0'; j++) {
            if (is_float(av[i]) == 0)
                return (84);
            if (is_float(av[i]) == 1)
                return(0);
        }
    }
    return (0);
}

int main(int ac, char ** av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        printf("USAGE\n");
        printf("    ./101pong x0 y0 z0 x1 y1 z1 n\n\n");
        printf("DESCRIPTION\n");
        printf("    x0  ball abscissa at time t - 1\n");
        printf("    y0  ball abscissa at time t - 1\n");
        printf("    z0  ball abscissa at time t - 1\n");
        printf("    x1  ball abscissa at time t\n");
        printf("    y1  ball abscissa at time t\n");
        printf("    z1  ball abscissa at time t\n");
        printf("    n   time shift (greater than or equal to zero, integer)\n");
        return (0);
    }
    else if (handling_error(ac, av) == 84) {
        return (84);
    } else {

    float x0 = atof(av[1]);
    float y0 = atof(av[2]);
    float z0 = atof(av[3]);
    float x1 = atof(av[4]);
    float y1 = atof(av[5]);
    float z1 = atof(av[6]);
    unsigned int n = atoi(av[7]);
    float pos_final_x;
    float pos_final_y;
    float pos_final_z;
    float vel_x;
    float vel_y;
    float vel_z;

    vel_x = x1 - x0;
    vel_y = y1 - y0;
    vel_z = z1 - z0;
    printf("The velocity vector of the ball is:\n(%.2f, %.2f, %.2f)\n", vel_x, vel_y, vel_z);
    pos_final_x = (vel_x * n) + x1;
    pos_final_y = (vel_y * n) + y1;
    pos_final_z = (vel_z * n) + z1;
    printf("At time t + %d, ball coordinates will be:\n(%.2f, %.2f, %.2f)\n", n, pos_final_x, pos_final_y, pos_final_z);
    float distance1 = sqrt(pow(vel_x, 2) + pow(vel_y, 2) + pow(vel_z, 2));
    float distance2 = sqrt(pow(vel_x, 2) + pow(vel_y, 2));
    if (vel_x > 0)
        printf("The ball won't reach the paddle.\n");
    else
        angle(distance2, distance1);
    return (0);
    }
}