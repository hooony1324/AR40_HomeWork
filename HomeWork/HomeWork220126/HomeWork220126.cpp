#include <iostream>

class MyInt
{
public:
    int Value;

public:

    MyInt(int _Value)
        : Value(_Value)
    {

    }

    // ++MyInt -> 1증가된 값 리턴
    // MyInt++ -> 값 리턴 후 1 증가

    // ++MyInt
    MyInt& operator++()
    {
        this->Value += 1;
        return *this;
    }

    // MyInt++
    MyInt operator++(int _Other)
    {
        MyInt temp = MyInt(this->Value);
        this->Value += 1;
        return temp;
    }

};

int main()
{
    int Value = 0;
    int Result = 0;

    Result = ++Value;
    Result = 0;
    Result = Value++;

    MyInt MyValue = 0;
    MyInt MyResult = 0;

    // ++ 쓰지마세요
    MyResult = ++MyValue;
    MyResult = 0;
    MyResult = MyValue++;

    int a = 0;
}