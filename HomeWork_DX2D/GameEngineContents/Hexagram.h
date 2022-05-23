#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Hexagram : public GameEngineActor
{
public:
	// constrcuter destructer
	Hexagram();
	~Hexagram();

	// delete Function
	Hexagram(const Hexagram& _Other) = delete;
	Hexagram(Hexagram&& _Other) noexcept = delete;
	Hexagram& operator=(const Hexagram& _Other) = delete;
	Hexagram& operator=(Hexagram&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

private:
};