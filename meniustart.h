
#ifndef STARTSCREEN_H_INCLUDED
#define STARTSCREEN_H_INCLUDED
#include "butoane.h"
#include <fstream>
#include <graphics.h>
#include <string>
#define FUNDAL BLACK
using namespace std;
void MeniuButoane()
{

    initwindow(1800,1000, "SOLITAIRE");
    readimagefile("C:\\ProiectGraphics\\unu.jpg", 0, 0, 1800, 1000);




    // meniul principal

    settextstyle (0, 0, 6);
    setbkcolor(TRANSPARENT);
    setcolor(TRANSPARENT);
    rectangle(0,150, getmaxx(), getmaxy());

int mx, my; // coordonatele mouse
POINT coordCursor;

while (1)
{
    GetCursorPos(&coordCursor);
    mx = coordCursor.x;
    my = coordCursor.y;

    // Detectează click-ul și execută acțiunea corespunzătoare
    if (GetAsyncKeyState(VK_LBUTTON))
    {
        // Play
        if (mx >= 1150 && mx <= 1150 + 150 && my >= 690 && my <= 690 + 50)


        {
            Game(); // Funcția care începe jocul
            break;
        }


        // Rules
        else if (mx >= 1400 && mx <= 1400 + 50 && my >= 690 && my <= 690 + 50)
             {

                ShowRules();
             }

        // Exit
        else if (mx >= 1350 && mx <= 1350 + 50 && my >= 790 && my <= 790 + 50)

        {
            exit(0);
            break;
        }


    }


}


}

#endif // STARTSCREEN_H_INCLUDED
