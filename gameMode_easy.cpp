/*******************************************************************************
* �^�C�g��:		�Q�[���C�[�W�[���[�h�v���O����
* �v���O������:	gameMode_easy.cpp
* �쐬��:			�љ��
* �쐬��:			2022/06/27
*******************************************************************************/

/*******************************************************************************
* �C���N���[�h�t�@�C��
*******************************************************************************/
#include "gameMode_easy.h"
#include "background.h"
#include "platform.h"
#include "player.h"
#include "spike.h"
#include "enemy.h"
#include "bullet.h"
#include "score.h"
#include "hp.h"

/*Game Over�̎��g�p���邽�߂̕�����*/
Textline g_eblank;
Textline g_eGameOver;
Textline g_eblank2;
Textline g_eContinue;
Textline g_eblank3;

/*******************************************************************************
 �֐���:		InitGameModeEasy
 ����:		�Ȃ�
 �߂�l:		�Ȃ�
 ����:		������
*******************************************************************************/
void InitGameModeEasy()
{
	InitBackground();
	InitScore();
	InitPlatform();
	InitSpike();
	InitEnemy();
	InitBullet();
	InitPlayer();
	InitHp();
	
	g_eblank		= { 2,11,"--------------------------------------------------------",false };
	g_eGameOver		= { 2,12,"|                        Game Over                     |",false };
	g_eblank2		= { 2,13,"|                                                      |",false };
	g_eContinue		= { 2,14,"|                Press ENTER to continue               |",false };
	g_eblank3		= { 2,15,"--------------------------------------------------------",false };
}

/*******************************************************************************
 �֐���:		UpdateGameModeEasy
 ����:		�Ȃ�
 �߂�l:		�Ȃ�
 ����:		�X�V
*******************************************************************************/
void UpdateGameModeEasy()
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
		g_eblank.use = true;
		g_eblank2.use = true;
		g_eblank3.use = true;
		g_eGameOver.use = true;
		g_eContinue.use = true;
		
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
 �֐���:		DrawGameModeEasy
 ����:		�Ȃ�
 �߂�l:		�Ȃ�
 ����:		�`��
*******************************************************************************/
void DrawGameModeEasy()
{
	DrawBackground();
	DrawScore();
	DrawPlatform();
	DrawSpike();
	DrawEnemy();
	DrawBullet();
	DrawPlayer();
	DrawHp();

	if (g_eGameOver.use == true)
	{
		SetTextline(GetWindow(), g_eGameOver);
	}

	if (g_eContinue.use == true)
	{
		SetTextline(GetWindow(), g_eContinue);
	}
	
	if (g_eblank.use == true)
	{
		SetTextline(GetWindow(), g_eblank);
	}
	
	if (g_eblank2.use == true)
	{
		SetTextline(GetWindow(), g_eblank2);
	}

	if (g_eblank3.use == true)
	{
		SetTextline(GetWindow(), g_eblank3);
	}
	
	DrawWindow(GetWindow());
}

/*******************************************************************************
 �֐���:		UninitGameModeEasy
 ����:		�Ȃ�
 �߂�l:		�Ȃ�
 ����:		�I������
*******************************************************************************/
void UninitGameModeEasy()
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
