#include "unity.h"
#include "TextEditor.h"

unsigned char txtEditorWidth,txtEditorHeight;
unsigned char txtX1,txtY1,txtX2,txtY2;
unsigned char txtCurX,txtCurY;
unsigned char txtK;

void InitTextEditor(unsigned char width,
                    unsigned char height,
                    unsigned char x,
                    unsigned char y) {
    txtEditorWidth=width;
    txtEditorHeight=height;
    txtX1=x;
    txtY1=y;
    txtX2=txtX1+width;
    txtY2=txtY1+height;
    txtCurX=0;
    txtCurY=0;
}

unsigned char ShowTextEditor(char *title,char *buffer,unsigned char showBorder,unsigned char showStats) {
    unsigned char result=1;
    int bufferLength;
    int pos,a,b;

    if (showBorder==1) {
        if (txtX1>0 && txtY1>0) {

            //Top/bottom border
            for (a=txtX1-1;a<txtX2+3;a++) {
                gotoxy(a,txtY1-1);
                cputc(166);
                gotoxy(a,txtY2+1);
                cputc(166);
            }

            if (title[0]!=0) {
                a = (txtEditorWidth - strlen(title))/2;
                gotoxy(a+txtX1,txtY1-1);
                cprintf(title);
            }

            //Side borders
            for (b=txtY1-1;b<txtY2+1;b++) {
                gotoxy(txtX1-1,b);
                cputc(166);
                gotoxy(txtX2+3,b);
                cputc(166);
            }
                
        }
    }

 //   bufferLength=strlen(buffer);
    if (showStats==1) {
        ShowStats();
    }

    //Write out buffer
    for (b=0;b<txtEditorHeight;b++) {
        for (a=0;a<txtEditorWidth;a++) {
            pos=b*txtEditorWidth + a;
            gotoxy(a+txtX1,b+txtY1);
            cputc(buffer[pos]);
        }
    }

    while (result) {

        gotoxy(txtCurX+txtX1,txtCurY+txtY1);
        cputc('#');
        //cputc(166);

        txtK = cgetc();
        if (txtK>31 && txtK!=TXTEDITOR_KEY_UP && txtK!=TXTEDITOR_KEY_DOWN && txtK!=TXTEDITOR_KEY_LEFT  && txtK!=TXTEDITOR_KEY_RIGHT && txtK!=TXTEDITOR_KEY_RETURN && txtK!=TXTEDITOR_KEY_ESCAPE && txtK!=TXTEDITOR_KEY_DELETE) {
            gotoxy(txtCurX+txtX1,txtCurY+txtY1);
            cputc(txtK);
            pos=txtCurY*txtEditorWidth + txtCurX;
            buffer[pos]=txtK;
            txtCurX++;
            if (txtCurX>txtX2) {
                txtCurX=0;
                txtCurY++;
            }
        }   
        //Delete 
        if (txtK==TXTEDITOR_KEY_DELETE) {
            if (txtCurX>0) {
                gotoxy(txtCurX+txtX1,txtCurY+txtY1);
                cputc(' ');
                txtCurX--;
                gotoxy(txtCurX+txtX1,txtCurY+txtY1);
                cputc(' ');
                pos=txtCurY*txtEditorWidth + txtCurX;
                buffer[pos]=' ';
            }
            /*
            if (txtCurX==0 && txtCurY>0) {
                gotoxy(txtCurX+txtX1,txtCurY+txtY1);
                cputc(' ');
                txtCurX--;
                txtCurY--;
                gotoxy(txtCurX+txtX1,txtCurY+txtY1);
                cputc(' ');
                pos=txtCurY*editorWidth + txtCurX;
                buffer[pos]=' ';
            }
            */
        }

        //Return 
        if (txtK==TXTEDITOR_KEY_RETURN) {
            if (txtCurY<txtEditorHeight) {
                gotoxy(txtCurX+txtX1,txtCurY+txtY1);
                pos=txtCurY*20 + txtCurX;
                cputc(buffer[pos]);
                txtCurX=0;
                txtCurY++;
            }
        }

        //Down 
        if (txtK==TXTEDITOR_KEY_DOWN) {
            if (txtCurY<txtEditorHeight) {
                gotoxy(txtCurX+txtX1,txtCurY+txtY1);
                pos=txtCurY*20 + txtCurX;
                cputc(buffer[pos]);
                txtCurY++;
            }
        }

        //Up 
        if (txtK==TXTEDITOR_KEY_UP) {
            if (txtCurY>0) {
                gotoxy(txtCurX+txtX1,txtCurY+txtY1);
                pos=txtCurY*20 + txtCurX;
                cputc(buffer[pos]);
                txtCurY--;
            }
        }

        //Left 
        if (txtK==TXTEDITOR_KEY_LEFT) {
            if (txtCurX>0) {
                gotoxy(txtCurX+txtX1,txtCurY+txtY1);
                pos=txtCurY*20 + txtCurX;
                cputc(buffer[pos]);
                txtCurX--;
            }
        }

        //Right 
        if (txtK==TXTEDITOR_KEY_RIGHT) {
            if (txtCurX<txtEditorWidth) {
                gotoxy(txtCurX+txtX1,txtCurY+txtY1);
                pos=txtCurY*20 + txtCurX;
                cputc(buffer[pos]);
                txtCurX++;
            }
        }

        //Escape
        if (txtK==TXTEDITOR_KEY_ESCAPE) {
            result=0;
        }

        if (showStats==1) {
            ShowStats();
        }

    }
    return result;
}

void ShowStats() {
    gotoxy(txtX1+2,txtY2+1);
    cprintf("k:[%i]  x:%i y:%i ",txtK,txtCurX,txtCurY);
}