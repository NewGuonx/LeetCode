// author - newguo@sonaspy.cn
// coding - utf_8

#include <stdio.h>

#define test() freopen("in", "r", stdin)

int newguo(int x)
{
    int res = 1;
    do
    {
        res *= x;
        x = x - 1;
    } while (x > 1);
    return res;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();

    return 0;
}