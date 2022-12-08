#include <iostream>

using namespace std;

struct Base {
    Base() {
        cout << "Base constructor" << endl;
    }
    ~Base() {
        cout << "Base destructor" << endl;
    }
};

struct Child : public Base{
    Child() {
        cout << "Child constructor" << endl;
    }
    ~Child() {
        cout << "Child destructor" << endl;
    }
};

struct ChildOfChild : public Child {
    ChildOfChild() {
        cout << "ChildOfChild constructor" << endl;
    }
    ~ChildOfChild() {
        cout << "ChildOfChild destructor" << endl;
    }
};

int main()
{
    {
        ChildOfChild();
    }
}