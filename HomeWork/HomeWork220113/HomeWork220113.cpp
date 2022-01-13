#include <iostream>

void StringTrimRemove(const char* _Left, char* _Right)
{
    int LeftIndex = 0;
    int RightIndex = 0;
    while (_Left[LeftIndex] != 0)
    {
        if (_Left[LeftIndex] == ' ')
        {

        }
        else
        {
            _Right[RightIndex] = _Left[LeftIndex];
            RightIndex += 1;
        }

        LeftIndex += 1;
    }

    _Right[RightIndex + 1] = 0;
    
}

int main()
{
    char Text[10000] = { 0, };
    StringTrimRemove("a b ,<.>/?:;! ~` @##$ %%^ &() *_+-=  1 2 3 c d", Text);
    // "aaabbbcccddd"
    printf_s(Text);
}