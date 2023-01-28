#pragma once
#include <windows.h>
#include <wrl.h>
#define DIRECTINPUT_VERSION     0x0800   // DirectInputのバージョン指定
#include <dinput.h>
#include "WinApp.h"

class Input
{
public:
	template<class T> using ComPtr = Microsoft::WRL::ComPtr<T>;

public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initilize(WinApp* winApp);

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 入力
	/// </summary>
	/// <param name="keyNumber">キー番号</param>
	/// <returns></returns>
	bool PushKey(BYTE keyNumber);

	/// <summary>
	/// トリガー処理
	/// </summary>
	/// <param name="keyNumber">キー番号</param>
	/// <returns></returns>
	bool TriggerKey(BYTE keyNumber);

private:
	// WindowsAPIポインタ
	WinApp* winApp = nullptr;

	// キーボードデバイスの設定
	ComPtr<IDirectInputDevice8> keyboard;

	// 今回の入力
	BYTE key[256] = {};
	// 前回の入力
	BYTE keyPre[256] = {};
};

