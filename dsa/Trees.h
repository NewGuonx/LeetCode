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

enum RBColor
{
    red,
    blk
};
template <typename T>
class rbtree;
template <typename T>
class bstree;
template <typename T>
class avltree;
template <typename T>
class btree;
template <typename T>
class bintree;
template <typename T>
struct binode;

template <typename T>
static inline binode<T> *__getmax(binode<T> *opnv)
{
    while (opnv->rc)
        opnv = opnv->rc;
    return opnv;
}
template <typename T>
static inline binode<T> *__getmin(binode<T> *opnv)
{
    while (opnv->lc)
        opnv = opnv->lc;
    return opnv;
}

template <typename T>
struct binode
{
    T val;
    binode *lc, *rc, *parent;
    int height, depth, ltag, rtag;
    RBColor color;
    binode(const T &x) : val(x), lc(nullptr), rc(nullptr), parent(nullptr), height(0), depth(0), ltag(0), rtag(0) {}
    binode(const T &x, binode<T> *p) : val(x), lc(nullptr), rc(nullptr), parent(p), height(0) {}
    binode(const T &x, binode<T> *p, binode<T> *l, binode<T> *r) : val(x), lc(l), rc(r), parent(p), height(0) {}
    bool inline is_l()
    {
        return parent && parent->lc == this;
    }
    bool inline is_r()
    {
        return parent && parent->rc == this;
    }
    bool inline isroot()
    {
        return parent == nullptr;
    }
    bool inline has_r()
    {
        return rc != nullptr;
    }
    bool inline has_l()
    {
        return lc != nullptr;
    }
    bool inline has_lr()
    {
        return lc != nullptr && rc != nullptr;
    }
    bool inline is_leaf()
    {
        return !rc && !lc;
    }
    inline bool operator==(const binode *&bn) { return val == bn->val; }
    inline bool operator<(const binode *&bn) { return val < bn->val; }
    inline bool operator>(const binode *&bn) { return val > bn->val; }
    inline binode *successor()
    {
        return this->rc ? __getmin(this->rc) : nullptr;
    }
    inline binode *precessor()
    {
        return this->lc ? __getmax(this->lc) : nullptr;
    }
    inline binode *uncle() { this->parent->is_l() ? this->parent->parent->rc : this->parent->parent->lc; }

    inline void insert_l(const T &x)
    {
        lc = new binode(x, this);
    }
    inline void insert_r(const T &x)
    {
        rc = new binode(x, this);
    }
    int size()
    {
        int cnt = 0;
        binode *tp1;
        queue<binode *> q;
        q.push_back(this);
        while (q.size())
        {
            tp1 = q.front(), q.pop_front();
            cnt++;
            if (tp1->lc)
                q.push_back(tp1->lc);
            if (tp1->rc)
                q.push_back(tp1->rc);
        }
        return cnt;
    }
};

#define from_parent2(x) \
    ((x)->isroot() ? this->_root : ((x)->is_l() ? (x)->parent->lc : (x)->parent->rc))
#define nodeBalanced(x) ((-2 < _factor(x)) && (_factor(x) < 2))
// The higher of the two children
#define tallerchild(x) ( \
    _height((x)->lc) > _height((x)->rc) ? (x)->lc : (_height((x)->lc) < _height((x)->rc) ? (x)->rc : ((x)->is_l() ? (x)->lc : (x)->rc)))
#define _height(p) ((p != nullptr) ? (p)->height : -1)
#define _depth(p) ((p != nullptr) ? (p)->depth : -1)
#define _factor(p) ((_height(p->lc)) - (_height(p->rc)))
#define __release(p) ( delete (p), (p) = nullptr)

template <typename T>
class bintree
{
    friend class rbtree<T>;
    friend class avltree<T>;
    friend class bstree<T>;

protected:
    binode<T> *_root, *tp1;
    deque<binode<T> *> q, nexq;
    int _size;
    bool isunique; // pre post build
    vector<vector<string>> disp_buf;
    static inline void __updatedepth(binode<T> *&opnv) { opnv->depth = _depth(opnv->parent) + 1; }
    static inline void __updateheight(binode<T> *&opnv) { opnv->height = max(_height(opnv->lc), _height(opnv->rc)) + 1; }
    static inline void __updateheightabove(binode<T> *opnv)
    {
        while (opnv)
        {
            __updateheight(opnv);
            opnv = opnv->parent;
        }
    }
    static void __update_member(binode<T> *opnv, binode<T> *p)
    {
        if (!opnv)
            return;
        opnv->parent = p;
        __updatedepth(opnv);
        __update_member(opnv->lc, opnv);
        __update_member(opnv->rc, opnv);
        __updateheight(opnv);
    }
    inline void __update_status()
    {
        __update_member(_root, nullptr);
    }
    inline void __update_root(binode<T> *&opnv)
    {
        _root = opnv;
    }
    binode<T> *__build_pi(int opnv, int lo, int hi, binode<T> *p)
    {
        if (hi < lo)
            return nullptr;
        int i = lo;
        binode<T> *node = new binode<T>(preorder[opnv]);
        hashtable[preorder[opnv]] = node;
        node->parent = p;
        __updatedepth(node);
        while (i < hi && inorder[i] != preorder[opnv])
            i++;
        node->lc = __build_pi(opnv + 1, lo, i - 1, node);
        node->rc = __build_pi(opnv + 1 + i - lo, i + 1, hi, node);
        __updateheight(node);
        return node;
    }
    void __print_horizon(binode<T> *opnv, int root_x, int root_y, int interval)
    {
        if (!opnv)
            return;
        int left_child = root_y - interval, right_child = root_y + interval;
        string tp = to_string(opnv->val);
        if (tp.size() == 1)
            tp.push_back(' ');
        disp_buf[root_x][root_y] = tp;
        if (opnv->lc)
            disp_buf[root_x + 1][root_y - (interval + 1) / 2] = "/ ";
        if (opnv->rc)
            disp_buf[root_x + 1][root_y + (interval + 1) / 2] = " \\";
        __print_horizon(opnv->lc, root_x + 2, left_child, (interval >> 1));
        __print_horizon(opnv->rc, root_x + 2, right_child, (interval >> 1));
    }
    void __print_vertical(binode<T> *opnv, int root_x, int root_y, int interval)
    { // root_y = 0;
        if (!opnv)
            return;
        int left_child = root_x + interval, right_child = root_x - interval;
        string tp = to_string(opnv->val);
        while (tp.size() < 4)
            tp.push_back(' ');
        disp_buf[root_x][root_y] = tp;
        if (opnv->lc)
            disp_buf[root_x + (interval + 1) / 2][root_y + 1] = " \\  ";
        if (opnv->rc)
            disp_buf[root_x - (interval + 1) / 2][root_y + 1] = " /  ";
        __print_vertical(opnv->lc, left_child, root_y + 2, (interval >> 1));
        __print_vertical(opnv->rc, right_child, root_y + 2, (interval >> 1));
    }
    binode<T> *__build_ip(int opnv, int lo, int hi, binode<T> *p)
    {
        if (hi < lo)
            return nullptr;
        int i = lo;
        binode<T> *node = new binode<T>(postorder[opnv]);
        hashtable[postorder[opnv]] = node;
        node->parent = p;
        __updatedepth(node);
        while (i < hi && inorder[i] != postorder[opnv])
            i++;
        node->lc = __build_ip(opnv - 1 + i - hi, lo, i - 1, node);
        node->rc = __build_ip(opnv - 1, i + 1, hi, node);
        __updateheight(node);
        return node;
    }
    binode<T> *__build_pp(int leftOfpre, int rightOfpre, int leftOfpost, int rightOfpost)
    {
        if (leftOfpre > rightOfpre || leftOfpost > rightOfpost)
            return nullptr;
        binode<T> *opnv = new binode<T>(preorder[leftOfpre]);
        if (leftOfpre == rightOfpre)
            return opnv;
        int leftSubVal = preorder[leftOfpre + 1], i, sub_cnt;
        for (i = leftOfpost; i < rightOfpost && postorder[i] != leftSubVal; i++)
            ;
        sub_cnt = i - leftOfpost;
        if (i + 1 < rightOfpost) // 2 child
        {
            opnv->lc = __build_pp(leftOfpre + 1, leftOfpre + sub_cnt + 1, leftOfpost, i);
            opnv->rc = __build_pp(leftOfpre + sub_cnt + 2, rightOfpre, i + 1, rightOfpost - 1);
        }
        else
        {
            opnv->lc = __build_pp(leftOfpre + 1, rightOfpre, leftOfpost, rightOfpost - 1);
            // only one child, default choose left
            isunique = 0;
        }
        return opnv;
    }
    binode<T> *__invert(binode<T> *opnv)
    {
        if (!opnv)
            return nullptr;
        binode<T> *tmp = __invert(opnv->rc);
        opnv->rc = __invert(opnv->lc);
        opnv->lc = tmp;
        return opnv;
    }
    void __earse_leaf(binode<T> *&opnv, binode<T> *p)
    {
        if (!opnv)
            return;
        if (!opnv->lc && !opnv->rc)
        {
            if (p)
                __release(opnv);
            return;
        }
        __earse_leaf(opnv->lc, opnv);
        __earse_leaf(opnv->rc, opnv);
    }
    int __leafcount()
    {
        if (!this->_root)
            return -1;
        int cnt = 0;
        this->q.push_back(this->_root);
        while (this->q.size())
        {
            tp1 = this->q.front(), this->q.pop_front();
            if (!tp1->lc && !tp1->rc)
                cnt++;
            if (tp1->lc)
                this->q.push_back(tp1->lc);
            if (tp1->rc)
                this->q.push_back(tp1->rc);
        }
        this->q.clear();
        return cnt;
    }

    void __del_targetSub(binode<T> *opnv, int target)
    {
        binode<T> *x;
        if (opnv->val == target)
        {
            __del_allSub(opnv);
            return;
        }
        this->q.push_back(opnv);
        while (this->q.size())
        {
            x = this->q.front(), this->q.pop_front();
            if (x->val == target)
            {
                __del_allSub(x->lc);
                __del_allSub(x->rc);
                x->lc = x->rc = nullptr;
                continue;
            }
            if (x->lc)
                this->q.push_back(x->lc);
            if (x->rc)
                this->q.push_back(x->rc);
        }
        this->q.clear();
    }
    void __del_allSub(binode<T> *opnv)
    {
        if (!opnv)
            return;
        __del_allSub(opnv->lc);
        __del_allSub(opnv->rc);
        __release(opnv);
    }
    bool __treeIdentical(binode<T> *T1, binode<T> *T2)
    {
        if (!T1 && !T2)
            return 1;
        if (!T1 || !T2 || T1->val != T2->val)
            return 0;
        bool lf = __treeIdentical(T1->lc, T2->lc);
        bool rf = __treeIdentical(T1->rc, T2->rc);
        return lf && rf;
    }
    bool __TreeSimilar(binode<T> *T1, binode<T> *T2)
    {
        if (!T1 && !T2)
            return 1;
        if (!T1 || !T2) // if wanna test the two trees is identical , plus "|| T1->val != T2->val"
            return 0;
        return __TreeSimilar(T1->lc, T2->lc) && __TreeSimilar(T1->rc, T2->rc);
    }
    void __tree2Infix(binode<string> *opnv, int depth, string &s)
    {
        if (!opnv)
            return;
        if (!opnv->lc && !opnv->rc)
            s += opnv->val;
        else
        {
            if (depth)
                s.push_back('(');
            __tree2Infix(opnv->lc, depth + 1, s);
            s += opnv->val;
            __tree2Infix(opnv->rc, depth + 1, s);
            if (depth)
                s.push_back(')');
        }
    }
    template <class _Function>
    void __recur_pre(binode<T> *opnv, _Function f)
    {
        if (!opnv)
            return;
        f(opnv);
        __recur_pre(opnv->lc, f);
        __recur_pre(opnv->rc, f);
    }
    template <class _Function>
    void __recur_in(binode<T> *opnv, _Function f)
    {
        if (!opnv)
            return;
        __recur_in(opnv->lc, f);
        f(opnv);
        __recur_in(opnv->rc, f);
    }
    template <class _Function>
    void __recur_post(binode<T> *opnv, _Function f)
    {
        if (!opnv)
            return;
        __recur_post(opnv->lc, f);
        __recur_post(opnv->rc, f);
        f(opnv);
    }

    void __InThread(binode<T> *opnv, binode<T> *pre)
    {
        if (opnv)
        {
            __InThread(opnv->lc, pre);
            if (!opnv->lc)
            {
                opnv->ltag = 1;
                opnv->lc = pre;
            }
            if (pre && !pre->rc)
            {
                pre->rtag = 1;
                pre->rc = opnv;
            }
            __InThread(opnv->rc, opnv);
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
    double __infix_val(binode<string> *opnv)
    {
        if (!opnv)
            return 0;
        if (opnv->lc && opnv->rc)
        {
            double a = stof(__infix_val(opnv->lc)), b = stof(__infix_val(opnv->rc));
            return __op(a, b, opnv->val[0]);
        }
        return stof(opnv->val);
    }
    int __diameter()
    {
        q.push_back(this->_root);
        int level = 0, last = 0;
        while (q.size())
        {
            if (q.size() > 1)
                last = level;
            while (q.size())
            {
                tp1 = q.front(), q.pop_front();
                if (tp1->lc)
                    nexq.push_back(tp1->lc);
                if (tp1->rc)
                    nexq.push_back(tp1->rc);
            }
            level++;
            swap(q, nexq);
        }
        this->q.clear(), this->nexq.clear();
        return last + level - 1;
    }

public:
    unordered_map<T, binode<T> *> hashtable;
    vector<T> preorder, inorder, postorder;
    bintree()
    {
        this->_root = nullptr;
        this->isunique = true;
        this->q.clear(), this->nexq.clear();
        this->_size = 0;
    }
    ~bintree()
    {
        this->clear();
    }

    inline bool const empty() const { return this->_root == nullptr; }
    inline binode<T> *root() { return this->_root; }
    inline int size() const { return _size; }
    inline int diam() { return __diameter(); }
    inline int height() const
    {
        if (!_root)
            return 0;
        return _root->height;
    }
    inline void clear()
    {
        _root = tp1 = nullptr;
        q.clear(), nexq.clear();
        _size = 0;
        isunique = 1;
        disp_buf.clear();
    }

    void printTreeHorizon()
    {
        if (!this->_root)
            return;
        printf("🌲\n");
        if (this->_size > (1 << 8) - 1)
        {
            cout << " Too Many Node !\n";
            return;
        }
        this->disp_buf = vector<vector<string>>(40, vector<string>(MAXCOL, string(2, ' ')));
        __print_horizon(this->_root, 0, pow(2, this->_root->height) - 1, pow(2, this->_root->height - 1));
        int n = this->_root->height * 2 + 1, i, j, breadth = pow(2, this->_root->height + 1) + 1;
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
        if (!this->_root)
            return;
        if (this->_size > (1 << 15) - 1)
        {
            cout << " Too Many Node !\n";
            return;
        }
        printf("🌲\n");
        this->disp_buf = vector<vector<string>>(MAXROW, vector<string>(40, string(4, ' ')));
        __print_vertical(this->_root, pow(2, this->_root->height) - 1, 0, pow(2, this->_root->height - 1));
        int i, j, breadth = pow(2, this->_root->height + 1) + 1, n = this->_root->height * 2 + 1;
        for (i = 0; i < breadth; ++i)
        {
            for (j = 0; j < n; ++j)
                cout << disp_buf[i][j];
            cout << endl;
        }
        printf("🌲\n");
    }
    binode<T> *__buildcmp(int id, vector<int> &a)
    {
        if (a.size() - 1 < id)
            return nullptr;
        binode<T> *opnv = new binode<T>(a[id]);
        opnv->lc = __buildcmp(id * 2 + 1, a);
        opnv->rc = __buildcmp(id * 2 + 2, a);
        return opnv;
    }
    inline void build_cmp(vector<int> &a)
    {
        __update_root(__buildcmp(0, a));
        bintree<T>::__update_status();
    }
    inline void build_pi(vector<int> &pr, vector<int> &in)
    {
        this->preorder = pr, this->inorder = in;
        __update_root(__build_pi(0, 0, pr.size() - 1, nullptr));
        this->_size = in.size();
    }
    inline void build_ip(vector<int> &in, vector<int> &po)
    {
        this->postorder = po, this->inorder = in;
        __update_root(__build_ip(in.size() - 1, 0, in.size() - 1, nullptr));
        this->_size = in.size();
    }
    inline void invert()
    {
        if (!this->_root)
            return;
        __invert(this->_root);
        bintree<T>::__update_status();
    }
    inline void earse_leaf()
    {
        if (!_root)
            return;
        __earse_leaf(_root, nullptr);
        _size = _root ? _root->size() : 0;
        __update_status();
    }
    inline int leafsize()
    {
        if (!this->_root)
            return 0;
        return __leafcount();
    }
    inline bool similar(bintree<T> T2)
    {
        return __TreeSimilar(this->_root, T2.root());
    }
    inline bool identical(bintree<T> T2)
    {
        return __treeIdentical(this->_root, T2.root());
    }
    inline bool symmetric()
    {
        if (!this->_root)
            return true;
        return __TreeSimilar(this->_root->lc, this->_root->rc);
    }
    binode<T> *convert2list()
    {
        if (!this->_root)
            return;
        vector<binode<T> *> ls;
        intrav([&](binode<T> *opnv) { ls.push_back(opnv); });
        auto p1 = ls.begin(), p2 = ls.begin() + 1;
        binode<T> *head = *p1;
        for (; p2 != ls.end(); p1++, p2++)
        {
            (*p1)->lc = nullptr;
            (*p1)->rc = (*p2);
        }
        (*p1)->rc = (*p1)->lc = nullptr;
        return head;
    }
    string tree2infix()
    {
        string s;
        __tree2Infix(this->_root, 0, s);
        return s;
    }
    void eraseSubOf(const T &x)
    {
        if (!this->_root)
            return;
        __del_targetSub(this->_root, x);
    }
    double infixval()
    {
        return __infix_val(this->_root);
    }
    bool iscmp()
    {
        if (!this->_root)
            return true;
        binode<T> *opnv = this->_root;
        this->q.push_back(opnv);
        while (this->q.size())
        {
            tp1 = this->q.front(), this->q.pop_front();
            if (tp1)
                this->q.push_back(tp1->lc), this->q.push_back(tp1->rc);
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
    template <class _Function>
    void intrav(_Function f)
    {
        __recur_in(this->_root, f);
    }
    template <class _Function>
    void pretrav(_Function f)
    {
        __recur_pre(this->_root, f);
    }
    template <class _Function>
    void posttrav(_Function f)
    {
        __recur_post(this->_root, f);
    }
    void inTrav()
    {
        vector<T> resSeq;
        stack<binode<T> *> s;
        binode<T> *opnv = this->_root;
        if (!opnv)
            return;
        binode<T> *p = opnv;
        while (s.size() || p)
        {
            while (p)
            {
                s.push(p);
                p = p->lc;
            }
            if (s.size())
            {
                p = s.top();
                s.pop();
                resSeq.push_back(p->val);
                p = p->rc;
            }
        }
        this->inorder = resSeq;
    }
    void preTrav()
    {
        vector<T> resSeq;
        binode<T> *opnv = this->_root;
        if (!opnv)
            return;
        stack<binode<T> *> s;
        s.push(opnv);
        while (s.size())
        {
            opnv = s.top(), s.pop();
            resSeq.push_back(opnv->val);
            if (opnv->rc)
                s.push(opnv->rc);
            if (opnv->lc)
                s.push(opnv->lc);
        }
        this->preorder = resSeq;
    }
    void postTrav()
    {
        vector<T> resSeq;
        binode<T> *opnv = this->_root;
        if (!opnv)
            return;
        stack<pair<binode<T> *, bool>> s;
        s.push(make_pair(opnv, false));
        bool isMyTurn;
        while (s.size())
        {
            opnv = s.top().first, isMyTurn = s.top().second, s.pop();
            if (isMyTurn)
                resSeq.push_back(opnv->val);
            else
            {
                s.push(make_pair(opnv, true));
                if (opnv->rc)
                    s.push(make_pair(opnv->rc, false));
                if (opnv->lc)
                    s.push(make_pair(opnv->lc, false));
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
        if (!root1->lc && !root2->lc)
            return Isomprphic(root1->rc, root2->rc);
        if (root1->lc && root2->lc && root1->lc->val == root2->lc->val)
            return Isomprphic(root1->lc, root2->lc) && Isomprphic(root1->rc, root2->rc);
        else
            return Isomprphic(root1->lc, root2->rc) && Isomprphic(root1->rc, root2->lc);
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
        binode<T> *opnv, *w, *root;
        for (auto i : data)
        {
            binode<T> *opnv = new binode<T>(i);
            pq.push_back(opnv);
        }
        while (pq.size() > 1)
        {
            opnv = pq.top(), pq.pop_front();
            w = pq.top(), pq.pop_front();
            root = new binode<T>(opnv->val + w->val);
            root->lc = opnv, root->rc = w;
            pq.push_back(root);
        }
        this->__update_root(root);
    }
    void __wpl(binode<T> *opnv)
    {
        if (!opnv)
            return;
        if (opnv->lc)
            _wpl += opnv->val;
        __wpl(opnv->lc);
        __wpl(opnv->rc);
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
            __wpl(this->_root);
        return _wpl;
    }
    ~huffman() { this->clear(); }
};

template <typename T>
class bstree : public bintree<T>
{
protected:
    binode<T> *_last;
    inline binode<T> *___rearrange(binode<T> *&a, binode<T> *&b, binode<T> *&c, binode<T> *&t0, binode<T> *&t1, binode<T> *&t2, binode<T> *&t3)
    {
        a->lc = t0;
        if (t0)
            t0->parent = a;
        a->rc = t1;
        if (t1)
            t1->parent = a;
        bintree<T>::__updateheight(a);
        c->lc = t2;
        if (t2)
            t2->parent = c;
        c->rc = t3;
        if (t3)
            t3->parent = c;
        bintree<T>::__updateheight(c);
        b->lc = a, a->parent = b, b->rc = c, c->parent = b;
        bintree<T>::__updateheight(b);
        return b;
    }
    inline binode<T> *__rotate_at(binode<T> *opnv)
    {
        binode<T> *p = opnv->parent, *g = p->parent;
        if (p->is_l())
        {
            if (opnv->is_l())
            { // ll
                p->parent = g->parent;
                return ___rearrange(opnv, p, g, opnv->lc, opnv->rc, p->rc, g->rc);
            }
            //lr
            opnv->parent = g->parent;
            return ___rearrange(p, opnv, g, p->lc, opnv->lc, opnv->rc, g->rc);
        }
        if (opnv->is_r())
        { //rr
            p->parent = g->parent;
            return ___rearrange(g, p, opnv, g->lc, p->lc, opnv->lc, opnv->rc);
        }
        opnv->parent = g->parent; // rl
        return ___rearrange(g, opnv, p, g->lc, opnv->lc, opnv->rc, p->rc);
    }
    inline void __attAsL(binode<T> *&p, binode<T> *&lc)
    {
        p->lc = lc;
        if (lc)
            lc->parent = p;
    }
    inline void __attAsR(binode<T> *&p, binode<T> *&rc)
    {
        p->rc = rc;
        if (rc)
            rc->parent = p;
    }
    bool __judge_avl(binode<T> *opnv, binode<T> *&p)
    {
        if (!opnv)
            return true;
        bool f1, f2, f;
        f1 = __judge_avl(opnv->lc, p);
        f = nodeBalanced(opnv) && (p == nullptr || p->val < opnv->val);
        p = opnv;
        f2 = __judge_avl(opnv->rc, p);
        return f1 && f2 & f;
    }
    binode<T> *&__search(binode<T> *&opnv, const T &x)
    {
        if (!opnv || x == opnv->val)
            return opnv;
        _last = opnv;
        return __search(x < opnv->val ? opnv->lc : opnv->rc, x);
    }

    binode<T> *__erase(binode<T> *&opnv, const T &x)
    {
        if (!opnv)
            return nullptr;
        if (x < opnv->val)
            opnv->lc = __erase(opnv->lc, x);
        else if (opnv->val < x)
            opnv->rc = __erase(opnv->rc, x);
        else
        {
            binode<T> *tmp;
            if (opnv->lc && opnv->rc)
            {
                tmp = opnv->successor();
                opnv->val = tmp->val;
                opnv->rc = __erase(opnv->rc, tmp->val);
            }
            else
            {
                tmp = opnv;
                opnv = opnv->lc ? opnv->lc : opnv->rc;
                __release(tmp);
            }
        }
        return opnv;
    }
    //return is delnode's succ ，last is delnode's parent
    static binode<T> *__erase_at(binode<T> *&opnv, binode<T> *&last)
    {
        binode<T> *w = opnv, *succ = nullptr;
        if (!opnv->has_l())
        {
            opnv = opnv->rc;
            succ = opnv;
        }
        else if (!opnv->has_r())
        {
            opnv = opnv->lc;
            succ = opnv;
        }
        else
        {
            w = w->successor();
            swap(opnv->val, w->val);
            binode<T> *u = w->parent;
            succ = w->rc;
            u == opnv ? u->rc = succ : u->lc = succ;
        }
        last = w->parent;
        __release(w);
        return succ;
    }

public:
    ~bstree() { this->clear(); }
    void build(vector<T> &a)
    {
        for (auto &i : a)
            insert(i);
        this->__update_status();
    }
    bool balanced()
    {
        binode<T> *p = nullptr;
        return __judge_avl(this->_root, p);
    }
    bool erase(const T &x)
    {
        binode<T> *&w = search(x);
        if (!w)
            return false;
        __erase_at(w, _last);
        this->__updateheightabove(_last);
        this->_size--;
        return true;
    }
    bool insert(const T &x)
    {
        binode<T> *&w = search(x);
        if (w)
            return false;
        w = new binode<T>(x, _last);
        this->_size++;
        this->__updateheightabove(w);
        return true;
    }

    binode<T> *&search(const T &x)
    {
        _last = nullptr;
        return __search(this->_root, x);
    }
    inline void clear()
    {
        bintree<T>::clear();
        _last = nullptr;
    }
    binode<T> *findLCA(const T &v1, const T &v2)
    {
        binode<T> *walk = this->_root;
        while (walk)
        {
            if (v1 < walk->val && v2 < walk->val)
                walk = walk->lc;
            else if (walk->val < v1 && walk->val < v2)
                walk = walk->rc;
            else
                break;
        }
        return walk;
    }
};

template <typename T>
class avltree : public bstree<T>
{
public:
    void build(vector<T> &a)
    {
        for (auto i : a)
            insert(i);
        bintree<T>::__update_status();
    }
    void erase(const T &x)
    {
        __erase(this->_root, x);
        bintree<T>::__update_status();
        this->_size--;
    }
    void insert(const T &x)
    {
        __insert(this->_root, x, nullptr);
    }

    // bool insert(const T &x)
    // {
    //     binode<T> *&w = bstree<T>::search(x);
    //     if (w)
    //         return false;
    //     w = new binode<T>(x, this->_last);
    //     this->_size++;
    //     binode<T> *g = this->_last;
    //     for (; g != nullptr; g = g->parent)
    //     {
    //         if (!nodeBalanced(g))
    //         {
    //             from_parent2(g) = __rotate_at(tallerchild(tallerchild(g)));
    //             break;
    //         }
    //         bintree<T>::__updateheight(g);
    //     }
    //     return true;
    // }
    // bool erase(const T &x)
    // {
    // }
    inline void clear() { bstree<T>::clear(); }
    ~avltree()
    {
        this->clear();
    }

protected:
    inline void _zig(binode<T> *&opnv)
    {
        binode<T> *tmp = opnv->lc;
        opnv->lc = tmp->rc;
        if (tmp->rc)
            tmp->rc->parent = opnv;
        tmp->rc = opnv;
        tmp->parent = opnv->parent;
        opnv->parent = tmp;
        bintree<T>::__updateheight(opnv);
        bintree<T>::__updateheight(tmp);
        opnv = tmp;
    }
    inline void _zag(binode<T> *&opnv)
    {
        binode<T> *tmp = opnv->rc;
        opnv->rc = tmp->lc;
        if (tmp->lc)
            tmp->lc->parent = opnv;
        tmp->lc = opnv;
        tmp->parent = opnv->parent;
        opnv->parent = tmp;
        bintree<T>::__updateheight(opnv);
        bintree<T>::__updateheight(tmp);
        opnv = tmp;
    }
    inline void _zigzag(binode<T> *&opnv)
    {
        _zag(opnv->lc);
        _zig(opnv);
    }
    inline void _zagzig(binode<T> *&opnv)
    {
        _zig(opnv->rc);
        _zag(opnv);
    }
    void __insert(binode<T> *&opnv, const T &x, binode<T> *p)
    {
        if (!opnv)
        {
            opnv = new binode<T>(x);
            opnv->parent = p;
            this->_size++;
            return;
        }
        else if (x < opnv->val)
        {
            __insert(opnv->lc, x, opnv);
            bintree<T>::__updateheight(opnv);
            if (_factor(opnv) == 2)
                _factor(opnv->lc) == 1 ? _zig(opnv) : _zigzag(opnv);
        }
        else if (x > opnv->val)
        {
            __insert(opnv->rc, x, opnv);
            bintree<T>::__updateheight(opnv);
            if (_factor(opnv) == -2)
                _factor(opnv->rc) == -1 ? _zag(opnv) : _zagzig(opnv);
        }
    }

    binode<T> *__erase(binode<T> *&opnv, const T &x)
    {
        if (!opnv)
            return nullptr;
        if (x < opnv->val)
        {
            opnv->lc = __erase(opnv->lc, x);
            bintree<T>::__updateheight(opnv);
            if (_factor(opnv) == -2)
                _factor(opnv->rc) == -1 ? _zag(opnv) : _zagzig(opnv);
        }
        else if (opnv->val < x)
        {
            opnv->rc = __erase(opnv->rc, x);
            bintree<T>::__updateheight(opnv);
            if (_factor(opnv) == 2)
                (_factor(opnv->lc) == 1) ? _zig(opnv) : _zigzag(opnv);
        }
        else // find it
        {
            binode<T> *tmp;
            if (opnv->rc && opnv->lc)
            {
                if (_factor(opnv) > 0)
                {
                    tmp = opnv->precessor();
                    opnv->val = tmp->val;
                    opnv->lc = __erase(opnv->lc, tmp->val);
                }
                else
                {
                    tmp = opnv->successor();
                    opnv->val = tmp->val;
                    opnv->rc = __erase(opnv->rc, tmp->val);
                }
            }
            else
            {
                tmp = opnv;
                opnv = opnv->lc ? opnv->lc : opnv->rc;
                __release(tmp);
            }
        }
        return opnv;
    }
};

template <class T>
class spltree : public bstree<T>
{ 
protected:
    binode<T> *__splay(binode<T> *opnv)
    {
        if (!opnv)
            return nullptr;
        binode<T> *p, *g, *gg;
        while (1)
        {
            if (!opnv->parent)
                break;
            p = opnv->parent;
            if (!p->parent)
                break;
            g = p->parent;
            gg = g->parent;
            if (opnv->is_l())
            {
                if (p->is_l())
                    this->__attAsL(g, p->rc), this->__attAsL(p, opnv->rc), this->__attAsR(p, g), this->__attAsR(opnv, p);
                else
                    this->__attAsL(p, opnv->rc), this->__attAsR(g, opnv->lc), this->__attAsL(opnv, g), this->__attAsR(opnv, p);
            }
            else if (p->is_r())
                this->__attAsR(g, p->lc), this->__attAsR(p, opnv->lc), this->__attAsL(p, g), this->__attAsL(opnv, p);
            else
                this->__attAsR(p, opnv->lc), this->__attAsL(g, opnv->rc), this->__attAsR(opnv, g), this->__attAsL(opnv, p);
            if (!gg)
                opnv->parent = nullptr;
            else
                g == gg->lc ? this->__attAsL(gg, opnv) : this->__attAsR(gg, opnv);
            bintree<T>::__updateheight(g), bintree<T>::__updateheight(p), bintree<T>::__updateheight(opnv);
        }
        p = opnv->parent;
        if (p)
        {
            if (opnv->is_l())
                this->__attAsL(p, opnv->rc), this->__attAsR(opnv, p);
            else
                this->__attAsR(p, opnv->lc), this->__attAsL(opnv, p);
            bintree<T>::__updateheight(p), bintree<T>::__updateheight(opnv);
        }
        opnv->parent = nullptr;
        return opnv;
    }

public:
    void build(vector<T> &a)
    {
        for (auto data : a)
            insert(data);
        this->__update_status();
    }
    binode<T> *search(const T &e)
    {
        this->_last = nullptr;
        binode<T> *p = this->__search(this->_root, e);
        this->_root = __splay(p ? p : this->_last);
        return this->_root;
    }
    bool insert(const T &x)
    {
        if (!this->_root)
        {
            this->_size++;
            this->_root = new binode<T>(x);
            return true;
        }
        binode<T> *w = search(x), *t;
        if (w->val == x)
            return false;
        this->_size++;
        t = this->_root;
        if (this->_root->val < x)
        {
            t->parent = (this->_root = new binode<T>(x, nullptr, t, t->rc));
            if (t->has_r())
            {
                t->rc->parent = this->_root;
                t->rc = nullptr;
            }
        }
        else
        {
            t->parent = (this->_root = new binode<T>(x, nullptr, t->lc, t));
            if (t->has_l())
            {
                t->lc->parent = this->_root;
                t->lc = nullptr;
            }
        }
        this->__updateheightabove(t);
        return true;
    }
    bool erase(const T &x)
    {
        if(!this->__root || (x != search(x)->val))
            return 0;
        binode<T> *w = this->_root, *t, *lt;
        if (!(this->_root->has_l()))
        {
            this->_root = this->_root->rc;
            if (this->_root)
                this->_root->parent = nullptr;
        }
        else if (!(this->_root->has_r()))
        {
            this->_root = this->_root->lc;
            if (this->_root)
                this->_root->parent = nullptr;
        }
        else
        {
            lt = this->_root->lc;
            lt->parent = nullptr;
            this->_root->lc = nullptr;
            this->_root = this->_root->rc;
            this->_root->parent = nullptr;
            search(w->val);
            this->_root->lc = lt;
            lt->parent = this->_root;
        }

    }
};

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
    bnode(const T &x, bnode *lc = nullptr, bnode *rc = nullptr)
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
    void __overfSolution(bnode<T> *opnv)
    {
        if (opnv->key.size() <= _order - 1)
            return;
        int s = _order / 2;
        bnode<T> *u = new bnode<T>();

        // right split [0 1 2 |<3>| 4 5]
        u->child.insert(u->child.begin(), opnv->child.begin() + s + 1, opnv->child.end());
        opnv->child.erase(opnv->child.begin() + s + 1, opnv->child.end());

        u->key.insert(u->key.begin(), opnv->key.begin() + s + 1, opnv->key.begin() + _order);
        opnv->key.erase(opnv->key.begin() + s + 1, opnv->key.begin() + _order);

        if (opnv->child.front())
        {
            for (int j = 0; j < _order - s; j++)
                u->child[j]->parent = u;
        }
        bnode<T> *p = opnv->parent;
        if (!p)
        {
            p = new bnode<T>();
            _root = p;
            p->child[0] = opnv;
            opnv->parent = p;
        }

        int r = upper_bound(p->key.begin(), p->key.end(), opnv->key[0]) - p->key.begin();
        p->key.insert(p->key.begin() + r, *(opnv->key.begin() + s));
        opnv->key.erase(opnv->key.begin() + s);
        p->child.insert(p->child.begin() + r + 1, u);
        u->parent = p;

        __overfSolution(p);
    }

    void __underfSolution(bnode<T> *opnv)
    {
        //cout << "s-1\n";
        if (!opnv)
            return;
        if ((_order - 1) / 2 <= opnv->key.size())
            return;
        //cout << "s-2\n";
        bnode<T> *p = opnv->parent;
        if (!p)
        {
            //cout << "s-3\n";
            if (opnv->key.empty() && opnv->child[0])
            {
                _root = opnv->child[0];
                _root->parent = nullptr;
                opnv->child[0] = nullptr;
                __release(opnv);
            }
            return;
        }
        int r = -1;
        //cout << "sp" << endl;
        while (p->child[++r] != opnv)
            ;
        if (0 < r)
        {
            bnode<T> *ls = p->child[r - 1];
            if ((_order - 1) / 2 < ls->key.size())
            {
                opnv->key.insert(opnv->key.begin(), p->key[r - 1]);
                p->key[r - 1] = ls->key.back();
                ls->key.pop_back();
                opnv->child.insert(opnv->child.begin(), ls->child.back());
                ls->child.pop_back();
                if (opnv->child[0])
                    opnv->child[0]->parent = opnv;
                //cout << "s1" << endl;
                return;
            }
        }
        if (r + 1 < p->child.size())
        {
            bnode<T> *rs = p->child[r + 1];
            if ((_order - 1) / 2 < rs->key.size())
            {
                //cout << "s2\n";
                opnv->key.insert(opnv->key.end(), p->key[r]);
                p->key[r] = rs->key.front();
                rs->key.erase(rs->key.begin());
                opnv->child.push_back(rs->child.front());
                rs->child.erase(rs->child.begin());
                if (opnv->child.back())
                    opnv->child.back()->parent = opnv;
                return;
            }
        }
        if (0 < r)
        {
            //cout << "s3\n";
            bnode<T> *ls = p->child[r - 1];
            ls->key.push_back(p->key[r - 1]);
            p->key.erase(p->key.begin() + r - 1);
            p->child.erase(p->child.begin() + r);

            ls->child.push_back(opnv->child.front());
            opnv->child.erase(opnv->child.begin());
            if (ls->child.back())
                ls->child.back()->parent = ls;
            ls->key.insert(ls->key.end(), opnv->key.begin(), opnv->key.end());
            ls->child.insert(ls->child.end(), opnv->child.begin(), opnv->child.end());
            for (auto &lsch : ls->child)
                if (lsch)
                    lsch->parent = ls;
            __release(opnv);
        }
        else
        {
            //cout << "s4\n";
            bnode<T> *rs = p->child[r + 1];
            rs->key.insert(rs->key.begin(), p->key[r]);
            p->key.erase(p->key.begin() + r);
            p->child.erase(p->child.begin() + r);

            rs->child.insert(rs->child.begin(), opnv->child.back());
            opnv->child.pop_back();

            if (rs->child.front())
                rs->child.front()->parent = rs;
            rs->key.insert(rs->key.begin(), opnv->key.begin(), opnv->key.end());
            rs->child.insert(rs->child.begin(), opnv->child.begin(), opnv->child.end());

            for (auto &rsch : rs->child)
                if (rsch)
                    rsch->parent = rs;

            __release(opnv);
        }
        __underfSolution(p);
        //cout << "end\n";
    }

    inline void _output_node(bnode<T> *opnv)
    {
        cout << " ( ";
        for (auto i : opnv->key)
            cout << i << " ";
        cout << ") ";
    }

    void __inorder(bnode<T> *opnv)
    {
        if (!opnv)
            return;
        int i;
        for (i = 0; i < opnv->key.size(); i++)
        {
            __inorder(opnv->child[i]);
            cout << opnv->key[i] << " -> ";
        }
        for (; i < opnv->child.size(); i++)
            __inorder(opnv->child[i]);
    }

public:
    btree<T>(int order = 3) : _order(order), _size(0)
    {
        _root = new bnode<T>();
    }
    ~btree()
    {
        this->clear();
    }
    inline void printTree()
    {
        bnode<T> *opnv = _root;
        queue<bnode<T> *> q, nexq;
        q.push(opnv);
        int le = 1;
        while (q.size())
        {
            printf("LeveL %d : ", le);
            while (q.size())
            {
                opnv = q.front(), q.pop();
                _output_node(opnv);
                for (auto chi : opnv->child)
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
    }
    inline int const order() { return this->_order; }
    inline int const size() { return this->_size; }
    inline bnode<T> *opnv() { return this->_root; }
    inline bool const empty() { return !size(); }
    bnode<T> *search(const T &x)
    {
        bnode<T> *opnv = _root;
        _last = nullptr;
        while (opnv)
        {
            auto it = lower_bound(opnv->key.begin(), opnv->key.end(), x);
            int r = it - opnv->key.begin();
            if (it != opnv->key.end() && *it == x)
                return opnv;
            _last = opnv, opnv = opnv->child[r];
        }
        return nullptr;
    }
    void inorder()
    {
        __inorder(this->_root);
        cout << "nullptr\n";
    }
    void build(vector<T> &a)
    {
        for (auto &x : a)
            insert(x);
    }
    bool insert(const T &x)
    {
        bnode<T> *opnv = search(x);
        if (opnv)
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
        bnode<T> *opnv = search(x);
        if (!opnv)
            return false;
        int r = lower_bound(opnv->key.begin(), opnv->key.end(), x) - opnv->key.begin();
        if (opnv->child.front())
        {
            bnode<T> *u = opnv->child[r + 1];
            while (u->child[0])
                u = u->child[0];
            opnv->key[r] = u->key[0];
            opnv = u, r = 0;
        }
        opnv->key.erase(opnv->key.begin() + r);
        opnv->child.erase(opnv->child.begin() + 1 + r);
        _size--;
        __underfSolution(opnv);
        return true;
    }
};

template <typename T>
class rbtree : public bstree<T>
{
    // in rbtree the memver 'height' is blk height
protected:
    static inline bool _blk(binode<T> *&opnv) { return opnv == nullptr || opnv->color == blk; }
    static inline bool _red(binode<T> *&opnv) { return !_blk(opnv); }
    static inline void __alterheight(binode<T> *&opnv)
    {
        opnv->height = max(_height(opnv->lc), _height(opnv->rc));
        opnv->height += _blk(opnv) ? 1 : 0;
    }
    static inline bool _blk_altered(binode<T> *&opnv)
    {
        return _height(opnv->lc) == _height(opnv->rc) &&
                       opnv->height == _red(opnv)
                   ? _height(opnv->lc)
                   : _height(opnv->lc) + 1;
    }

    void __double_red_solution(binode<T> *)
    {
    }
    void __double_blk_solution(binode<T> *)
    {
    }

public:
    bool insert(const T &x)
    {
        binode<T> *&opnv = search(x);
        if (opnv)
            return false;
        opnv = new binode<T>(x, this->_last);
        this->_size++;
        __double_red_solution(opnv);
        return true;
    }
    bool erase(const T &x)
    {
        binode<T> *&opnv = search(x);
        if (!opnv)
            return false;
        binode<T> *r = this->__erase_at(opnv, this->_last);
        if (--this->_size == 0)
            return true;
        if (!this->_last)
        {
            this->_root->color = blk;
            __alterheight(this->_root);
            return true;
        }
        if (_blk_altered(this->_last))
            return true;
        if (_red(r))
        {
            r->color = blk;
            r->height++;
            return true;
        }
        solveDoubleBlack(r);
        return true;
    }
    void build(vector<T> &a)
    {
        for (auto &x : a)
            insert(x);
        bintree<T>::__update_status();
    }
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
    void push(const T &x)
    {
        data.push_back(x);
        _size++;
        int i = _size;
        for (; data[i / 2] < x; i /= 2)
            data[i] = data[i / 2];
        data[i] = x;
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