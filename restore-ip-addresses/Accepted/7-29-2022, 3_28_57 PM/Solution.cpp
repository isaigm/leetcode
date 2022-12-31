// https://leetcode.com/problems/restore-ip-addresses

class Solution {
public:
   std::string filter(std::vector<std::string>& ip)
{
    std::string res = "";
    for (int i = 0; i < 4; i++)
    {
     
        std::stringstream ss(ip[i]);
        int num;
        ss >> num;
        if (ip[i][0] == '0' && ip[i].size() > 1) return "";
        if (num > 255) return "";
        if (i < 3)
        {
            res += ip[i] + ".";
        }
        else
        {
            res += ip[i];
        }
    }
    return res;
}
void bt(std::string& s, std::vector<std::string>& ip, std::vector<std::string>& ips, int start, int segment)
{
    if (segment >= 4)
    {
        if (start >= s.size())
        {
            std::string res = filter(ip);
            if (res.size() > 0) ips.push_back(res);
        }
      
        return;
    }
   
    for (int i = start; i < start + 3; i++)
    {
       
        if (i >= s.size()) break;
        ip[segment].push_back(s[i]);
        bt(s, ip, ips, i + 1, segment + 1);
    }
    ip[segment].erase(ip[segment].begin(), ip[segment].end());
}
std::vector<std::string> restoreIpAddresses(std::string s)
{

    std::vector<std::string> ips;
    std::vector<std::string> ip {"","","",""};
    bt(s, ip, ips, 0, 0);
    return ips;
}
};