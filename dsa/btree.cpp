// author - newguo@sonaspy.cn
// coding - utf_8

#define SIZE 50
#include <bits/stdc++.h>
#include "dsa.h"
#define test() freopen("in", "r", stdin)

using namespace std;
using namespace dsa;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    srand(time(NULL));
    int b[SIZE];
    //generate(b, b + SIZE, [&]() { return rand() % 1000; });
    iota(b, b + SIZE, 0);
    vector<int> a(b, b + SIZE);
    btree<int> bt(6);
    for (auto i : a)
        bt.insert(i);
    clock_t startTime, endTime;
    //bt.printTree();
    startTime = clock();
    //cout << bt.size() << endl;
    //cout << bt.root()->key.size() << endl;
    //cout << bt.root()->child.size() << endl;
    cout << bt.search(a[23]) << endl;
    int c = 0;
    for (int i = 0; i < 10; i++)
        bt.erase(a[i]);
    bt.inorder();

    endTime = clock();
    cout << "The run time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}