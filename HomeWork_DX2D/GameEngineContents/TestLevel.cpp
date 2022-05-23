#include "TestLevel.h"

#include "Hexagram.h"

TestLevel::TestLevel() 
{
}

TestLevel::~TestLevel() 
{
}

void TestLevel::Start()
{
	CreateActor<Hexagram>(0);
}

void TestLevel::Update(float _DeltaTime)
{
}

void TestLevel::End()
{
}
