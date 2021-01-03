// author -sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <string>
#include <algorithm>
#define test() freopen("in", "r", stdin)

using namespace std;

class Solution
{
  public:
    bool isPalindrome(int x)
    {
        string s, s2;
        s = to_string(x), s2 = s;
        ::reverse(s.begin(), s.end());
        if (s == s2)
            return true;
        return false;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();

    return 0;
}