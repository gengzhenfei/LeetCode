#include <iostream>
#include <string>
#include "L010RegularExpressionMatching.cpp"
using namespace std;

int main()
{
    string s = "aabcbcbcaccbcaabc";
    string p = ".*a*aa*.*b*.c*.*a*";
    L010RegularExpressionMatching RegularExpression;
    cout << "true = " << true << "  " << RegularExpression.isMatch(s, p) << endl;

    return 0;
}