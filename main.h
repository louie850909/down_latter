/*******************************************************************************
* タイトル:		メインプログラム
* プログラム名:	main.h
* 作成者:			林劭羲
* 作成日:			2022/06/17
*******************************************************************************/
#pragma once

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS			// scanf のwarning防止
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

/*******************************************************************************
* 列挙型定義
*******************************************************************************/
enum MODE
{
	GAME_TITLE,
	GAME_TUTORIAL,
	GAME_MODE_EASY,
	GAME_MODE_NORMAL,
	GAME_MODE_HARD,
	GAME_RESULT,
	GAME_END,
};

/*******************************************************************************
* マクロ定義
*******************************************************************************/
#define MAX_WORD_LENGTH (80)
#define FRAME_RATE (1000/10)

/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/
void Init();
void Update();
void Draw();
void Uninit();

int GetState();
void SetState(int state);

char *GetWindow();
