/* 
@author Mithil Raut
@version 1.0 01/18/18
Problem: Given a string, find the length of the longest substring without repeating characters.
Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlength = s.length();
        int count = 0;
        int tempcount = 0;
        char tempchar [maxlength];
     for(int i = 0; i< s.length() - 1; i++ ){
         if(s.at(i) == s.at(i+1)){
             if (tempcount > count){
                 count = tempcount;
             }
             tempcount  = 0;
         }
         else{
             tempchar []
         }
     }
        return count;
    }
};