#include <iostream>
#include <time.h>
#include <conio.h>
#include <Windows.h>

using namespace std;
enum eDir { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6 };


class cBall
{
private:
    int x, y;
    int startingX, startingY;
    eDir direction;

public:
    cBall(int posX, int posY)
    {
        startingX = posX;
        startingY = posY;
        x = posX;
        y = posY;
        direction = STOP;
    }

    void Reset()
    {
        x = startingX;
        y = startingY;
        direction = STOP;
    }

    void changeDirection(eDir d)
    {
        direction = d;
    }

    void randomDirection()
    {
        srand(time(0));
        direction = (eDir)((rand)() % 6 + 1);
    }

    inline int getX() { return x; }
    inline int getY() { return y; }
    inline eDir getDirection() { return direction; }

    void Move()
    {
        switch (direction)
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
            x--;
            y--;
            break;

        case DOWNLEFT:
            x--;
            y++;
            break;

        case UPRIGHT:
            x++;
            y--;
            break;

        case DOWNRIGHT:
            x++;
            y++;
            break;

        default:
            break;
        }
    }

    friend ostream& operator <<(ostream& o, cBall c)
    {
        o << "Ball [" << c.x << "," << c.y << "][" << c.direction << "]";
        return o;
    }

    bool operator == (eDir d)
    {
        eDir e;
        if (d == e)
            return true;

        return false;
    }
};

class cPaddle
{
private:
    int x, y;
    int startingX, startingY;

public:
    cPaddle()
    {
        x = y = 0;
    }

    cPaddle(int posX, int posY) : cPaddle() // INCEARCA FARA CPADDLE
    {
        startingX = posX;
        startingY = posY;
        x = posX;
        y = posY;
    }

    inline void Reset() { x = startingX; y = startingY; }
    inline int getX() { return x; }
    inline int getY() { return y; }
    void moveUP() { y--; }
    void moveDOWN() { y++; }

    friend ostream& operator <<(ostream& o, cPaddle c)
    {
        o << "Paddle [" << c.x << "," << c.y << "]";
        return o;
    }
};

class cGameManager
{
private:
    int column, row;
    int score1, score2;
    char up1, down1, up2, down2;
    bool quit;
    cBall* ball;
    cPaddle* player1;
    cPaddle* player2;

public:
    cGameManager(int w, int h)
    {
        column = w;
        row = h;
        srand(time(NULL));
        quit = false;
        up1 = 'w';
        up2 = 'o';
        down1 = 's';
        down2 = 'l';
        score1 = score2 = 0;

        ball = new cBall(w / 2, h / 2);
        player1 = new cPaddle(1, h / 2 - 3); /// h/2 -3
        player2 = new cPaddle(w - 2, h / 2 - 3); // w-1
    }

    ~cGameManager()
    {
        delete ball, player1, player2;
    }

    void scoreUP(cPaddle* player)
    {
        if (player == player1)
            score1++;
        else if (player == player2)
            score2++;

        ball->Reset();
        player1->Reset();
        player2->Reset();
    }

    void Draw()
    {
        system("cls"); // clear console screen
        for (int j = 0; j < column + 2; j++)
            cout << "\xB2";

        cout << endl;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                int ballX = ball->getX();
                int ballY = ball->getY();
                int player1X = player1->getX(); // player1X ->column
                int player1Y = player1->getY(); // player1Y-> row
                int player2X = player2->getX();
                int player2Y = player2->getY();

                if (j == 0)
                    cout << "\xB2";

                if (i == ballY && j == ballX)
                    cout << "O";// ball
                else if (i == player1Y && j == player1X)
                    cout << "\xDB"; // player1 charmap
                else if (i == player1Y + 1 && j == player1X)
                    cout << "\xDB"; // player1
                else if (i == player1Y + 2 && j == player1X)
                    cout << "\xDB"; // player1
                else if (i == player1Y + 3 && j == player1X)
                    cout << "\xDB"; // player1
                else if (player2X == j && player2Y == i)
                    cout << "\xDB"; // player2

                else if (i == player2Y + 1 && j == player2X)
                    cout << "\xDB"; // player2
                else if (i == player2Y + 2 && j == player2X)
                    cout << "\xDB"; // player2
                else if (i == player2Y + 3 && j == player2X)
                    cout << "\xDB"; // player2

                else
                    cout << " ";

                if (j == column - 1)
                    cout << "\xB2";
            }
            cout << endl;
        }

        for (int j = 0; j < column + 2; j++)
            cout << "\xB2";
        cout << endl;

        cout << "Score 1: " << score1 << endl << "Score 2: " << score2;
    }

    void Input()
    {
        ball->Move();

        int ballX = ball->getX();
        int ballY = ball->getY();
        int player1X = player1->getX();
        int player1Y = player1->getY();
        int player2X = player2->getX();
        int player2Y = player2->getY();

        if (_kbhit())
        {
            char current = _getch();
            if (current == up1)
                if (player1Y > 0)
                    player1->moveUP();

            if (current == up2)
                if (player2Y > 0)
                    player2->moveUP();

            if (current == down1)
                if (player1Y + 4 < row) // 4 segments = length of a paddle
                    player1->moveDOWN();

            if (current == down2)
                if (player2Y + 4 < row)
                    player2->moveDOWN();


            if (ball->getDirection() == STOP)
                ball->randomDirection();

            if (current == 'q')
                quit = true;
        }
    }

    void Logic()
    {
        int ballX = ball->getX();
        int ballY = ball->getY();
        int player1X = player1->getX();
        int player1Y = player1->getY();
        int player2X = player2->getX();
        int player2Y = player2->getY();


        // LEFT PADDLE
        for (int i = 0; i < 4; i++)
            if (ballX == player1X + 1)
                if (ballY == player1Y + i)
                    ball->changeDirection((eDir)(rand() % 3 + 4));  // RIGHT UPRIGHT DOWNRIGHT..

        // RIGHT PADDLE
        for (int i = 0; i < 4; i++)
            if (ballX == player2X - 1)
                if (ballY == player2Y + i)
                    ball->changeDirection((eDir)(rand() % 3 + 1));  // LEFT DOWNLEFT UPLEFT ....

        // bottom wall
        if (ballY == row - 1)
            ball->changeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);

        // top wall
        if (ballY == 1)
            ball->changeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);

        //right wall
        if (ballX == column - 1)
            scoreUP(player1);

        //left wall
        if (ballX == 0)
            scoreUP(player2);
    }

    void Run()
    {
        while (!quit)
        {
            Draw();
            Input();
            Logic();
        }
    }

};

int main()
{
    cGameManager c(40, 20);
    c.Run();
}