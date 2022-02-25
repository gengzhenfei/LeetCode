#include <iostream>
#include <vector>
#include <string>
using namespace std;

class L091DecodeWays
{
private:
    /* data */
public:
    L091DecodeWays(/* args */);
    ~L091DecodeWays();

    int numDecodings(string s)
    {
        int res = 0;
        // for (int k = 1; k <= 2; k++) { dfs(s, res, 0, k); }
        dp(s, res);
        return res;
    }

    void dfs(string &s, int &res, int i, int n)
    {
        if (i >= s.size() || s[i] == '0') return;
        string str = s.substr(i, n);
        int str_i = stoi(str);
        if (str_i < 1 || str_i > 26) { return; }
        cout << i << " " << n << endl;
        if (i + n == s.size()) res++;
        for (int k = 1; k <= 2; k++) { dfs(s, res, i + n, k); }
    }

    /**
     * https://leetcode-cn.com/problems/decode-ways/comments/15627
     * 用DP去做，可以发现就是约束版的d(n) = d(n-1) + d(n-2);
     * 其中 如果是s[n-1]为0，d(n-1) = 0，d(n) = d(n-2)，因为0无法单独解码，而d(n-2)的条件则是必须在1与26之间，否则d(n) = d(n-1)
     */
    void dp(string &s, int &res)
    {
        if (s.size() == 0 || (s.size() == 1 && s[0] == '0')) return;
        if (s.size() == 1) {
            res = 1;
            return;
        }
        vector<int> d(s.size() + 1, 0);
        d[0] = 1;
        for (int i = 1; i < d.size(); i++) {
            d[i] = s[i - 1] == '0' ? 0 : d[i - 1]; // s[n-1]为0，d(n-1) = 0，d(n) = d(n-2)
            if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) {
                // d(n) = d(n-1) + d(n-2)
                d[i] += d[i - 2];
            }
        }

        res = d.back();
    }
};

L091DecodeWays::L091DecodeWays(/* args */) {}

L091DecodeWays::~L091DecodeWays() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L091DecodeWays.cpp"
// using namespace std;

// int main()
// {
//     string s = "10";
//     L091DecodeWays DecodeWays;
//     int res = DecodeWays.numDecodings(s);
//     cout << res << endl;
//     return 0;
// }