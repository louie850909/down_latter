/*******************************************************************************
* �^�C�g��:		�`���[�g���A���v���O����
* �v���O������:	tutorial.cpp
* �쐬��:			�љ��
* �쐬��:			2022/06/25
*******************************************************************************/

/*******************************************************************************
* �C���N���[�h�t�@�C��
*******************************************************************************/
#include "tutorial.h"

/*******************************************************************************
* �O���[�o���ϐ�
*******************************************************************************/
FullwidthUnit tu_player;
FullwidthUnit tu_enemy;
FullwidthUnit tu_spike;
FullwidthUnit tu_platform;
//FullwidthUnit tu_bounceplat; todo
FullwidthUnit tu_arrow;

Textline tu_title;
FullwidthUnit tu_divider;

Textline tu_player_explain;
Textline tu_enemy_explain;
Textline tu_spike_explain;
Textline tu_platform_explain;
//Textline tu_bounceplat_explain; todo
FullwidthUnit tu_divider2;

Textline tu_select_difficulty;

Textline tu_easy_explain;
Textline tu_normal_explain;
Textline tu_hard_explain;

Textline tu_difficulty_easy;
Textline tu_difficulty_normal;
Textline tu_difficulty_hard;

/*******************************************************************************
 �֐���:		InitTutorial
 ����:		�Ȃ�
 �߂�l:		�Ȃ�
 ����:		������
*******************************************************************************/
void InitTutorial()
{
	tu_title				= { 33,1,"�`���[�g���A��", true };
	tu_divider				= { 0, 2, 40, 1, "�\", true };
	
	tu_player				= { 12, 3, 1, 1, "��", true };
	tu_enemy				= { 12, 4, 1, 1, "��", true };
	tu_spike				= { 12, 5, 1, 1, "��", true };
	tu_platform				= { 12, 6, 1, 1, "��", true };
	//tu_bounceplat			= { 12, 7, 1, 1, "��", true }; todo

	tu_player_explain		= { 14, 3, "�F�v���C���[�ł��A�����L�[�ō��E�𐧌䂷��A�X�y�[�X�ōU��", true };
	tu_enemy_explain		= { 14, 4, "�F�G�ł��A�G��ꂽ��HP������", true };
	tu_spike_explain		= { 14, 5, "�F�X�p�C�N�ł��A�G��ꂽ��HP������", true };
	tu_platform_explain		= { 14, 6, "�F�v���b�g�t�H�[���ł�", true };
	//tu_bounceplat_explain	= { 14, 7, "�F�o�E���h�v���b�g�t�H�[���ł��A�G��ꂽ���ɏオ��", true }; todo
	tu_divider2				= { 0, 8, 40, 1, "�\", true };

	tu_select_difficulty	= { 29, 11, "��Փx��I�����Ă�������", true };

	tu_easy_explain			= { 7, 14, "�v���b�g�t�H�[���̐��������A�G���Ȃ��A�X�p�C�N�ɂ��_���[�W�����Ȃ�", false };
	tu_normal_explain		= { 6, 14, "�v���b�g�t�H�[���̐���G�̐������Ȃ��A�G��X�p�C�N�ɂ��_���[�W������", false };
	tu_hard_explain			= { 1, 14, "�v���b�g�t�H�[���̐��������Ȃ߁A�G�̐��������A�G��X�p�C�N�ɂ��_���[�W������", false };

	tu_arrow				= { 34, 21, 1, 1, "��", true };
	tu_difficulty_easy		= { 36, 21, "�C�[�W�[", true };
	tu_difficulty_normal	= { 36, 22, "�m�[�}��", true };
	tu_difficulty_hard		= { 36, 23, "�n�[�h", true };
}

/*******************************************************************************
 �֐���:		UpdateTutorial
 ����:		�Ȃ�
 �߂�l:		�Ȃ�
 ����:		�X�V
*******************************************************************************/
void UpdateTutorial()
{	
	if (tu_arrow.pos_y == 21)
	{
		tu_easy_explain.use = true;
		tu_normal_explain.use = false;
		tu_hard_explain.use = false;
	}
	else if (tu_arrow.pos_y == 22)
	{
		tu_easy_explain.use = false;
		tu_normal_explain.use = true;
		tu_hard_explain.use = false;
	}
	else if (tu_arrow.pos_y == 23)
	{
		tu_easy_explain.use = false;
		tu_normal_explain.use = false;
		tu_hard_explain.use = true;
	}
	
	if (_kbhit() == 0)					// Key���͂��Ȃ��H
	{									// Key���͂��Ȃ����炱���Ń��^�[������
		return;
	}


	int key = _getch();					// �L�[���͏���
	if ((key == 0) || (key == 224))		// ����Key�Ȃ�����P�x�擾����
	{
		key = _getch();
	}

	// �����ꂽkey�̕����ֈړ�������
	switch (key)
	{
	case 'w':
	case 0x48:	// ��
		tu_arrow.pos_y = ((tu_arrow.pos_y - 1) % 3) + 21;
		break;

	case 's':
	case 0x50:	// ��
		tu_arrow.pos_y = ((tu_arrow.pos_y + 1) % 3) + 21;
		break;

	default:
		break;
	}

	// �����ꂽkey��Enter�Ȃ玟�̃V�[����
	if ((key == 13) && (tu_arrow.pos_y == 21))
	{
		SetState(GAME_MODE_EASY);
	}
	else if ((key == 13) && (tu_arrow.pos_y == 22))
	{
		SetState(GAME_MODE_NORMAL);
	}
	else if ((key == 13) && (tu_arrow.pos_y == 23))
	{
		SetState(GAME_MODE_HARD);
	}
}

/*******************************************************************************
 �֐���:		DrawTutorail
 ����:		�Ȃ�
 �߂�l:		�Ȃ�
 ����:		�`��
*******************************************************************************/
void DrawTutorial()
{
	SetTextline(GetWindow(), tu_title);
	SetFullwidthUnit(GetWindow(), tu_divider);

	SetFullwidthUnit(GetWindow(), tu_player);
	SetFullwidthUnit(GetWindow(), tu_enemy);
	SetFullwidthUnit(GetWindow(), tu_spike);
	SetFullwidthUnit(GetWindow(), tu_platform);
	//SetFullwidthUnit(GetWindow(), tu_bounceplat); todo

	SetTextline(GetWindow(), tu_player_explain);
	SetTextline(GetWindow(), tu_enemy_explain);
	SetTextline(GetWindow(), tu_spike_explain);
	SetTextline(GetWindow(), tu_platform_explain);
	//SetTextline(GetWindow(), tu_bounceplat_explain); todo
	SetFullwidthUnit(GetWindow(), tu_divider2);

	SetTextline(GetWindow(), tu_select_difficulty);

	if (tu_easy_explain.use == true)
	{
		SetTextline(GetWindow(), tu_easy_explain);
	}
	else if (tu_normal_explain.use == true)
	{
		SetTextline(GetWindow(), tu_normal_explain);
	}
	else if (tu_hard_explain.use == true)
	{
		SetTextline(GetWindow(), tu_hard_explain);
	}

	SetFullwidthUnit(GetWindow(), tu_arrow);
	SetTextline(GetWindow(), tu_difficulty_easy);
	SetTextline(GetWindow(), tu_difficulty_normal);
	SetTextline(GetWindow(), tu_difficulty_hard);

	DrawWindow(GetWindow());
}

/*******************************************************************************
 �֐���:		UninitTutorial
 ����:		�Ȃ�
 �߂�l:		�Ȃ�
 ����:		�I������
*******************************************************************************/
void UninitTutorial()
{
	ClearWindow(GetWindow());
}
