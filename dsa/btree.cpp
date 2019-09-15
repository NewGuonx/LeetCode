// author - newguo@sonaspy.cn
// coding - utf_8

#define SIZE 100
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
    generate(b, b + SIZE, [&]() { return rand() % 1000; });
    vector<int> a(b, b + SIZE);
    BTree<int> bt(4);
    for (auto i : a)
        bt.insert(i);
    clock_t startTime, endTime;
    bt.printTree();
    startTime = clock();
    //cout << bt.size() << endl;
    //cout << bt.root()->key.size() << endl;
    //cout << bt.root()->child.size() << endl;
    cout << bt.search(a[23]) << endl;

    endTime = clock();
    cout << "The run time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}