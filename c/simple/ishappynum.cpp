// author -sonaspy@outlook.com 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;

class Solution
{
  public:
    bool isHappy(int n)
    {
        int num = n;
        unordered_set<int> st;
        if(num ==0 )return false;
        while(num != 1){
            string s = to_string(num);
            num = 0;
            for(auto i : s)
                num += (i-'0')*(i-'0');
            if(st.count(num))break;
            st.insert(num);
        }
        return num == 1;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    Solution s;
    s.isHappy(2007);
    return 0;
}