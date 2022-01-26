#include <climits>
using namespace std;

class L050PowxN
{
private:
    /* data */
public:
    L050PowxN(/* args */);
    ~L050PowxN();

    /**
     * 1. x==0 直接返回0；
     * 2. n<0 转化为 n>0；
     * 3. n>=0 时，通过循环 x=x^2, n=n/2，直到将幂将为0；
     */
    double myPow(double x, int n)
    {
        double res = 1;
        if (x == 0) return 0;
        if (n == INT_MIN) { // int 边界
            res = 1 / x;
            x = 1 / x;
            n = INT_MAX;
        } else if (n < 0) { // n<0 负次方转为正的次方
            x = 1 / x;
            n = ~(n - 1); // n<0 负数转为正数
        }
        while (n > 0) {
            if ((n & 1) == 1) { // n为奇数
                res *= x;
            }
            x *= x;
            n = n >> 1; // 右移一位 相当于 n/2
        }
        return res;
    }
};

L050PowxN::L050PowxN(/* args */) {}

L050PowxN::~L050PowxN() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L050PowxN.cpp"
// using namespace std;

// int main()
// {
//     double x = 2;
//     int n = -2;
//     L050PowxN PowxN;
//     double res = PowxN.myPow(x, n);
//     cout << res << endl;
//     return 0;
// }