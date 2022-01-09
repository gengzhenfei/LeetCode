#include <vector>
#include <string>

using namespace std;

class L022GenerateParentheses
{
private:
    /* data */
public:
    L022GenerateParentheses(/* args */);
    ~L022GenerateParentheses();

    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        if (n <= 0) return result;
        generation(result, n, n);
        return result;
    }

    /**
     * 抄袭LeetCode上其他作者的思路
     * https://leetcode-cn.com/problems/generate-parentheses/solution/gua-hao-sheng-cheng-by-leetcode-solution/540232
     */
    void generation(vector<string> &result, int left, int right, string str = "")
    {
        if (left <= 0 && right <= 0) {
            result.push_back(str);
            return;
        }
        if (left == right) { // 已经生成的左右括号数相等，则下一个加入左括号
            generation(result, left - 1, right, str + "(");
        } else if (left < right) { // 剩余左括号数小于剩余右括号数 下一个加入左右括号均可
            if (left > 0) generation(result, left - 1, right, str + "(");
            generation(result, left, right - 1, str + ")");
        }
    }
};

L022GenerateParentheses::L022GenerateParentheses(/* args */) {}

L022GenerateParentheses::~L022GenerateParentheses() {}

// #include <iostream>
// #include "L022GenerateParentheses.cpp"
// using namespace std;

// int main()
// {
//     int n = 3;
//     L022GenerateParentheses GenerateParentheses;
//     vector<string> result = GenerateParentheses.generateParenthesis(n);
//     for (auto i : result) cout << i << endl;

//     return 0;
// }