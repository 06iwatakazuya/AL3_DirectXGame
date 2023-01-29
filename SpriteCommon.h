#pragma once
#include <d3d12.h>
#include <wrl.h>
#include "DirectXCommon.h"

class SpriteCommon
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initilize(DirectXCommon* _dxCommon);

	/// <summary>
	/// 描画前処理
	/// </summary>
	void PreDrow();

	// ゲッター
	DirectXCommon* GetDirectXCommon() { return dxCommon; }

private:
	DirectXCommon* dxCommon = nullptr;

	// パイプラインステート
	Microsoft::WRL::ComPtr<ID3D12PipelineState> pipelineState;
	// ルートシグネチャ
	Microsoft::WRL::ComPtr<ID3D12RootSignature> rootSignature;
};

