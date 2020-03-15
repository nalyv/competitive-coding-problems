#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

/*
   Given an array of strings, group anagrams together.

    Example:

    Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
    Output:
    [
        ["ate","eat","tea"],
        ["nat","tan"],
        ["bat"]
    ] 
*/
class Solution {
private:
    std::vector<std::vector<std::string>> result;
    std::unordered_map<std::string, std::vector<std::string>> map;
    
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        
        for(auto s: strs) {
            
            std::string temp = s;
            std::sort(temp.begin(), temp.end());
            map[temp].push_back(s);
        }
        
        for(auto x: map) {
            result.push_back(x.second);
        }
        
        return result;
    }
};

int main() {
    Solution s;
    std::vector<std::string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> res;
    
    res = s.groupAnagrams(input);

    for(auto x: res) {
        for(auto y: x) {
            std::cout<<y<<",";
        }
        std::cout<<"\n";
    }
    return 0;
}