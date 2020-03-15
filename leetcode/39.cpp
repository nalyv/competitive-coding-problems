#include <vector>
#include <string>
#include <iostream>
#include <map>

/*
    Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

    The same repeated number may be chosen from candidates unlimited number of times.

    Note:

    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.
    
    Example 1:
        
    Input: candidates = [2,3,6,7], target = 7,
    A solution set is:
    [
        [7],
        [2,2,3]
    ]

    Example 2:

    Input: candidates = [2,3,5], target = 8,
    A solution set is:
    [
        [2,2,2,2],
        [2,3,3],
        [3,5]
    ]
*/


class Solution {
private:
    std::vector<std::vector<int>> result;
    std::vector<int> combinations;
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        
        calculate(result, candidates, combinations, target, 0);
        
        return result;
    }
    
    static void calculate(std::vector<std::vector<int>> &result, std::vector<int> &candidates, std::vector<int> &combinations, int target, int index) {
        
        if(target < 0) {
            return;
        }
        else if(target == 0) {
            result.push_back(combinations);
        }
        else {
            for(std::size_t i = index; i != candidates.size(); ++i) {
                
                combinations.push_back(candidates[i]);
                calculate(result, candidates, combinations, target-candidates[i], i);
                combinations.pop_back();
            }
        }
    }
};

int main() {
    Solution s;

    std::map<int, std::vector<int>> map = {
        {7, {2, 3, 6, 7}},
        {8, {2, 3, 5}},
    };

    std::vector<std::vector<int>> res;

    for(auto x: map) {
        res = s.combinationSum(x.second, x.first);

        for(auto yres: res) {
            for(auto y: yres) {
                std::cout<<y<<",";
            }
            std::cout<<"\n";
        }
    }

    return 0;
}