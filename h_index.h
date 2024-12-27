#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

/*
274. H-Index [medium]

Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return the researcher's h-index.
According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.

Example 1:
Input: citations = [3,0,6,1,5]
Output: 3
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.

Example 2:
Input: citations = [1,3,1]
Output: 1

Constraints:
n == citations.length
1 <= n <= 5000
0 <= citations[i] <= 1000
*/

// h == n

int hIndex(std::vector<int> citations) 
{
    int size = citations.size() + 1;

    // create array and start with 0
    int* vec = new int[size]();    
    //std::vector<int> vec(size + 1, 0);

    for (int& value : citations)
    {
        if (value > size - 1)
        {
            ++vec[size - 1];
        }
        else
        {
            ++vec[value];
        }
    }

    int total = 0;
    for (int i = size - 1; i >= 0; --i)
    {
        total += vec[i];
        if (total >= i)
        {
            size = i;
            break;
        }
    }

    delete[] vec;
    return size;
}

int hIndex2(std::vector<int> citations) 
{
    // Ordena as citações em ordem decrescente
    std::sort(citations.rbegin(), citations.rend());

    int hIndex = 0;
    for (int i = 0; i < citations.size(); ++i) 
    {
        if (citations[i] >= i + 1) 
        {
            hIndex = i + 1;
        }
        else 
        {
            break;
        }
    }

    return hIndex;
}

/*
    int output_1 = hIndex({ 3,0,6,1,5 });       // 3
    int output_2 = hIndex({ 1,3,1 });           // 1
    int output_3 = hIndex({ 1 });               // 1
    int output_4 = hIndex({ 0 });               // 0
    int output_5 = hIndex({ 0, 1 });            // 1
    int output_6 = hIndex({ 1, 1 });            // 1
    int output_7 = hIndex({ 11, 15 });          // 2
*/