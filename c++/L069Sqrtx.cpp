#include <climits>
using namespace std;

class L069Sqrtx
{
private:
    /* data */
public:
    L069Sqrtx(/* args */);
    ~L069Sqrtx();

    int mySqrt(int x)
    {
        if (x == 1) return 1; // 特殊情况
        int low = 0, high = x > 9 ? x / 2 : x; // 简单起见，high可初始为x
        int mid = (low + high) / 2;
        while (high - low > 1) {
            if (x / mid == mid) // 使用除法而不是乘法 防止溢出
                return mid;
            else if (x / mid > mid) {
                low = mid;
            } else {
                high = mid;
            }
            mid = (low + high) / 2;
        }
        return low;
    }
};

L069Sqrtx::L069Sqrtx(/* args */) {}

L069Sqrtx::~L069Sqrtx() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L069Sqrtx.cpp"
// using namespace std;

// int main()
// {
//     int x = 6;
//     L069Sqrtx Sqrtx;
//     int res = Sqrtx.mySqrt(x);
//     cout << res << endl;
//     return 0;
// }