// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        char c;
        bool exist = false;
        int src = 0, dst;
        words.push_back(beginWord);
        for (auto &i : wordList)
        {
            if (i == beginWord)
                continue;
            if (i == endWord)
            {
                dst = words.end() - words.begin();
                exist = true;
            }
            words.push_back(i);
        }
        if (!exist)
            return 0;
        this->MAP = vector<vector<int>>(words.size(), vector<int>());
        for (int i = 0; i < words.size(); i++)
        {
            string tmp = words[i];
            for (auto &j : words[i])
            {
                c = j;
                j = '*';
                generic_forms[words[i]].push_back(i);
                for (auto k : generic_forms[words[i]])
                {
                    if (i != k)
                        MAP[i].push_back(k), MAP[k].push_back(i);
                }
                j = c;
            }
        }
        deque<int> q, nexq;
        int ans = 0, v;
        vector<int> vis(words.size(), 0);
        q.push_back(src);
        exist = false;
        while (q.size())
        {
            ans++;
            while (q.size())
            {
                v = q.front(), q.pop_front();
                vis[v] = 1;
                for (auto i : MAP[v])
                    if (!vis[i])
                        nexq.push_back(i);
                if (v == dst)
                {
                    exist = true;
                    goto end;
                }
            }
            swap(q, nexq);
        }
    end:
        return exist ? ans : 0;
    }

private:
    vector<vector<int>> MAP;
    vector<string> words;
    unordered_map<string, vector<int>> generic_forms;
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}