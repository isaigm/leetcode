// https://leetcode.com/problems/integer-to-roman

class Solution {
public:
    string intToRoman(int num) {
        std::map<int, char> m {{1, 'I'}, {5, 'V'}, {10, 'X'}, {50, 'L'},
                               {100, 'C'}, {500, 'D'}, {1000, 'M'}};
        std::array<int, 7> nums {1000, 500, 100, 50, 10, 5, 1};
        
        std::string ans;
        while(num > 0)
        {
            std::stringstream ss;
            ss << num;
            auto str = ss.str();
            if(str[0] == '4')
            {
                switch(str.size())
                {
                    case 1:
                        ans.push_back('I');
                        ans.push_back('V');
                        num %= 4;
                        break;
                    case 2:
                        ans.push_back('X');
                        ans.push_back('L');
                        num %= 40;
                        break;
                    case 3:
                        ans.push_back('C');
                        ans.push_back('D');
                        num %= 400;
                        break;
                    default:
                        break;
                }
            }else if(str[0] == '9'){
               switch(str.size())
                {
                    case 1:
                        ans.push_back('I');
                        ans.push_back('X');
                        num %= 9;
                        break;
                    case 2:
                        ans.push_back('X');
                        ans.push_back('C');
                        num %= 90;
                        break;
                    case 3:
                        ans.push_back('C');
                        ans.push_back('M');
                        num %= 900;
                        break;
                    default:
                        break;
                }  
            }else{
                int d = -1;
                for(const auto &i: nums)
                {
                    if(num >= i)
                    {
                        d = i;
                        break;
                    }
                }
                if(d != -1)
                {
                    for(int i = 0; i < num / d; i++)
                    {
                        ans.push_back(m[d]);
                    }
                    num %= d;
                } 
            }
            
        }
        
        return ans;
    }
};