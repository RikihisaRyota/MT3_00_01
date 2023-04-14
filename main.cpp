#include <Novice.h>
#include "vector3.h"

const char kWindowTitle[] = "LC1A_21_リキヒサ_リョウタ";

static const int kColumWidth = 60;
static const int kRowHeight = 20;

void VectorScreenPreintf(int x,int y,const vector3& vector,const char* label){
	Novice::ScreenPrintf(x, y, "%.02f", vector.x);
	Novice::ScreenPrintf(x + kColumWidth, y, "%.02f", vector.y);
	Novice::ScreenPrintf(x + kColumWidth * 2, y, "%.02f", vector.z);
	Novice::ScreenPrintf(x + kColumWidth * 3, y, "%s", label);
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	vector3 v1{ 1.0f,3.0f,-5.0f };
	vector3 v2{ 4.0f,-1.0f,2.0f };
	float k = 4.0f;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		vector3 resultAdd = Add(v1, v2);
		vector3 resultSub = Subtract(v1, v2);
		vector3 resultMul = Multiply(k, v1);
		float resultDot = Dot(v1, v2);
		float resultLength = Length(v1);
		vector3 resultNormalize = Normalize(v2);
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		VectorScreenPreintf(0, 0, resultAdd, "	: Add");
		VectorScreenPreintf(0, kRowHeight, resultSub, "	: Subtract");
		VectorScreenPreintf(0, kRowHeight * 2, resultMul, "	: Multiply");
		Novice::ScreenPrintf(0, kRowHeight * 3, "%.02f	:	Dot", resultDot);
		Novice::ScreenPrintf(0, kRowHeight * 4, "%.02f	:	Length", resultLength);
		VectorScreenPreintf(0, kRowHeight * 5, resultNormalize, "	: Normalize");
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
