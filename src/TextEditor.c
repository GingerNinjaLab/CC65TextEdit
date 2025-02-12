#include "unity.h"
#include "TextEditor.h"

unsigned char editorWidth,editorHeight;
unsigned char x1,y1,x2,y2;
unsigned char curX,curY;
unsigned char k;

void InitTextEditor(unsigned char width,
                    unsigned char height,
                    unsigned char x,
                    unsigned char y) {
    editorWidth=width;
    editorHeight=height;
    x1=x;
    y1=y;
    x2=x1+width;
    y2=y1+height;
    curX=0;
    curY=0;
}

unsigned char ShowTextEditor(char *buffer,unsigned char showBorder,unsigned char showStats) {
    unsigned char result=1;
    int bufferLength;
    int pos,a,b;

    if (showBorder==1) {
        if (x1>0 && y1>0) {

            //Top/bottom border
            for (a=x1-1;a<x2+3;a++) {
                gotoxy(a,y1-1);
                cputc(166);
                gotoxy(a,y2+1);
                cputc(166);
            }

            //Side borders
            for (b=y1-1;b<y2+1;b++) {
                gotoxy(x1-1,b);
                cputc(166);
                gotoxy(x2+3,b);
                cputc(166);
            }
                
        }
    }

 //   bufferLength=strlen(buffer);
    if (showStats==1) {
        ShowStats();
    }

    while (result) {

        gotoxy(curX+x1,curY+y1);
        cputc('#');
        //cputc(166);

        k = cgetc();
        if (k>31 && k<128) {
            gotoxy(curX+x1,curY+y1);
            cputc(k);
            pos=curY*editorWidth + curX;
            buffer[pos]=k;
            curX++;
            if (curX>x2) {
                curX=0;
                curY++;
            }
        }   
        //Delete 
        if (k==20) {
            if (curX>0) {
                gotoxy(curX+x1,curY+y1);
                cputc(' ');
                curX--;
                gotoxy(curX+x1,curY+y1);
                cputc(' ');
                pos=curY*editorWidth + curX;
                buffer[pos]=' ';
            }
            if (curX==0 && curY>0) {
                gotoxy(curX+x1,curY+y1);
                cputc(' ');
                curX--;
                curY--;
                gotoxy(curX+x1,curY+y1);
                cputc(' ');
                pos=curY*editorWidth + curX;
                buffer[pos]=' ';
            }
        }

        //Return 
        if (k==13) {
            if (curY<editorHeight) {
                gotoxy(curX+x1,curY+y1);
                cputc(' ');
                curX=0;
                curY++;
            }
        }

        //Down 
        if (k==157) {
            if (curY<editorHeight) {
                gotoxy(curX+x1,curY+y1);
                cputc(' ');
                curY++;
            }
        }

        //Up 
        if (k==145) {
            if (curY>0) {
                gotoxy(curX+x1,curY+y1);
                cputc(' ');
                curY--;
            }
        }

        //Left 
        if (k==157) {
            if (curX>0) {
                gotoxy(curX+x1,curY+y1);
                cputc(' ');
                curX--;
            }
        }

        //Right 
        if (k==29) {
            if (curX<editorWidth) {
                gotoxy(curX+x1,curY+y1);
                cputc(' ');
                curX++;
            }
        }

        //Escape
        if (k==3) {
            result=0;
        }

        if (showStats==1) {
            ShowStats();
        }

    }
    return result;
}

void ShowStats() {
    gotoxy(x1+2,y2+1);
    cprintf("k:[%i]  x:%i y:%i ",k,curX,curY);
}