#include "DirectXCommon.h"
#include "Input.h"
#include "WinApp.h"
#include "Sprite.h"
#include "SpriteCommon.h"

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
#pragma region 基盤システムの初期化
    WinApp* winApp = nullptr;
    // WindowsAPIの初期化
    winApp = new WinApp();
    winApp->Initilize();

    DirectXCommon* dxCommon = nullptr;
    // DirectXの初期化
    dxCommon = new DirectXCommon();
    dxCommon->Initilize(winApp);

    Input* input = nullptr;
    // 入力の初期化
    input = new Input();
    input->Initilize(winApp);

    SpriteCommon* spriteCommon = nullptr;
    // SpriteCommonの初期化
    spriteCommon = new SpriteCommon();
    spriteCommon->Initilize(dxCommon);
#pragma endregion

#pragma region 最初のシーンの初期化
    Sprite* sprite = nullptr;
    // Spriteの初期化
    sprite = new Sprite();
    sprite->Initilize(spriteCommon);

#pragma endregion

    // ゲームループ
    while (true) {
#pragma region 基盤システムの更新
        // メッセージ処理
        if (winApp->ProcesMessage() == true) {
            // ゲームループを抜ける
            break;
        }

        // 入力の更新
        input->Update();
#pragma endregion

#pragma region 最初のシーンの更新

#pragma endregion

        // 描画前処理
        dxCommon->PreDrow();

#pragma region 最初のシーンの描画
        spriteCommon->PreDrow();
        sprite->Draw();
#pragma endregion

        // 描画後処理
        dxCommon->PostDraw();
    }

#pragma region 最初のシーンの終了
    // Spriteの解放
    delete sprite;
    sprite = nullptr;
#pragma endregion

#pragma region 基盤システムの終了
    // SpriteCommonの解放
    delete spriteCommon;
    spriteCommon = nullptr;
    // 入力解放
    delete input;
    input = nullptr;
    // DirectX解放
    delete dxCommon;
    dxCommon = nullptr;
    // WindowsAPIの終了処理
    winApp->Finalize();
    // WincowsAPIの解放
    delete winApp;
    winApp = nullptr;
#pragma endregion 基盤システムの終了

    return 0;
}
