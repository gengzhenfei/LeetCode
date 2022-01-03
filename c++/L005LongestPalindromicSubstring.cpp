#include <string>
#include <iostream>
using namespace std;

class L005LongestPalindromicSubstring
{
private:
    /* data */
public:
    L005LongestPalindromicSubstring(/* args */);
    ~L005LongestPalindromicSubstring();

    string longestPalindrome(string s)
    {
        int i = 0, j = 0, p = 0;
        int l1 = i, l2 = j, len = l2 - l1 + 1;
        while (p < s.size() - 1) {
            cout << "p " << p << endl;
            cout << "i " << i << " j " << j << " len " << len << endl;
            i = p;
            p++;
            j = p;
            cout << "i " << i << " j " << j << " len " << len << endl;
            // 优先判断相邻三个字符构成回文串
            if (i - 1 >= 0 && s[i - 1] == s[j]) {
                // 如果相邻三个字符相等 则寻找附近相邻相等的字符
                if (s[i] == s[j]) {
                    while (i > 0) {
                        if (s[i - 1] == s[j])
                            i--;
                        else
                            break;
                    }
                    while (j < s.size() - 1) {
                        if (s[i] == s[j + 1])
                            j++;
                        else
                            break;
                    }
                } else
                    i--;
                while (i >= 0 && j < s.size()) {
                    if (s[i] == s[j]) {
                        if (j - i + 1 > len) {
                            l1 = i;
                            l2 = j;
                            len = l2 - l1 + 1;
                        }
                        i--;
                        j++;
                    } else
                        break;
                }
            } else if (s[i] == s[j]) // 相邻三个字符没有构成回文没 则如果相邻两个字符相等亦可
                while (i >= 0 && j < s.size()) {
                    if (s[i] == s[j]) {
                        if (j - i + 1 > len) {
                            l1 = i;
                            l2 = j;
                            len = l2 - l1 + 1;
                        }
                        i--;
                        j++;
                    } else
                        break;
                }
            cout << "i " << i << " j " << j << " len " << len << endl;
            // 越界，说明越界之前是满足回文串
            if (i < 0 || j > s.size() - 1) {
                i++;
                j--;
                if (s[i] == s[j] && j - i + 1 > len) {
                    l1 = i;
                    l2 = j;
                    len = l2 - l1 + 1;
                }
            }
            cout << "i " << i << " j " << j << endl;
        }
        return s.substr(l1, len);
    }
};

L005LongestPalindromicSubstring::L005LongestPalindromicSubstring(/* args */) {}

L005LongestPalindromicSubstring::~L005LongestPalindromicSubstring() {}

// #include <iostream>
// #include <string>
// #include "L005LongestPalindromicSubstring.cpp"
// using namespace std;

// int main()
// {
//     string str("baba");
//     L005LongestPalindromicSubstring subString;
//     cout << subString.longestPalindrome(str) << endl;

//     return 0;
// }