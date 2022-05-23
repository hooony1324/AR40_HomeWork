#include "Hexagram.h"
#include <GameEngineCore/GEngine.h>
#include <GameEngineCore/GameEngineRenderer.h>

Hexagram::Hexagram() 
{
}

Hexagram::~Hexagram() 
{
}

void Hexagram::Start()
{
	GetTransform().SetScale({ 100, 100 });
	GetTransform().SetPosition({ 300, 300, 100 });
	{
		GameEngineRenderer* Renderer = CreateComponent<GameEngineRenderer>();
	}
}

void Hexagram::Update(float _DeltaTime)
{
}

void Hexagram::End()
{
}
