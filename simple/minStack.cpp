// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class MinStack
{
  public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        S.push(x);
        if (S_min.empty() || x <= S_min.top())
            S_min.push(x);
    }

    void pop()
    {

        if (S_min.top() == S.top())
            S_min.pop();
        S.pop();
    }

    int top()
    {
        return S.top();
    }

    int getMin()
    {
        return S_min.top();
    }

  private:
    stack<int> S, S_min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    MinStack ms;
    ms.push(10);
    ms.push(1);
    ms.push(4);
    ms.pop();
    return 0;
}