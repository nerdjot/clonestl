#include <iostream>

namespace clonestl
{
	template<typename T>
	class vector
	{
	private:
		T* _data;
		unsigned int _size;
		unsigned int _capacity;
	public:
		vector() : _data(nullptr), _size(0), _capacity(0) {}
		~vector()
		{
			delete[] _data;
		}
		void push_back(const T& val)
		{
			if (isFilled())
				expand();
			_data[_size] = val;
			_size++;
		}
		unsigned int size()
		{
			return _size;
		}
		unsigned int capacity()
		{
			return _capacity;
		}
		void reserve(const unsigned int new_cap)
		{
			if(new_cap > _capacity)
				reallocVector(new_cap);
		}
		void shrink_to_size()
		{
			reallocVector(_size);
		}

		T& operator[](const unsigned int pos)
		{
			return _data[pos];
		}
		
	private:
		void expand()
		{
			if (_capacity > 0)
				reallocVector(_capacity * 2);
			else
				reallocVector(1);
		}
		void reallocVector(const unsigned int new_cap)
		{
			if (new_cap >= _size)
			{
				T* dataNew = new T[new_cap];
				for (unsigned int i = 0; i < _size; i++)
					dataNew[i] = _data[i];
				delete[] _data;
				_data = dataNew;
				_capacity = new_cap;
			}
		}
		bool isFilled()
		{
			return _capacity == _size;
		}


	};

}