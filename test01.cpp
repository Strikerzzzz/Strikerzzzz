#include<iostream>
using namespace std;
#include <cstring>
#include <conio.h>
#include <windows.h>
#define consoleWidth 80
#define consoleHeight 25
enum DiChuyen{ UP, DOWN, LEFT, RIGHT};
void gotoxy( short x, short y) 
{
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
struct DoiTuong
{
    char s[10];    
    int x,y;     
    DiChuyen dc;
};
int main()
{
    DoiTuong dt;
    strcpy(dt.s, "Hello world");
    dt.y=0; 
    dt.x=consoleWidth/2; 
    dt.dc=DOWN;  
    while(1)
    {
        system("cls");
        gotoxy(dt.x, dt.y);  
        system("color 9");
        cout<<dt.s; 
        if(kbhit())                
        {
            char key = _getch();         
            if(key == 'A' || key == 'a')           
                    dt.dc =LEFT;
            if(key == 'D' || key == 'd')      
                    dt.dc = RIGHT;
            if(key == 'W' || key == 'w')       
                    dt.dc = UP;
            if(key == 'S' || key == 's')          
                    dt.dc = DOWN;
        }
        if(dt.y >= consoleHeight-1)             
            dt.dc = UP;                               
        else if(dt.y <= 0)                            
            dt.dc = DOWN;                    
        if(dt.x <= 0)                         
            dt.dc = RIGHT;                    
        if(dt.x>=consoleWidth-1)                 
            dt.dc = LEFT;                        
        if (dt.dc == DOWN)             
            dt.y++;
        else if (dt.dc == UP)             
            dt.y--;
        if (dt.dc == LEFT)                 
            dt.x--;
        if (dt.dc == RIGHT)            
            dt.x++;
            _sleep(200); 
    }
    return 0;
}