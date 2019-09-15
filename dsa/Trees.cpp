// author - newguo@sonaspy.cn
// coding - utf_8

#include "dsa.h"

#define SIZE 100000
using namespace std;
using namespace newtree;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    srand(time(NULL));
    int b[SIZE];

    clock_t startTime, endTime;
    startTime = clock();
    int n;
    string s;
    //iota(b, b + n, 1);
    while (cin >> n && n != 0)
    {
        generate(b, b + n, [&]() { return rand() % 100; });
        vector<int> a(b, b + n), c = a, d;
        AVLTree<int> ax;
        ax.build(a);
        cin >> s;
        while (s != "q")
        {
            if (s[0] == 'v')
                ax.printTreeVertical();
            else
                ax.printTreeHorizon();
            cin >> s;
        }
    }

    endTime = clock();
    cout << "The run time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}