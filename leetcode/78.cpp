#include <vector>
#include <iostream>

/*
    Given a set of distinct integers, nums, return all possible subsets (the power set).

    Note: The solution set must not contain duplicate subsets.

    Example:

    Input: nums = [1,2,3]
    Output:
    [
        [3],
        [1],
        [2],
        [1,2,3],
        [1,3],
        [2,3],
        [1,2],
        []
    ]
*/


class Solution {
private:
   std::vector<std::vector<int>> result;
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        
        int n = nums.size();
        result.push_back({});
        
        for(int i=0; i<n; i++) {
            int m = result.size();
            
            for(int j=0; j<m; j++) {
                std::vector<int> tmp = result[j];
                tmp.push_back(nums[i]);
                result.push_back(tmp);
            }
        }
        
        return result;
    }

    //backtrack solution
    std::vector<std::vector<int>> subsets2(std::vector<int>& nums) {
       
       int n = nums.size();
       if(n == 0) {
           return result;
       }
       std::vector<int> track;
       backtrack(nums, 0, n, track);
       return result;
    }
   
    void backtrack(std::vector<int>& nums, int k, int n, std::vector<int>& track) {
       result.push_back(track);
       for(int i=k; i<n; i++) {
           track.push_back(nums[i]);
           backtrack(nums, i+1, n, track);
           track.pop_back();
       }
    }
};

int main() {
    Solution s;
    std::vector<int> input = {1, 2, 4};
    std::vector<std::vector<int>> res;

    res = s.subsets(input);

    for(auto x: res){
        for(auto y: x) {
            std::cout<<y<<",";
        }
        std::cout<<"\n";
    }

    return 0;
}