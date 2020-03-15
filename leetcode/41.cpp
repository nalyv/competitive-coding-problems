#include <vector>
#include <iostream>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        
        int size = nums.size();
        int temp;
        if(size == 0) {
            return 0;
        }
        
        for(int i=0; i<size;i++) {
            while(0 < nums[i] < size && nums[nums[i] - 1] != nums[i]) {
                int temp = nums[i] - 1;
                nums[i], nums[temp] = nums[temp], nums[i];
            }
        }
        
        for(int i=1; i<size; i++) {
            if (nums[i] != i+1) {
                
                return i+1;
            }
        }
        
        return size + 1;
    }

    int firstMissingPositive2(std::vector<int>& nums) {
        
        if(nums.size() == 0) {
            return 1;
        }
        
        nums.push_back(0);
        int size = nums.size();
        
        for(int i=0; i<size; i++) {
            if(nums[i] <= 0 or nums[i] >= size) {
                nums[i] = 0;
            }
        }
        
        for(int i=0; i<size; i++) {
            nums[nums[i] % size] += size;
        }
        
        for(int i=0; i<size; i++) {
            
            if(!(nums[i] / size)) {
               return i;
            }
        }
        
        return size;
    }
};

int main() {
    Solution s;

    std::vector<std::vector<int>> inputs = {
        {1, 2, 0},
        {3, 4, -1, 1},
        {7, 8, 9, 11, 12},
        { 3, 4, 5, 7, 8, 1, 2}
    };

    for(auto x: inputs) {
        std::cout<<s.firstMissingPositive2(x)<<std::endl;
    }

    return 0;
}