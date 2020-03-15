#include <vector>
#include <iostream>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int l_max = 0, r_max = 0;
        int res = 0;
        
        while (l<r) {
            if(height[l] < height[r]) {
                if(height[l] > l_max) {
                    l_max = height[l];
                }
                else {
                    res += l_max - height[l];
                }
                l++;
            }
            else {
                if(height[r] > r_max) {
                    r_max = height[r];
                }
                else {
                    res += r_max - height[r];
                }
                r--;
            }
        }
        
        return res;
    }
};

int main() {
    Solution s;

    std::vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};

    std::cout<<s.trap(arr)<<"\n";

    return 0;
}