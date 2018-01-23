/* 
@author Mithil Raut
@version 1.0 01/22/18
Problem:  35. Search insert position
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.

Example 1:
Input: [1,3,5,6], 5
Output: 2

Example 2:
Input: [1,3,5,6], 2
Output: 1

Example 3:
Input: [1,3,5,6], 7
Output: 4

Example 1:
Input: [1,3,5,6], 0
Output: 0

*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int length = nums.size();
        int min = 0;
        int max = length - 1;
        if (target > nums.at(max)) return max + 1;
        if (target < nums.at(0)) return 0;
        
        int i = (min + max)/2;
        while(min<=max){
            if (nums.at(i)==target){
                return i;
            } else if (nums.at(i) < target) {
                min  = i + 1;
            } else {
                max = i - 1;
            }
            i = (min + max )/2;
        }
        return i + 1;
    }
};