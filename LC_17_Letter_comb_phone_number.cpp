/* 
@author Mithil Raut
@version 1.0 01/20/18
Problem: 17. Letter Combinations of a Phone Number
Given a digit string, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below.
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note: Although the above answer is in lexicographical order, your answer could be in any order you want. 
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        const vector<vector<string>> comb ={
            {""},
            {"a","b","c"},
            {"d","e","f"},
            {"g","h","i"},
            {"j","k","l"},
            {"m","n","o"},
            {"p","q","r","s"},
            {"t","u","v"},
            {"w","x","y","z"}
        };
        int length = digits.length();
        if (length==0)
            return result;
        int inputarray[length];
        int productarray[length + 1];
        
        int total = 1;
        for(int i =0 ; i<length; i++){
            int digit = digits.at(i) - '0';
            inputarray[i]=digit;
            cout<<inputarray[i]<<endl;
            }
        productarray[length] = total;
        
        for (int i = (length - 1);i>=0; i--){
            productarray[i]=total * ((comb[inputarray[i]-1]).size());
            total = productarray[i];
            cout<<productarray[i]<<endl;
        }
        
        for(int i = 0; i < productarray[0]; i ++){
            result.push_back("");
        }
        for(int i = 0;i < length; i++){
            int digit = inputarray[i];
             vector<string>::const_iterator k = result.begin();
            for(int j = 0 ; j < productarray[0]; j++){
                int temp = ((j/productarray[i+1])%comb[inputarray[i]-1].size());
                result.at(j) += (comb[digit-1][temp]);
                cout<<result.at(j)<<endl;
            }
        }
        return result;
    }
};