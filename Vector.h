#ifndef Vector_H
#define Vector_H
#include "Vector.h"
using std::cout;
template <class T> class Vector
{
public:
	Vector(unsigned int = 0);
	Vector(const Vector &);
	~Vector();
	unsigned int size();
	unsigned int capacity();
	void push_back(T);
	void pop_back();


	T& operator[](unsigned int );

private:

	unsigned int get_capacity(unsigned int);
	unsigned int m_size;
	unsigned int m_capacity;
	
	T * array;
	

};


template <class T>
Vector<T>::Vector(unsigned int s)
{
	m_size = s;
	if (s!=0)
	{
		m_capacity = get_capacity(s);	
		array = new T [m_capacity];	
	}
	array = new T [1];
	
}

template <class T>
Vector<T>::Vector(const Vector &obj) 
{

	m_size = obj.m_size;
	m_capacity = obj.m_capacity;
	


	array = new T [m_capacity];
	for (int i = 0; i < m_size; ++i)
	{
		array[i] = obj.array[i];
	}

}




template <class T>
Vector<T>::~Vector()
{
	if (array !=NULL)
	{
		delete [] array;
	}
	
}

template <class T>
unsigned int Vector<T>::size()
{
	return m_size;
}
template <class T>
unsigned int Vector<T>::capacity()
{
	return m_capacity;
}

template <class T>
unsigned int Vector<T>::get_capacity(unsigned int n)
{
	if (n==0)
		return 0;
	unsigned int mask = 1;
	mask<<=31;
	
	while (!(mask & n))
		mask>>=1;
	
	
	if (mask!=n)	
		mask<<=1;	
	
	return mask;
}


template <class T>
void Vector<T>::push_back(T val)
{
	if (m_size+1 > m_capacity)
	{
		m_capacity = get_capacity(m_size+1);
		T * temp = new T[m_size];
		
		for (int i = 0; i < m_size; ++i)
		{
			temp[i] = array[i];			
		}

		delete [] array;

		array = new T[m_capacity];

		for (int i = 0; i < m_size; ++i)
		{
			array[i] = temp [i];
		}
	}
	++m_size;
	array[m_size-1] = val;

}
template <class T>
void Vector<T>::pop_back()
{
	if (m_size==0)
	{
		return;
	}
	
	m_size--;
}

template <class T>
T& Vector<T>::operator[](unsigned int i)
{
	return array[i];
}


#endif