#include <string>

using namespace std;

class L010RegularExpressionMatching
{
private:
    /* data */
public:
    L010RegularExpressionMatching(/* args */);
    ~L010RegularExpressionMatching();

    bool isMatch(string s, string p)
    {
        int s_len = s.size();
        int p_len = p.size();
        int si = 0;
        int pi = 0;
        // 对字符串预处理 优先匹配开头和结尾的a-z字符
        for (; si < s_len && pi < p_len; pi++, si++) {
            if (pi < p_len - 1 && p[pi + 1] == '*')
                break;
            else if (p[pi] != '.' && p[pi] != s[si])
                return false;
        }
        s = s.substr(si);
        p = p.substr(pi);
        s_len = s.size();
        p_len = p.size();
        si = s_len - 1;
        pi = p_len - 1;
        for (; si >= 0 && pi >= 0; pi--, si--) {
            if (p[pi] == '*')
                break;
            else if (p[pi] != '.' && p[pi] != s[si])
                return false;
        }
        s = s.substr(0, si + 1);
        p = p.substr(0, pi + 1);
        s_len = s.size();
        p_len = p.size();
        si = 0;
        pi = 0;

        cout << " s_len " << s_len << " p_len " << p_len << endl;
        while (si < s_len && pi < p_len) {
            cout << "0# pi " << pi << " si " << si << endl;
            if (p[pi] == s[si]) { // 情况1 相同字符
                pi++;
                si++;
                continue;
            } else if (p[pi] == '.') { // 情况2 '.'匹配任意一个字符
                if ((pi < p_len - 1 && p[pi + 1] != '*') || (pi == p_len - 1)) {
                    pi++;
                    si++;
                    continue;
                } else if (pi < p_len - 1 && p[pi + 1] == '*') { // s:"a", p:".*a"
                    pi++;
                    continue;
                }
            } else if (p[pi] == '*') { // 情况3 '*'匹配处理
                if (p[pi - 1] == '.') { // 如果*字符前为 . 字符
                    pi++;
                    if (s[si] == p[pi]) {
                        // 寻找si后第一个不等于p[pi]的字符
                        while (si < s_len && s[si] == p[pi]) { si++; }
                        if (si < s_len)
                            si--;
                        else {
                            pi++;
                        }
                    } else if (p[pi] == '.') {
                        continue;
                    } else {
                        // 寻找si后第一个等于p[pi]的字符
                        while (si < s_len && s[si] != p[pi]) { si++; }
                    }
                } else { // 如果*字符前为 非. 字符
                    if (pi == p_len - 1) { // p[pi]=='*' 为p的最后一个字符
                        while (si < s_len && s[si] == p[pi - 1]) { si++; }
                        pi++;
                    } else {
                        char c = p[pi - 1];
                        pi++;
                        while (si < s_len && s[si] == c) { si++; }
                        while (pi < p_len && p[pi] == c) { pi++; }
                    }
                }
                cout << "1# pi " << pi << " si " << si << endl;
                if (si != s_len && pi != p_len) {
                    continue;
                } else if (si == s_len && pi == p_len)
                    return true;
                else
                    break;
            } else if (p[pi] != s[si] && pi < p_len - 1 && p[pi + 1] == '*') { // 情况4 当前字符不匹配，但pi下一个索引的字符为*
                pi++;
            } else { // 情况4 不匹配
                return false;
            }
            cout << "2# pi " << pi << " si " << si << endl;
        }
        // 以上循环结束，判断s和p是否同时匹配完
        if (pi == p_len && si == s_len) // 全部匹配完成
            return true;
        else if (pi != p_len && si == s_len) { // s匹配完，p还剩余，判断p剩余字符串是不是以*结尾
            while (pi < p_len) {
                if (p[pi] == '*' || (pi < p_len - 1 && p[pi + 1] == '*'))
                    pi++;
                else
                    break;
            }
            if (pi < p_len)
                return false;
            else
                return true;
        } else {
            return false;
        }
    }
};

L010RegularExpressionMatching::L010RegularExpressionMatching(/* args */) {}

L010RegularExpressionMatching::~L010RegularExpressionMatching() {}

// #include <iostream>
// #include <string>
// #include "L010RegularExpressionMatching.cpp"
// using namespace std;

// int main()
// {
//     string s = "aabcbcbcaccbcaabc";
//     string p = ".*a*aa*.*b*.c*.*a*";
//     L010RegularExpressionMatching RegularExpression;
//     cout << "true = " << true << "  " << RegularExpression.isMatch(s, p) << endl;

//     return 0;
// }