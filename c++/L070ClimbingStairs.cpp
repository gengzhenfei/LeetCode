class L070ClimbingStairs
{
private:
    /* data */
public:
    L070ClimbingStairs(/* args */);
    ~L070ClimbingStairs();

    int climbStairs(int n)
    {
        if (n == 1) return 1;
        int pre_steps = 1;
        int steps = 2;
        for (int i = 2; i < n; i++) {
            int tmp = pre_steps + steps;
            pre_steps = steps;
            steps = tmp;
        }
        return steps;
    }
};

L070ClimbingStairs::L070ClimbingStairs(/* args */) {}

L070ClimbingStairs::~L070ClimbingStairs() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L070ClimbingStairs.cpp"
// using namespace std;

// int main()
// {
//     int x = 45;
//     L070ClimbingStairs ClimbingStairs;
//     int res = ClimbingStairs.climbStairs(x);
//     cout << res << endl;
//     return 0;
// }