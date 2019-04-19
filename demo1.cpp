// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
const char *ss = "http://sonaspy.cn/";
vector<const char*> container;
map<const char *, const char *> mp;
inline char *return_str()
{
    char *str = (char *)malloc(40 * sizeof(char));
    strcpy(str, ss);
    char *walk = str + strlen(str);
    int n, branch, count = 0;
    while (count < 8)
    {
        n = rand() % 10;
        if (n < 4)
            *walk = 'A' + rand() % 26;
        else if (n < 7)
            *walk = 'a' + rand() % 26;
        else if (n < 10)
            *walk = '0' + rand() % 10;
        count++, walk++;
    }
    *walk = '\0';
    container.push_back(str);
    return str;
}



int main(int argc, char const *argv[])
{
    /* code */
    //test();
    srand(time(nullptr));
    const char *url = return_str();
    free((void *)url);
    cout << url;
    return 0;
}   