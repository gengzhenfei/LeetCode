#include <iostream>
#include <vector>
#include <string>
using namespace std;

class L093RestoreIpAddresses
{
private:
    /* data */
public:
    L093RestoreIpAddresses(/* args */);
    ~L093RestoreIpAddresses();

    vector<string> restoreIpAddresses(string s)
    {
        vector<string> res;
        backtrace(s, res, "", 0, 0);

        return res;
    }

    /**
     * 回溯
     * @param string s
     * @param vector<string> res 储存IP的结果
     * @param string ip ip字符串
     * @param int ci 当前指针
     * @param int n 计数器 ip共4部分组成
     */
    void backtrace(string &s, vector<string> &res, string ip, int ci, int n)
    {
        // cout << "ci:" << ci << " n:" << n << " ip:" << ip << endl;
        if (n == 4) { // ip共四部分组成
            if (ci == s.size()) res.push_back(ip);
            return;
        }
        // ip地址每一部分最多三位 分三次回溯
        for (int i = 0; i < 3 && i + ci < s.size(); i++) {
            string subip;
            if (n > 0) { subip = '.'; }
            subip += s.substr(ci, i + 1);
            backtrace(s, res, ip + subip, ci + i + 1, n + 1);
            if (s[ci] == '0' || (i == 1 && stoi(s.substr(ci, 3)) > 255)) {
                // s[ci]==0 则只能1位ip地址； 而s[ci~ci+3]>255 则不可组成3位的ip地址
                break;
            } else { // 回滚
                subip = subip.substr(0, subip.size() - i - 1);
            }
        }
        return;
    }
};

L093RestoreIpAddresses::L093RestoreIpAddresses(/* args */) {}

L093RestoreIpAddresses::~L093RestoreIpAddresses() {}
