// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if(!haystack.compare(needle)) return 0;

    if (haystack.length() >= needle.length())
    {
        int len = needle.length();
        for (int i = 0; i < haystack.length() - len + 1; i++)
        {
            auto substr = haystack.substr(i, len);
            if(!substr.compare(needle)) return i;
        }
        
    }
    return -1;
}
};