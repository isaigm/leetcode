// https://leetcode.com/problems/determine-if-string-halves-are-alike

class Solution {
public:
    bool is_vowel(char c)
    {
        if (isupper(c))
        {
            c = tolower(c);
        }
        char vowels[] = { 'a', 'e', 'i', 'o', 'u' };
        for (int i = 0; i < 5; i++)
        {
            if (vowels[i] == c) return true;
        }
        return false;
    }
    bool halvesAreAlike(std::string s) {
        int first_half = 0;
        int second_half = 0;
        for (int i = 0; i < s.size() / 2; i++) {
            if (is_vowel(s[i])) first_half++;
            if (is_vowel(s[s.size() / 2 + i])) second_half++;
        }
        return first_half == second_half;
    }
};