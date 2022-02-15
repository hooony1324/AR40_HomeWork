#include <iostream>
#include <assert.h>
#include <crtdbg.h>

// Resize 기능 숙제
// 기존의 데이터가 있다면 데이터를 유지하도록

using DataType = int;

class GameArray
{
private:
    int Size_;
    int SizePrev_;
    DataType* ArrData_;

public:
    int GetSize()
    {
        return Size_;
    }

    DataType& operator[](int _Index)
    {
        if (Size_ <= _Index)
        {
            assert(false);
        }

        return ArrData_[_Index];
    }

    inline void operator=(const GameArray& _Other)
    {
        Resize(_Other.Size_);

        // 작은사이즈에서 큰 사이즈 배열 받을때만
        if (this->Size_ < _Other.Size_)
        {
            for (size_t i = SizePrev_; i < _Other.Size_; i++)
            {
                ArrData_[i] = _Other.ArrData_[i];
            }
        }
    }

    inline void AllValueSetting(const DataType& Data)
    {
        for (size_t i = 0; i < this->Size_; i++)
        {
            this->ArrData_[i] = Data;
        }
    }

    inline void Release()
    {
        if (nullptr != ArrData_)
        {
            delete[] ArrData_;
            ArrData_ = nullptr;
        }
    }

    void Resize(unsigned int _SizeNew)
    {
        SizePrev_ = this->Size_;

        // 유지할 기존의 메모리 임시 저장
        DataType* TempData = new DataType[SizePrev_];
        for (size_t i = 0; i < SizePrev_; i++)
        {
            TempData[i] = ArrData_[i];
        }
        
        // 기존 메모리 해제
        Release();
        
        // 20(prev) -> 10(new)
        // 저장해둔 기존 메모리 이전
        ArrData_ = new DataType[_SizeNew];
        for (size_t i = 0; i < SizePrev_; i++)
        {
            if (i >= _SizeNew)
            {
                break;
            }
            ArrData_[i] = TempData[i];
        }

        this->Size_ = _SizeNew;
        delete[] TempData;
    }

    void PrintArr()
    {
        for (size_t i = 0; i < Size_; i++)
        {
            std::cout << ArrData_[i] << " ";
        }
        std::cout << std::endl;
    }

public:
    GameArray(unsigned int _Size)
        : ArrData_(nullptr)
        , Size_(0)
        , SizePrev_(0)
    {
        Resize(_Size);
    }

    ~GameArray()
    {
        Release();
    }
};

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // Resize시 기존 데이터 유지
    {
        GameArray NewArray1 = GameArray(10);
        NewArray1.AllValueSetting(1);
        NewArray1.Resize(20);

        NewArray1.PrintArr();
    }

    {
        GameArray NewArray1 = GameArray(10);
        //GameArray NewArray2 = GameArray(5);
        GameArray NewArray2 = GameArray(20);
        NewArray2.AllValueSetting(2);

        NewArray2 = NewArray1;
        NewArray2.PrintArr();
    }
    
}
