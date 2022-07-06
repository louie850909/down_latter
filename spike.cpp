/*******************************************************************************
* �^�C�g��:		�X�p�C�N�v���O����
* �v���O������:	spike.cpp
* �쐬��:			�љ��
* �쐬��:			2022/07/01
*******************************************************************************/

/*******************************************************************************
* �C���N���[�h�t�@�C��
*******************************************************************************/
#include "spike.h"
#include "player.h"

/*******************************************************************************
* �O���[�o���ϐ�
*******************************************************************************/
FullwidthUnit g_spike[SPIKE_MAX];

/*******************************************************************************
 �֐���:		InitSpike
 ����:		�Ȃ�
 �߂�l:		�Ȃ�
 ����:		�X�p�C�N������
*******************************************************************************/
void InitSpike()
{
	switch (GetState())					//��Փx�ɂ���Ďg�p���ꂽ�v���b�g�t�H�[�������Ⴄ
	{
	case GAME_MODE_HARD:				//�S�����g�p����
		for (int i = 0; i < SPIKE_MAX; i++)
		{
			g_spike[i].pos_x = (rand() % 49) + 2;
			g_spike[i].pos_y = i * 8 + 3;
			g_spike[i].height = 1;
			g_spike[i].width = 4;
			g_spike[i].FullWidth = "��";
			g_spike[i].use = true;
		}
		break;

	case GAME_MODE_NORMAL:				//����g�p����
		for (int i = 0; i < SPIKE_MAX - 1; i++)
		{
			g_spike[i].pos_x = (rand() % 49) + 2;
			g_spike[i].pos_y = i * 8 + 3;
			g_spike[i].height = 1;
			g_spike[i].width = 4;
			g_spike[i].FullWidth = "��";
			g_spike[i].use = true;
		}

		for (int i = SPIKE_MAX - 1; i < SPIKE_MAX; i++)
		{
			g_spike[i].use = false;
		}
		break;

	case GAME_MODE_EASY:				//����g�p����
		for (int i = 0; i < SPIKE_MAX - 2; i++)
		{
			g_spike[i].pos_x = (rand() % 49) + 2;
			g_spike[i].pos_y = i * 8 + 3;
			g_spike[i].height = 1;
			g_spike[i].width = 4;
			g_spike[i].FullWidth = "��";
			g_spike[i].use = true;
		}

		for (int i = SPIKE_MAX - 2; i < SPIKE_MAX; i++)
		{
			g_spike[i].use = false;
		}
		break;

	default:
		break;
	}
}

/*******************************************************************************
 �֐���:		UpdateSpike
 ����:		�Ȃ�
 �߂�l:		�Ȃ�
 ����:		�X�p�C�N�X�V
*******************************************************************************/
void UpdateSpike()
{
	PLAYER* p = GetPlayer();
	if (p[0].unit.use == true)
	{
		for (int i = 0; i < SPIKE_MAX; i++)
		{
			if (g_spike[i].use == true)
			{
				g_spike[i].pos_y -= 1;		//�X�p�C�N�͉�ʂ̏�ɏオ��܂�

				if (g_spike[i].pos_y < 2)	//�͈͊O�ɂȂ������A���ɖ߂�܂�
				{
					g_spike[i].pos_x = (rand() % 46) + 5;
					g_spike[i].pos_y = 24;
				}
			}
		}
	}
}

/*******************************************************************************
 �֐���:		DrawSpike
 ����:		�Ȃ�
 �߂�l:		�Ȃ�
 ����:		�X�p�C�N�`��
*******************************************************************************/
void DrawSpike()
{
	for (int i = 0; i < SPIKE_MAX; i++)
	{
		if (g_spike[i].use == true)		//�g�p���Ă���X�p�C�N�����ŕ`�悷��
		{
			SetFullwidthUnit(GetWindow(), g_spike[i]);
		}
	}
}

/*******************************************************************************
 �֐���:		UninitSpike
 ����:		�Ȃ�
 �߂�l:		�Ȃ�
 ����:		�X�p�C�N�I��
*******************************************************************************/
void UninitSpike()
{
	for (int i = 0; i < SPIKE_MAX; i++)
	{
		g_spike[i].use = false;
	}
}

/*******************************************************************************
 �֐���:		GetSpike
 ����:		�Ȃ�
 �߂�l:		�X�p�C�N�̃A�h���X
 ����:		�X�p�C�N�̃A�h���X��Ԃ�
*******************************************************************************/
FullwidthUnit* GetSpike()
{
	return &g_spike[0];
}
