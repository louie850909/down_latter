/*******************************************************************************
* �^�C�g��:		�Q�[���m�[�}�����[�h�v���O����
* �v���O������:	gameMode_normal.cpp
* �쐬��:			�љ��
* �쐬��:			2022/07/04
*******************************************************************************/

/*******************************************************************************
* �C���N���[�h�t�@�C��
*******************************************************************************/
#include "gameMode_normal.h"
#include "background.h"
#include "platform.h"
#include "player.h"
#include "spike.h"
#include "enemy.h"
#include "bullet.h"
#include "score.h"
#include "hp.h"

/*Game Over�̎��g�p���邽�߂̕�����*/
Textline g_nblank;
Textline g_nGameOver;
Textline g_nblank2;
Textline g_nContinue;
Textline g_nblank3;

/*******************************************************************************
 �֐���:		InitGameModeNormal
 ����:		�Ȃ�
 �߂�l:		�Ȃ�
 ����:		������
*******************************************************************************/
void InitGameModeNormal()
{
	InitBackground();
	InitScore();
	InitPlatform();
	InitSpike();
	InitEnemy();
	InitBullet();
	InitPlayer();
	InitHp();

	g_nblank	= { 2,11,"--------------------------------------------------------",false };
	g_nGameOver = { 2,12,"|                        Game Over                     |",false };
	g_nblank2	= { 2,13,"|                                                      |",false };
	g_nContinue = { 2,14,"|                Press ENTER to continue               |",false };
	g_nblank3	= { 2,15,"--------------------------------------------------------",false };
}

/*******************************************************************************
 �֐���:		UpdateGameModeNormal
 ����:		�Ȃ�
 �߂�l:		�Ȃ�
 ����:		�X�V
*******************************************************************************/
void UpdateGameModeNormal()
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
		g_nblank.use = true;
		g_nblank2.use = true;
		g_nblank3.use = true;
		g_nGameOver.use = true;
		g_nContinue.use = true;

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
 �֐���:		DrawGameModeNormal
 ����:		�Ȃ�
 �߂�l:		�Ȃ�
 ����:		�`��
*******************************************************************************/
void DrawGameModeNormal()
{
	DrawBackground();
	DrawScore();
	DrawPlatform();
	DrawSpike();
	DrawEnemy();
	DrawBullet();
	DrawPlayer();
	DrawHp();

	if (g_nGameOver.use == true)
	{
		SetTextline(GetWindow(), g_nGameOver);
	}

	if (g_nContinue.use == true)
	{
		SetTextline(GetWindow(), g_nContinue);
	}

	if (g_nblank.use == true)
	{
		SetTextline(GetWindow(), g_nblank);
	}

	if (g_nblank2.use == true)
	{
		SetTextline(GetWindow(), g_nblank2);
	}

	if (g_nblank3.use == true)
	{
		SetTextline(GetWindow(), g_nblank3);
	}

	DrawWindow(GetWindow());
}

/*******************************************************************************
 �֐���:		UninitGameModeNormal
 ����:		�Ȃ�
 �߂�l:		�Ȃ�
 ����:		�I������
*******************************************************************************/
void UninitGameModeNormal()
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
