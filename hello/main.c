/*
 *    SPDX-FileCopyrightText: 2021 Monaco F. J. <monaco@usp.br>
 *    SPDX-FileCopyrightText: 2025 Gabriel Cruz <gabrieldemelocruz@gmail.com>
 *
 *    SPDX-License-Identifier: GPL-3.0-or-later
 *
 *  This file is a derivative of SYSeg (https://gitlab.com/monaco/syseg)
 *  and includes modifications made by the following author(s):
 *  Gabriel Cruz <gabrieldemelocruz@gmail.com>
 */

#include <stdio.h>

void itoa(char *str, int value) {
    int i = 0;
    for (i = 0; value != 0; i++) {
        int digit = value % 10;
        str[i] = '0' + digit;
        value /= 10;
    }
    str[i] = '\0';
}

int main(void) {
    char str[32];
    itoa(str, memsize());
    printf(str);
    return 0;
}



