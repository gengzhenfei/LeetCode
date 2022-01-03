#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class L007ReverseInteger
{
private:
    /* data */
public:
    L007ReverseInteger(/* args */);
    ~L007ReverseInteger();

    int reverse(int x)
    {
        // 如果x==-2147483648，直接返回0
        if (x == -2147483648) return 0;
        // |x| <= 2^31 - 1 则先取绝对值，再转为string，然后反转，再判断
        // 取绝对值
        int x_abs = x;
        if (x < 0) x_abs = abs(x);
        // 转为string
        string x_str = to_string(x_abs);
        // string reverse
        std::reverse(x_str.begin(), x_str.end());
        // string转为int
        long double x_rev = stold(x_str);
        if ((x > 0 && x_rev > 2147483647) || (x < 0 && x_rev > 2147483648)) // 如果string转long double超出范围
            x_rev = 0;
        else if (x < 0) // 如果x为负数，则反转之后的数加上负号
            x_rev = -x_rev;
        // cout << "x_abs " << x_abs << " x_str " << x_str << " x_rev " << x_rev << endl;
        return x_rev;
    }
};

L007ReverseInteger::L007ReverseInteger(/* args */) {}

L007ReverseInteger::~L007ReverseInteger() {}

// #include <iostream>
// #include <string>
// #include "L007ReverseInteger.cpp"
// using namespace std;

// int main()
// {
//     int x = -2147483648;
//     L007ReverseInteger Reverse;
//     cout << Reverse.reverse(x) << endl;

//     return 0;
// }