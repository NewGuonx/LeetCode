// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    vector<vector<int>> a(2, vector<int>(2, 8));
    a[1][0] = 10, a[1][1] = 20;
    cout << binary_search(a[0].begin(), a.back().end(), 20) << endl;
    cout << &a[0][0] << endl;
    cout << &a[0][1] << endl;
    cout << &a[1][0] << endl;
    cout << &a[1][1] << endl;
    return 0;
}