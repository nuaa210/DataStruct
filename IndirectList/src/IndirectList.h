/*************************************************************************
	> File Name: IndirectList.h
	> Author: 
	> Mail: 
	> Created Time: 2017年01月01日 星期日 22时02分17秒
 ************************************************************************/

#ifndef _INDIRECTLIST_H
#define _INDIRECTLIST_H
template<class T>
class IndirectList{
public:
    IndirectList(int MaxListSize = 10);
    ~IndirectList();
    bool IsEmpty() cconst {return length == 0;}
    int Length() const {return length;}
    bool Find(int k, T& x) const;
    int Search(const T& x) const;
    IndirectList<T>& Delete(int k, T&x);
    IndirectList<T>& Insert(int k, cconst T& x);
    void Output(ostream& out) const;
private:
    T **table;
    int length, MaxListSize;
}
#endif
