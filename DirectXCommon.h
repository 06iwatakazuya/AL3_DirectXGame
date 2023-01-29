#pragma once
#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>
#include <vector>
#include <chrono>
#include "WinApp.h"

class DirectXCommon
{
public:
	/// <summary>
	/// ������
	/// </summary>
	void Initilize(WinApp* winApp);

	/// <summary>
	/// �`��O����
	/// </summary>
	void PreDrow();

	/// <summary>
	/// �`��㏈��
	/// </summary>
	void PostDraw();

	// �Q�b�^�[
	// �f�o�C�X�擾
	ID3D12Device* GetDevice() const { return device.Get(); }

	// �R�}���h���X�g
	ID3D12GraphicsCommandList* GetCommandList() const { return commandList.Get(); }


private:
	/// <summary>
	/// �f�o�C�X������
	/// </summary>
	void InitilizeDevice();

	/// <summary>
	/// �R�}���h�֘A�̏�����
	/// </summary>
	void InitilizeCommand();

	/// <summary>
	/// �X���b�v�`�F�[��������
	/// </summary>
	void InitilizeSwapchain();

	/// <summary>
	/// �����_�[�^�[�Q�b�g�r���[������
	/// </summary>
	void InitilizeRenderTargetView();

	/// <summary>
	/// �[�x�o�b�t�@�̏�����
	/// </summary>
	void InitilizeDepthBuffer();

	/// <summary>
	/// �t�F���X�̏�����
	/// </summary>
	void InitilizeFence();

	/// <summary>
	/// FPS�Œ菊�ȉ�
	/// </summary>
	void InitilizeFixFPS();

	/// <summary>
	/// FPS�Œ�X�V
	/// </summary>
	void UpdateFixFPS();

private:
	WinApp* winApp = nullptr;

	// �f�o�C�X
	Microsoft::WRL::ComPtr<ID3D12Device> device;
	Microsoft::WRL::ComPtr<IDXGIFactory7> dxgiFactory;

	// �R�}���h�֘A
	Microsoft::WRL::ComPtr<ID3D12CommandAllocator> commandAllocator;
	Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> commandList;
	Microsoft::WRL::ComPtr<ID3D12CommandQueue> commandQueue;

	// �X���b�v�`�F�[��
	Microsoft::WRL::ComPtr<IDXGISwapChain4> swapChain;
	DXGI_SWAP_CHAIN_DESC1 swapChainDesc{};

	// �����_�[�^�[�Q�b�g�r���[
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> rtvHeap;
	std::vector<Microsoft::WRL::ComPtr<ID3D12Resource>> backBuffers;

	// �[�x�o�b�t�@
	Microsoft::WRL::ComPtr<ID3D12Resource> depthBuff;
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> dsvHeap;

	// �t�F���X
	Microsoft::WRL::ComPtr<ID3D12Fence> fence;
	UINT64 fenceVal = 0;

	// �L�^���ԁiFPS�Œ�p�j
	std::chrono::steady_clock::time_point reference_;
};

