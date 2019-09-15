#include <memory.h>
#include <stdio.h>
#include <types.h>
#include <string.h>

template <typename T>
MemObject<T>::MemObject()
{
	sz = 0;
	arr = NULL;
}

template <typename T>
MemObject<T>::~MemObject()
{
	if(arr != NULL)
	{
		delete [] arr;
		sz = 0;
		arr = NULL;
	}
}

template <typename T>
void MemObject<T>::Resize(int amount)
{
	if(sz > 0)
	{
		T *temp = arr;
		arr = new T[sz + amount];
		/* BUG: don't memcpy() when using ANY c++ type within ANY member */
		//memcpy(arr, temp, sizeof(T) * sz);
		for(int i = 0; i < sz; i++)
		{
			arr[i] = temp[i];
		}
		memset(temp, 0, sizeof(T) * sz);
		delete [] temp;
	}
	else
	{
		arr = new T[amount];
	}
	sz += amount;
}

template <typename T>
T &MemObject<T>::operator[](int index)
{
	if(index >= sz)
	{
		T ret;
		printf("%s:%d: Index %d out of bounds (%d)\n", __FILE__, __LINE__, index, sz - 1);
		return ret;
	}
	return arr[index];
}

template <typename T>
int MemObject<T>::size()
{
	return sz;
}

/* Template instantiations */
template class MemObject<Category>;
template class MemObject<Word>;
