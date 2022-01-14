#include <iostream>

// 좀 어려울거다.
int ToInt(const char* _Left)
{
	// 문자열 길이 측정
	int zeros = 0;
	int leftIndex = 0;
	while (_Left[leftIndex] != 0)
	{
		leftIndex += 1;
	}
	zeros = leftIndex - 1;

	// 문자의 자릿수 별로 계산
	int result = 0;
	for (int i = 0; i < leftIndex; i += 1)
	{
		int tens = 1;
		for (int j = 0; j < zeros; j += 1)
		{
			tens *= 10;
		}

		result += ((int)(_Left[i] - 48)) * tens;
		zeros -= 1;
	}

	return result;
}

int main()
{

	{
		char Text = '1';
		int Count = '2';

		int Value = ToInt("2147483647");

		int a = 0;
	}

}