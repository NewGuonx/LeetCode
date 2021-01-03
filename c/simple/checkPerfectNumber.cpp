// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    bool checkPerfectNumber(int num)
    {
        switch (num)
        {
        case 6:
        case 28:
        case 496:
        case 8128:
        case 33550336:
            return true;
        default:
            break;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    Solution s;
    cout << s.checkPerfectNumber(99999996);
    return 0;
}