#include <vector>
using namespace std;

class L066PlusOne
{
private:
    /* data */
public:
    L066PlusOne(/* args */);
    ~L066PlusOne();

    vector<int> plusOne(vector<int> &digits)
    {
        int len = digits.size();
        if (len == 0) return vector<int>{1};
        int carry = (digits[len - 1] + 1) / 10; // 进位
        digits[len - 1] = (digits[len - 1] + 1) % 10; // 最低位
        for (int i = len - 2; i >= 0 && carry != 0; i--) {
            int sum = carry + digits[i];
            carry = sum / 10; // 进位
            digits[i] = sum % 10; // 更新位
        }
        while (carry != 0) {
            vector<int>::iterator it = digits.begin();
            digits.insert(it, carry % 10);
            carry /= 10;
        }
        return digits;
    }
};

L066PlusOne::L066PlusOne(/* args */) {}

L066PlusOne::~L066PlusOne() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L066PlusOne.cpp"
// using namespace std;

// int main()
// {
//     vector<int> list{};
//     L066PlusOne PlusOne;
//     vector<int> res = PlusOne.plusOne(list);
//     for (int i : res) cout << i << " ";
//     cout << endl;
//     return 0;
// }