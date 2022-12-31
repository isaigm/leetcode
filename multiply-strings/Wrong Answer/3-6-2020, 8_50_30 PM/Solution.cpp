// https://leetcode.com/problems/multiply-strings

std::string add(std::string &s1, std::string &s2){
    std::string result = "";
    auto fill_with_zeros = [](std::string &str, size_t n){
        size_t zeros = 0;
        while (zeros < n)
        {
            str.insert(str.begin(), '0');
            zeros++;
        }
        
    };
    if(s1.size() > s2.size()){
        fill_with_zeros(s2, s1.size() - s2.size());
    }else if(s2.size() > s1.size()){
        fill_with_zeros(s1, s2.size() - s1.size());
    }
    int carry = 0;
    int s;
    for(int i = s1.size() - 1; i >= 0; i--){
        s = (s1[i] - '0') + (s2[i] - '0') + carry;
        if(s > 9){
            carry = s / 10;
            result.insert(result.begin(), '0' + (s % 10));
        }else {
            result.insert(result.begin(), '0' + s);
            carry = 0;
        }
    }
    if(carry) result.insert(result.begin(), carry + '0');
    return result;

}
class Solution {
public:
   std::string multiply(std::string &s1, std::string &s2){
    std::string result = "0";
    if(s1.size() > s2.size()){
        s1.swap(s2);
    }
    auto right_zeros = [](std::string &str, size_t n){
        size_t z = 0;
        while (z < n)
        {
            str.push_back('0');
            z++;
        }
        
    };
    int carry = 0;
    int zeros = 0;
    for(int i = s1.size() - 1; i >= 0; i--){
        std::string temp = "";
        for(int j = s2.size() - 1; j >= 0; j--){
            int pr = (s1[i] - '0') * (s2[j] - '0') + carry;
            if(pr > 9){
                temp.insert(temp.begin(), (pr % 10) + '0');
                carry = pr / 10;
            }else{
                temp.insert(temp.begin(), pr + '0');
                carry = 0;
            }
        }
        if(carry) temp.insert(temp.begin(), carry + '0');
        right_zeros(temp, zeros++);
        result = add(result, temp);
        carry = 0;
    }
    return result;   
}
};