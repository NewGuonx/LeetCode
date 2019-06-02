// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int bsearch(int array[], int n, int v)
{
    int left, right, middle;
    left = 0, right = n - 1;
    while (left <= right)
    {
        middle = left + (right - left) / 2;
        cout << middle << endl;
        if (array[middle] > v)
        {
            right = middle - 1;
        }
        else if (array[middle] < v)
        {
            left = middle + 1;
        }
        else
        {
            return middle;
        }
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int a[18] = {2, 6, 8, 10, 13, 25, 36, 45, 53, 76, 88, 100, 127, 129, 130, 131, 132, 133};
    int i = bsearch(a, 18, 10);
    return 0;
}