// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    int findLUSlength(string a, string b)
    {
        if (a == b)
            return -1;
        return a.size() >= b.size() ? a.size() : b.size();
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}