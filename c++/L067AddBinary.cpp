#include <string>
using namespace std;

class L067AddBinary
{
private:
    /* data */
public:
    L067AddBinary(/* args */);
    ~L067AddBinary();

    string addBinary(string a, string b)
    {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        int sum = 0;
        string res = "";
        while (i >= 0 && j >= 0) {
            sum = carry + c2i(a[i--]) + c2i(b[j--]);
            res.insert(0, i2s(sum % 2));
            carry = sum / 2;
        }
        while (i >= 0) {
            sum = carry + c2i(a[i--]);
            res.insert(0, i2s(sum % 2));
            carry = sum / 2;
        }
        while (j >= 0) {
            sum = carry + c2i(b[j--]);
            res.insert(0, i2s(sum % 2));
            carry = sum / 2;
        }
        while (carry != 0) {
            res.insert(0, i2s(carry % 2));
            carry /= 2;
        }

        return res;
    }

    int c2i(char c)
    {
        if (c > '9' || c < '0') return 0;
        return c - '0';
    }

    string i2s(int i)
    {
        if (i > 9 || i < 0) return "0";
        return string(1, i + '0');
    }
};

L067AddBinary::L067AddBinary(/* args */) {}

L067AddBinary::~L067AddBinary() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L067AddBinary.cpp"
// using namespace std;

// int main()
// {
//     string a = "1010", b = "1011";
//     L067AddBinary AddBinary;
//     string result = AddBinary.addBinary(a, b);
//     cout << result << endl;
//     return 0;
// }