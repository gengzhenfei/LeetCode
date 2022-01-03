#include <iostream>
#include <string>

using namespace std;

class L003LongestSubstringWithoutRepeating
{
private:
    /* data */
public:
    L003LongestSubstringWithoutRepeating(/* args */);
    ~L003LongestSubstringWithoutRepeating();

    int lengthOfLongestSubstring(string s)
    {
        int len = 0;
        int i = 0, j = 0;
        while (j < s.length()) {
            j++;
            string substr(s.substr(i, j - i));
            // 查找当前字符是否重复
            int substr_j = substr.find(s[j]);
            // 出现重复字符
            if (string::npos != substr_j) {
                if (j - i > len) len = j - i;
                i = i + substr_j + 1;
            }
        }
        // 判断最后子串是否为最长子串
        if (j - i > len) len = j - i;

        return len;
    }
};

L003LongestSubstringWithoutRepeating::L003LongestSubstringWithoutRepeating(/* args */) {}

L003LongestSubstringWithoutRepeating::~L003LongestSubstringWithoutRepeating() {}

// #include <iostream>
// #include <string>
// #include "L003LongestSubstringWithoutRepeating.cpp"
// using namespace std;

// int main()
// {
//     // 003 longest substring without repeating characters
//     string str("abcabcbb");
//     L003LongestSubstringWithoutRepeating LongestSubstr;
//     cout << LongestSubstr.lengthOfLongestSubstring(str) << endl;

//     return 0;
// }