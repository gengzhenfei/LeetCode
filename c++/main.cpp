// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L060PermutationSequence.cpp"
using namespace std;

int main()
{
    int n = 4, k = 9;
    L060PermutationSequence PermutationSequence;
    string result = PermutationSequence.getPermutation(n, k);
    cout << result << endl;
    return 0;
}