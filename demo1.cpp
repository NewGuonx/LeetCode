// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class ClassA
{
public:
    virtual ~ClassA(){};
    virtual void FunctionA(){};
};
class ClassB
{
public:
    virtual void FunctionB(){};
};
class ClassC : public ClassA, public ClassB
{
public:
};

ClassC aObject;
ClassA *pA = &aObject;
ClassB *pB = &aObject;
ClassC *pC = &aObject;
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}