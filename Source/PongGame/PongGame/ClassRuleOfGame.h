#include "ClassPaddle.h"

class ClassRuleOfGame
{
private:
	int width, height;
	int scorePlayer1, scorePlayer2;
	char goUpPaddle1, goDownPaddle1, goUpPaddle2, goDownPaddle2;
	bool exitGame;
	ClassBall *ball;
	ClassPaddle *player1;
	ClassPaddle *player2;
public:
	//Khởi tạo hàm quản lý luật chơi
	ClassRuleOfGame(int w, int h)
	{
		srand(time(NULL));
		exitGame = false;
		goUpPaddle1 = 'w'; goUpPaddle2 = 72;
		goDownPaddle1 = 's'; goDownPaddle2 = 80;
		scorePlayer1 = scorePlayer2 = 0;
		width = w; height = h;
		ball = new ClassBall(w / 2, h / 2);
		player1 = new ClassPaddle(1, h / 2 - 3);
		player2 = new ClassPaddle(w - 2, h / 2 - 3);
	}

	//Hàm hủy
	~ClassRuleOfGame()
	{
		delete ball, player1, player2;
	}

	//Cập nhật điểm cho người chơi
	void scoreUpdate(ClassPaddle * player)
	{
		if (player == player1)
		{
			scorePlayer1++;
			if (scorePlayer1 == 10)
			{
				scorePlayer1 = 0;
				cout << "Player 1 Win!" << endl;
				system("pause");
			}
		}
		else if (player == player2)
		{
			scorePlayer2++;
			if (scorePlayer2 == 10)
			{
				scorePlayer2 = 0;
				cout << "Player 2 Win!" << endl;
				system("pause");
			}
		}

		ball->Reset();
		player1->Reset();
		player2->Reset();
	}

	//Hàm vẽ giao diện trò chơi
	void Draw()
	{
		//Xuất điểm cho người chơi
		cout << "Score Player 1: " << scorePlayer1 << endl << "Score Player 2: " << scorePlayer2 << endl;

		system("cls");
		for (int i = 0; i < width + 2; i++)
			cout << "\xB2";
		cout << endl;

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				int ball_x = ball->getX();
				int ball_y = ball->getY();
				int player1_x = player1->getX();
				int player2_x = player2->getX();
				int player1_y = player1->getY();
				int player2_y = player2->getY();

				if (j == 0)
					cout << "\xB2";

				//Vẽ ball
				if (ball_x == j && ball_y == i)
					cout << "0"; 

				//Vẽ paddle
				else if (player1_x == j && player1_y == i)
					cout << "\xDB"; //player1
				else if (player1_x == j && player1_y + 1 == i)
					cout << "\xDB"; //player1
				else if (player1_x == j && player1_y + 2 == i)
					cout << "\xDB"; //player1
				else if (player1_x == j && player1_y + 3 == i)
					cout << "\xDB"; //player1

				else if (player2_x == j && player2_y == i)
					cout << "\xDB"; //player2
				else if (player2_x == j && player2_y + 1 == i)
					cout << "\xDB"; //player1
				else if (player2_x == j && player2_y + 2 == i)
					cout << "\xDB"; //player1
				else if (player2_x == j && player2_y + 3 == i)
					cout << "\xDB"; //player1
				else
					cout << " ";

				if (j == width - 1)
					cout << "\xB2";
			}
			cout << endl;
		}

		for (int i = 0; i < width + 2; i++)
			cout << "\xB2";
		cout << endl;

		
	}

	void Input()
	{
		ball->Move();

		int ball_x = ball->getX();
		int ball_y = ball->getY();
		int player1_x = player1->getX();
		int player2_x = player2->getX();
		int player1_y = player1->getY();
		int player2_y = player2->getY();

		if (_kbhit())
		{
			char current = _getch();
			if (current == goUpPaddle1)
				if (player1_y > 0)
					player1->moveUp();
			if (current == goUpPaddle2)
				if (player2_y > 0)
					player2->moveUp();
			if (current == goDownPaddle1)
				if (player1_y + 4 < height)
					player1->moveDown();
			if (current == goDownPaddle2)
				if (player2_y + 4 < height)
					player2->moveDown();

			if (ball->getDirection() == STOP)
				ball->randomDirection();

			//Thoát game bằng nút z
			if (current == 'z' || current == 'Z')
				exitGame = true;
		}
	}

	//Hàm xử lý va chạm
	void Handle()
	{
		int ball_x = ball->getX();
		int ball_y = ball->getY();
		int player1_x = player1->getX();
		int player2_x = player2->getX();
		int player1_y = player1->getY();
		int player2_y = player2->getY();

		//Xử lý ball va chạm paddle trái
		for (int i = 0; i < 4; i++)
			if (ball_x == player1_x + 1)
				if (ball_y == player1_y + i)
					ball->changeDirection((Direction)((rand() % 3) + 4));

		//Xử lý ball va chạm paddle phải
		for (int i = 0; i < 4; i++)
			if (ball_x == player2_x - 1)
				if (ball_y == player2_y + i)
					ball->changeDirection((Direction)((rand() % 3) + 1));

		//Xử lý ball va chạm Wall dưới
		if (ball_y == height - 1)
			ball->changeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);
		//Xử lý ball va chạm Wall trên
		if (ball_y == 0)
			ball->changeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
		//Xử lý ball va chạm Wall phải
		if (ball_x == width - 1)
			scoreUpdate(player1);
		//Xử lý ball va chạm Wall trái
		if (ball_x == 0)
			scoreUpdate(player2);
	}

	//Hàm run game
	void Run()
	{
		while (!exitGame)
		{
			Draw();
			Input();
			Handle();
		}
	}
};