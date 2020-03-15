#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i<grid.size();i++) {
            for(int j=0;j<grid[i].size(); j++) {
                if(i !=0 && j != 0) {
                    grid[i][j] += std::min(grid[i-1][j], grid[i][j-1]);
                }
                else {
                    if(i!=0) {
                        grid[i][j] += grid[i-1][j];
                    }
                    if(j!=0) {
                        grid[i][j] += grid[i][j-1];
                    }
                }
            }
        }
        
        return grid[n-1][m-1];
    }
};

int main(){
    Solution s;
    std::vector<std::vector<int>> data = {
        {1,3,1,},
        {1,5,1,},
        {4,2,1,}
    };
    
    std::cout<<s.minPathSum(data);
    return 0;
}