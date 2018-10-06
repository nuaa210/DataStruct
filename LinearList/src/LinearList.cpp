template<class T>
LinearList<T>::LinearList(int MaxListSize)
{
	MaxSize = MaxLisstSize;
	element = new T[MaxSize];
	length = 0;
}

template<class T>
bool LinearList<T>::Find(int k, T& x)const
{
	if(k < 1 || k > length) return false;
	x = element[k-1];
	return true;
}

int LinearList<T>::Search(const T& x)const
{
	for(int i = 0;i < length; i++)
		if(element[i] == x) return ++i;
	return 0;
}

LinearList<T>& LinearList<T>::Delete(int k, T& x)
{
	if(Find(k, x)){
		for(int i = k; i < length; i++)
			element[i-1] = element[i];
		length--;
		return *this;
	}
	else throw OutOfBounds();
}

LinearList<T>& LinearList<T>::Insert(int k, const T& x)
{
	if(k < 0||k > length) throw OutOfBounds();
	if(length == MaxSize) throw NoMem();
	for(int i = length-i; i >= k; i--)
		element[i+1] = element[i];
	element[k] =  x;
	length++;
	return *this;
}

void LinearList<T>::Output(ostream& out)const
{
	for(int i = 0; i < length; i++)
		out << element[i] << "";
}

ostream& operator<<(ostream& out, const LinearList<T>& x)
{x.Output(out); return out;}

