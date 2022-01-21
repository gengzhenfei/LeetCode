// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L043MultiplyStrings.cpp"
using namespace std;

int main()
{
    string num1 = "2";
    string num2 = "3";
    L043MultiplyStrings MultiplyStrings;
    string result = MultiplyStrings.multiply(num1, num2);
    cout << result << endl;
    return 0;
}