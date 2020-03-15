#include <vector>
#include <map>
#include <iostream>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int l = 0, r = nums.size();

        while (l < r) {
            int m = l + (r - l) / 2;

            if (nums[m] >= target) {
                r = m;
            } 
            else {
                l = m + 1;
            }
        }
        
        return r;
    }
};

int main() {
    Solution s;

    std::map<int, std::vector<int>> map = {
        {2, {1, 3, 5, 6}},
        {5, {1, 3, 5, 6}},
        {7, {1, 3, 5, 6}},
    };

    for(auto x: map) {
        std::cout<<s.searchInsert(x.second, x.first)<<std::endl;
    }

    return 0;
}