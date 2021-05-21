#include <stdio.h>

/*
Overview: Returns if it's the leap year.
@argument: {int} year - Input year.
@return: {int}
*/
int isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

/*
Overview: Returns if it's the right date.
@argument: {int} year - Input year.
@argument: {int} month - Input month.
@argument: {int} day - Input day.
@return: {bool}
*/
void testIsLeapYear(FILE *fp)
{
    int year = 1900;
    char str[256];

    while (fgets(str, 256, fp) != NULL)
    {
        if (year > 2400) return;

        while (year != atoi(str))
        {
            if (isLeapYear(year) != 0)
                printf("%d has different output.\n", year);
            year++;
        }

        if (isLeapYear(atoi(str)) != 1)
            printf("%d has different output.\n", year);
        year++;
    }
    return;
}

int main(void)
{
    FILE *fp;
    char fname[] = "years.txt";

    fp = fopen(fname, "r");
    if (fp == NULL)
    {
        printf("%s file not open!\n", fname);
        return -1;
    }

    testIsLeapYear(fp);

    fclose(fp);
    return 0;
}