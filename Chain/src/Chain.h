/*************************************************************************
	> File Name: Chain.h
	> Author: 
	> Mail: 
	> Created Time: 2017年01月01日 星期日 20时50分36秒
 ************************************************************************/

#ifndef _CHAIN_H
#define _CHAIN_H
template <class T>
class ChainNode{
    friend Chain<T>;
    private:
        T data;
        ChainNode<T> *link;
}

class Chain{
public:
    Chain(){first = 0;}
    ~Chain();
    bool IsEmpty() const {return first == 0;}
    int Length()const;
    bool Find(int k, T& x)const;
    int Search(const T& x)const;
    Chain<T>& Delete(int k, T& x);
    Chain<T>& Insert(int k, const T& x);
    void Output(ostream& out)const;
private:
    ChainNode<T> *first;
};
#endif
