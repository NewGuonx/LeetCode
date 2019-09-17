// author - sonaspy@outlook.com
// coding - utf_8

#ifndef __AVLTREE__
#define __AVLTREE__

#include "bstree.h"
namespace dsa
{

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
        // binode<T> *&w = this->search(x);
        // if (w)
        //     return false;
        // w = new binode<T>(x, this->_last);
        // this->_size++;
        // binode<T> *g = this->_last;
        // for (; g; g = g->parent)
        // {
        //     this->__updateheight(g);
        //     if (!nodeBalanced(g))
        //     {
        //         __rotate_zz(this->_root, g);
        //         break;
        //     }
        //     this->__updateheight(g);
        // }
        // this->__updateheightabove(g);
        // return true;
        __insert(this->_root, x, nullptr);
    }
    inline void clear() { bstree<T>::clear(); }
    ~avltree()
    {
        this->clear();
    }

protected:
    inline void __rotate_zz(binode<T> *&root, binode<T> *x)
    {
        if (_factor(x) == 2)
            _factor(x->lc) == 1 ? __rotate_zig(root, x) : __rotate_zag(root, x->lc), __rotate_zig(root, x);
        if (_factor(x) == -2)
            _factor(x->lc) == -1 ? __rotate_zag(root, x) : __rotate_zig(root, x->rc), __rotate_zag(root, x);
    }
    inline void __rotate_zag(binode<T> *&root, binode<T> *x)
    {
        binode<T> *y = x->rc;
        x->rc = y->lc;
        if (y->lc)
            y->lc->parent = x;
        y->parent = x->parent;
        x->isroot() ? (root = y) : from_parent2(x) = y;
        y->lc = x;
        x->parent = y;
    }
    inline void __rotate_zig(binode<T> *&root, binode<T> *x)
    {
        binode<T> *y = x->lc;
        x->lc = y->rc;
        if (y->rc)
            y->rc->parent = x;
        y->parent = x->parent;
        x->isroot() ? (root = y) : from_parent2(x) = y;
        y->rc = x;
        x->parent = y;
    }

    inline void _zig(binode<T> *&opnv)
    {
        binode<T> *newroot = opnv->lc;
        opnv->lc = newroot->rc;
        if (newroot->rc)
            newroot->rc->parent = opnv;
        newroot->rc = opnv;
        newroot->parent = opnv->parent;
        opnv->parent = newroot;
        bintree<T>::__updateheight(opnv);
        bintree<T>::__updateheight(newroot);
        opnv = newroot;
    }
    inline void _zag(binode<T> *&opnv)
    {
        binode<T> *newroot = opnv->rc;
        opnv->rc = newroot->lc;
        if (newroot->lc)
            newroot->lc->parent = opnv;
        newroot->lc = opnv;
        newroot->parent = opnv->parent;
        opnv->parent = newroot;
        bintree<T>::__updateheight(opnv);
        bintree<T>::__updateheight(newroot);
        opnv = newroot;
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

} // namespace dsa
#endif