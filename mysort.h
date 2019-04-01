// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
void Merge(int a[], int lo, int m, int hi, int tmp[])
{
    int c = 0, p1 = lo, p2 = m + 1;
    while (p1 <= m && p2 <= hi)
    {
        if (a[p1] < a[p2])
            tmp[c++] = a[p1++];
        else
            tmp[c++] = a[p2++];
    }
    while (p1 <= m)
        tmp[c++] = a[p1++];
    while (p2 <= hi)
        tmp[c++] = a[p2++];
    for (int i = 0; i < hi - lo + 1; ++i)
        a[lo + i] = tmp[i];
}

void MergeSort(int a[], int lo, int hi, int tmp[])
{
    if (lo < hi)
    {
        int m = lo + (hi - lo) / 2;
        MergeSort(a, lo, m, tmp);
        MergeSort(a, m + 1, hi, tmp);
        Merge(a, lo, m, hi, tmp);
    }
}

void Qsort(int a[], int lo, int hi)
{
    if (hi <= lo)
        return;
    int pivot = a[lo], l = lo, r = hi;
    while (l < r)
    {
        while (l < r && pivot <= a[r])
            r--;
        swap(a[l], a[r]);
        while (l < r && a[l] <= pivot)
            l++;
        swap(a[l], a[r]);
    }
    Qsort(a, lo, l - 1);
    Qsort(a, l + 1, hi);
}
void insertionSort(int a[], int n)
{ // Sort a[0:n-1] using the insertion sort method.
    for (int i = 1; i < n; i++)
    { // insert a[i] into a[0:i-1]
        int t = a[i];
        int j;
        for (j = i; 0 < j && t < a[j - 1]; j--)
            a[j] = a[j - 1];
        a[j] = t;
    }
}