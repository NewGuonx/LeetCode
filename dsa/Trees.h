// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

using namespace std;

#ifndef __NEW_TREE__
#define __NEW_TREE__
namespace dsa
{
#define MAXCOL 1000
#define MAXROW 100000

template <typename T>
struct binode
{
    T val;
    binode *left, *right, *parent;
    int height, depth, ltag, rtag;
    binode(T x) : val(x), left(nullptr), right(nullptr), parent(nullptr), height(1), depth(1), ltag(0), rtag(0) {}
    bool inline is_l()
    {
        return parent && parent->left == this;
    }
    bool inline is_r()
    {
        return parent && parent->right == this;
    }
    bool inline isroot()
    {
        return parent == nullptr;
    }
};

template <typename T>
class bintree
{
protected:
    binode<T> *_ROOT, *tp1;
    unordered_set<binode<T> *> __memoryONode;
    deque<binode<T> *> q, nexq;
    int _cnt;
    bool isunique; // pre post build
    vector<vector<string>> disp_buf;
    inline int __height(binode<T> *root) { return root == nullptr ? 0 : root->height; }
    inline int __depth(binode<T> *root) { return root == nullptr ? 0 : root->depth; }
    inline void __updatedepth(binode<T> *root) { root->depth = __depth(root->parent) + 1; }
    inline void __updateheight(binode<T> *root) { root->height = max(__height(root->left), __height(root->right)) + 1; }
    inline int __factor(binode<T> *root) { return __height(root->left) - __height(root->right); }
    inline binode<T> *__getmax(binode<T> *root)
    {
        while (root->right)
            root = root->right;
        return root;
    }
    inline binode<T> *__getmin(binode<T> *root)
    {
        while (root->left)
            root = root->left;
        return root;
    }
    inline void __updateROOT(binode<T> *root)
    {
        this->_ROOT = root;
    }
    binode<T> *__build_pi(int root, int lo, int hi, binode<T> *p)
    {
        if (hi < lo)
            return nullptr;
        int i = lo;
        binode<T> *node = new binode<T>(preorder[root]);
        __memoryONode.insert(node);
        table[preorder[root]] = node;
        node->parent = p;
        __updatedepth(node);
        while (i < hi && inorder[i] != preorder[root])
            i++;
        node->left = __build_pi(root + 1, lo, i - 1, node);
        node->right = __build_pi(root + 1 + i - lo, i + 1, hi, node);
        __updateheight(node);
        return node;
    }
    void __print_horizon(binode<T> *root, int root_x, int root_y, int interval)
    {
        if (!root)
            return;
        int left_child = root_y - interval, right_child = root_y + interval;
        string tp = to_string(root->val);
        if (tp.size() == 1)
            tp.push_back(' ');
        disp_buf[root_x][root_y] = tp;
        if (root->left)
            disp_buf[root_x + 1][root_y - (interval + 1) / 2] = "/ ";
        if (root->right)
            disp_buf[root_x + 1][root_y + (interval + 1) / 2] = " \\";
        __print_horizon(root->left, root_x + 2, left_child, (interval >> 1));
        __print_horizon(root->right, root_x + 2, right_child, (interval >> 1));
    }
    void __print_vertical(binode<T> *root, int root_x, int root_y, int interval)
    { // root_y = 0;
        if (!root)
            return;
        int left_child = root_x + interval, right_child = root_x - interval;
        string tp = to_string(root->val);
        while (tp.size() < 4)
            tp.push_back(' ');
        disp_buf[root_x][root_y] = tp;
        if (root->left)
            disp_buf[root_x + (interval + 1) / 2][root_y + 1] = " \\  ";
        if (root->right)
            disp_buf[root_x - (interval + 1) / 2][root_y + 1] = " /  ";
        __print_vertical(root->left, left_child, root_y + 2, (interval >> 1));
        __print_vertical(root->right, right_child, root_y + 2, (interval >> 1));
    }
    binode<T> *__build_ip(int root, int lo, int hi, binode<T> *p)
    {
        if (hi < lo)
            return nullptr;
        int i = lo;
        binode<T> *node = new binode<T>(postorder[root]);
        __memoryONode.insert(node);
        table[postorder[root]] = node;
        node->parent = p;
        __updatedepth(node);
        while (i < hi && inorder[i] != postorder[root])
            i++;
        node->left = __build_ip(root - 1 + i - hi, lo, i - 1, node);
        node->right = __build_ip(root - 1, i + 1, hi, node);
        __updateheight(node);
        return node;
    }
    binode<T> *__build_pp(int leftOfpre, int rightOfpre, int leftOfpost, int rightOfpost)
    {
        if (leftOfpre > rightOfpre || leftOfpost > rightOfpost)
            return nullptr;
        binode<T> *root = new binode<T>(preorder[leftOfpre]);
        __memoryONode.insert(root);
        if (leftOfpre == rightOfpre)
            return root;
        int leftSubVal = preorder[leftOfpre + 1], i, sub_cnt;
        for (i = leftOfpost; i < rightOfpost && postorder[i] != leftSubVal; i++)
            ;
        sub_cnt = i - leftOfpost;
        if (i + 1 < rightOfpost) // 2 child
        {
            root->left = __build_pp(leftOfpre + 1, leftOfpre + sub_cnt + 1, leftOfpost, i);
            root->right = __build_pp(leftOfpre + sub_cnt + 2, rightOfpre, i + 1, rightOfpost - 1);
        }
        else
        {
            root->left = __build_pp(leftOfpre + 1, rightOfpre, leftOfpost, rightOfpost - 1);
            // only one child, default choose left
            isunique = 0;
        }
        return root;
    }
    binode<T> *__invert(binode<T> *root)
    {
        if (!root)
            return nullptr;
        binode<T> *tmp = __invert(root->right);
        root->right = __invert(root->left);
        root->left = tmp;
        return root;
    }
    void __del_leaf(binode<T> *&root, binode<T> *p)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            if (p)
            {
                if (root == p->left)
                    p->left = nullptr;
                if (root == p->right)
                    p->right = nullptr;
                this->__memoryONode.erase(root);
                delete root;
            }
            return;
        }
        __del_leaf(root->left, root);
        __del_leaf(root->right, root);
    }
    int __leafcount()
    {
        if (!this->_ROOT)
            return -1;
        int cnt = 0;
        this->q.push_back(this->_ROOT);
        while (this->q.size())
        {
            tp1 = this->q.front(), this->q.pop_front();
            if (!tp1->left && !tp1->right)
                cnt++;
            if (tp1->left)
                this->q.push_back(tp1->left);
            if (tp1->right)
                this->q.push_back(tp1->right);
        }
        this->q.clear();
        return cnt;
    }
    int __nodecount()
    {
        if (!this->_ROOT)
            return 0;
        int cnt = 0;
        this->q.push_back(this->_ROOT);
        while (this->q.size())
        {
            tp1 = this->q.front(), this->q.pop_front();
            cnt++;
            if (tp1->left)
                this->q.push_back(tp1->left);
            if (tp1->right)
                this->q.push_back(tp1->right);
        }
        this->q.clear();
        return cnt;
    }
    void __del_targetSub(binode<T> *root, int target)
    {
        binode<T> *x;
        if (root->val == target)
        {
            __del_allSub(root);
            return;
        }
        this->q.push_back(root);
        while (this->q.size())
        {
            x = this->q.front(), this->q.pop_front();
            if (x->val == target)
            {
                __del_allSub(x->left);
                __del_allSub(x->right);
                x->left = x->right = nullptr;
                continue;
            }
            if (x->left)
                this->q.push_back(x->left);
            if (x->right)
                this->q.push_back(x->right);
        }
        this->q.clear();
    }
    void __del_allSub(binode<T> *root)
    {
        if (!root)
            return;
        __del_allSub(root->left);
        __del_allSub(root->right);
        this->__memoryONode.erase(root);
        delete root;
    }
    bool __treeIdentical(binode<T> *T1, binode<T> *T2)
    {
        if (!T1 && !T2)
            return 1;
        if (!T1 || !T2 || T1->val != T2->val)
            return 0;
        bool lf = __treeIdentical(T1->left, T2->left);
        bool rf = __treeIdentical(T1->right, T2->right);
        return lf && rf;
    }
    bool __TreeSimilar(binode<T> *T1, binode<T> *T2)
    {
        if (!T1 && !T2)
            return 1;
        if (!T1 || !T2) // if wanna test the two trees is identical , plus "|| T1->val != T2->val"
            return 0;
        return __TreeSimilar(T1->left, T2->left) && __TreeSimilar(T1->right, T2->right);
    }
    void __tree2Infix(binode<string> *root, int depth, string &s)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
            s += root->val;
        else
        {
            if (depth)
                s.push_back('(');
            __tree2Infix(root->left, depth + 1, s);
            s += root->val;
            __tree2Infix(root->right, depth + 1, s);
            if (depth)
                s.push_back(')');
        }
    }
    template <class _Function>
    void __recur_pre(binode<T> *root, _Function f)
    {
        if (!root)
            return;
        f(root);
        __recur_pre(root->left, f);
        __recur_pre(root->right, f);
    }
    template <class _Function>
    void __recur_in(binode<T> *root, _Function f)
    {
        if (!root)
            return;
        __recur_in(root->left, f);
        f(root);
        __recur_in(root->right, f);
    }
    template <class _Function>
    void __recur_post(binode<T> *root, _Function f)
    {
        if (!root)
            return;
        __recur_post(root->left, f);
        __recur_post(root->right, f);
        f(root);
    }

    void __InThread(binode<T> *root, binode<T> *pre)
    {
        if (root)
        {
            __InThread(root->left, pre);
            if (!root->left)
            {
                root->ltag = 1;
                root->left = pre;
            }
            if (pre && !pre->right)
            {
                pre->rtag = 1;
                pre->right = root;
            }
            __InThread(root->right, root);
        }
    }
    double __op(double a, double b, char oper)
    {
        double res;
        switch (oper)
        {
        case '+':
            res = a + b;
            break;
        case '-':
            res = a - b;
            break;
        case '*':
            res = a * b;
            break;
        case '/':
            res = a / b;
            break;
        }
        return res;
    }
    double __infix_val(binode<string> *root)
    {
        if (!root)
            return 0;
        if (root->left && root->right)
        {
            double a = stof(__infix_val(root->left)), b = stof(__infix_val(root->right));
            return __op(a, b, root->val[0]);
        }
        return stof(root->val);
    }
    int __diameter()
    {
        q.push_back(this->_ROOT);
        int level = 0, last = 0;
        while (q.size())
        {
            if (q.size() > 1)
                last = level;
            while (q.size())
            {
                tp1 = q.front(), q.pop_front();
                if (tp1->left)
                    nexq.push_back(tp1->left);
                if (tp1->right)
                    nexq.push_back(tp1->right);
            }
            level++;
            swap(q, nexq);
        }
        this->q.clear(), this->nexq.clear();
        return last + level - 1;
    }

    void __update_member(binode<T> *root, binode<T> *p)
    {
        if (!root)
            return;
        root->parent = p;
        __updatedepth(root);
        __update_member(root->left, root);
        __update_member(root->right, root);
        __updateheight(root);
    }

public:
    unordered_map<T, binode<T> *> table;
    vector<T> preorder, inorder, postorder;
    bintree()
    {
        this->_ROOT = nullptr;
        this->isunique = true;
        this->q.clear(), this->nexq.clear();
        this->_cnt = 0;
    }
    inline bool const empty() { return this->_root == nullptr; }
    void printTreeHorizon()
    {
        if (!this->_ROOT)
            return;
        printf("🌲\n");
        if (this->_cnt > (1 << 8) - 1)
        {
            cout << " Too Many Node !\n";
            return;
        }
        this->disp_buf = vector<vector<string>>(40, vector<string>(MAXCOL, string(2, ' ')));
        __print_horizon(this->_ROOT, 0, pow(2, this->_ROOT->height - 1) - 1, pow(2, this->_ROOT->height - 2));
        int n = this->_ROOT->height * 2 - 1, i, j, breadth = pow(2, this->_ROOT->height) + 1;
        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < breadth; ++j)
                cout << disp_buf[i][j];
            cout << endl;
        }
        printf("🌲\n");
    }
    void printTreeVertical()
    {
        if (!this->_ROOT)
            return;
        if (this->_cnt > (1 << 15) - 1)
        {
            cout << " Too Many Node !\n";
            return;
        }
        printf("🌲\n");
        this->disp_buf = vector<vector<string>>(MAXROW, vector<string>(40, string(4, ' ')));
        __print_vertical(this->_ROOT, pow(2, this->_ROOT->height - 1) - 1, 0, pow(2, this->_ROOT->height - 2));
        int i, j, breadth = pow(2, this->_ROOT->height) + 1, n = this->_ROOT->height * 2 - 1;
        for (i = 0; i < breadth; ++i)
        {
            for (j = 0; j < n; ++j)
                cout << disp_buf[i][j];
            cout << endl;
        }
        printf("🌲\n");
    }

    inline binode<T> *root()
    {
        return this->_ROOT;
    }
    binode<T> *__buildcmp(int id, vector<int> &a)
    {
        if (a.size() - 1 < id)
            return nullptr;
        binode<T> *v = new binode<T>(a[id]);
        __memoryONode.insert(v);
        v->left = __buildcmp(id * 2 + 1, a);
        v->right = __buildcmp(id * 2 + 2, a);
        return v;
    }
    inline void build_cmp(vector<int> &a)
    {
        __updateROOT(__buildcmp(0, a));
        __update_status();
    }
    inline void build_pi(vector<int> &pr, vector<int> &in)
    {
        this->preorder = pr, this->inorder = in;
        __updateROOT(__build_pi(0, 0, pr.size() - 1, nullptr));
        this->_cnt = in.size();
    }
    inline void build_ip(vector<int> &in, vector<int> &po)
    {
        this->postorder = po, this->inorder = in;
        __updateROOT(__build_ip(in.size() - 1, 0, in.size() - 1, nullptr));
        this->_cnt = in.size();
    }
    inline void invert()
    {
        if (!this->_ROOT)
            return;
        __invert(this->_ROOT);
        __update_status();
    }
    inline void eraseLeaf()
    {
        if (!this->_ROOT)
            return;
        __del_leaf(this->_ROOT, nullptr);
        this->_cnt = __nodecount();
        __update_status();
    }
    inline int countleaf()
    {
        if (!this->_ROOT)
            return 0;
        return __leafcount();
    }
    inline int size()
    {
        return _cnt;
    }
    inline int height()
    {
        if (!this->_ROOT)
            return 0;
        return this->_ROOT->height;
    }
    inline void __update_status()
    {
        this->__update_member(_ROOT, nullptr);
    }
    inline int diam() { return __diameter(); }
    inline bool similar(bintree<T> T2)
    {
        return __TreeSimilar(this->_ROOT, T2.root());
    }
    inline bool identical(bintree<T> T2)
    {
        return __treeIdentical(this->_ROOT, T2.root());
    }
    inline bool symmetric()
    {
        if (!this->_ROOT)
            return true;
        return __TreeSimilar(this->_ROOT->left, this->_ROOT->right);
    }
    binode<T> *convert2list()
    {
        if (!this->_ROOT)
            return;
        vector<binode<T> *> ls;
        intrav([&](binode<T> *v) { ls.push_back(v); });
        auto p1 = ls.begin(), p2 = ls.begin() + 1;
        binode<T> *head = *p1;
        for (; p2 != ls.end(); p1++, p2++)
        {
            (*p1)->left = nullptr;
            (*p1)->right = (*p2);
        }
        (*p1)->right = (*p1)->left = nullptr;
        return head;
    }
    string tree2infix()
    {
        string s;
        __tree2Infix(this->_ROOT, 0, s);
        return s;
    }
    void eraseSubOf(T v)
    {
        if (!this->_ROOT)
            return;
        __del_targetSub(this->_ROOT, v);
    }
    double infixval()
    {
        return __infix_val(this->_ROOT);
    }
    bool iscmp()
    {
        if (!this->_ROOT)
            return true;
        binode<T> *root = this->_ROOT;
        this->q.push_back(root);
        while (this->q.size())
        {
            tp1 = this->q.front(), this->q.pop_front();
            if (tp1)
                this->q.push_back(tp1->left), this->q.push_back(tp1->right);
            else
                while (this->q.size())
                {
                    tp1 = this->q.front(), this->q.pop_front();
                    if (tp1)
                        return false;
                }
        }
        this->q.clear();
        return true;
    }
    inline void clear()
    {
        _ROOT = tp1 = nullptr;
        q.clear(), nexq.clear();
        _cnt = 0;
        isunique = 1;
        disp_buf.clear();
        for (auto &p : __memoryONode)
            delete p;
        __memoryONode.clear();
    }

    template <class _Function>
    void intrav(_Function f)
    {
        __recur_in(this->_ROOT, f);
    }
    template <class _Function>
    void pretrav(_Function f)
    {
        __recur_pre(this->_ROOT, f);
    }
    template <class _Function>
    void posttrav(_Function f)
    {
        __recur_post(this->_ROOT, f);
    }
    void inTrav()
    {
        vector<T> resSeq;
        stack<binode<T> *> s;
        binode<T> *root = this->_ROOT;
        if (!root)
            return;
        binode<T> *p = root;
        while (s.size() || p)
        {
            while (p)
            {
                s.push(p);
                p = p->left;
            }
            if (s.size())
            {
                p = s.top();
                s.pop();
                resSeq.push_back(p->val);
                p = p->right;
            }
        }
        this->inorder = resSeq;
    }
    void preTrav()
    {
        vector<T> resSeq;
        binode<T> *root = this->_ROOT;
        if (!root)
            return;
        stack<binode<T> *> s;
        s.push(root);
        while (s.size())
        {
            root = s.top(), s.pop();
            resSeq.push_back(root->val);
            if (root->right)
                s.push(root->right);
            if (root->left)
                s.push(root->left);
        }
        this->preorder = resSeq;
    }
    void postTrav()
    {
        vector<T> resSeq;
        binode<T> *root = this->_ROOT;
        if (!root)
            return;
        stack<pair<binode<T> *, bool>> s;
        s.push(make_pair(root, false));
        bool isMyTurn;
        while (s.size())
        {
            root = s.top().first, isMyTurn = s.top().second, s.pop();
            if (isMyTurn)
                resSeq.push_back(root->val);
            else
            {
                s.push(make_pair(root, true));
                if (root->right)
                    s.push(make_pair(root->right, false));
                if (root->left)
                    s.push(make_pair(root->left, false));
            }
        }
        this->postorder = resSeq;
    }
    binode<T> *get_LCA(binode<T> *p, binode<T> *q)
    {
        while (p->depth > q->depth)
            p = p->parent;
        while (q->depth > p->depth)
            q = q->parent;
        while (p != q)
            p = p->parent, q = q->parent;
        return p;
    }

    // T1 <-> T2  convertable, left <-> right;
    int Isomprphic(binode<T> *root1, binode<T> *root2)
    {
        if (!root1 && !root2)
            return 1;
        if ((!root1 && root2) || (!root2 && root1))
            return 0;
        if (root1->val != root2->val)
            return 0;
        if (!root1->left && !root2->left)
            return Isomprphic(root1->right, root2->right);
        if (root1->left && root2->left && root1->left->val == root2->left->val)
            return Isomprphic(root1->left, root2->left) && Isomprphic(root1->right, root2->right);
        else
            return Isomprphic(root1->left, root2->right) && Isomprphic(root1->right, root2->left);
    }
    ~bintree()
    {
        this->clear();
    }
};

// 后缀表达式 -> exp_tree
// stack : node*; 遇 oprand: build node then push, 遇operator: pop 2 item become its childs, then push, 2nd_pop item is left.
template <typename T>
class huffman : public bintree<T>
{
protected:
    int _wpl;
    struct __cmp
    {
        bool operator()(const binode<T> *a, const binode<T> *b) const { return a->val > b->val; }
    };
    void __build_hfm(vector<int> &data)
    {
        priority_queue<binode<T> *, vector<binode<T> *>, __cmp> pq;
        binode<T> *v, *w, *root;
        for (auto i : data)
        {
            binode<T> *v = new binode<T>(i);
            pq.push_back(v);
            this->__memoryONode.insert(v);
        }
        while (pq.size() > 1)
        {
            v = pq.top(), pq.pop_front();
            w = pq.top(), pq.pop_front();
            root = new binode<T>(v->val + w->val);
            this->__memoryONode.insert(root);
            root->left = v, root->right = w;
            pq.push_back(root);
        }
        this->__updateROOT(root);
    }
    void __wpl(binode<T> *root)
    {
        if (!root)
            return;
        if (root->left)
            _wpl += root->val;
        __wpl(root->left);
        __wpl(root->right);
    };

public:
    huffman()
    {
        _wpl = -1;
    }
    void build(vector<int> &a)
    {
        if (a.empty())
            return;
        __build_hfm(a);
    }
    inline void clear()
    {
        bintree<T>::clear();
        _wpl = 0;
    }
    int wpl()
    {
        if (_wpl == -1)
            __wpl(this->_ROOT);
        return _wpl;
    }
    ~huffman() { this->clear(); }
};
template <typename T>
class bstree : public bintree<T>
{
protected:
    binode<T> *_last;
    inline void __attAsL(binode<T> *&p, binode<T> *&lc)
    {
        p->left = lc;
        if (lc)
            lc->parent = p;
    }
    inline void __attAsR(binode<T> *&p, binode<T> *&rc)
    {
        p->right = rc;
        if (rc)
            rc->parent = p;
    }
    binode<T> *__search(binode<T> *&root, const T &v)
    {
        binode<T> *x = root;
        while (x)
        {
            if (x->val == v)
                break;
            this->_last = x;
            x = x->val < v ? x->right : x->left;
        }
        return x;
    }
    void __insert(binode<T> *&root, const T &v)
    {
        if (!root)
        {
            root = new binode<T>(v);
            this->__memoryONode.insert(root);
            this->_cnt++;
            return;
        }
        this->_last = nullptr;
        binode<T> *x = __search(root, v);
        if (x)
            return;
        x = new binode<T>(v);
        this->__memoryONode.insert(x);
        v < this->_last->val ? this->_last->left = x : this->_last->right = x;
        this->_cnt++;
    }
    bool __judge_avl(binode<T> *root)
    {
        if (!root)
            return true;
        bool f1 = __judge_avl(root->left);
        bool f2 = __judge_avl(root->right);
        this->__updateheight(root);
        return f1 && f2 && abs(this->__factor(root)) < 2;
    }

    binode<T> *__delete(binode<T> *&root, T x)
    {
        if (!root)
            return nullptr;
        if (x < root->val)
            root->left = __delete(root->left, x);
        else if (root->val < x)
            root->right = __delete(root->right, x);
        else
        {
            binode<T> *tmp;
            if (root->left && root->right)
            {
                tmp = this->__getmin(root->right);
                root->val = tmp->val;
                root->right = __delete(root->right, tmp->val);
            }
            else
            {
                tmp = root;
                root = root->left ? root->left : root->right;
                bintree<T>::__memoryONode.erase(tmp);
                delete tmp;
            }
        }
        return root;
    }

public:
    void build(vector<T> &a)
    {
        for (auto i : a)
            __insert(this->_ROOT, i);
        this->__update_status();
    }
    bool balanced()
    {
        return __judge_avl(this->_ROOT);
    }
    void erase(const T &val)
    {
        __delete(this->_ROOT, val);
        this->_cnt--;
    }
    void insert(const T &val)
    {
        __insert(this->_ROOT, val);
    }
    binode<T> *locate(const T &e)
    {
        this->_last = nullptr;
        return __search(this->_ROOT, e);
    }
    inline void clear()
    {
        bintree<T>::clear();
        this->_last = nullptr;
    }
    binode<T> *findLCA(T v1, T v2)
    {
        binode<T> *walk = this->_ROOT;
        while (walk)
        {
            if (v1 < walk->val && v2 < walk->val)
                walk = walk->left;
            else if (walk->val < v1 && walk->val < v2)
                walk = walk->right;
            else
                break;
        }
        return walk;
    }
    inline bool exist(const T &e)
    {
        return locate(e);
    }
    ~bstree() { this->clear(); }
};

template <typename T>
class avltree : public bstree<T>
{
public:
    void build(vector<T> &a)
    {
        for (auto i : a)
            __insert(this->_ROOT, i, nullptr);
        this->__update_status();
    }
    void erase(const T &val)
    {
        __delete(this->_ROOT, val);
        this->__update_status();
        this->_cnt--;
    }
    void insert(const T &val)
    {
        __insert(this->_ROOT, val, nullptr);
        this->__update_status();
    }
    inline void clear() { bstree<T>::clear(); }
    ~avltree()
    {
        this->clear();
    }

protected:
    inline void _zig(binode<T> *&root)
    {
        binode<T> *tmp = root->left;
        root->left = tmp->right;
        if (tmp->right)
            tmp->right->parent = root;
        tmp->right = root;
        tmp->parent = root->parent;
        root->parent = tmp;
        this->__updateheight(root);
        this->__updateheight(tmp);
        root = tmp;
    }
    inline void _zag(binode<T> *&root)
    {
        binode<T> *tmp = root->right;
        root->right = tmp->left;
        if (tmp->left)
            tmp->left->parent = root;
        tmp->left = root;
        tmp->parent = root->parent;
        root->parent = tmp;
        this->__updateheight(root);
        this->__updateheight(tmp);
        root = tmp;
    }
    inline void _zigzag(binode<T> *&root)
    {
        _zag(root->left);
        _zig(root);
    }
    inline void _zagzig(binode<T> *&root)
    {
        _zig(root->right);
        _zag(root);
    }
    void __insert(binode<T> *&root, const T &val, binode<T> *p)
    {
        if (!root)
        {
            root = new binode<T>(val);
            this->__memoryONode.insert(root);
            root->parent = p;
            this->_cnt++;
            return;
        }
        else if (val < root->val)
        {
            __insert(root->left, val, root);
            this->__updateheight(root);
            if (this->__factor(root) == 2)
                this->__factor(root->left) == 1 ? _zig(root) : _zigzag(root);
        }
        else if (val > root->val)
        {
            __insert(root->right, val, root);
            this->__updateheight(root);
            if (this->__factor(root) == -2)
                this->__factor(root->right) == -1 ? _zag(root) : _zagzig(root);
        }
    }

    binode<T> *__delete(binode<T> *&root, const T &val)
    {
        if (!root)
            return nullptr;
        if (val < root->val)
        {
            root->left = __delete(root->left, val);
            this->__updateheight(root);
            if (this->__factor(root) == -2)
                this->__factor(root->right) == -1 ? _zag(root) : _zagzig(root);
        }
        else if (root->val < val)
        {
            root->right = __delete(root->right, val);
            this->__updateheight(root);
            if (this->__factor(root) == 2)
                (this->__factor(root->left) == 1) ? _zig(root) : _zigzag(root);
        }
        else // find it
        {
            binode<T> *tmp;
            if (root->right && root->left)
            {
                if (this->__factor(root) > 0)
                {
                    tmp = this->__getmax(root->left);
                    root->val = tmp->val;
                    root->left = __delete(root->left, tmp->val);
                }
                else
                {
                    tmp = this->__getmin(root->right);
                    root->val = tmp->val;
                    root->right = __delete(root->right, tmp->val);
                }
            }
            else
            {
                tmp = root;
                root = root->left ? root->left : root->right;
                bintree<T>::__memoryONode.erase(tmp);
                delete tmp;
            }
        }
        return root;
    }
};

// template <class T>
// class splayTree : public bstree<T>
// { // still bug there
// protected:
//     binode<T> *__splay(binode<T> *&v)
//     {
//         if (!v)
//             return nullptr;
//         binode<T> *p, *g, *gg;
//         while (1)
//         {
//             p = v->parent;
//             if (!p)
//                 break;
//             g = p->parent;
//             if (!g)
//                 break;
//             if (v->is_l())
//                 if (p->is_l())
//                     this->__attAsL(g, p->right), this->__attAsL(p, v->right), this->__attAsR(p, g), this->__attAsR(v, p);
//                 else
//                     this->__attAsL(p, v->right), this->__attAsR(g, v->left), this->__attAsL(v, g), this->__attAsR(v, p);
//             else if (p->is_r())
//                 this->__attAsR(g, p->left), this->__attAsR(p, v->left), this->__attAsL(p, g), this->__attAsL(v, p);
//             else
//                 this->__attAsR(p, v->left), this->__attAsL(g, v->right), this->__attAsR(v, g), this->__attAsL(v, p);
//             if (!gg)
//                 v->parent = nullptr;
//             else
//                 g == gg->left ? this->__attAsL(gg, v) : this->__attAsR(gg, v);
//             this->__updateheight(g), this->__updateheight(p), this->__updateheight(v);
//         }
//         p = v->parent;
//         if (p)
//         {
//             if (v->is_l())
//                 this->__attAsL(p, v->right), this->__attAsR(v, p);
//             else
//                 this->__attAsR(p, v->left), this->__attAsL(v, p);
//             this->__updateheight(p), this->__updateheight(v);
//         }
//         v->parent = nullptr;
//         return v;
//     }

// public:
//     binode<T> *locate(const T &e)
//     {
//         this->_last = nullptr;
//         binode<T> *p = this->__search(this->_ROOT, e);
//         this->_ROOT = __splay(p ? p : this->_last);
//         return this->_ROOT;
//     }
// };

template <typename T>
struct bnode
{
    vector<T> key;
    vector<bnode<T> *> child; // always more 1 item than key
    bnode<T> *parent = nullptr;
    bnode()
    {
        parent = nullptr;
        child.push_back(nullptr);
    }
    bnode(T x, bnode<T> *lc = nullptr, bnode<T> *rc = nullptr)
    {
        parent = nullptr;
        key.push_back(x);
        child.resize(2);
        child[0] = lc, child[1] = rc;
        if (lc)
            lc->parent = this;
        if (rc)
            rc->parent = this;
    }
};

template <typename T>
class btree
{
protected:
    int _size, _order;
    bnode<T> *_root, *_last;
    unordered_set<bnode<T> *> _memoryOfNode;

    void __overfSolution(bnode<T> *v)
    {
        if (v->key.size() + 1 <= _order)
            return;
        int s = _order / 2;
        bnode<T> *u = new bnode<T>();

        // right split [0 1 2 |<3>| 4 5]
        u->child.insert(u->child.begin(), v->child.begin() + s + 1, v->child.begin() + _order + 1);
        v->child.erase(v->child.begin() + s + 1, v->child.begin() + _order + 1);

        u->key.insert(u->key.begin(), v->key.begin() + s + 1, v->key.begin() + _order);
        v->key.erase(v->key.begin() + s + 1, v->key.begin() + _order);

        if (v->child.front())
        {
            for (int j = 0; j < _order - s; j++)
                u->child[j]->parent = u;
        }
        bnode<T> *p = v->parent;
        if (!p)
        {
            p = new bnode<T>();
            _root = p;
            p->child[0] = v;
            v->parent = p;
        }

        int r = upper_bound(p->key.begin(), p->key.end(), v->key[0]) - p->key.begin();
        p->key.insert(p->key.begin() + r, *(v->key.begin() + s));
        v->key.erase(v->key.begin() + s);
        p->child.insert(p->child.begin() + r + 1, u);
        u->parent = p;

        __overfSolution(p);
    }

    void __underfSolution(bnode<T> *v)
    {
        if ((_order + 1) / 2 <= v->child.size())
            return;
        bnode<T> *p = v->parent;
        if (!p)
        {
            if (v->key.empty() && v->child[0])
            {
                _root = v->child[0];
                _root->parent = nullptr;
                v->child[0] = nullptr;
                _memoryOfNode.erase(v);
                delete v;
            }
            return;
        }
        int r = -1;
        while (p->child[++r] != v)
            ;
        if (0 < r)
        {
            bnode<T> *ls = p->child[r - 1];
            if ((_order + 1) / 2 < ls->child.size())
            {
                v->key.insert(v->key.begin(), p->key[r - 1]);
                p->key[r - 1] = ls->key.back();
                ls->key.pop_back();
                v->child.insert(v->child.begin(), ls->child.back());
                ls->child.pop_back();
                if (v->child[0])
                    v->child[0]->parent = v;
                return;
            }
        }
        if (r < p->key.size())
        {
            bnode<T> *rs = p->child[r + 1];
            if ((_order + 1) / 2 < rs->child.size())
            {
                v->key.insert(v->key.end(), p->key[r]);
                p->key[r] = rs->key.front();
                rs->key.erase(rs->key.begin());
                v->child.push_back(rs->child.front());
                rs->child.erase(rs->child.begin());
                if (v->child.back())
                    v->child.back()->parent = v;
                return;
            }
        }
        if (0 < r)
        {
            bnode<T> *ls = p->child[r - 1];
            ls->key.push_back(p->key[r - 1]);
            p->key.erase(p->key.begin() + r - 1);
            p->child.erase(p->child.begin() + r);

            ls->child.push_back(v->child.front());
            v->child.erase(v->child.begin());
            if (ls->child.back())
                ls->child.back()->parent = ls;
            ls->key.insert(ls->key.end(), v->key.begin(), v->key.end());
            ls->child.insert(ls->child.end(), v->child.begin(), v->child.end());
            for (auto &lsch : ls->child)
                if (lsch)
                    lsch->parent = ls;
            _memoryOfNode.erase(v);
            delete v;
        }
        else
        {
            bnode<T> *rs = p->child[r + 1];
            rs->key.insert(rs->key.begin(), p->key[r]);
            p->key.erase(p->key.begin() + r);
            p->child.erase(p->child.begin() + r);

            rs->child.insert(rs->child.begin(), v->child.back());
            v->child.pop_back();

            if (rs->child.front())
                rs->child.front()->parent = rs;
            rs->key.insert(rs->key.begin(), v->key.begin(), v->key.end());
            rs->child.insert(rs->child.begin(), v->child.begin(), v->child.end());

            for (auto &rsch : rs->child)
                if (rsch)
                    rsch->parent = rs;
            _memoryOfNode.erase(v);
            delete v;
        }
        __underfSolution(p);
    }

    inline void _output_node(bnode<T> *v)
    {
        cout << " ( ";
        for (auto i : v->key)
            cout << i << " ";
        cout << ") ";
    }

public:
    btree<T>(int order = 3) : _order(order), _size(0)
    {
        _root = new bnode<T>();
        _memoryOfNode.insert(_root);
    }
    ~btree()
    {
        this->clear();
    }
    inline void printTree()
    {
        bnode<T> *v = _root;
        queue<bnode<T> *> q, nexq;
        q.push(v);
        int le = 1;
        while (q.size())
        {
            printf("LeveL %d : ", le);
            while (q.size())
            {
                v = q.front(), q.pop();
                _output_node(v);
                for (auto chi : v->child)
                    if (chi)
                        nexq.push(chi);
            }
            cout << endl;
            le++;
            swap(q, nexq);
        }
    }
    inline void const clear()
    {
        for (auto &ptr : _memoryOfNode)
            delete ptr;
        _memoryOfNode.clear();
    }
    inline int const order() { return this->_order; }
    inline int const size() { return this->_size; }
    inline bnode<T> *root() { return this->_root; }
    inline bool const empty() { return this->_root == nullptr; }
    bnode<T> *search(const T &x)
    {
        bnode<T> *v = _root;
        _last = nullptr;
        while (v)
        {
            auto it = lower_bound(v->key.begin(), v->key.end(), x);
            int r = it - v->key.begin();
            if (it != v->key.end() && *it == x)
                return v;
            _last = v, v = v->child[r];
        }
        return nullptr;
    }
    void __inorder(bnode<T> * root)
    {
        if (!root)
            return;
        int i;
        for (i = 0; i < root->key.size(); i++)
        {
            __inorder(root->child[i]);
            cout << root->key[i] << " -> ";
        }
        for (; i < root->child.size(); i++)
            __inorder(root->child[i]);
    }

    void inorder()
    {
        __inorder(this->_root);
        cout << "nullptr\n";
    }
    bool insert(const T &x)
    {
        bnode<T> *v = search(x);
        if (v)
            return 0;
        int r = upper_bound(_last->key.begin(), _last->key.end(), x) - _last->key.begin();
        _last->key.insert(_last->key.begin() + r, x);
        _last->child.insert(_last->child.begin() + r + 1, nullptr);
        _size++;
        __overfSolution(_last); // key size <= m - 1
        return true;
    }
    bool erase(const T &x)
    {
        bnode<T> *v = search(x);
        if (!v)
            return false;
        int r = lower_bound(v->key.begin(), v->key.end(), x) - v->key.begin();
        if (v->child.front())
        {
            bnode<T> *u = v->child[r + 1];
            while (u->child[0])
                u = u->child[0];
            v->key[r] = u->key[0];
            v = u, r = 0;
        }
        v->key.erase(v->key.begin() + r);
        v->child.erase(v->child.begin() + 1 + r);
        _size--;
        __underfSolution(v);
        return true;
    }
};

template <typename T>
class rbtree
{
protected:

public:

};

template <typename T>
class heap
{
    // data[1....n] data[0] = INT_MAX
protected:
    vector<T> data;
    int _size;

    void __percDown(int pos)
    {
        T val = data[pos];
        int up = pos, down = 2 * pos;
        for (; down <= _size; up = down, down *= 2)
        {
            if (down < _size && data[down] < data[down + 1])
                ++down;
            if (data[down] > val)
                data[up] = data[down];
            else
                break;
        }
        data[up] = val;
    }

    void __buildHeap()
    {
        int i;
        for (i = _size / 2; i; --i)
            __percDown(i);
    }

public:
    heap()
    {
        _size = 0;
    }
    void push(const T &val)
    {
        data.push_back(val);
        _size++;
        int i = _size;
        for (; data[i / 2] < val; i /= 2)
            data[i] = data[i / 2];
        data[i] = val;
    }
    void pop()
    {
        if (_size == 1)
            return;
        iter_swap(data.begin() + 1, data.end() - 1);
        data.pop_back();
        _size--;
        __percDown(1);
    }
    T top()
    {
        return data[1];
    }
    int size()
    {
        return _size;
    }
    void build(vector<T> &a)
    {
        data.push_back(INT_MAX);
        data.insert(data.end(), a.begin(), a.end());
        _size = a.size();
        __buildHeap();
    }
};

}; // namespace dsa
#endif