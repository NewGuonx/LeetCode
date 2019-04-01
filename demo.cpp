// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
int a[10000];

int ways(int w, int k){
    if(w == 0) return 1;
    if(k <= 0) return 0;
    return ways(w, k-1) + ways(w-a[k] ,k-1);
}


int main(int argc, char const *argv[])
{
    /* code */
    test();
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)cin >> a[i];
    cout << ways(m,n);
    return 0;
}