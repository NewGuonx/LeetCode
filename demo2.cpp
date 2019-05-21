// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
// 0-1 -> dfs
int target = 1000, ans_sum = 0, N = 20;
vector<int> v(1000);

void dfs(int id, int sum)
{
    if (id == N)
    {
        if (sum > ans_sum)
            ans_sum = sum;
        return;
    }
    dfs(id + 1, sum);
    if (sum + v[id] <= target)
        dfs(id + 1, sum + v[id]);
}
int main(int argc, const char *argv[])
{
    // insert code here...
    srand(time(NULL));
    generate(v.begin(), v.end(), [] { return rand() % 1000; });
    dfs(0, 0);
    cout << abs(ans_sum - target) << endl;
    return 0;
}
