#include "result.h"
#include "score.h"

RANK g_f = {'f'," ######## " 
			   ," ##       "
			   ," #######  "
			   ," ##       "
			   ," ##       "};

RANK g_e = {'e'," ######## " 
			   ," ##       "
			   ," ######## "
			   ," ##       "
			   ," ######## "};

RANK g_d = {'d'," ######   " 
			   ," ##   ##  "
			   ," ##    ## "
			   ," ##   ##  "
			   ," ######   "};

RANK g_c = {'c',"   ###### " 
			   ," ##       "
			   ,"###       "
			   ," ##       "
			   ,"   ###### "};

RANK g_b = {'b'," #######  " 
			   ," ##     # "
			   ," #######  "
			   ," ##     # "
			   ," #######  "};

RANK g_a = {'a',"   ####   " 
			   ,"  ##   #  "
			   ," ######## "
			   ," ##     # "
			   ," ##     # "};

RANK g_s = {'s',"  ####### " 
			   ,"###       "
			   ," #######  "
			   ,"      ### "
			   ," ######   "};

Textline line1;
Textline line2;
Textline line3;
Textline line4;
Textline line5;

Textline title;
Textline textline;
Textline score1;
Textline score2;
Textline score3;
Textline score4;
Textline score5;
Textline score6;

FullwidthUnit g_arrow;
Textline g_back_to_title;
Textline g_quit_game;

void InitResult()
{
	line1		= { 50, 6, g_f.line1, false };
	line2		= { 50, 7, g_f.line2, false };
	line3		= { 50, 8, g_f.line3, false };
	line4		= { 50, 9, g_f.line4, false };
	line5		= { 50,10, g_f.line5, false };

	title		= { 36, 2, "RESULT", true };
	textline	= { 10, 8, "あなたのスコアは：", true };
	score1		= { 28, 8, "０", false };
	score2		= { 30, 8, "０", false };
	score3		= { 32, 8, "０", false };
	score4		= { 34, 8, "０", false };
	score5		= { 36, 8, "０", false };
	score6		= { 38, 8, "０", false };

	g_arrow			= { 30, 21, 1, 1, "→", true };
	g_back_to_title = { 32, 21, "タイトルに戻る", true };
	g_quit_game		= { 32, 22, "ゲームを閉じる", true };
}

void UpdateResult()
{
	SCORE* score = GetScore();

	score1.text = score[0].hundredK_Digit.FullWidth;
	score1.use = true;
	score2.text = score[0].tenK_Digit.FullWidth;
	score2.use = true;
	score3.text = score[0].kiloDigit.FullWidth;
	score3.use = true;
	score4.text = score[0].hundredDigit.FullWidth;
	score4.use = true;
	score5.text = score[0].tenDigit.FullWidth;
	score5.use = true;
	score6.text = score[0].singleDigit.FullWidth;
	score6.use = true;

	if (score[0].value <= 100)
	{
		line1.text = g_f.line1;
		line2.text = g_f.line2;
		line3.text = g_f.line3;
		line4.text = g_f.line4;
		line5.text = g_f.line5;
	}
	else if (score[0].value > 100 && score[0].value <= 200)
	{
		line1.text = g_e.line1;
		line2.text = g_e.line2;
		line3.text = g_e.line3;
		line4.text = g_e.line4;
		line5.text = g_e.line5;
	}
	else if (score[0].value > 200 && score[0].value <= 300)
	{
		line1.text = g_d.line1;
		line2.text = g_d.line2;
		line3.text = g_d.line3;
		line4.text = g_d.line4;
		line5.text = g_d.line5;
	}
	else if (score[0].value > 300 && score[0].value <= 400)
	{
		line1.text = g_c.line1;
		line2.text = g_c.line2;
		line3.text = g_c.line3;
		line4.text = g_c.line4;
		line5.text = g_c.line5;
	}
	else if (score[0].value > 400 && score[0].value <= 500)
	{
		line1.text = g_b.line1;
		line2.text = g_b.line2;
		line3.text = g_b.line3;
		line4.text = g_b.line4;
		line5.text = g_b.line5;
	}
	else if (score[0].value > 500 && score[0].value <= 600)
	{
		line1.text = g_a.line1;
		line2.text = g_a.line2;
		line3.text = g_a.line3;
		line4.text = g_a.line4;
		line5.text = g_a.line5;
	}
	else if (score[0].value > 600)
	{
		line1.text = g_s.line1;
		line2.text = g_s.line2;
		line3.text = g_s.line3;
		line4.text = g_s.line4;
		line5.text = g_s.line5;
	}
	line1.use = true;
	line2.use = true;
	line3.use = true;
	line4.use = true;
	line5.use = true;
	
	if (_kbhit() == 0)					// Key入力がない？
	{									// Key入力がないからここでリターンする
		return;
	}


	int key = _getch();					// キー入力処理
	if ((key == 0) || (key == 224))		// 特殊Keyならもう１度取得する
	{
		key = _getch();
	}

	// 押されたkeyの方向へ移動させる
	switch (key)
	{
	case 'w':
	case 0x48:	// ↑
		g_arrow.pos_y = ((g_arrow.pos_y - 2) % 2) + 21;
		break;

	case 's':
	case 0x50:	// ↓
		g_arrow.pos_y = ((g_arrow.pos_y + 2) % 2) + 21;
		break;

	default:
		break;
	}

	// 押されたkeyがEnterなら次のシーンへ
	if ((key == 13) && (g_arrow.pos_y == 21))
	{
		SetState(GAME_TITLE);
	}
	else if ((key == 13) && (g_arrow.pos_y == 22))
	{
		SetState(GAME_END);
	}
}

void DrawResult()
{
	if (line1.use == true)
	{
		SetTextline(GetWindow(), line1);
	}
	if (line2.use == true)
	{
		SetTextline(GetWindow(), line2);
	}
	if (line3.use == true)
	{
		SetTextline(GetWindow(), line3);
	}
	if (line4.use == true)
	{
		SetTextline(GetWindow(), line4);
	}
	if (line5.use == true)
	{
		SetTextline(GetWindow(), line5);
	}

	SetTextline(GetWindow(), title);
	SetTextline(GetWindow(), textline);
	
	if (score1.use == true)
	{
		SetTextline(GetWindow(), score1);
	}
	if (score2.use == true)
	{
		SetTextline(GetWindow(), score2);
	}
	if (score3.use == true)
	{
		SetTextline(GetWindow(), score3);
	}
	if (score4.use == true)
	{
		SetTextline(GetWindow(), score4);
	}
	if (score5.use == true)
	{
		SetTextline(GetWindow(), score5);
	}
	if (score6.use == true)
	{
		SetTextline(GetWindow(), score6);
	}

	SetFullwidthUnit(GetWindow(), g_arrow);
	SetTextline(GetWindow(), g_back_to_title);
	SetTextline(GetWindow(), g_quit_game);

	DrawWindow(GetWindow());
}

void UninitResult()
{
	ClearWindow(GetWindow());
}
