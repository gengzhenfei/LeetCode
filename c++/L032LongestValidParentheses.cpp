#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class L032LongestValidParentheses
{
private:
    /* data */
public:
    L032LongestValidParentheses(/* args */);
    ~L032LongestValidParentheses();

    int longestValidParentheses(string s)
    {
        int longest = 0;
        int start = 0;
        stack<int> st;
        int s_len = s.size();
        for (int i = 0; i < s_len; i++) {
            if (s[i] == '(') { // 左括号的索引入栈
                st.push(i);
            } else if (!st.empty()) { // 栈不空 则说明匹配
                st.pop();
                if (st.empty()) { // 栈空，则当前匹配最长串为 i - start + 1
                    longest = max(longest, i - start + 1);
                } else {
                    longest = max(longest, i - st.top());
                }
            } else { // 栈为空 则说明不匹配了 更新起点
                start = i + 1;
            }
        }

        return longest;
    }
};

L032LongestValidParentheses::L032LongestValidParentheses(/* args */) {}

L032LongestValidParentheses::~L032LongestValidParentheses() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L032LongestValidParentheses.cpp"
// using namespace std;

// int main()
// {
//     string str = "(()(((()";
//     L032LongestValidParentheses LongestValidParentheses;
//     int index = LongestValidParentheses.longestValidParentheses(str);
//     cout << index << endl;
//     return 0;
// }