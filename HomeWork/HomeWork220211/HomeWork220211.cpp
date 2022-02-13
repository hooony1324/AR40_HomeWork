#include <iostream>

int count = 0;

class Test
{
public:
    Test()
    {

    }

    ~Test()
    {

    }

    Test& operator()()
    {
        std::cout << "()연산자 실행 : " << ++count << std::endl;
        return *this;
    }
};

int main()
{
    Test test;
    test();
    
    Test test2(test());
    test2();
    
    return 0;
}