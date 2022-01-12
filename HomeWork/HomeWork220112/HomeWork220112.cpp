#include <iostream>

int main()
{
	//int Arr[10];
	//for (int i = 0; i < 10; i += 1)
	//{
	//	Arr[i] = i;
	//}

	// 짝수 채우기
	{
		int Arr[10] = { 0, };
		int Index = 0;
		while (true)
		{
			if (Index > 9)
				break;

			Arr[Index] = (Index * 2) + 2;
			
			Index += 1;
		}

		int a = 0;
	}

	// 홀수 채우기
	{
		int Arr[10] = { 0, };
		int Index = 0;
		while (true)
		{
			if (Index > 9)
				break;

			Arr[Index] = (Index * 2) + 1;

			Index += 1;
		}

		int a = 0;
	}

}
