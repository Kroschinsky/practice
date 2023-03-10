#pragma once

/*
Created : 25-02-23

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.

int value = getMultiples3or5(1000);
*/

int getMultiples3or5(int n)
{
    int value = 0;

    for (int i = 1; i < n; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            value += i;
        }
    }

    return value;
}

//int value = getMultiples3or5(1000);