#include "GameEngineRenderer.h"
#include "GameEngineActor.h"
#include "GameEngineLevel.h"
#include <Windows.h>
#include <GameEngineBase/GameEngineWindow.h>

#include "GameEngineVertexBuffer.h"
#include "GameEngineIndexBuffer.h"

GameEngineRenderer::GameEngineRenderer() 
{
}

GameEngineRenderer::~GameEngineRenderer() 
{
}


void GameEngineRenderer::Start() 
{
	GetActor()->GetLevel()->PushRenderer(this);
}

float4 XDir = { 1, 0 };
float4 YDir = { 0, -1 };

float Angle = 0.0f;
float Dis = 0.0f;
float4 Postion;

void GameEngineRenderer::Render(float _DeltaTime)
{
	float4 Dir = {100.0f, 100.0f, 0.0f};

	Angle += _DeltaTime * 90.0f;
	Dis = 30.0f;

	GetActor()->GetTransform().SetPosition(float4{300.0f, 300.0f});
	// 랜더링
	GameEngineVertexBuffer* Vertex = GameEngineVertexBuffer::Find("Box");
	GameEngineIndexBuffer* Index = GameEngineIndexBuffer::Find("Box");
	
	std::vector<POINT> DrawVertex;
	DrawVertex.resize(Index->Indexs.size());

	std::vector<float4> CopyBuffer;
	CopyBuffer.resize(Index->Indexs.size());


	for (size_t i = 0; i < Index->Indexs.size(); i++)
	{
		int TriIndex = Index->Indexs[i];

		// 0 번째 순서의 점이 됩니다.
		// 최초에 원본 매쉬의 점을 복사합니다.
		CopyBuffer[i] = Vertex->Vertexs[TriIndex];

		// [0.5f] [0.5f] []                  [100] [100] [] 
		// 크
		CopyBuffer[i] *= GetActor()->GetTransform().GetScale();

		// 자전
		CopyBuffer[i] = float4::VectorRotationToDegreeXAxis(CopyBuffer[i], Angle);
		CopyBuffer[i] = float4::VectorRotationToDegreeYAxis(CopyBuffer[i], Angle);
		CopyBuffer[i] = float4::VectorRotationToDegreeZAxis(CopyBuffer[i], Angle);
		
		// 이동
		CopyBuffer[i] += GetActor()->GetTransform().GetPosition();


		DrawVertex[i] = CopyBuffer[i].GetConvertWindowPOINT();
	}

	
	for (size_t i = 0; i < DrawVertex.size(); i += 3)
	{
		Polygon(GameEngineWindow::GetHDC(), &DrawVertex[i], 3);
	}
	

	// Rectangle(GameEngineWindow::GetHDC(), LeftTop.ix(), LeftTop.iy(), RightBot.ix(), RightBot.iy());
}