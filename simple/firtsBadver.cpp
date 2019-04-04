// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int hi = n, lo =1;
        while(lo < hi){
            int mid = lo + (lo+hi)/2;
            if(isBadVersion(mid))
                hi = mid;
            else lo = mid+1;
        }
        return hi;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}