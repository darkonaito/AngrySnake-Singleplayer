#include <iostream>
using counter = unsigned char;
/*
#include "DynamicArray\\dyn_arr.hpp"
#include "graphicd4\\graphicd4-2.hpp"
*/

#include "..\\dyn_arr.hpp"
#include "..\\graphicd3-2.hpp"

using namespace grph;
using namespace grph;
using namespace grph;

#include "snake.cpp"

using namespace std;

int main()
{
    short background = 10, score = 0, foodclr = 40, speed = 0;
    char foodtxt = 'o';

    cout <<"\n\t Delay Between Frames : ";
    cin >> speed;

    bool toRemoveBadSnakeSegm = false, toRemoveMoiSnakeSegm = false;
    system("mode 31,16");
    short time = 0;
    Grid grid(30,15);
    grid.setup(background,' ');
    grid.square(Point(1,1),Point((grid.getX() - 2),(grid.getY() - 2)),67,' ');
    Snake badSnake(2,2,80,'@','0',grid);
    Snake moiSnake(27,12,30,'@','0',grid);
    Entity food(grid.getX() / 2,grid.getY() / 2,foodclr,foodtxt,'0');
    grid.drawnty(food);

    grid.paint();


    while(true)
    {
        ///SAY

        Console::setOutColor(07);

        /*
        cout << (moiSnake.getLastSegmX() > badSnake.getLastSegmX()) << "   ";
        cout << (moiSnake.getLastSegmY() > badSnake.getLastSegmY()) << endl;
        cout << badSnake.getFacing() << "   " << moiSnake.getFacing() << endl;
        cout << badSnake.getFirstSegmX() << "   " << badSnake.getLastSegmX() << endl;
        cout << badSnake.getFirstSegmY() << "   " << badSnake.getLastSegmY() << endl;
        cout << badSnake.getLength() << "   " << moiSnake.getLength() << endl;
        */

        //cout << "\t" << food.getX() << "   " << food.getY() << endl;

        ///TIME ++

        if(time == 102) time = 0;

        time++;

        ///DRAW

        badSnake.draw();
        moiSnake.draw();

        ///PAINT

        //grid.paint();

        ///CHECK KEYS

        if(GetAsyncKeyState('W') && moiSnake.getFacing() != 's')
        {
            moiSnake.setFacing('w');
        }
        if(GetAsyncKeyState('A') && moiSnake.getFacing() != 'd')
        {
            moiSnake.setFacing('a');
        }
        if(GetAsyncKeyState('S') && moiSnake.getFacing() != 'w')
        {
            moiSnake.setFacing('s');
        }
        if(GetAsyncKeyState('D') && moiSnake.getFacing() != 'a')
        {
            moiSnake.setFacing('d');
        }

        /// C H E A T S :D

        if(GetAsyncKeyState(' '))
            if(GetAsyncKeyState(TAB))
            {
                badSnake.addSegm();
                Beep(500,500);
            }
            else
                moiSnake.addSegm();

        /// EXIT

        if(GetAsyncKeyState(ESC))
            return 0;

        ///MOVEMENT TEST

        if(moiSnake.nextPxlIs(80,'@'))
        {
            if(badSnake.getLength() > 1)
            {
                moiSnake.addSegm();
                score++;
                toRemoveBadSnakeSegm = true;
            }
        }

        if(moiSnake.nextPxlIs(foodclr,foodtxt))
        {
            short x,y;
            do
            {
                x = (rand() % (grid.getX() - 6)) + 4;
                y = (rand() % (grid.getY() - 6)) + 4;
            }while(grid.getPxlClr(x,y) != background && grid.getPxlTxt(x,y) != ' ');
            moiSnake.addSegm();
            grid.drawpnt(food,background,' ');
            food.set(Point(x,y));
            grid.drawnty(food);
        }

        if(!moiSnake.nextPxlIs(background,' ')) moiSnake.setFacing('0');

        ///BADSNAKE CHECK COORD

        #include "badSnakeMove.cpp"



        ///BADSNAKE MOVEMENT TEST

        if(badSnake.nextPxlIs(30,'@',badSnake.getFacing()))
        {
            if(moiSnake.getLength() > 1)
            {
                badSnake.addSegm();
                toRemoveMoiSnakeSegm = true;
            }
        }
        if(badSnake.nextPxlIs(foodclr,foodtxt))
        {
            short x,y;
            do
            {
                x = (rand() % (grid.getX() - 6)) + 4;
                y = (rand() % (grid.getY() - 6)) + 4;
            }while(grid.getPxlClr(x,y) != background && grid.getPxlTxt(x,y) != ' ');
            badSnake.addSegm();
            grid.drawpnt(food,background,' ');
            food.set(Point(x,y));
            grid.drawnty(food);
        }

        ///NEW SLEEP

        Sleep(speed);

        ///CLEAR BADSNAKE & REMOVE SEGM   /// if(time % 3 == 0)

        badSnake.clear(background,' ');

        if(toRemoveBadSnakeSegm)
        {
            if(time % 3 == 0) badSnake.subSegm();
            if(time % 3 == 0) toRemoveBadSnakeSegm = false;
        }

        if(time % 3 == 0) if(
                             badSnake.nextPxlIs(10,' ',badSnake.getFacing()) ||
                             badSnake.nextPxlIs(foodclr,foodtxt,badSnake.getFacing()) //||
                             //badSnake.nextPxlIs(30,'@',badSnake.getFacing())
                            ) badSnake.move(badSnake.getFacing());

        ///TRUE MOVEMENT & CLEAR

        moiSnake.clear(background,' ');

        if(toRemoveMoiSnakeSegm)
        {
            moiSnake.subSegm();
            toRemoveMoiSnakeSegm = false;
        }

        moiSnake.move(moiSnake.getFacing());

        ///CLEAR SCREEN
        //Console::cls();
    }




    return 0;
}
