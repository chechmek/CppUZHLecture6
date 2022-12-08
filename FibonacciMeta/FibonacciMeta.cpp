#include <iostream>

using namespace std;

template<int n>
struct fibonacci
{
    static constexpr int result = fibonacci<n - 1>::result + fibonacci<n - 2>::result;
};

template<>
struct fibonacci<0>
{
    static constexpr int result = 0;
};
template<>
struct fibonacci<1>
{
    static constexpr int result = 1;
};

int main()
{
    cout << fibonacci<4>::result << endl;
}
