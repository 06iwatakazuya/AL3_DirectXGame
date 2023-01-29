#pragma once
#include <d3d12.h>
#include <wrl.h>
#include "DirectXCommon.h"

class SpriteCommon
{
public:
	/// <summary>
	/// ������
	/// </summary>
	void Initilize(DirectXCommon* _dxCommon);

	/// <summary>
	/// �`��O����
	/// </summary>
	void PreDrow();

	// �Q�b�^�[
	DirectXCommon* GetDirectXCommon() { return dxCommon; }

private:
	DirectXCommon* dxCommon = nullptr;

	// �p�C�v���C���X�e�[�g
	Microsoft::WRL::ComPtr<ID3D12PipelineState> pipelineState;
	// ���[�g�V�O�l�`��
	Microsoft::WRL::ComPtr<ID3D12RootSignature> rootSignature;
};

