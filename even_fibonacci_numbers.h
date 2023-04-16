#pragma once

#include <iostream>
#include <algorithm>

/*
Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
*/

long long evenFibonacciNumbers()
{
    long long prev = 0, cur = 1;
    long long total = 0;

    while (true)
    {
        long long temp = cur;
        cur += prev;
        prev = temp;

        if (cur >= 4000000)
            break;

        if (cur % 2 == 0)
            total += cur;
    }
    
    std::cout << total;

    return total;
}