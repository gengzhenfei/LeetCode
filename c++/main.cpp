#include <iostream>
#include <string>
#include <vector>
#include "L014LongestCommonPrefix.cpp"
using namespace std;

int main()
{
    vector<string> list{"nll", "null", "nu3"};
    L014LongestCommonPrefix LongestCommonPrefix;
    cout << LongestCommonPrefix.longestCommonPrefix(list) << endl;

    return 0;
}