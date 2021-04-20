#include <stdio.h>

/*
Overview: Convert decimal single digit to one character
@argument: {int} num - Decimal single digit.
@return: {char} - One character.
*/
char itoc(int num)
{
    char c = num + 48;  // Value to return
    return c;
}

int main(void)
{
    int num = 9;
    printf("%c\n", itoc(num));
    return 0;
}