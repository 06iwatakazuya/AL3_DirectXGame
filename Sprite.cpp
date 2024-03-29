#include "Sprite.h"

using namespace DirectX;
using namespace Microsoft::WRL;

void Sprite::Initilize(SpriteCommon* _spriteCommon)
{
	HRESULT result{};
	assert(_spriteCommon);
	spriteCommon = _spriteCommon;

	// 頂点データ
	XMFLOAT3 vertices[] = {
		{-0.5f, -0.5f, 0.0f}, // 左下
		{-0.5f, +0.5f, 0.0f}, // 左上
		{+0.5f, -0.5f, 0.0f}, // 右下
	};

	// 頂点データ全体のサイズ = 頂点データ１つ分のサイズ * 頂点データの要素数
	UINT sizeVB = static_cast<UINT>(sizeof(XMFLOAT3) * _countof(vertices));

	// 頂点バッファの設定
	D3D12_HEAP_PROPERTIES heapProp{};  // ヒープ設定
	heapProp.Type = D3D12_HEAP_TYPE_UPLOAD;  // GPUへの転送用
	// リソース設定
	D3D12_RESOURCE_DESC resDesc{};
	resDesc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
	resDesc.Width = sizeVB;  // 頂点データの全体サイズ
	resDesc.Height = 1;
	resDesc.DepthOrArraySize = 1;
	resDesc.MipLevels = 1;
	resDesc.SampleDesc.Count = 1;
	resDesc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;

	// 頂点バッファの生成
	result = spriteCommon->GetDirectXCommon()->GetDevice()->CreateCommittedResource(
		&heapProp,  // ヒープ設定
		D3D12_HEAP_FLAG_NONE,
		&resDesc,  // リソース設定
		D3D12_RESOURCE_STATE_GENERIC_READ,
		nullptr,
		IID_PPV_ARGS(&vertBuff));
	assert(SUCCEEDED(result));

	// GPU上のバッファに対応した仮想メモリを取得
	XMFLOAT3* vertMap = nullptr;
	result = vertBuff->Map(0, nullptr, (void**)&vertMap);
	assert(SUCCEEDED(result));
	// 全頂点に対して
	for (int i = 0; i < _countof(vertices); i++) {
		vertMap[i] = vertices[i];
	}
	// 繋がりを解除
	vertBuff->Unmap(0, nullptr);

	// GPU仮想アドレス
	vbView.BufferLocation = vertBuff->GetGPUVirtualAddress();
	// 頂点バッファのサイズ
	vbView.SizeInBytes = sizeVB;
	// 頂点１つ分のデータサイズ
	vbView.StrideInBytes = sizeof(XMFLOAT3);
}

void Sprite::Draw()
{
	// 頂点バッファの設定コマンド
	spriteCommon->GetDirectXCommon()->GetCommandList()->IASetVertexBuffers(0, 1, &vbView);
	// 描画コマンド
	spriteCommon->GetDirectXCommon()->GetCommandList()->DrawInstanced(3, 1, 0, 0);
}
