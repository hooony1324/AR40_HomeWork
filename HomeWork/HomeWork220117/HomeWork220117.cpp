#include <iostream>

int StringCount(const char* _Text)
{
    int Count = 0;

    while (_Text[Count] != 0)
    {
        Count += 1;
    }

    return Count;
}

int CountFirst(const char* _Text, int _Start, const char* _FindStr)
{
    // _Text의 원소를 하나씩 살펴봄
    for (int i = _Start; _Text[i] != 0; i += 1)
    {
        // 첫 문자 일치 
        if (_Text[i] == _FindStr[0])
        {
            bool find = true;
            int checkIdx = i;

            // 나머지 문자열 검사
            for (int j = 0; _FindStr[j] != 0; j += 1)
            {
                checkIdx += j;
                if (_Text[i] != _FindStr[j])
                {
                    find = false;
                    break;
                }
            }

            // 문자열 검사가 통과되면 함수 종료
            if (find == true)
            {
                return i;
            }

            i = checkIdx; // 문자열 검사한 다음 위치로
        }
    }

    return -1;
}

int CountLast(const char* _Text, int _End, const char* _FindStr)
{
    int fIdx = StringCount(_FindStr) - 1;

    // _Text의 원소를 하나씩 살펴봄
    for (int i = _End; i >= 0; i -= 1)
    {
        // 첫 문자 일치 
        if (_Text[i] == _FindStr[fIdx])
        {
            bool find = true;

            // 나머지 문자열 검사
            for (int j = fIdx; j >= 0; j -= 1)
            {
                if (_Text[i] != _FindStr[j])
                {
                    find = false;
                    break;
                }

                i -= 1;
            }

            // 문자열 검사가 통과되면 함수 종료
            if (find == true)
            {
                return i + 1; // 문자열 검사로 인덱스가 한칸 당겨져 있음
            }
        }
    }

    return -1;
}

int main()
{
    // 실패
    {
        int Count = CountFirst("aaa sseeees ttt asdfasd eee", 2, "eee");
        int a = 0;
    }
    {
        int Count = CountLast("aba tdffff eceb dddfffd", 13, "ce");
        int a = 0;
    }

}