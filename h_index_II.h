#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

/*
275. H-Index II [medium]

Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper and citations is sorted in ascending order, return the researcher's h-index.
According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.
You must write an algorithm that runs in logarithmic time.

Example 1:
Input: citations = [0,1,3,5,6]
Output: 3
Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had received 0, 1, 3, 5, 6 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.

Example 2:
Input: citations = [1,2,100]
Output: 2

Constraints:
n == citations.length
1 <= n <= 105
0 <= citations[i] <= 1000
citations is sorted in ascending order.
*/

// h == n

int hIndex(std::vector<int> citations)
{
    int size = citations.size();
    int lower = 0;
    int high = size;
    int mid = 0;

    while (lower < high)
    {
        mid = (lower + high) / 2;
        if (citations[mid] < size - mid)
        {
            lower = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return size-lower;
}

/*
    int output_1 = hIndex({ 0,1,3,5,6 });   // 3
    int output_2 = hIndex({ 1,2,100 });     // 2
    int output_3 = hIndex({ 0 });           // 0
*/

/*
[0,1,3,5,6]

lower = 0
high = 5

1:
mid = (0+5) / 2 = 2
citations[2] = 3
size - mid = 3
high = 2

2:
mid = (0+2) / 2 = 1
citations[1] = 1
size - mid = 4
lower = mid + 1 = 2

while: lower [2] < high [2]
h = size - lower = 5 - 2 = 3
*/