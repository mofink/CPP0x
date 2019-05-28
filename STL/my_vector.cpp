#include <iostream>
#include <memory>
#include <utility> 
#include <string> //for test case

//uses of allocator here are depricated in C++17, valid for C++11

template <typename T>
class my_vector
{

public:

	my_vector() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
	my_vector(std::initializer_list<T> input) : elements(nullptr), first_free(nullptr), cap(nullptr)
	{
		for (auto val: input)
		{
			chck_if_resize();
			alloc.construct(first_free++, val);

		}
	}

	
	my_vector(my_vector& orig)
	{
		auto iter_pair = alloc_and_copy(orig.begin(), orig.end());

		elements = iter_pair.first;
		first_free = cap = iter_pair.second;
	}
	
	my_vector& operator=(const my_vector& rhs)
	{
		auto iter_pair = alloc_and_copy(rhs.begin(), rhs.end()); //in case this == &rhs
		free();
		elements = iter_pair.first;
		first_free = cap = iter_pair.second;

		return *this;

	}

	my_vector(my_vector&& orig) noexcept : elements(orig.elements), first_free(orig.first_free), cap(orig.cap)
	{
		orig.elements = orig.first_free = orig.cap = nullptr;
	}
	

	my_vector& operator=(const my_vector&& rhs) noexcept
	{
		if (this != &rhs)
		{
			free();
			elements = rhs.elements;
			first_free = rhs.first_free;
			cap = rhs.cap;

			rhs.elements = rhs.first_free = rhs.cap = nullptr;
		}
		return *this;
	}

	~my_vector()
	{
		free();
	}

	size_t size() const
	{
		return first_free - elements;
	}

	size_t capacity() const
	{
		return cap - elements;
	}

	T *begin() const //uses regular pointers. I need to research how iterators are generally implemented
	{
		return elements;
	}

	T *end() const
	{
		return first_free;
	}

	void push_back(const T& val) //pass by reference in case T is class type (e.g. std::string), don't want the overhead of copying
	{
		chck_if_resize();
		alloc.construct(first_free++, val);
	}

private:

	T* elements; //points to beginning of vector
	T* first_free; //points to first undefined slot in allocated memory
	T* cap; //points to one past allocated memory

	std::allocator<T> alloc;


	void chck_if_resize()
	{
		if (size() == capacity())
		{
			resize();
		}
	}

	void resize()
	{
		int new_size = size() ? size()*2 : 1;
		auto new_mem_block = alloc.allocate(new_size);

		auto dest = new_mem_block;
		auto old_elem = begin();

		for (size_t i = 0; i != size(); ++i)
		{
			alloc.construct(dest++, std::move(*old_elem++));
		}

		free(); //free old memory block once we've moved

		elements = new_mem_block;
		first_free = dest;
		cap = elements + new_size;

	}

	void free() //frees allocated memory (compare to malloc/free)
	{
		if (elements) //cannot call deallocate on nullptr
		{
			for (auto p = first_free; p != elements; /*empty */) 
			{
				 alloc.destroy(--p); //calls destructor for T
			}

			alloc.deallocate(elements, cap - elements); //deallocates memory

		}
	}

	std::pair<T,T> alloc_and_copy(const T* b, const T* e) //"iterator" arguments
	{
		//allocate memory for the size of the range
		auto mem_block = alloc.allocate(e - b);

		//return start of memory block, copy data, and return one passed the end of the block
		return {mem_block, std::uninitialized_copy(b, e, mem_block)};

	}


};


int main()
{
	my_vector<int> vec;
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(5);


	for (auto i: vec)
	{
		std::cout << i << std::endl;
	}
	std::cout << vec.size() << std::endl;

	my_vector<std::string> vec_str{"This","is","a","vector"};

	for (auto i: vec_str)
	{
		std::cout << i << std::endl;
	}
	std::cout << vec_str.size() << std::endl;





	return 0;
}
