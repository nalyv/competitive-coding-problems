#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
private:
    std::vector<std::vector<int>> permu;
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        
        if(nums.size() == 0) {
            permu.push_back(std::vector<int>());
        }
        calculate(nums, 0, nums.size()-1);
        
        return permu;
    }
    
    void calculate(std::vector<int>& nums, int l, int r) {
        if(l == r) {
            permu.push_back(nums);
        }
        else {
            for(int i=l; i<=r; i++) {
                std::swap(nums[l], nums[i]);
                calculate(nums, l+1, r);
                std::swap(nums[l], nums[i]);
            }
        }
    }

    std::vector<std::vector<int>> permute2(std::vector<int>& nums) {

        std::sort(nums.begin(), nums.end());
        
        do {

            std::vector<int> per;
            for(size_t i =0;i<nums.size(); i++) {
                per.push_back(nums[i]);
            }
            permu.push_back(per);

        } while ( std::next_permutation(nums.begin(),nums.end()) );

        return permu;
    }
};

int main() {
    Solution s;

    std::vector<int> arr = {4, 5, 6, 7};
    std::vector<std::vector<int>>  res;
    
    res = s.permute(arr);

    for(auto x: res) {
        for(auto y: x) {
            std::cout<<y<<",";
        }
        std::cout<<"\n";
    }

    return 0;
}