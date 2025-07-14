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

		T& operator[](const unsigned int pos_)
		{
			return _data[pos_];
		}
		void print()
		{
			for (unsigned int i = 0; i < _size; i++)
			{
				std::cout << _data[i] << ", ";
			}
			std::cout << std::endl;
		}
	private:
		void expand()
		{
			if (_capacity > 0)
			{
				_capacity = _capacity * 2;
				T* dataNew = new T[_capacity];
				for (unsigned int i = 0; i < _size; i++)
					dataNew[i] = _data[i];
				delete[] _data;
				_data = dataNew;
			}
			else
			{
				_capacity = 1;
				_data = new T[_capacity];
			}
		}
		bool isFilled()
		{
			return _capacity == _size;
		}


	};

}