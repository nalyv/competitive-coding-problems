#include <iostream>
#include <map>
#include <climits>

class Solution {
public:
    int reverse(int x) {
        long result = 0;
        
        while(x) {
            int cur = x%10;
            x = x/10;
            result = result*10 + cur;
            if(result > INT_MAX || result < INT_MIN) return 0;
        }
        
        return result;
    }
};

int main() {
    Solution s;
    int inputs[3] = {123, -123, 120};

    for(int x: inputs) {
        std::cout<<s.reverse(x)<<std::endl;
    }

    return 0;
}