// https://leetcode.com/problems/iterator-for-combination

class CombinationIterator
{
public:
    CombinationIterator(std::string characters, int combinationLength)
    {
        std::string curr;
        dfs(combinations, characters, curr, combinationLength, 0);
    }

    std::string next()
    {
        if (curr_idx < combinations.size())
        {
            return combinations[curr_idx++];
        }
        return "";
    }

    bool hasNext()
    {
        if (curr_idx  < combinations.size())
        {
            return std::binary_search(combinations.begin(), combinations.end(), combinations[curr_idx]);
        }
        return false;
    }

private:
    void dfs(std::vector<std::string> &combinations, std::string &characters, std::string &curr, int max_len, int start)
    {
        if (curr.size() == max_len)
        {
            combinations.push_back(curr);
            return;
        }
        for (int i = start; i < characters.size(); i++)
        {
            curr.push_back(characters[i]);
            dfs(combinations, characters, curr, max_len, i + 1);
            curr.pop_back();
        }
    }

    std::vector<std::string> combinations;
    size_t curr_idx = 0;
};
/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */