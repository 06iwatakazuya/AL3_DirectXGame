#pragma once
#include <Windows.h>

class WinApp
{

public: // 静的メンバ関数
	static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

public:
	// ウィンドウサイズ
	static const int window_width = 1280;  // 横幅
	static const int window_height = 720;  // 縦幅

public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initilize();

	/// <summary>
	/// メッセージ処理
	/// </summary>
	/// <returns></returns>
	bool ProcesMessage();

	/// <summary>
	/// 終了処理
	/// </summary>
	void Finalize();

	// getter
	HWND GetHwnd() const { return hwnd; }
	HINSTANCE GetHInstance() const { return w.hInstance; }

private:
	// ウィンドウハンドル
	HWND hwnd = nullptr;
	// ウィンドウクラスの設定
	WNDCLASSEX w{};
};

