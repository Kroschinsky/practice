#pragma once

#include <iostream>
#include <vector>
#include <string>

/*
80. Remove Duplicates from Sorted Array II [medium]

Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.
Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, 
if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.
Return k after placing the final result in the first k slots of nums.
Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}

If all assertions pass, then your solution will be accepted.

Example 1:
Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Example 2:
Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3,_,_]
Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Constraints:
1 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.
*/

int removeDuplicates(std::vector<int> nums)
{
    int total = 1;
    int current_value = nums[0];
    int count = 1;

    int index = 1;
    int index_stop = 1;

    int size = nums.size();

    while(index_stop < size && index < size)
    {
        if (current_value != nums[index])
        {
            // copy elements
            if (index_stop != index)
            {
                for (int i = index; i < size; ++i)
                {
                    nums[index_stop + (i - index)] = nums[i];
                }
            }

            size += index_stop - index;
            ++total;
            index = index_stop;
            current_value = nums[index];
            count = 1;
            index_stop = index + 1;
        }
        else if (count < 2)
        {
            ++total;
            ++count;
            ++index_stop;
        }
        
        ++index;
    }

    return total;
}

int removeDuplicates2(std::vector<int> nums)
{
    int size = nums.size();
    if (size <= 2)
        return size;

    int k = 2;

    for (int i = 2; i < size; ++i)
    {
        if (nums[k - 2] != nums[i]) 
        {
            nums[k++] = nums[i];
        }
    }

    return k;
}

//int value_1 = removeDuplicates({ 1,1,1,2,2,3 });
//int value_2 = removeDuplicates({ 0,0,1,1,1,1,2,3,3 });