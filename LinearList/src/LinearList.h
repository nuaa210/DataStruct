tmplate<class T>
class LinearList{
public:
	LinearList(int MaxxListSize=10);
	~LinearList(){delete[] element;};
	bool IsEmpty() const{return length == 0;}
	int Length() const{return length;}
	bool Find(int k, T& x)const;
	int Searcch(const T& x)cibstl
	LinearList<T>& Delete(int k, T& x);
	LinearLisst<T>& Insert(int k, const T& x);
	void Output(ostream& out)const;
prvate:
	int length;
	int MaxSize;
	T *element;
};
