#include <string>
#include <stack>
using namespace std;

class L020ValidParentheses
{
private:
    /* data */
public:
    L020ValidParentheses(/* args */);
    ~L020ValidParentheses();

    bool isValid(string s)
    {
        stack<char> st;
        int s_len = s.size();
        for (int i = 0; i < s_len; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') // 左括号 入栈
                st.push(s[i]);
            else { // 右括号 则判断栈顶是否匹配
                if (!st.empty() && st.top() == matchLeftBracket(s[i]))
                    st.pop();
                else
                    return false;
            }
        }
        if (st.empty())
            return true;
        else
            return false;
    }

    char matchLeftBracket(char right)
    {
        if (right == ')') return '(';
        if (right == ']') return '[';
        if (right == '}') return '{';
        return ' ';
    }
};

L020ValidParentheses::L020ValidParentheses(/* args */) {}

L020ValidParentheses::~L020ValidParentheses() {}

// #include <iostream>
// #include "L020ValidParentheses.cpp"
// using namespace std;

// int main()
// {
//     string s("]");
//     L020ValidParentheses ValidParentheses;
//     cout << "true=" << true << " isValid " << ValidParentheses.isValid(s) << endl;

//     return 0;
// }