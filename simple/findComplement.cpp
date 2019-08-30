// author -sonaspy@outlook.com 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
  public:
    int findComplement(int num)
    {
        int temp = num, c = 0;
        while (temp)
        {
            temp >>= 1;
            c = (c << 1) + 1;
        }
        return num ^ c;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}