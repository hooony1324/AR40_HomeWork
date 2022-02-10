#include "ConsoleObject.h"

ConsoleObject::ConsoleObject(
	TextScreen* _Screen,
	const char* _Text,
	const ConsoleVector& _Pos
	)
	: Screen_(_Screen)
	, Pos_(_Pos)
{
	//if (nullptr == _Screen)
	//{
	//	assert(false);
	//}

	if (nullptr == _Text)
	{
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		Text_[i] = _Text[i];
	}
}

ConsoleObject::~ConsoleObject() 
{
}

bool ConsoleObject::CheckNextMove(ConsoleVector _Value)
{
	ConsoleVector ScreenSize(Screen_->GetSize());
	if (_Value.x_ < 0 || _Value.y_ < 0 || _Value.x_ >= ScreenSize.x_ || _Value.y_ >= ScreenSize.y_)
	{
		return false;
	}
	return true;
}

void ConsoleObject::Render()
{
	if (nullptr == Screen_)
	{
		assert(false);
	}

	Screen_->SetPixel(Pos_, Text_);
}
