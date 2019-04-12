// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
public:
    vector<int> constructRectangle(int area)
    {
        int w = sqrt(area);
        while (area / w != (double)area / w)
            w--;
        vector<int> res = {area / w, w}; // L - W
        return res;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}