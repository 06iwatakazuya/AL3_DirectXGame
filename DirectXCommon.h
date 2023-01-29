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
	/// 初期化
	/// </summary>
	void Initilize(WinApp* winApp);

	/// <summary>
	/// 描画前処理
	/// </summary>
	void PreDrow();

	/// <summary>
	/// 描画後処理
	/// </summary>
	void PostDraw();

	// ゲッター
	// デバイス取得
	ID3D12Device* GetDevice() const { return device.Get(); }

	// コマンドリスト
	ID3D12GraphicsCommandList* GetCommandList() const { return commandList.Get(); }


private:
	/// <summary>
	/// デバイス初期化
	/// </summary>
	void InitilizeDevice();

	/// <summary>
	/// コマンド関連の初期化
	/// </summary>
	void InitilizeCommand();

	/// <summary>
	/// スワップチェーン初期化
	/// </summary>
	void InitilizeSwapchain();

	/// <summary>
	/// レンダーターゲットビュー初期化
	/// </summary>
	void InitilizeRenderTargetView();

	/// <summary>
	/// 深度バッファの初期化
	/// </summary>
	void InitilizeDepthBuffer();

	/// <summary>
	/// フェンスの初期化
	/// </summary>
	void InitilizeFence();

	/// <summary>
	/// FPS固定所以下
	/// </summary>
	void InitilizeFixFPS();

	/// <summary>
	/// FPS固定更新
	/// </summary>
	void UpdateFixFPS();

private:
	WinApp* winApp = nullptr;

	// デバイス
	Microsoft::WRL::ComPtr<ID3D12Device> device;
	Microsoft::WRL::ComPtr<IDXGIFactory7> dxgiFactory;

	// コマンド関連
	Microsoft::WRL::ComPtr<ID3D12CommandAllocator> commandAllocator;
	Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> commandList;
	Microsoft::WRL::ComPtr<ID3D12CommandQueue> commandQueue;

	// スワップチェーン
	Microsoft::WRL::ComPtr<IDXGISwapChain4> swapChain;
	DXGI_SWAP_CHAIN_DESC1 swapChainDesc{};

	// レンダーターゲットビュー
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> rtvHeap;
	std::vector<Microsoft::WRL::ComPtr<ID3D12Resource>> backBuffers;

	// 深度バッファ
	Microsoft::WRL::ComPtr<ID3D12Resource> depthBuff;
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> dsvHeap;

	// フェンス
	Microsoft::WRL::ComPtr<ID3D12Fence> fence;
	UINT64 fenceVal = 0;

	// 記録時間（FPS固定用）
	std::chrono::steady_clock::time_point reference_;
};

