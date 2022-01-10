#include <iostream>
#include "L027RemoveElement.cpp"
using namespace std;

int main()
{
    // 构造测试数据
    vector<int> v{0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    L027RemoveElement RemoveElement;
    int result = RemoveElement.removeElement(v, val);
    cout << result << endl;
    for (auto i : v) cout << i << endl;

    return 0;
}