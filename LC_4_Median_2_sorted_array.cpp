/* 
@author Mithil Raut
@version 1.0 01/19/18
Problem: There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
Example 1:
nums1 = [1, 3]
nums2 = [2]
The median is 2.0

Example 2:
nums1 = [1, 2]
nums2 = [3, 4]
The median is (2 + 3)/2 = 2.5
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length_nums1 = nums1.size();
        int length_nums2 = nums2.size();
        int total_length = length_nums1 + length_nums2;
        std::vector<int> nums;
        int x = 0, y = 0;
        while (x < length_nums1 && y < length_nums2){
            if (nums1[x] <= nums2[y]){
                nums.push_back(nums1[x]);
                x++;
            }else{
                nums.push_back(nums2[y]);
                y++;
            }
        }
        while(x < length_nums1){
            nums.push_back(nums1[x]);
            x++;
        }
        while(y < length_nums2){
            nums.push_back(nums2[y]);
            y++;
        }
        
        if(total_length%2 == 0){
            return ((double)(nums[total_length/2] + nums[(total_length/2) - 1]) / 2);
        }
        else{
            return ((double) nums[total_length/2]);
        }
    } 
};