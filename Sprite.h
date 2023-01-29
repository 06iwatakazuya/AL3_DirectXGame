#pragma once
#include <DirectXMath.h>
#include "SpriteCommon.h"

class Sprite
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initilize(SpriteCommon* _spriteCommon);

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private:
	SpriteCommon* spriteCommon = nullptr;

	// 頂点バッファ
	Microsoft::WRL::ComPtr<ID3D12Resource> vertBuff;
	// 頂点バッファビューの作成
	D3D12_VERTEX_BUFFER_VIEW vbView{};
};

