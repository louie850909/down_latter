/*******************************************************************************
* �^�C�g��:		�e�v���O����
* �v���O������:	bullet.cpp
* �쐬��:			�љ��
* �쐬��:			2022/07/02
*******************************************************************************/

/*******************************************************************************
* �C���N���[�h�t�@�C��
*******************************************************************************/
#include "bullet.h"
#include "enemy.h"
#include "collision.h"
#include "score.h"

/*******************************************************************************
* �O���[�o���ϐ�
*******************************************************************************/
BULLET g_Bullet[BULLET_MAX];

/*******************************************************************************
 �֐���:		InitBullet
 ����:		�Ȃ�
 �߂�l:		�Ȃ�
 ����:		�e������
*******************************************************************************/
void InitBullet()
{
	for (int i = 0; i < BULLET_MAX; i++)
	{
		g_Bullet[i].unit.use = false;
	}
}

/*******************************************************************************
 �֐���:		UpdateBullet
 ����:		�Ȃ�
 �߂�l:		�Ȃ�
 ����:		�e�X�V
*******************************************************************************/
void UpdateBullet()
{
	PLAYER* player = GetPlayer();
	FullwidthUnit* enemy = GetEnemy();
	
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (g_Bullet[i].unit.use == true)
		{
			//�ړ�����
			if (g_Bullet[i].dir == RIGHT)		// �v���C���[���E�Ɍ������Ƃ��A�e�͉E�Ɉړ�����
			{
				g_Bullet[i].unit.pos_x += 2;
			}
			else
			{
				g_Bullet[i].unit.pos_x -= 2;	// �v���C���[�����Ɍ������Ƃ��A�e�͍��Ɉړ�����
			}
			g_Bullet[i].unit.pos_y -= 1;
			
			//��ʊO�`�F�b�N
			if (g_Bullet[i].unit.pos_x < 2 || g_Bullet[i].unit.pos_x > 56 || g_Bullet[i].unit.pos_y < 2)
			{
				g_Bullet[i].unit.use = false;
			}

			//�G�Ƃ̓����蔻��
			for (int j = 0; j < ENEMY_MAX; j++)
			{
				if (enemy[j].use == true)
				{
					if (CheckCollision(g_Bullet[i].unit.pos_x, g_Bullet[i].unit.pos_y, g_Bullet[i].unit.width, g_Bullet[i].unit.height,
						enemy[j].pos_x, enemy[j].pos_y, enemy[j].width, enemy[j].height) == true)
					{
						enemy[j].use = false;
						g_Bullet[i].unit.use = false;
						AddScore(100);
					}
				}
			}
		}
	}
}

/*******************************************************************************
 �֐���:		DrawBullet
 ����:		�Ȃ�
 �߂�l:		�Ȃ�
 ����:		�e�`��
*******************************************************************************/
void DrawBullet()
{
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (g_Bullet[i].unit.use == true)
		{
			SetFullwidthUnit(GetWindow(), g_Bullet[i].unit);
		}
	}
}

/*******************************************************************************
 �֐���:		UninitBullet
 ����:		�Ȃ�
 �߂�l:		�Ȃ�
 ����:		�I������
*******************************************************************************/
void UninitBullet()
{
	for (int i = 0; i < BULLET_MAX; i++)
	{
		g_Bullet[i].unit.use = false;
	}
}

/*******************************************************************************
 �֐���:		SetBullet
 ����:		PLAYER* player
 �߂�l:		�Ȃ�
 ����:		�e��ݒu���܂�
*******************************************************************************/
void SetBullet(PLAYER* player)
{
 	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (g_Bullet[i].unit.use == false)		// ���g�p�̒e��T���܂�
		{
			if (player[0].direction == LEFT)	// �v���C���[�͍��Ɍ��������A�������ɒe��ݒu����
			{
				g_Bullet[i].dir = LEFT;
				g_Bullet[i].unit.pos_x = player[0].unit.pos_x - g_Bullet[i].unit.width;
				g_Bullet[i].unit.pos_y = player[0].unit.pos_y + 1;
				g_Bullet[i].unit.FullWidth = "�Z";
				g_Bullet[i].unit.height = 1;
				g_Bullet[i].unit.width = 1;
				g_Bullet[i].unit.use = true;
				return;
			}
			else								// �v���C���[�͉E�Ɍ��������A�E�����ɒe��ݒu����
			{
				g_Bullet[i].dir = RIGHT;
				g_Bullet[i].unit.pos_x = player[0].unit.pos_x - g_Bullet[i].unit.width;
				g_Bullet[i].unit.pos_y = player[0].unit.pos_y + 1;
				g_Bullet[i].unit.FullWidth = "�Z";
				g_Bullet[i].unit.height = 1;
				g_Bullet[i].unit.width = 1;
				g_Bullet[i].unit.use = true;
				return;
			}
		}
	}
}
