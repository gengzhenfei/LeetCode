// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L032LongestValidParentheses.cpp"
using namespace std;

int main()
{
    string str = "(()(((()";
    L032LongestValidParentheses LongestValidParentheses;
    int index = LongestValidParentheses.longestValidParentheses(str);
    cout << index << endl;
    return 0;
}