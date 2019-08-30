// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
typedef bitset<8> byte;
typedef bitset<4> block;
typedef vector<byte> stream;
class SymmetricCypher
{
public:
    typedef bitset<8> byte;
    typedef vector<byte> stream;
    SymmetricCypher()
    {
        generate_key();
    }
    string get_cypher(string s)
    {
        string cypher;
        for (int j = 0; j < s.size(); j++)
        {
            byte b(s[j]);
            block bk1, bk2;
            for (int i = 7, c = 0; i > 3; i--, c++)
                bk1[c] = b[i];
            for (int i = 3, c = 3; i > -1; i--, c--)
                bk2[c] = b[i];
            cout << b << endl;
            cout << bk1 << bk2 << endl;
            bk1 = encry_mp[bk1];
            bk2 = encry_mp[bk2];
            for (int i = 7, c = 3; i > 3; i--, c--)
                b[i] = bk1[c];
            for (int i = 3, c = 3; i > -1; i--, c--)
                b[i] = bk2[c];
            cout << bk1 << bk2 << endl;
            cout << b << endl;
            cout << endl;
            cypher.push_back(char(b.to_ulong()));
        }
        return cypher;
    }
    string get_text(string cypher)
    {
        string text;
        for (int i = 0; i < cypher.size(); i++)
        {
            byte b(cypher[i]);
            block bk1, bk2;
            for (int i = 7, c = 0; i > 3; i--, c++)
                bk1[c] = b[i];
            for (int i = 3, c = 0; i > -1; i--, c++)
                bk2[c] = b[i];
            bk1 = decry_mp[bk1];
            bk2 = decry_mp[bk2];
            for (int i = 7, c = 3; i > 3; i--, c--)
                b[i] = bk1[c];
            for (int i = 3, c = 3; i > 3; i--, c--)
                b[i] = bk2[c];
            text.push_back(char(b.to_ulong()));
        }
        return text;
    }

private:
    unordered_map<block, block> encry_mp, decry_mp;
    void generate_key()
    {
        for (int i = 0; i < 16; i++)
        {
            block b(i), b1;
            int tmp;
            while (decry_mp.count(b1))
            {
                tmp = rand() % 16;
                block bb(tmp);
                b1 = bb;
            }
            encry_mp[b] = b1;
            decry_mp[b1] = b;
        }
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    srand(time(NULL));
    SymmetricCypher demo;
    string c = demo.get_cypher("asdasd");
    cout << c;
    // cout << "Cypher Stream is : \n";
    // for (auto i : c)
    //     cout << i;
    // cout << endl;
    // cout << "text is : \n";
    // cout << demo.get_text(c);
    return 0;
}