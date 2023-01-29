#pragma once
#include <DirectXMath.h>
#include "SpriteCommon.h"

class Sprite
{
public:
	/// <summary>
	/// ������
	/// </summary>
	void Initilize(SpriteCommon* _spriteCommon);

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

private:
	SpriteCommon* spriteCommon = nullptr;

	// ���_�o�b�t�@
	Microsoft::WRL::ComPtr<ID3D12Resource> vertBuff;
	// ���_�o�b�t�@�r���[�̍쐬
	D3D12_VERTEX_BUFFER_VIEW vbView{};
};

