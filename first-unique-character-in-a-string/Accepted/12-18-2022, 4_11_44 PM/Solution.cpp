// https://leetcode.com/problems/first-unique-character-in-a-string

struct info
{
    int counter = 0;
    int last_idx = -1;
};
class Solution {
public:
    int firstUniqChar(string s) {
        info mem[26];
        for(int i = 0; i < s.size(); i++)
        {
            int idx = s[i] - 'a';
            mem[idx].counter++;
            mem[idx].last_idx = i;
        }
        int idx = s.size();
        int min = 0;
        for(int i = 0; i < 26; i++)
        {
            if(mem[i].counter == 1 && mem[i].last_idx < idx )
            {
                idx = mem[i].last_idx;

            }
        }
        if(idx == s.size()) return -1;
        return idx;
    }
};