#include "TextScreen.h"
#include <iostream>


TextScreen::TextScreen(int _Width, int _Height, const char* _DefaultValue)
	: Size_(0, 0)
	, PixelData_(nullptr)
	, DefaultPixel_()
{
	CreateScreen(_Width, _Height, _DefaultValue);
}

TextScreen::~TextScreen() 
{
	for (int i = 0; i < Size_.y_; i++)
	{
		if (nullptr != PixelData_)
		{
			delete[] PixelData_[i];
			PixelData_[i] = nullptr;
		}
	}

	if (nullptr != PixelData_)
	{
		delete[] PixelData_;
		PixelData_ = nullptr;
	}

}

void TextScreen::CreateScreen(int _Width, int _Height, const char* _DefaultValue)
{
	Size_.x_ = _Width;
	Size_.y_ = _Height;

	for (int i = 0; i < 3; i++)
	{
		DefaultPixel_[i] = _DefaultValue[i];
	}

	int RealWidth = Size_.x_ * 2 + 2;

	PixelData_ = new char* [Size_.y_];

	for (int i = 0; i < Size_.y_; i++)
	{
		PixelData_[i] = new char[RealWidth];
	}
}

void TextScreen::SettingScreen()
{
	for (int y = 0; y < Size_.y_; y++)
	{
		for (int x = 0; x < Size_.x_; x++)
		{
			for (int i = 0; i < 2; i++)
			{
				PixelData_[y][x * 2 + i] = DefaultPixel_[i];
			}
			PixelData_[y][(Size_.x_ * 2)] = '\n';
			PixelData_[y][(Size_.x_ * 2) + 1] = 0;
		}
	}
}

void TextScreen::PrintScreen()
{
	system("cls");

	for (int y = 0; y < Size_.y_; y++)
	{
		printf_s(PixelData_[y]);
	}
}

void TextScreen::SetPixel(ConsoleVector _Pos, const char* _DefaultValue)
{
	if (false == IsValidPixel(_Pos))
	{
		assert(false);
	}

	SetPixel(_Pos.x_, _Pos.y_, _DefaultValue);
}

void TextScreen::SetPixel(int _x, int _y, const char* _DefaultValue)
{
	for (int i = 0; i < 2; i++)
	{
		PixelData_[_y][(_x * 2) + i] = _DefaultValue[i];
	}
}

bool TextScreen::IsValidPixel(ConsoleVector _Pos)
{
	if (_Pos.x_ >= Size_.x_ || _Pos.y_ >= Size_.y_ || _Pos.x_ < 0 || _Pos.y_ < 0)
	{
		return false;
	}
	
	return true;
}
