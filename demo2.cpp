// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //freopen("in","r",stdin);
    list<int> ls;
    int N, M, i, var, flag = 0;
    cin >> N >> M;
    for (i = 0; i < N; i++)
    {
        cin >> var;
        ls.push_back(var);
    }
    for (i = 0; i < M; i++)
        ls.push_front(ls.back()), ls.pop_back();
    for (auto p : ls)
    {
        if (!flag)
            flag = 1;
        else
            cout << " ";
        cout << p;
    }
    return 0;
}