#include <iostream>
#include <vector>

using namespace std;

template<typename Iter> enable_if<iterator_traits<Iter>::iterator_category::forward_iterator_tag, bool>
between(Iter fst, Iter lst, Iter i) {
	typename iterator_traits<Iter>::difference_type n = 0;
	while (fst != lst) {
		if (fst == i)
			return true;
		++fst;
		++n;
	}
	return false;
}

template<typename Iter> enable_if<iterator_traits<Iter>::iterator_category::random_access_iterator_tag, bool>
between(Iter fst, Iter lst, Iter i) {
	if (fst <= i && i <= lst)
		return true;
	return false;
}

//template<typename Iter>
//bool between(Iter fst, Iter lst, Iter i) {
//	typedef typename iterator_traits<Iter>::iterator_category cat;
//	return between<Iter>(fst, lst, i, cat());
//}

struct InputIterator
{
private:
	int* m_ptr;
public:
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = int;
	using pointer = int*;
	using reference = int&;
	InputIterator& operator++() { m_ptr++; return *this; }
	int& operator*() const { return *m_ptr; }
	int* operator->() { return m_ptr; }
	friend bool operator== (const InputIterator& a, const InputIterator& b) { return a.m_ptr == b.m_ptr; };
	friend bool operator!= (const InputIterator& a, const InputIterator& b) { return a.m_ptr != b.m_ptr; };
	InputIterator(int* ptr) : m_ptr(ptr) {}
};

int main()
{
	// rand acces iter
	vector<int> nums = { 2,3,4,5,67,8 };
	auto itBeg = nums.begin();
	auto itEnd = nums.end();
	auto it = nums.begin() + 1;
	itBeg += 4;

	cout << between<vector<int>::iterator>(itBeg, itEnd, it) << endl;

	// input iter
	/*int a = 3;
	auto itBeg = InputIterator(&a + 4);
	auto itEnd = InputIterator(&a + 10);
	auto it = InputIterator(&a + 2);

	cout << between(itBeg, itEnd, it) << endl;*/
}