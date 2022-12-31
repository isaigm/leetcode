// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:
   int strStr(std::string haystack, std::string needle)
    {
        if(needle.size() > haystack.size()) return -1;

        std::string substr = "";
        for(int i = 0; i < needle.size(); i++)
        {
            substr.push_back(haystack[i]);
        }
        if(substr == needle) return 0;
        for(int i = needle.size(); i < haystack.size(); i++)
        {
            substr.erase(substr.begin());
            substr.push_back(haystack[i]);
            if(substr == needle) return i - needle.size() + 1;
        }
        return -1;
    }
};