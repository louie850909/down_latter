/*******************************************************************************
* �^�C�g��:		���C���v���O����
* �v���O������:	main.cpp
* �쐬��:			�љ��
* �쐬��:			2022/06/17
*******************************************************************************/

/*******************************************************************************
* �C���N���[�h�t�@�C��
*******************************************************************************/
#include "main.h"
#include "draw.h"
#include "title.h"
#include "tutorial.h"
#include "gameMode_easy.h"
#include "gameMode_normal.h"
#include "gameMode_hard.h"
#include "result.h"

/*******************************************************************************
* �O���[�o���ϐ�
*******************************************************************************/
int		g_State;													// ���
char	g_Window[WINDOW_HEIGHT][WINDOW_WIDTH];						// �E�B���h�E

//=============================================================================
// ���C���֐�
//=============================================================================
int main()
{
	Init();

	while (GetState() < GAME_END)
	{
		
		Update();

		Draw();
	}

	Uninit();

	return 0;
}

//=============================================================================
// ����������
//=============================================================================
void Init()
{
	srand((unsigned)time(NULL));
	ClearWindow(GetWindow());
	SetState(GAME_TITLE);										// �^�C�g���X�^�[�g
}

//=============================================================================
// �X�V����
//=============================================================================
void Update()
{
	switch (GetState())
	{
	case GAME_TITLE:
		UpdateTitle();
		break;
		
	case GAME_TUTORIAL:
		UpdateTutorial();
		break;

	case GAME_MODE_EASY:
		UpdateGameModeEasy();
		break;

	case GAME_MODE_NORMAL:
		UpdateGameModeNormal();
		break;

	case GAME_MODE_HARD:
		UpdateGameModeHard();
		break;

	case GAME_RESULT:
		UpdateResult();
		break;
		
	default:
		break;
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void Draw()
{
	switch (GetState())
	{
	case GAME_TITLE:
		DrawTitle();
		break;

	case GAME_TUTORIAL:
		DrawTutorial();
		break;
		
	case GAME_MODE_EASY:
		DrawGameModeEasy();
		break;

	case GAME_MODE_NORMAL:
		DrawGameModeNormal();
		break;

	case GAME_MODE_HARD:
		DrawGameModeHard();
		break;
		
	case GAME_RESULT:
		DrawResult();
		break;
		
	case GAME_END:
		break;
		
	default:
		break;

	}
	
	ClearWindow(GetWindow());
	Sleep(FRAME_RATE);
}

void Uninit()
{
	
}

int GetState()
{
	return g_State;
}

//=============================================================================
// �X�e�[�g�̐ݒ�
//=============================================================================
void SetState(int state)
{
	UninitTitle();
	UninitTutorial();
	UninitGameModeEasy();
	UninitGameModeNormal();
	UninitGameModeHard();
	UninitResult();
	
	g_State = state;
	
	switch (state)
	{
	case GAME_TITLE:
		InitTitle();
		break;

	case GAME_TUTORIAL:
		InitTutorial();
		break;
		
	case GAME_MODE_EASY:
		InitGameModeEasy();
		break;
		
	case GAME_MODE_NORMAL:
		InitGameModeNormal();
		break;

	case GAME_MODE_HARD:
		InitGameModeHard();
		break;

	case GAME_RESULT:
		InitResult();
		break;

	case GAME_END:
		break;

	default:
		break;

	}
}

//=============================================================================
// �E�B���h�E�̎擾
//=============================================================================
char *GetWindow()
{
	return &g_Window[0][0];
}