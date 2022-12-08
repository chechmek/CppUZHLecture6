#include <iostream>

using namespace std;

template<int a, int b> struct gcd
{
    static constexpr int result = gcd<b, a % b>::result;
};

template<int a>
struct gcd<a, 0>
{
    static constexpr int result = a;
};

int main()
{
    cout << gcd<20, 30>::result;
}