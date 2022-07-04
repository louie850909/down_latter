/*******************************************************************************
* �^�C�g��:		�`��v���O����
* �v���O������:	draw.cpp
* �쐬��:			�љ��
* �쐬��:			2022/06/17
*******************************************************************************/

/*******************************************************************************
* �C���N���[�h�t�@�C��
*******************************************************************************/
#include "draw.h"

/*******************************************************************************
 �֐���:		DrawWindow
 ����:		char *window
 �߂�l:		�Ȃ�
 ����:		window���̓��e����ʂɕ\������
*******************************************************************************/
void DrawWindow(char *window)
{
	printf("%s\r", window);
}

/*******************************************************************************
 �֐���:		SetHalfwidthUnit
 ����:		char *window, HalfwidthUnit obj
 �߂�l:		�Ȃ�
 ����:		���pobj��window�̒��ɓ�������
*******************************************************************************/
void SetHalfwidthUnit(char *window, HalfwidthUnit obj)
{
	for (int y = 0; y < obj.height; y++)
	{
		for (int x = 0; x < obj.width; x++)
		{
			window[(obj.pos_y + y) * WINDOW_WIDTH + obj.pos_x + x] = obj.Halfwidth;
		}
	}
	
}

/*******************************************************************************
 �֐���:		SetFullwidthUnit
 ����:		char *window, FullwidthUnit obj
 �߂�l:		�Ȃ�
 ����:		�S�pobj��window�̒��ɓ�������
*******************************************************************************/
void SetFullwidthUnit(char *window, FullwidthUnit obj)
{
	for (int y = 0; y < obj.height; y++)
	{
		for(int x = 0; x < obj.width * 2; x++)
		{
			window[(obj.pos_y + y) * WINDOW_WIDTH + obj.pos_x + x] = obj.FullWidth[x % 2];
		}
		
	}
}

/*******************************************************************************
 �֐���:		SetTextline
 ����:		char *window, Textline gametext
 �߂�l:		�Ȃ�
 ����:		�������window�̒��ɓ�������
*******************************************************************************/
void SetTextline (char* window, Textline gametext)
{
	int len = strlen(gametext.text);
	for (int i = 0; i < len; i++)
	{
		window[gametext.pos_y * WINDOW_WIDTH + gametext.pos_x + i] = gametext.text[i];
	}
}

/*******************************************************************************
 �֐���:		ClearWindow
 ����:		char *window
 �߂�l:		�Ȃ�
 ����:		window�̒��̓��e������
*******************************************************************************/
void ClearWindow(char* window)
{
	for (int y = 0; y < WINDOW_HEIGHT; y++)
	{
		for (int x = 0; x < WINDOW_WIDTH; x++)
		{
			window[y * WINDOW_WIDTH + x] = ' ';
		}
	}
}
