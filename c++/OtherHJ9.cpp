#include <iostream>
#include <vector>
using namespace std;

class OtherHJ9
{
private:
    /* data */
public:
    OtherHJ9(/* args */);
    ~OtherHJ9();

    int newInt(int old)
    {
        vector<int> unique(10, 0); // 去重辅助数组
        int result = 0;
        while (old > 0) {
            int last = old % 10;
            unique[last]++;
            if (unique[last] == 1) { result = result * 10 + last; }
            old /= 10;
        }
        return result;
    }
};

OtherHJ9::OtherHJ9(/* args */) {}

OtherHJ9::~OtherHJ9() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include <set>
// #include <algorithm>
// #include "OtherHJ9.cpp"
// using namespace std;

// int main()
// {
//     int old = 2147083659;
//     OtherHJ9 NewInt;
//     int newi = NewInt.newInt(old);
//     cout << newi << endl;
//     return 0;
//     // string num;
//     // cin >> num;
//     // reverse(num.begin(), num.end());

//     // vector<char> target;
//     // set<char> uniq;
//     // for (auto c : num) {
//     //     if (uniq.find(c) == uniq.end()) {
//     //         target.push_back(c);
//     //         uniq.insert(c);
//     //     }
//     // }

//     // for (auto c : target) { cout << c; }
//     // cout << endl;
// }