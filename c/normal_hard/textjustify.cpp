// author -sonaspy@outlook.com 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> res;
        for (int i = 0; i < words.size();)
        {
            vector<string> tmp;
            int curWidth = 0;
            string new_word = "";
            while (i < words.size() && curWidth + words[i].size() + tmp.size() <= maxWidth)
            {
                curWidth = curWidth + words[i].size();
                tmp.push_back(words[i]);
                i++;
            }
            if (i < words.size())
            {
                if (tmp.size() == 1)
                {
                    new_word += tmp[0];
                    new_word += string(maxWidth - new_word.size(), ' ');
                    res.push_back(new_word);
                    continue;
                }
                int result = (maxWidth - curWidth) / (tmp.size() - 1), remainder = (maxWidth - curWidth) % (tmp.size() - 1);
                for (int j = 0; j < tmp.size(); j++)
                {
                    string sp(result, ' ');
                    if (j != tmp.size() - 1)
                    {
                        if (remainder-- > 0)
                            new_word = new_word + tmp[j] + sp + " ";
                        else
                            new_word = new_word + tmp[j] + sp;
                    }
                    else
                        new_word += tmp[j];
                }
                res.push_back(new_word);
            }
            else
            {
                for (int j = 0; j < tmp.size() - 1; j++)
                    new_word += tmp[j] + ' ';
                new_word += tmp[tmp.size() - 1];
                new_word += string(maxWidth - new_word.size(), ' ');
                res.push_back(new_word);
            }
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}