// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
const char *s;
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    char *ss = (char*)malloc(sizeof(char) * 10);
    *ss = '*';
    if (ss != nullptr)
    {
        free(ss);
        //ss = nullptr;
    }
    cout << ss;
    return 0;
}