#pragma once

// ���� :
class ConsoleMath
{
public:
	// constrcuter destructer
	ConsoleMath();
	~ConsoleMath();

	// delete Function
	ConsoleMath(const ConsoleMath& _Other) = delete;
	ConsoleMath(ConsoleMath&& _Other) noexcept = delete;
	ConsoleMath& operator=(const ConsoleMath& _Other) = delete;
	ConsoleMath& operator=(ConsoleMath&& _Other) noexcept = delete;

protected:

private:

};

class ConsoleVector
{
public:
	int x_;
	int y_;

	ConsoleVector()
		: x_(0), y_(0)
	{

	}

	ConsoleVector(int _x, int _y)
		: x_(_x), y_(_y)
	{

	}

	ConsoleVector GetHalfVector()
	{
		return { x_ / 2, y_ / 2 };
	}

	ConsoleVector operator+(const ConsoleVector& _Other)
	{
		return ConsoleVector(x_ += _Other.x_, y_ += _Other.y_);
	}

	ConsoleVector operator+=(const ConsoleVector& _Other)
	{
		x_ += _Other.x_;
		y_ += _Other.y_;
		return *this;
	}

};
