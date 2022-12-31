// https://leetcode.com/problems/find-unique-binary-string

class Solution {
public:
    std::string result;
    string findDifferentBinaryString(vector<string>& nums) {
        std::unordered_set<std::string> uniques;
        std::string curr;
        for(int i = 0; i < nums.size(); i++)
        {
            uniques.insert(nums[i]);
         
        }
    
        search(uniques, curr, nums.size());
        
        return result;
        
        
    }
    void search(std::unordered_set<std::string> &uniques, std::string &curr, int n)
    {
       
        if(curr.size() == n)
        {
            if(uniques.find(curr) == uniques.end())
            {
                result = curr;
            }
            return;
        }
        curr.push_back('0');
        search(uniques, curr, n);
        curr.pop_back();
        if(result.size() > 0) return;
        curr.push_back('1');
        search(uniques, curr, n);
        if(result.size() > 0) return;
        curr.pop_back();
    }
};