// https://leetcode.com/problems/encode-and-decode-tinyurl

class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        std::string random_str;
        for(int i = 0; i < 9; i++)
        {
            int r = rand() % 3;
            switch(r)
            {
                case 0:
                    random_str.push_back(rand() % 10 - '0');
                    break;
                case 1:
                    random_str.push_back(rand() % 26 + 65);
                    break;
                case 2:
                    random_str.push_back(rand() % 26 + 97);
                    break;
                default:
                    break;
            }
        }
        std::string encoded = "http://tinyurl.com/" + random_str;
        short_to_long[encoded] = longUrl;
        return encoded;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return short_to_long[shortUrl];
    }
    std::map<std::string, std::string> short_to_long;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));