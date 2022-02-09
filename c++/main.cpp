// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L067AddBinary.cpp"
using namespace std;

int main()
{
    string a = "1010", b = "1011";
    L067AddBinary AddBinary;
    string result = AddBinary.addBinary(a, b);
    cout << result << endl;
    return 0;
}