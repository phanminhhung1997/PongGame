#include "ClassBall.h"

class ClassPaddle
{
private:
	int x, y;
	int oriX, oriY;
public:
	//Khởi tạo mặc định
	ClassPaddle::ClassPaddle()
	{
		x = y = 0;
	}
	
	//Khởi tạo mặc định với 2 tham số
	ClassPaddle::ClassPaddle(int pX, int pY) : ClassPaddle()
	{
		oriX = pX;
		oriY = pY;
		x = pX;
		y = pY;
	}

	//Reset vị trí của Paddle
	inline void ClassPaddle::Reset()
	{
		x = oriX;
		y = oriY;
	}
	
	//Lấy vị trí của Pallde
	inline int ClassPaddle::getX()
	{
		return x;
	}
	inline int ClassPaddle::getY()
	{
		return y;
	}

	//Di chuyển Paddle
	inline void ClassPaddle::moveUp()
	{
		y -= 2;
	}
	inline void ClassPaddle::moveDown()
	{
		y += 2;
	}


};

