// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    const int MAXN = 1001;
    int n;
    vector<int> a(MAXN), f(MAXN, 1);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        for (int k = 0; k < i; k++)
            if (a[k] < a[i])
                f[i] = max(f[i], f[k] + 1);
    }
    int max_len = *max_element(f.begin(), f.begin() + n);
    return 0;
}