#include <vector>
#include <iostream>

class Solution {
public:
    int numTrees(int n) {      
        int unique = 0;
        if(n == 0 || n == 1) {
            return 1;
        }
        else if(n == 2) {
            return 2;
        }
        for(int i=1;i<=n; i++) {
            unique += numTrees(i-1) * numTrees(n-i);
        }
        return unique;
    }

    // dp solution
    int numTrees2(int n) {      
        std::vector<int> dp(n+1,0);
        dp[0] = 1;
        
        for(int i=1; i <= n; ++i) {
            for(int j=1; j <= i; ++j) {
                dp[i] += dp[j-1]*dp[i-j];
            }
        }
        
        return dp[n];
    }
};

int main() {
    Solution s;
    std::cout<<s.numTrees2(3);

    return 0;
}