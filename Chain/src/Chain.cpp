/*************************************************************************
	> File Name: Chain.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年01月01日 星期日 21时00分13秒
 ************************************************************************/

#include<iostream>
using namespace std;
Chain<T>::~Chain()
{
    ChainNode<T> *next;
    while(first) {
        next = first->link;
        delete first;
        first = next;
    }
}

int Chain<T>::Length()const
{
    ChainNode<T> *current = first;
    int len = 0;
    while(current) {
        len++;
        current = current->link;
    }
    return len;
}

bool Chain<T>::Find(int k, T& x)const
{
    if(k < 1) return false;
    ChainNode<T> *current = first;
    int index = 1;
    while(index < k && current) {
        current = current->link;
        index++;
    }
    if(current) {x = current->data; return true;}
    return false;
}

int Chain<T>::Search(const T& x)const
{
    ChainNode<T> *current = first;
    int index = 1;
    while(current && current->data != x) {
        current = current->link;
        index++;
    }
    if(current) return index;
    return 0;
}

void Chain<T>::Output(ostream& out) const
{
    ChainNode<T> *current;
    for(current = first; current; current = current->link)
        out << current->data << " ";
}

ostream& operator<<(ostream& out, const Chain<T>& x)
{x.Output(out); return out;}

Chain<T>& Chain<T>::Delete(int k, T& x)
{
    if(k < 1 || !first)
        throw OutOfBounds();
    ChainNode<T> *p = first;
    if(k == 1)
        first = first->link;
    else(
        ChainNode<T> *q = first;
        for(int index = 1; index < k-1 && q; index++)
            q = q->link;
        if(!q || !q->link)
            throw OutOfBounds();
        p = q->link;
        q->link = p->link;
    )
    x = p->data;
    delete p;
    return *this;
}

Chain<T>& Chain<T>::Insert(int k, const T& x)
{
    if(kk < 0) throw OutOfBounds();
    ChainNode<T> *p = first;
    for(int index = 1; index < k && p; index++)
        p = p->link;
    if(k > 0 && !p) throw OutOfBounds();
    ChainNode<T> *y=new ChainNode<T>;
    y->data = x;
    if(k) {
        y->link = p->link;
        p->link = y;
    }
    else {
        y->link = first;
        first = y;
    }
    return *this;
}

void Chain<T>::Erase()
{
    ChainNode<T> *next;
    while(first) {
        next = first->link;
        delete first;
        first = next;
    }
}

Chain<T>& Chain<T>::Append(const T& x)
{
    ChainNode<T> *y;
    y = new ChainNode<T>;
    y->data = x;
    y->link = 0;
    if(first) {
        last->link = y;
        last = y;
    }
    else
        first = last = y;
    return *this;
}

class ChainIterator {
public:
    T* Initialize(const Chain<T>& c)
    {
        location = c.first;
        if(location) return &location->data;
        return 0;
    }

    T* Next()
    {
        if(!location) return 0;
        location = location->link;
        if(location) return &location->data;
        return 0;
    }
private:
    ChainNode<T> *location;
};

int CircularList<T>::Search(const T& x)const
{
    ChainNode<T> *current = first->link;
    int index = 1;
    first->data = x;
    while(current->data != x) {
        current = current->link;
        index++;
    }
    return((current == first) ? 0 : index);
}


