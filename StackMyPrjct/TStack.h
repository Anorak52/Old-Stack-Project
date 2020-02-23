#pragma once
#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING 1

template <class T>
class TStack {
	int MaxSize;
	int Size;
	T *mas;
public:
	TStack(int max = 10);
	~TStack() { delete[] mas; }
	TStack(const TStack &tmp);
	TStack& operator =(const TStack &tmp);
	void Push(const T elem);
	T Pop();
	T Top()const;
	bool IsEmpty()const;
	bool IsFull()const;
	void clear();
};

template <class T>
TStack<T>::TStack(int max)
{
	//if (MaxSize < 0)
		//throw MaxSize;
	MaxSize = max;
	Size = 0;
	mas = new T[MaxSize];
}

template <class T>
TStack<T>::TStack(const TStack &tmp)
{
	MaxSize = tmp.MaxSize;
	Size = tmp.Size;
	mas = new T[MaxSize];
	for (int i = 0; i < Size; i++)
		mas[i] = tmp.mas[i];
}
template <class T>
TStack <T> &TStack <T> ::operator= (const TStack &tmp)
{
	if (MaxSize != tmp.MaxSize)
	{
		delete[] mas;
		mas = new T[tmp.MaxSize];
	}
	MaxSize = tmp.MaxSize;
	Size = tmp.Size;
	for (int i = 0; i < Size; i++)
		mas[i] = tmp.mas[i];
	return *this;
}


template <class T>
void TStack<T>::Push(const T elem)
{
	if (Size == MaxSize)
		throw - 1;
	mas[Size] = elem;
	Size++;
}

template <class T>
T TStack<T>::Pop()
{
	if (Size == 0)
		throw - 1;
	Size--;
	return mas[Size];
}

template <class T>
T TStack<T>::Top()const
{
	if (Size == 0)
		throw - 1;
	return mas[Size - 1];
}

template <class T>
bool TStack<T>::IsEmpty()const
{
	return (Size == 0);
}

template <class T>
bool TStack<T>::IsFull()const
{
	return (Size == MaxSize);
}

template <class T>
void TStack<T>::clear() {
	Size = 0;
}