#pragma once
#include "ConsoleMath.h"
#include <assert.h>

// Ό³Έν :
class TextScreen
{
public:
	// constrcuter destructer
	TextScreen(int _Width, int _Height, const char* _DefaultValue);
	~TextScreen();

	// delete Function
	TextScreen(const TextScreen& _Other) = delete;
	TextScreen(TextScreen&& _Other) noexcept = delete;
	TextScreen& operator=(const TextScreen& _Other) = delete;
	TextScreen& operator=(TextScreen&& _Other) noexcept = delete;

	ConsoleVector GetSize()
	{
		return Size_;
	}

	void CreateScreen(int _Width, int _Height, const char* _DefaultValue);

	void SettingScreen();

	void PrintScreen();

	void SetPixel(ConsoleVector _Pos, const char* _DefaultValue);
	void SetPixel(int _x, int _y, const char* _DefaultValue);

	bool IsValidPixel(ConsoleVector _Pos);

protected:

private:
	ConsoleVector Size_;
	char** PixelData_;
	char DefaultPixel_[3];
};

