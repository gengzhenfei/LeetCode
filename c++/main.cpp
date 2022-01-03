#include <iostream>
#include <string>
#include "L009PalindromeNumber.cpp"
using namespace std;

int main()
{
    int x = 1211;
    cout << "" << to_string(x) << endl;
    L009PalindromeNumber PalindromeNumber;
    cout << PalindromeNumber.isPalindrome(x) << endl;

    return 0;
}