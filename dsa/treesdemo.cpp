// author - newguo@sonaspy.cn
// coding - utf_8

#include "dsa.h"

#define SIZE 10
using namespace std;
using namespace dsa;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    srand(time(NULL));
    int b[SIZE];

    clock_t startTime, endTime;
    startTime = clock();
    int n = SIZE;
    string s;
    generate(b, b + n, [&]() { return rand() % 100; });
    //iota(b, b + n, 1);
    vector<int> a(b, b + n);
    avltree<int> ax;
    ax.build(a);
    ax.printTreeHorizon();
    cout << ax.balanced() << endl;
    // while (cin >> n && n != 0)
    // {

    //     cin >> s;
    //     while (s != "q")
    //     {
    //         if (s[0] == 'v')
    //             ax.printTreeVertical();
    //         else
    //             ax.printTreeHorizon();
    //         cin >> s;
    //     }
    // }

    endTime = clock();
    cout << "The run time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}