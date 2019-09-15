// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int b[10] = {1, 2, 3, 4, 5, 6};
    vector<int> a(b, b + 6), c(b, b + 6), d(b, b + 6), f(6);

    f.insert(f.begin(), *(a.begin() + 6));
    cout << f.size();

    return 0;
}