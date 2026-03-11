//Main.cpp

#include "DxLib.h"

#include "Main.h"

int WINAPI WinMain(HINSTANCE hIns, HINSTANCE hPrevIns, LPSTR lpCmdLine, int nCmdShow)
{
	Main main;

	main.Init();

	main.Update();

	main.Exit();

	return 0;
}

Main::Main(){}

void Main::Init() {
	
	SetGraphMode(1920, 1080, 32);	// 画面モードの変更（解像度、カラーの設定）
	ChangeWindowMode(true);	// ウィンドウモードへ
	
	if (DxLib_Init() == -1) { return; }// DXライブラリの初期化
	
	SetDrawScreen(DX_SCREEN_BACK);// ダブルバッファリング設定
	
	SetFontSize(40);// フォントの設定
}

void Main::Update() {
	while (true) {	// 無限ループ
		ClearDrawScreen();		// 画面を消す

		ScreenFlip();			// 裏画面を表画面にコピー
		if (ProcessMessage() < 0) { break; }	// Xをクリックで終了
		if (CheckHitKey(KEY_INPUT_ESCAPE)) { break; }// ESCで終了
	}
}