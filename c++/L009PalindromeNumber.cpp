#include <string>
#include <vector>

using namespace std;

class L009PalindromeNumber
{
private:
    /* data */
public:
    L009PalindromeNumber(/* args */);
    ~L009PalindromeNumber();

    // 方法一 转为字符串进行判断
    bool isPalindrome(int x)
    {
        if (x < 0) return false;
        string x_str = to_string(x);
        int x_strlen = x_str.size();
        int x_strlen_half = x_strlen / 2;
        for (int i = 0; i < x_strlen_half; i++) {
            if (x_str[i] == x_str[x_strlen - 1 - i]) {
                continue;
            } else
                return false;
        }

        return true;
    }

    // 方法二 拆分数字进行判断
    bool isPalindrome(int x)
    {
        if (x < 0) return false;
        vector<int> nums;
        while (x > 0) {
            nums.push_back(x % 10);
            x = x / 10;
        }
        int v_len = nums.size();
        int v_len_half = v_len / 2;
        for (int i = 0; i < v_len_half; i++) {
            if (nums[i] == nums[v_len - 1 - i]) {
                continue;
            } else
                return false;
        }
        return true;
    }
};

L009PalindromeNumber::L009PalindromeNumber(/* args */) {}

L009PalindromeNumber::~L009PalindromeNumber() {}

// #include <iostream>
// #include <string>
// #include "L009PalindromeNumber.cpp"
// using namespace std;

// int main()
// {
//     int x = 1211;
//     cout << "" << to_string(x) << endl;
//     L009PalindromeNumber PalindromeNumber;
//     cout << PalindromeNumber.isPalindrome(x) << endl;

//     return 0;
// }