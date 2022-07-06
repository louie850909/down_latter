/*******************************************************************************
* �^�C�g��:		�X�R�A�v���O����
* �v���O������:	score.cpp
* �쐬��:			�љ��
* �쐬��:			2022/07/05
*******************************************************************************/

/*******************************************************************************
* �C���N���[�h�t�@�C��
*******************************************************************************/
#include "score.h"

/*******************************************************************************
* �O���[�o���ϐ�
*******************************************************************************/
SCORE g_Score;

/*******************************************************************************
 �֐���:		InitScore
 ����:		�Ȃ�
 �߂�l:		�Ȃ�
 ����:		�X�R�A�̏�����
*******************************************************************************/
void InitScore()
{
	g_Score.value = 0;
	g_Score.singleDigit		= { 74, 11, 1, 1, "�O", false };
	g_Score.tenDigit		= { 72, 11, 1, 1, "�O", false };
	g_Score.hundredDigit	= { 70, 11, 1, 1, "�O", false };
	g_Score.kiloDigit		= { 68, 11, 1, 1, "�O", false };
	g_Score.tenK_Digit		= { 66, 11, 1, 1, "�O", false };
	g_Score.hundredK_Digit	= { 64, 11, 1, 1, "�O", false };
}

/*******************************************************************************
 �֐���:		UpdateScore
 ����:		�Ȃ�
 �߂�l:		�Ȃ�
 ����:		�X�R�A�̍X�V
*******************************************************************************/
void UpdateScore()
{
	if (g_Score.value <= 999999)
	{
		int num = g_Score.value;
		g_Score.singleDigit.FullWidth		= Convert(num % 10);
		g_Score.singleDigit.use = true;
		num /= 10;
		g_Score.tenDigit.FullWidth			= Convert(num % 10);
		g_Score.tenDigit.use = true;
		num /= 10;
		g_Score.hundredDigit.FullWidth		= Convert(num % 10);
		g_Score.hundredDigit.use = true;
		num /= 10;
		g_Score.kiloDigit.FullWidth			= Convert(num % 10);
		g_Score.kiloDigit.use = true;
		num /= 10;
		g_Score.tenK_Digit.FullWidth		= Convert(num % 10);
		g_Score.tenK_Digit.use = true;
		num /= 10;
		g_Score.hundredK_Digit.FullWidth	= Convert(num % 10);
		g_Score.hundredK_Digit.use = true;

		g_Score.value += 1;
	}
}

/*******************************************************************************
 �֐���:		DrawSpike
 ����:		�Ȃ�
 �߂�l:		�Ȃ�
 ����:		�X�R�A�̕`��
*******************************************************************************/
void DrawScore()
{
	if (g_Score.singleDigit.use == true)
	{
		SetFullwidthUnit(GetWindow(), g_Score.singleDigit);
	}
	if (g_Score.tenDigit.use == true)
	{
		SetFullwidthUnit(GetWindow(), g_Score.tenDigit);
	}
	if (g_Score.hundredDigit.use == true)
	{
		SetFullwidthUnit(GetWindow(), g_Score.hundredDigit);
	}
	if (g_Score.kiloDigit.use == true)
	{
		SetFullwidthUnit(GetWindow(), g_Score.kiloDigit);
	}
	if (g_Score.tenK_Digit.use == true)
	{
		SetFullwidthUnit(GetWindow(), g_Score.tenK_Digit);
	}
	if (g_Score.hundredK_Digit.use == true)
	{
		SetFullwidthUnit(GetWindow(), g_Score.hundredK_Digit);
	}
}

/*******************************************************************************
 �֐���:		UninitSpike
 ����:		�Ȃ�
 �߂�l:		�Ȃ�
 ����:		�X�R�A�̏I������
*******************************************************************************/
void UninitScore()
{
	
}

/*******************************************************************************
 �֐���:		AddScore
 ����:		������������
 �߂�l:		�Ȃ�
 ����:		�X�R�A�𑫂�
*******************************************************************************/
void AddScore(int value)
{
	g_Score.value += value;
}

/*******************************************************************************
 �֐���:		GetSpike
 ����:		�Ȃ�
 �߂�l:		�X�R�A�̃A�h���X
 ����:		�X�R�A�̃A�h���X��Ԃ�
*******************************************************************************/
SCORE* GetScore()
{
	return &g_Score;
}

/*******************************************************************************
 �֐���:		Convert
 ����:		����������������
 �߂�l:		������
 ����:		�����𕶎���ɕϊ�����
*******************************************************************************/
const char* Convert(int value)
{
	switch (value)
	{
		case 0:
			return "�O";
			break;
			
		case 1:
			return "�P";
			break;
			
		case 2:
			return "�Q";
			break;

		case 3:
			return "�R";
			break;
			
		case 4:
			return "�S";
			break;
			
		case 5:
			return "�T";
			break;
			
		case 6:
			return "�U";
			break;
			
		case 7:
			return "�V";
			break;
			
		case 8:
			return "�W";
			break;
			
		case 9:
			return "�X";
			break;
	default:
		break;
	}
}
