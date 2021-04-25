#include <stdio.h>
#include <stdbool.h>

int DAY_IN_MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/*
Overview: Returns if it's the leap year.
@argument: {int} year - Input year.
@return: {bool}
*/
bool isLeapYear(int year)
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
bool isValidDate(int year, int month, int day)
{
    if (year < 1970 || year >= 2038)
        return false;
    if (month < 1 || month > 12)
        return false;

    int max_day = DAY_IN_MONTH[month - 1];

    // For Leap Year
    if (month == 2 && isLeapYear(year))
        max_day++;

    if (day < 1 || day > max_day)
        return false;

    return true;
}

int main(void)
{
    bool valid = isValidDate(2020, 11, 20);
    printf("%d\n", valid);
    return 0;
}