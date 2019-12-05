#include <iostream>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
enum Direction { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6 };

class ClassBall
{
private:
	int x, y;
	int oriX, oriY;
	Direction dir;
	
public:

	//Khởi tạo mặc định
	ClassBall::ClassBall()
	{}

	//Khởi tạo với tọa độ của Ball
	ClassBall::ClassBall(int pX, int pY)
	{
		oriX = pX;
		oriY = pY;
		x = pX;
		y = pY;
		dir = STOP;
	}

	//Reset vị trí của Ball
	void ClassBall::Reset()
	{
		x = oriX; y = oriY;
		dir = STOP;
	}

	//Thay đổi hướng di chuyển của Ball
	void ClassBall::changeDirection(Direction d)
	{
		dir = d;
	}

	//Ngẫu nhiên hướng di chuyển của Ball
	void ClassBall::randomDirection()
	{
		dir = (Direction)((rand() % 6) + 1);
	}

	//Hàm xác định hướng di chuyển của Ball
	void ClassBall::Move()
	{
		switch (dir)
		{
		case STOP:
			break;
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UPLEFT:
			x--; y--;
			break;
		case DOWNLEFT:
			x--; y++;
			break;
		case UPRIGHT:
			x++; y--;
			break;
		case DOWNRIGHT:
			x++; y++;
			break;
		default:
			break;
		}
	}

	//Lấy tọa độ của Ball
	inline int ClassBall::getX()
	{
		return x;
	}

	inline int ClassBall::getY()
	{
		return y;
	}

	//Lấy hướng của Ball
	inline Direction ClassBall::getDirection()
	{
		return dir;
	}

	//Hàm hủy
	ClassBall::~ClassBall()
	{
	}
};

