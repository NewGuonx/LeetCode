// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

typedef vector<int> BIGINT;

BIGINT to_bigint(const string &s)
{
    BIGINT n;
    transform(s.rbegin(), s.rend(), back_inserter(n), [](char c) { return c - '0'; });
    return n;
}
string to_str(const BIGINT &s)
{
    string n;
    transform(find_if(s.rbegin(), prev(s.rend()), [](char c) { return c > '\0'; }), s.rend(), back_inserter(n), [](char c) { return c + '0'; });
    return n;
}
BIGINT operator*(BIGINT const &x, BIGINT const &y)
{
    BIGINT z(x.size() + y.size());
    int i, j;
    for (i = 0; i < x.size(); i++)
        for (j = 0; j < y.size(); j++)
        {
            z[i + j] += x[i] * y[j];
            z[i + j + 1] += z[i + j] / 10;
            z[i + j] %= 10;
        }
    return z;
}

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        return to_str(to_bigint(num1) * to_bigint(num2));
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}