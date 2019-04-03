// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
  public:
    int addDigits(int num)
    {
        string s;
        while((num / 10 )!= 0){
            s = to_string(num);
            num = 0;
            for(auto i : s) num += i -'0';
        }
        return num;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    Solution s;
    cout << s.addDigits(88);
    return 0;
}