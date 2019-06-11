// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int bsearch(int array[], int n, int v)
{
    int left, right, middle;
    left = 0, right = n - 1;
    int num = 0;
    while (left <= right)
    {
        middle = left + (right - left) / 2;
        num++;
        if (array[middle] > v)
            right = middle - 1;
        else if (array[middle] < v)
            left = middle + 1;
        else
            return num;
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int a[11] = {2, 11, 15, 19, 30, 32, 61, 72, 88, 90, 96};
    cout << bsearch(a, 11, 15);
    return 0;
}