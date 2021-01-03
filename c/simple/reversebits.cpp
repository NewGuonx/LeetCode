// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
  public:
    uint32_t reverseBits(uint32_t n)
    {
        bitset<32> bin(n);
        string s = bin.to_string();
        reverse(s.begin(), s.end());
        bitset<32> bin1(s);
        uint32_t res = bin1.to_ulong();
        return res;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}