// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
#include<stack>
#include<queue>
#include<numeric>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int res = haystack.find(needle);
        return res;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    Solution s;
    cout << s.strStr("1234567","45");
    return 0;
}