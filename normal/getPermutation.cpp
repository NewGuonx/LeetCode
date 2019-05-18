// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
public:
    string getPermutation(int n, int k)
    {
        string s = "123456789";
        s = s.substr(0, n);
        int c = 1;
        while (c < k && next_permutation(s.begin(), s.end()))
            c++;
        return s;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}