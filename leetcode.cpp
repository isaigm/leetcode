#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <chrono>
#include <bitset>
__int128_t pow(__int128_t x, __int128_t y){
    __int128_t res = 1;
    for (__int128_t i = 1; i <= y; i++)
    {
        res *= x;
    }
    return res;
    
}
int reverse(long int x){
    std::vector<long int> digits;
    long int k = abs(x);
    while (k > 0)
    {
        digits.push_back(k % 10);
        k /= 10;
    }
    std::reverse(digits.begin(), digits.end());
    long int res = 0;
    long int p = 0;
    for(auto &digit : digits){
        std::cout << digit << std::endl;
        res += (long int) pow(10, p++) * digit;
    }
    if (x > 0) return res;
    return -res;
    
}
int myAtoi(std::string str) {
        size_t index = 0;
        size_t len = str.length();
        int sign = 0;
        while(str[index] == ' ' && index++ < len){}
        if(index >= len) return 0;
        if(str[index] == '-'){
            sign = -1;
            index++;
        }else if(str[index] == '+'){
            sign = 1;
            index++;
        }else if(isdigit(str[index])){
            sign = 1;
        }else return 0;
        if(index >= len) return 0;
        __int128_t res = 0;
        __int128_t aux = 0;
        int y = 0;
        std::string substr;
        while (isdigit(str[index])){ substr.push_back(str[index++]); }
        bool is_zero = substr[0] == '0';
        for (int i = substr.length() - 1; i >= 0; i--)
        {
            __int128_t p = pow(10, y++);
            res += p * (substr[i] - '0');
            if(substr[i] == '0') aux += p;
            else aux += p * (substr[i] - '0');
            if(is_zero){aux = res;}
            if (aux * sign < INT32_MIN) return INT32_MIN;
            else if (aux * sign > INT32_MAX) return INT32_MAX;
        }
        return res * sign;
                
}
std::string longestPalindrome(std::string s) {
    if (s.length() > 1){
        std::vector<std::string> substrs;
        for (size_t i = 0; i < s.length(); i++)
        {
            for (size_t j = i; j < s.length(); j++)
            {
                std::string str = s.substr(i, j - i + 1);
                std::string cpy = str;
                std::reverse(str.begin(), str.end());
                if (!str.compare(cpy))
                {
                    substrs.push_back(str);
                }
            }
        }
        auto iter = std::max_element(substrs.begin(), substrs.end(), [](std::string &str1, std::string &str2) {
            return str1.length() < str2.length();
        });
        return *iter;
    }else return s;
}

/*
int hammingWeight(uint32_t n){
    int count = 0;
    for (size_t i = 0; i < 32; i++)
    {
        if(((n >> (31-i)) & 0x1) != 0) count++;
    }
    return count;
}*/
int hammingWeight(uint32_t n){
    int count = 0;
    while(n > 0){
        count += n & 1; //Con n & 1 se obtiene el bit menos significativo
        n >>= 1; //Se desplaza una posicion a la derecha 
    }
    return count;
}
int strStr(std::string haystack, std::string needle) {
    if(!haystack.compare(needle)) return 0;
    if (haystack.length() >= needle.length())
    {
        int len = needle.length();
        for (int i = 0; i < haystack.length() - len + 1; i++)
        {
            auto substr = haystack.substr(i, len);
            std::cout << substr << std::endl;
            if(!substr.compare(needle)) return i;
        }
        
    }
    return -1;
}
std::string longestCommonPrefix(std::vector<std::string> &strs) {
    if(!strs.size()) return std::string("");
    else if(strs.size() == 1) return strs[0];
    auto common = [](std::string &str1, std::string &str2){
        std::string res = "";
        size_t i = 0;
        size_t j = 0;
        while ((i < str1.length() && j < str2.length()) && str1[i] == str2[j])
        {
            res.push_back(str1[i]);
            i++;
            j++;
        }
        return res;
    };
    auto res = common(strs[0], strs[1]);
    if(!res.length()) return res;
    for (size_t i = 1; i < strs.size() - 1; i++)
    {
        auto aux = common(res, strs[i+1]);
        res = aux;
        if(!res.length()) return std::string("");
    }
    return res;    
}
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
//Claramente se puede mejorar xD
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
    if(result[0] == '0') return std::string("0");
    return result;   
}
uint64_t aux(uint64_t x, int n){
    uint64_t res = 1;
    for (int i = 0; i < n; i++)
    {
        res *= x;
    }
    return res;
    
}
uint64_t myPow(uint64_t x, int n) {
    if (n == 1) return x;
    else if (n % 2 == 0) {
        uint64_t temp = aux(x, n / 2);
        return temp * temp;
    }else return x * myPow(x, n - 1);
}
uint32_t reverseBits(uint32_t n) {
    uint32_t rev = 0x0;
    int places = 32;
    uint32_t bits;
    while (n > 0)
    {
        bits = (n & 1) << ((places--) - 1);
        rev |= bits;
        n >>= 1;
    }
    return rev;
    
}
bool isPowerOfTwo(int n) {
    auto counting_bits = [](int k) -> int{
        int c = 0;
        while (k > 0)
        {
            if(k & 1) c++;
            k >>= 1;
        }
        return c;
    };        
    if (counting_bits(n) == 1) return true;
    return false;
}
int main(){
    auto start = std::chrono::steady_clock::now();
    //std::cout << longestPalindrome("zudfweormatjycujjirzjpyrmaxurectxrtqedmmgergwdvjmjtstdhcihacqnothgttgqfywcpgnuvwglvfiuxteopoyizgehkwuvvkqxbnufkcbodlhdmbqyghkojrgokpwdhtdrwmvdegwycecrgjvuexlguayzcammupgeskrvpthrmwqaqsdcgycdupykppiyhwzwcplivjnnvwhqkkxildtyjltklcokcrgqnnwzzeuqioyahqpuskkpbxhvzvqyhlegmoviogzwuiqahiouhnecjwysmtarjjdjqdrkljawzasriouuiqkcwwqsxifbndjmyprdozhwaoibpqrthpcjphgsfbeqrqqoqiqqdicvybzxhklehzzapbvcyleljawowluqgxxwlrymzojshlwkmzwpixgfjljkmwdtjeabgyrpbqyyykmoaqdambpkyyvukalbrzoyoufjqeftniddsfqnilxlplselqatdgjziphvrbokofvuerpsvqmzakbyzxtxvyanvjpfyvyiivqusfrsufjanmfibgrkwtiuoykiavpbqeyfsuteuxxjiyxvlvgmehycdvxdorpepmsinvmyzeqeiikajopqedyopirmhymozernxzaueljjrhcsofwyddkpnvcvzixdjknikyhzmstvbducjcoyoeoaqruuewclzqqqxzpgykrkygxnmlsrjudoaejxkipkgmcoqtxhelvsizgdwdyjwuumazxfstoaxeqqxoqezakdqjwpkrbldpcbbxexquqrznavcrprnydufsidakvrpuzgfisdxreldbqfizngtrilnbqboxwmwienlkmmiuifrvytukcqcpeqdwwucymgvyrektsnfijdcdoawbcwkkjkqwzffnuqituihjaklvthulmcjrhqcyzvekzqlxgddjoir") << std::endl;
    auto s1 = std::string("12459405490642329031053750459749064698340312323546680284028043");
    auto s2 = std::string("424214241241257777777s7756");
    std::cout << multiply(s1, s2) << std::endl;
    std::cout << hammingWeight(12345) << std::endl; 
    std::cout << strStr("mississippi", "pi") << std::endl;
    std::vector<std::string> strs {"flower","flow","flight"};
    std::cout << longestCommonPrefix(strs) << std::endl;
    std::cout << myPow(2, 23) << std::endl;
    std::cout << reverseBits(43261596) << std::endl;
    std::cout << isPowerOfTwo(123) << std::endl;
    auto end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;
    return 0;
}
