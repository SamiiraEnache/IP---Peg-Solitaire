
#ifndef BUTOANERESULT_H_INCLUDED
#define BUTOANERESULT_H_INCLUDED
#include <graphics.h>
#include <winbgim.h>
#include <iostream>
#include <windows.h>
#include <cstdio>
#define FUNDAL LIGHTBLUE
int Click =0;
int test = 1;
int TablaDeJoc[9][9];
void ShowRules()
{
    // Curăță fereastra actuală
    cleardevice();

    // Încarcă și afișează imaginea cu regulile
    readimagefile("C:\\ProiectGraphics\\reguli.jpg", 0, 0, 1800, 1000);

    // Definiți coordonatele pentru butonul "Back"
    int backButtonX1 = 1500; // Coordonata X de start pentru butonul "Back"
    int backButtonY1 = 50;   // Coordonata Y de start pentru butonul "Back"
    int backButtonWidth = 250;  // Lățimea butonului "Back"
    int backButtonHeight = 100; // Înălțimea butonului "Back"

    // Desenează butonul "Back"
    setcolor(WHITE);
    setbkcolor(TRANSPARENT);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    outtextxy(backButtonX1, backButtonY1, "Back");

    // Așteaptă un click pentru a reveni la meniul principal
    int mx, my;
    POINT coordCursor;
    while(1)
    {
        GetCursorPos(&coordCursor);
        mx = coordCursor.x;
        my = coordCursor.y;

        if (GetAsyncKeyState(VK_LBUTTON))
        {
            // Verifică dacă click-ul este în zona butonului "Back"
            if (mx >= backButtonX1 && mx <= backButtonX1 + backButtonWidth &&
                my >= backButtonY1 && my <= backButtonY1 + backButtonHeight)
            {
                break; // Închide fereastra cu reguli și se întoarce la meniul principal
            }
        }
    }

    // Curăță fereastra și se reîntoarce la meniul principal
    cleardevice();
    readimagefile("C:\\ProiectGraphics\\unu.jpg", 0, 0, 1800, 1000);
}

void YouWon()
{
            delay(1900);
        cleardevice();
        setfillstyle(11, CYAN);
        bar(0, 0, 1000, 1000);
        setbkcolor(CYAN);
        settextstyle(SANS_SERIF_FONT, 0, 9);
        setfillstyle(SOLID_FILL, CYAN);
        bar(200,100,800,400);
        outtextxy(400, 140, (char*)"YOU");
        outtextxy(400, 240, (char*)"WIN");
        system("pause");
}
void GameOver()
{
            delay(1900);
        cleardevice();
        setfillstyle(11, RED);
        bar(0, 0, 1000, 1000);
        setbkcolor(RED);
        settextstyle(SANS_SERIF_FONT, 0, 9);
        setfillstyle(SOLID_FILL, RED);
        bar(200,100,800,400);
        outtextxy(360, 140, (char*)"GAME");
        outtextxy(360, 240, (char*)"OVER");
        system("pause");
}
void ButonExit()
{
    int mx, my;
    mx = mousex();
    my = mousey();
    int click=false;
    while (!click)
    {
        if (ismouseclick(WM_LBUTTONDOWN) && !click)
        {
            click = true;
            if (mx>=20 && mx <=300 && my >= 500 && my<= 700)
                exit(0);

        }
    }
    click = false;
}
void deseneazaPiesa(int rand, int coloana, int c = DARKGRAY)
{
    int stanga = 290;
    int sus = 20;
    int latura = 100;
    int x1, y1, x2, y2;
    int xmijloc, ymijloc;
    setcolor(BLACK);
    x1 = stanga + latura * (coloana - 1);
    y1 = sus + latura * (rand - 1);
    x2 = x1 + latura;
    y2 = y1 + latura - 7;
    xmijloc = (x1 + x2) / 2;
    ymijloc = (y1 + y2) / 2;
    setfillstyle(9, c);
    fillellipse(xmijloc, ymijloc, 20, 20);
}
void stergePiesa(int rand, int coloana, int culoare)
{
    int stanga = 290;
    int sus = 20;
    int latura = 100;
    int x1, y1, x2, y2;
    int xmijloc, ymijloc;
    setcolor(BLACK);
    x1 = stanga + latura * (coloana - 1);
    y1 = (sus + 4) + latura * (rand - 1);
    x2 = x1 + latura;
    y2 = y1 + latura - 4;
    xmijloc = (x1 + x2) / 2;
    ymijloc = (y1 + y2) / 2;
    setfillstyle(SOLID_FILL, FUNDAL);
    bar(xmijloc - 35, ymijloc - 35, xmijloc + 35, ymijloc + 35);
}
void mutarePiesa()
{
    ButonExit();
    int sus = 20;
    int latura = 100;
    int stanga = 290;
    int rand1, coloana1, rand2, coloana2, x, y;
    int x1, y1, x2, y2;
    int xmijloc, ymijloc;
    int click = false;
    int firstclick = 1;

    while (!click)
    {
        if (ismouseclick(WM_LBUTTONDOWN) && !click)
        {
            click = true;
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex();
            y = mousey();
            // urmatorul if nu permite ca piesele sa iasa din tabla
            if (x < 290 || x > 990 || y < 20 || y > 700) continue;
            if (firstclick = 0)
            {
                // firstclick este folosit pentru a scoate din vedere primul si ulterior al doilea click
                x = 640;
                y = 360;
            }
            rand1 = (y - sus) / latura + 1;
            coloana1 = (x - stanga) / latura + 1;
            if (!(TablaDeJoc[rand1][coloana1] % 2 == 0)) deseneazaPiesa(rand1, coloana1, WHITE);
        }
    }

    click = false;

    while (!click)
    {
        if (ismouseclick(WM_LBUTTONDOWN) && !click)
        {
            click = true;
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex();
            y = mousey();
            if (x < 290 || x > 990 || y < 20 || y > 700) continue;
            if (firstclick = 0)
            {
                x = 640;
                y = 360;
            }
            firstclick = 1;
            rand2 = (y - sus) / latura + 1;
            coloana2 = (x - stanga) / latura + 1;
            //SCOR
            if (!(TablaDeJoc[rand1][coloana1] % 2 == 0))
            {

                Click++;
                Beep(100,300);
                char sirScor[10];
                for (int i = 1; i < 9; i ++)
                    for (int j = 1; j < 9; j++)
                        sprintf(sirScor, "%d", Click-1);
                setcolor(15);
                outtextxy(185, 270, sirScor);
            }
        }
    }
    // Regulile jocului

    if (rand1 == rand2 && coloana1 == coloana2);
    else if (TablaDeJoc[rand1][coloana1] % 2 == 0 && TablaDeJoc[rand2][coloana2] % 2 == 0);
    else if (TablaDeJoc[rand1][coloana1] % 2 == 0 && TablaDeJoc[rand2][coloana2] == 1)
    {
        deseneazaPiesa(rand2, coloana2, DARKGRAY);
        delay(200);
        deseneazaPiesa(rand2, coloana2, LIGHTGRAY);
        delay(200);
        deseneazaPiesa(rand2, coloana2, DARKGRAY);
        delay(200);
        deseneazaPiesa(rand2, coloana2, LIGHTGRAY);
        delay(200);
    }
    else if (coloana1 - coloana2 > 2 || coloana2 - coloana1 > 2)
    {
        deseneazaPiesa(rand1, coloana1, DARKGRAY);
        delay(200);
        deseneazaPiesa(rand1, coloana1, LIGHTGRAY);
        delay(200);
        deseneazaPiesa(rand1, coloana1, DARKGRAY);
        delay(200);
        deseneazaPiesa(rand1, coloana1, LIGHTGRAY);
        delay(200);
    }
    else if (TablaDeJoc[rand1][coloana1] == 0);
    else if (rand1 - rand2 > 2 || rand2 - rand1 > 2)
    {
        deseneazaPiesa(rand1, coloana1, DARKGRAY);
        delay(200);
        deseneazaPiesa(rand1, coloana1, LIGHTGRAY);
        delay(200);
        deseneazaPiesa(rand1, coloana1, DARKGRAY);
        delay(200);
        deseneazaPiesa(rand1, coloana1, LIGHTGRAY);
        delay(200);
    }
    else if (TablaDeJoc[rand2][coloana2] == 0)
    {
        deseneazaPiesa(rand1, coloana1, DARKGRAY);
        delay(200);
        deseneazaPiesa(rand1, coloana1, LIGHTGRAY);
        delay(200);
        deseneazaPiesa(rand1, coloana1, DARKGRAY);
        delay(200);
        deseneazaPiesa(rand1, coloana1, LIGHTGRAY);
        delay(200);
    }
    else if (rand1 == rand2 + 1 || rand1 + 1 == rand2)
    {
        deseneazaPiesa(rand1, coloana1, DARKGRAY);
        delay(200);
        deseneazaPiesa(rand1, coloana1, LIGHTGRAY);
        delay(200);
        deseneazaPiesa(rand1, coloana1, DARKGRAY);
        delay(200);
        deseneazaPiesa(rand1, coloana1, LIGHTGRAY);
        delay(200);
    }
    else if (coloana1 == coloana2 + 1 || coloana1 + 1 == coloana2)
    {
        deseneazaPiesa(rand1, coloana1, DARKGRAY);
        delay(200);
        deseneazaPiesa(rand1, coloana1, LIGHTGRAY);
        delay(200);
        deseneazaPiesa(rand1, coloana1, DARKGRAY);
        delay(200);
        deseneazaPiesa(rand1, coloana1, LIGHTGRAY);
        delay(200);
    }
    else if (TablaDeJoc[rand1][coloana1] == 2)
    {
        deseneazaPiesa(rand2, coloana2, DARKGRAY);
        delay(200);
        deseneazaPiesa(rand2, coloana2, LIGHTGRAY);
        delay(200);
        deseneazaPiesa(rand2, coloana2, DARKGRAY);
        delay(200);
        deseneazaPiesa(rand2, coloana2, LIGHTGRAY);
        delay(200);
    }
    else if (TablaDeJoc[rand2][coloana2] == 1)
    {
        deseneazaPiesa(rand1, coloana1, DARKGRAY);
        delay(200);
        deseneazaPiesa(rand1, coloana1, LIGHTGRAY);
        delay(200);
        deseneazaPiesa(rand1, coloana1, DARKGRAY);
        delay(200);
        deseneazaPiesa(rand1, coloana1, LIGHTGRAY);
        delay(200);
    }
    else if (TablaDeJoc[rand1][(coloana1 + coloana2) / 2] == 0)
        test = 0;
    else if (TablaDeJoc[rand1][(coloana1 + coloana2) / 2] == 2)
    {
        TablaDeJoc[rand2][coloana2] = 2;
        TablaDeJoc[rand1][(coloana1 + coloana2) / 2] = 2;
    }
    else if (TablaDeJoc[(rand1 + rand2) / 2][coloana1] == 0);
    else if (TablaDeJoc[(rand1 + rand2) / 2][coloana1] == 2)
    {
        TablaDeJoc[rand2][coloana2] = 2;
        TablaDeJoc[(rand1 + rand2) / 2][coloana1] = 2;
    }
    //win criteria reached
    else if (rand1 == rand2)
    {
        TablaDeJoc[rand1][(coloana1 + coloana2) / 2] = 2;
        stergePiesa(rand1, (coloana1 + coloana2) / 2, CYAN);
        TablaDeJoc[rand1][coloana1] = 2;
        TablaDeJoc[rand2][coloana2] = 1;
    }
    else if (coloana1 == coloana2)
    {
        TablaDeJoc[(rand1 + rand2) / 2][coloana1] = 2;
        stergePiesa((rand1 + rand2) / 2, coloana1, CYAN);
        TablaDeJoc[rand1][coloana1] = 2;
        TablaDeJoc[rand2][coloana2] = 1;
    }
    int nr_piese = 0;
    for (int i = 1; i < 9; i++)
    {
        for (int j = 1; j < 9; j++)
        {
            if(TablaDeJoc[i][j] == 1)
                nr_piese++;
        }
    }

    if(TablaDeJoc[4][4] == 1 && nr_piese == 1)
    {
        for (int i = 1; i < 9; i++)
        {
            for (int j = 1; j < 9; j++)
            {
                if (TablaDeJoc[i][j] == 2)
                    stergePiesa(i, j, WHITE);
                else if (TablaDeJoc[i][j] == 1)
                    deseneazaPiesa(i, j, CYAN);
                else if (TablaDeJoc[i][j] == 0);
            }
        }
      //  int ScorFinal= Click;
        YouWon();
    }

    // verificam daca nu mai sunt miscari disponibile
    int lose = 0, count = 0;
    for (int i = 1; i < 9; i++)
    {
        for (int j = 1; j < 9; j++)
        {
            if(TablaDeJoc[i][j] == 1)
            {
                count++;
                if ((TablaDeJoc[i][j+1] % 2 == 0 &&
                        TablaDeJoc[i][j-1] % 2 == 0 &&
                        TablaDeJoc[i+1][j] % 2 == 0 &&
                        TablaDeJoc[i-1][j] % 2 == 0) ||
                        (TablaDeJoc[i+1][j] % 2 == 0 &&
                         TablaDeJoc[i-1][j] % 2 == 0 && (
                             (TablaDeJoc[1][4] == 1  && TablaDeJoc[1][5] == 1 && TablaDeJoc[1][3] == 1) ||
                             (TablaDeJoc[4][1] == 1  && TablaDeJoc[5][1] == 1 && TablaDeJoc[3][1] == 1) ||
                             (TablaDeJoc[4][9] == 1  && TablaDeJoc[5][9] == 1 && TablaDeJoc[3][9] == 1) ||
                             (TablaDeJoc[9][4] == 1  && TablaDeJoc[9][5] == 1 && TablaDeJoc[9][3] == 1)))
                   )
                    lose++;
            }
        }
    }
    //lose animation
    if (lose == count && nr_piese > 1)
    {
        stergePiesa(rand1, coloana1, DARKGRAY);
        deseneazaPiesa(rand2, coloana2);
        delay(800);
        for (int i = 1; i < 9; i++)
        {
            for (int j = 1; j < 9; j++)
            {
                if (TablaDeJoc[i][j] == 2)
                    stergePiesa(i, j, DARKGRAY);
                else if (TablaDeJoc[i][j] == 1)
                    deseneazaPiesa(i, j, RED);
                else if (TablaDeJoc[i][j] == 0);
            }
        }
int         ScorFinal= 3;
        GameOver();
    }

    // Dupa fiecare miscare, tabla se deseneaza din nou
    for (int i = 1; i < 9; i++)
    {
        for (int j = 1; j < 9; j++)
        {
            if (TablaDeJoc[i][j] == 2)
                stergePiesa(i, j, WHITE);
            else if (TablaDeJoc[i][j] == 1)
                deseneazaPiesa(i, j, DARKGRAY);
            else if (TablaDeJoc[i][j] == 0);
        }
    }
}

void Game()
{

    setbkcolor(BLACK);
    for (int i = 1; i <= 7; i++)
    {
        TablaDeJoc[3][i] = 1;
        TablaDeJoc[4][i] = 1;
        TablaDeJoc[5][i] = 1;
        TablaDeJoc[i][3] = 1;
        TablaDeJoc[i][4] = 1;
        TablaDeJoc[i][5] = 1;
    }
    TablaDeJoc[4][4] = 2; // locul liber initial (centrul)

    /*
    		0 1 2 3 4 5 6 7 8

    	0	0 0 0 0 0 0 0 0 0
    	1	0 0 0 1 1 1 0 0 0
    	2	0 0 0 1 1 1 0 0 0
    	3   0 1 1 1 1 1 1 1 0
    	4	0 1 1 1 2 1 1 1 0
    	5	0 1 1 1 1 1 1 1 0
    	6	0 0 0 1 1 1 0 0 0
    	7	0 0 0 1 1 1 0 0 0
    	8	0 0 0 0 0 0 0 0 0

    */

    cleardevice();
        readimagefile("C:\\ProiectGraphics\\of.jpg", 0, 0, 1800, 1000);

//grafica tabla
    int numar = 0;
    for (int i = 290; ; i = i + 100)
    {
        if (numar <= 7)
        {
            setcolor(WHITE);
            setbkcolor(BLUE);
            numar++;
            //line(i, 20, i, 699);
            for (int h = 20; h <= 700; h += 97)
            {
                // line(290, h, 990, h);

                //scor joc
                //titlu

//tabel jos


//tabel sus p1


                settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);

// Ajustează pozițiile pentru textele "Player" și "Score" astfel încât să încapă în chenar
outtextxy(70, 240, (char*)"Player ");
outtextxy(70, 270, (char*)"Score:");
                setfillstyle(1, LIGHTBLUE); // Setează fundalul cu LIGHTBLUE
setcolor(WHITE); // Setează culoarea textului la alb

// Ajustează poziția și dimensiunea fontului pentru textul "Exit"
settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4); // Poți ajusta dimensiunea fontului după preferința ta
outtextxy(70, 580, (char*)"Exit"); // Desenează textul "Exit" la noile coordonate

            }
        }




        //desen tabla piese
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (TablaDeJoc[i][j] == 0);
                else if (TablaDeJoc[i][j] == 1) deseneazaPiesa(i, j);
                else if (TablaDeJoc[i][j] == 2) stergePiesa(i, j, BLACK);
            }
        }

        while (true)
        {
            mutarePiesa();



        }

    }
}

#endif // BUTOANERESULT_H_INCLUDED
