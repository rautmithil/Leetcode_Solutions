/* 
@author Mithil Raut
@version 1.0 01/20/18
Problem: Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2. 
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int length = sizeof(&height);
        if(length = 2)
        {
            return height[0] < height[1]? height[0]:height[1];
        }
        else{
            
        }
    }
};