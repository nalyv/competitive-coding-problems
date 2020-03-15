#include <string>
#include <map>
#include <iostream>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        
        std::map<char, int> map;
        int st = -1;
        int ml = 0;       
        for(int i=0; i< s.size(); i++) {
            
            if(map.count(s[i]) != 0) {
                st = std::max(st, map[s[i]]);
            }
            map[s[i]] = i;
            ml = std::max(ml, i-st);
        }
        
        return ml;
    }

    int lengthOfLongestSubstring2(std::string s) {
        
        std::map<char, int> map;
        int res = 0; 
        int st = 0;
        
        for(int i=0; i< s.size(); i++) {
            if(map.count(s[i]) !=0 && st <= map[s[i]]) {
                st = map[s[i]] + 1;
            }
            else {
                res = std::max(i - st + 1, res);
            }
            map[s[i]] = i;
        }
        
        return res;
    }
};

int main() {
    Solution s;
    std::map<std::string, int> map;
    map["abcabcbb"] = 3;
    map["bbbbb"] = 1;
    map["pwwkew"] = 3;
    map["  "] = 1;
    map["b"] = 1;
    map[""] = 0;
    map["aab"] = 2;

    for(auto x: map) {
        std::cout<<"result:"<<s.lengthOfLongestSubstring(x.first)<<
                    "|"<<"expected:"<<x.second<<std::endl;
    }

    for(auto x: map) {
        std::cout<<"result:"<<s.lengthOfLongestSubstring2(x.first)<<
                    "|"<<"expected:"<<x.second<<std::endl;
    }

    return 0;
}