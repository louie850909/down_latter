/*******************************************************************************
* �^�C�g��:		�`��v���O����
* �v���O������:	draw.h
* �쐬��:			�љ��
* �쐬��:			2022/06/17
*******************************************************************************/
#pragma once

/*******************************************************************************
* �C���N���[�h�t�@�C��
*******************************************************************************/
#include <stdio.h>
#include <string.h>

/*******************************************************************************
* �}�N����`
*******************************************************************************/
#define WINDOW_WIDTH (80)
#define WINDOW_HEIGHT (25)
/*******************************************************************************
* �\���̒�`
*******************************************************************************/
struct HalfwidthUnit
{
	int pos_x;
	int pos_y;
	int width;
	int height;
	char Halfwidth;
	bool use;
};

struct FullwidthUnit
{
	int pos_x;
	int pos_y;
	int width;
	int height;
	const char* FullWidth;
	bool use;
};

struct Textline
{
	int pos_x;
	int pos_y;
	const char* text;
	bool use;
};

/*******************************************************************************
* �v���g�^�C�v�錾
*******************************************************************************/
void DrawWindow(char* window);
void SetHalfwidthUnit(char* window, HalfwidthUnit gameobj);
void SetFullwidthUnit(char* window, FullwidthUnit gameobj);
void SetTextline(char* window, Textline gametext);
void ClearWindow(char* window);


