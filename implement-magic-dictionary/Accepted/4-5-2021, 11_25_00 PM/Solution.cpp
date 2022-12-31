// https://leetcode.com/problems/implement-magic-dictionary

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        data = dictionary;
    }
    
    bool search(string searchWord) {
        auto is_valid = [](std::string &s1, std::string &s2)
        {
            if(s1.size() != s2.size()) return false;
            int equals = 0;
            int not_equals = 0;
            for(int i = 0; i < s1.size(); i++)
            {
                if(s1[i] != s2[i]){
                    not_equals++;
                    if(not_equals > 1) return false;
                }else equals++;
            }
            return not_equals == 1 && equals == s1.size() - 1;
        };
        for(auto &x: data)
        {
            if(is_valid(x, searchWord)) return true;
        }
        return false;
    }
    std::vector<std::string> data;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */