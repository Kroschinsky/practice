#pragma once

#include <iostream>
#include <vector>
#include <string>

/*
Created: 28-02-23

Given a signed 32-bit integer x, return x with its digits reversed. 
If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).


Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21
*/

int reverseInteger(int x)
{
    int p = 0;
    int r = 0;

    while (x != 0)
    {
        p = x % 10;
        x = (x - p) / 10;

        if (r > INT_MAX / 10 || (r == INT_MAX / 10 && p > 7))
            return 0;

        if (r < INT_MIN / 10 || (r == INT_MIN / 10 && p < -8)) 
            return 0;

        r = r * 10 + p;
    }

    return r;
}

/*
int i1 = reverseInteger(123);
int i2 = reverseInteger(-123);
int i3 = reverseInteger(120);
*/