/*******************************************************************************
* �^�C�g��:		�Q�[���n�[�h���[�h�v���O����
* �v���O������:	gameMode_hard.cpp
* �쐬��:			�љ��
* �쐬��:			2022/06/27
*******************************************************************************/

/*******************************************************************************
* �C���N���[�h�t�@�C��
*******************************************************************************/
#include "gameMode_hard.h"
#include "background.h"
#include "platform.h"
#include "player.h"
#include "spike.h"
#include "enemy.h"
#include "bullet.h"
#include "score.h"
#include "hp.h"

Textline g_hblank;
Textline g_hGameOver;
Textline g_hblank2;
Textline g_hContinue;
Textline g_hblank3;

/*******************************************************************************
 �֐���:		InitGameModeHard
 ����:		�Ȃ�
 �߂�l:		�Ȃ�
 ����:		������
*******************************************************************************/
void InitGameModeHard()
{
	InitBackground();
	InitScore();
	InitPlatform();
	InitSpike();
	InitEnemy();
	InitBullet();
	InitPlayer();
	InitHp();

	g_hblank = { 2,11,"--------------------------------------------------------",false };
	g_hGameOver = { 2,12,"|                        Game Over                     |",false };
	g_hblank2 = { 2,13,"|                                                      |",false };
	g_hContinue = { 2,14,"|                Press ENTER to continue               |",false };
	g_hblank3 = { 2,15,"--------------------------------------------------------",false };
}

/*******************************************************************************
 �֐���:		UpdateGameModeHard
 ����:		�Ȃ�
 �߂�l:		�Ȃ�
 ����:		�X�V
*******************************************************************************/
void UpdateGameModeHard()
{
	PLAYER* p = GetPlayer();
	if (p[0].unit.use == true)
	{
		UpdateBackground();
		UpdateScore();
		UpdatePlatform();
		UpdateSpike();
		UpdateEnemy();
		UpdatePlayer();
		UpdateBullet();
		UpdateHp();
	}
	else									// �v���C���[��������Ƃ�GAMEOVER�������o���܂�
	{
		g_hblank.use = true;
		g_hblank2.use = true;
		g_hblank3.use = true;
		g_hGameOver.use = true;
		g_hContinue.use = true;

		if (_kbhit() == 0)					// Key���͂��Ȃ��H
		{									// Key���͂��Ȃ����炱���Ń��^�[������
			return;
		}

		int key = _getch();					// �L�[���͏���
		if ((key == 0) || (key == 224))		// ����Key�Ȃ�����P�x�擾����
		{
			key = _getch();
		}

		// �����ꂽkey��Enter�Ȃ玟�̃V�[����
		if (key == 13)
		{
			SetState(GAME_RESULT);
		}
	}
}

/*******************************************************************************
 �֐���:		DrawGameModeHard
 ����:		�Ȃ�
 �߂�l:		�Ȃ�
 ����:		�`��
*******************************************************************************/
void DrawGameModeHard()
{
	DrawBackground();
	DrawScore();
	DrawPlatform();
	DrawSpike();
	DrawEnemy();
	DrawBullet();
	DrawPlayer();
	DrawHp();

	if (g_hGameOver.use == true)
	{
		SetTextline(GetWindow(), g_hGameOver);
	}

	if (g_hContinue.use == true)
	{
		SetTextline(GetWindow(), g_hContinue);
	}

	if (g_hblank.use == true)
	{
		SetTextline(GetWindow(), g_hblank);
	}

	if (g_hblank2.use == true)
	{
		SetTextline(GetWindow(), g_hblank2);
	}

	if (g_hblank3.use == true)
	{
		SetTextline(GetWindow(), g_hblank3);
	}

	DrawWindow(GetWindow());
}

/*******************************************************************************
 �֐���:		UninitGameModeHard
 ����:		�Ȃ�
 �߂�l:		�Ȃ�
 ����:		�I������
*******************************************************************************/
void UninitGameModeHard()
{
	UninitBackground();
	UninitScore();
	UninitPlatform();
	UninitSpike();
	UninitEnemy();
	UninitBullet();
	UninitPlayer();
	UninitHp();
}
