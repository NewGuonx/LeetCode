// author -sonaspy@outlook.com 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
  public:
    int hammingWeight(uint32_t n)
    {
        bitset<32> b(n);
        int res =  b.count();
        return res;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}