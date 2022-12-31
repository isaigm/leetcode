// https://leetcode.com/problems/valid-parentheses

#include <vector>
#include <stack>
#include <string>
#include <algorithm>
class Solution {
public:
    bool isValid(string seq) {
         const auto open_list = std::vector<char> {'{', '(', '['};
    const auto closed_list = std::vector<char> {'}', ')', ']'};
    std::stack<char> aux;
    for(const auto &ch : seq){
        if(auto it = std::find(open_list.begin(), open_list.end(), ch); it != open_list.end()){
            aux.push(ch);
        }else if(auto it = std::find(closed_list.begin(), closed_list.end(), ch); it != closed_list.end()){
            if(aux.size() == 0) return false;
            auto last = std::find(open_list.begin(), open_list.end(), aux.top()) - open_list.begin();
            auto curr = it - closed_list.begin();
            if(last != curr) return false;
            else aux.pop();
        }
    }
    return aux.size() == 0;
    }
};