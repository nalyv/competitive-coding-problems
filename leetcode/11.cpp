#include <iostream>
#include <vector>

class Solution {
private:
   int max = 0;
public:
   int maxArea(std::vector<int>& height) {
       
       int temp = 0;

       int n = height.size();
       
       for(int i=0;i<n;i++) {
           
           for(int j=i+1;j<n;j++) {
               
               if(height[i] <= height[j]) {
                   temp = height[i];
               } 
               else {
                   temp = height[j];
               }
               
               temp = (j - i)*temp;
               
               if(temp > max) {
                   max = temp;
               }
           }
       }
       
       return max;
   }

   int maxArea2(std::vector<int>& height) {
        
        int water = 0;
        int i = 0;
        int j = height.size() - 1;
        
        while(i < j) {
            int h = std::min(height[i], height[j]);
            
            water = std::max(water, (j - i)*h);
            
            while(height[i] <= h && i < j) 
                i++;
            while(height[j] <= h && i < j) 
                j--;
        }
        
        return water;
    }
};

int main() {
    Solution s;
    std::vector<int> inputs = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    std::cout<<s.maxArea(inputs)<<std::endl;
    std::cout<<s.maxArea2(inputs)<<std::endl;

    return 0;
}