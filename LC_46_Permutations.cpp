/* 
@author Mithil Raut
@version 1.0 01/23/18
Problem:  46. Permutations
Given a collection of distinct numbers, return all possible permutations.
For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/
class Solution {
public:  
    //Calculate the number of permutations
    int n_permute(int length){
        if(length == 1)
            return 1;
        return (length * n_permute(length - 1));
    }
    
    //Recursive permute
    vector<vector<int>> permute(vector<int>& nums){
        int length = nums.size();
        if(length == 1){
            vector<vector<int>> r {{nums[0]}};
            return r;
        }
        
        int p_nums = n_permute(length);
        int ratio = p_nums/length;
        vector<vector<int>> result;
        result.resize(p_nums, vector<int>(1));
        
        for(int i =0;i<p_nums;){
            int m = nums[(int)(i/ratio)];
            result[i].erase(result[i].end() - 1); //remove default 0 inserted at initialization
            result[i].insert(result[i].begin(),m);
            vector<int> temp_nums = nums;
            temp_nums.erase(temp_nums.begin() + (int)(i/ratio));
            vector<vector<int>> soln = permute(temp_nums); //Get the permutation of the subset
            for(int j = 0; j < soln.size(); j++){
                for(int k = 0; k < soln[j].size(); k++){
                    result[i].push_back(soln[j][k]);    //Merge the results with the original subset
                }
                if(++i < p_nums){
                    result[i].insert(result[i].begin(),m);
                    result[i].erase(result[i].end() - 1); //remove default 0 inserted at initialization
                }
            }
        }
        return result;
    }
};