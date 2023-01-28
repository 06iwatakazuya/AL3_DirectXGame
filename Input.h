#pragma once
#include <windows.h>
#include <wrl.h>
#define DIRECTINPUT_VERSION     0x0800   // DirectInput�̃o�[�W�����w��
#include <dinput.h>
#include "WinApp.h"

class Input
{
public:
	template<class T> using ComPtr = Microsoft::WRL::ComPtr<T>;

public:
	/// <summary>
	/// ������
	/// </summary>
	void Initilize(WinApp* winApp);

	/// <summary>
	/// �X�V
	/// </summary>
	void Update();

	/// <summary>
	/// ����
	/// </summary>
	/// <param name="keyNumber">�L�[�ԍ�</param>
	/// <returns></returns>
	bool PushKey(BYTE keyNumber);

	/// <summary>
	/// �g���K�[����
	/// </summary>
	/// <param name="keyNumber">�L�[�ԍ�</param>
	/// <returns></returns>
	bool TriggerKey(BYTE keyNumber);

private:
	// WindowsAPI�|�C���^
	WinApp* winApp = nullptr;

	// �L�[�{�[�h�f�o�C�X�̐ݒ�
	ComPtr<IDirectInputDevice8> keyboard;

	// ����̓���
	BYTE key[256] = {};
	// �O��̓���
	BYTE keyPre[256] = {};
};

