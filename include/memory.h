#ifndef _MEMORY_H_
#define _MEMORY_H_

template <typename T>
class MemObject {
	public:
		MemObject();
		~MemObject();
		void Resize(int newsz);
		T &operator[](int index);
		int size();
	private:
		int sz;
		T *arr;
};

#endif /* _MEMORY_H_ */
