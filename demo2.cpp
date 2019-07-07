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
void funa(int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}
inline int GCD(int n1, int n2)
{
    while (n2 > 0)
    {
        int tmp = n1 % n2;
        n1 = n2;
        n2 = tmp;
    }
    return n1;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    // int a[11] = {13, 18, 24, 35, 47, 50, 62};
    // cout << bsearch(a, 7, 24);
    double a = 1.11111111111111;
    printf("%%");
    return 0;
}
/*

    




 */