/*************************************************************************
	> File Name: IndirectList.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年01月01日 星期日 22时07分58秒
 ************************************************************************/

#include<iostream>
using namespace std;
template<class T>
IndirectList<T>::IndirectList(int MaxListSize)
{
    MaxSize = MaxListSize;
    table = new T *[MaxSize];
    length = 0;
}

IndirectList<T>::~IndirectList()
{
    for(int i = 0; i < length; i++)
        delete table[i];
    delete[] table;
}

bool IndirectList<T>::Find(int k, T& x) const
{
    if(k < 1 || k > length) return false;
    x = *table[k - 1];
    return true;
}

IndirectList<T>& IndirectList<T>::Delete(int k, T& x)
{
    if(Find(k, x)){
        for(int i = k; i < length; i++)
            table[i-1] = table[i];
        length--;
        return *this;
    }
    else throw OutOfBounds();
}

IndirectList<T>& IndirectList<T>::Insert(int k, const T& x)
{
    if(k < 0 || k > length) throw OutOfBounds();
    if(length == MaxSize) throw NoMem();
    for(int i = length-i; i >= k; i--)
        table[i+1] = table[i];
    table[k] = new T;
    *table[k] = x;
    length++;
    return *this;
}
