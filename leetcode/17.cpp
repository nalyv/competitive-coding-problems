#include <iostream>
#include <vector>
#include <map>
#include <string>

/*
    Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
    A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

    Input: "23"
    Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/
class Solution {
private:
    std::vector<std::string> result;
    
    std::map<char, std::vector<char>> phoneMap = {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r','s'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}}
        };
    
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        
        std::vector<std::string> result;
        if(digits.size() == 0) {
            return result;
        }
        
        for(char dig: digits) {
            if(result.empty()) {
                for(char c: phoneMap[dig]) {
                    result.push_back(std::string()+c);
                }
            }
            else {
                int size = result.size();
                for(int i=0; i<size; i++) {
                    for(char c: phoneMap[dig]) {
                        result.push_back(*result.begin()+c);
                    }
                    result.erase(result.begin());
                }
            }
        }
        
        
        return result;
    }
    
    // Backtracking solution
    std::vector<std::string> letterCombinations2(std::string digits) {
        
        if(digits.size() == 0) {
            return result;
        }
        
        DFS(digits, phoneMap, 0, {}, result);
        return result;
    }
    
    void DFS(std::string digits, std::map<char, std::vector<char>>& phoneMap, int pos, std::vector<char> path, std::vector<std::string>&result) {
        if(!path.empty() && path.size() == digits.size()) {
            std::string s = "";
            for(char&c: path) {
                s +=c;
            }
            result.push_back(s);
            return;
        }
        for(char&c: phoneMap[digits[pos]]) {
            path.push_back(c);
            DFS(digits, phoneMap, pos + 1, path, result);
            path.pop_back();
        }
    }
};

int main() {
    Solution s;

    std::vector<std::string> inputs = {"23", "34"};
    std::vector<std::string> res;

    for(auto x: inputs) {
        res = s.letterCombinations(x);

        for(auto y: res) {
            std::cout<<y<<",";
        }
        std::cout<<std::endl;
    }

    return 0;
}