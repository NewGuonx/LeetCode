// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class LRUCache
{
public:
    struct cacheNode
    {
        int key, val;
        cacheNode(int k, int v) : key(k), val(v){};
    };
    LRUCache(int capacity)
    {
        this->maxsize = capacity;
    }
    int get(int key)
    {
        if (cacheMAP.count(key))
        {
            cacheQ.splice(cacheQ.begin(), cacheQ, cacheMAP[key]);
            cacheMAP[key] = cacheQ.begin();
            return cacheMAP[key]->val;
        }
        return -1;
    }
    void put(int key, int value)
    {
        if (!cacheMAP.count(key))
        {
            if (cacheQ.size() == maxsize)
            {
                cacheMAP.erase(cacheQ.back().key);
                cacheQ.pop_back();
            }
            cacheQ.push_front(cacheNode(key, value));
            cacheMAP[key] = cacheQ.begin();
        }
        else
        {
            cacheMAP[key]->val = value;
            cacheQ.splice(cacheQ.begin(), cacheQ, cacheMAP[key]);
            cacheMAP[key] = cacheQ.begin();
        }
    }
    unordered_map<int, list<cacheNode>::iterator> cacheMAP;
    int maxsize;
    list<cacheNode> cacheQ;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}