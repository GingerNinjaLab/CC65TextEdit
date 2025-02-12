
#include "unity.h"
#include "TextEditor.h"
#include "test.h"

unsigned char textBuffer[800];
unsigned char x,y,result,k;
int pos;
unsigned char width,height;

int main (void)
{

    clrscr();

    width=10;
    height=20;
    //Clear the text buffer
    for (pos=0;pos<800;pos++) {
        textBuffer[pos]=' ';
    }
    InitTextEditor(width,height,2,2);

    k=0;
    while (k!='q') {
        result = ShowTextEditor("Sound code",textBuffer,1,1);

        clrscr();
        gotoxy(0,0);
        cprintf("Text editor result: %i Buffer:",result);
        for (y=0;y<height;y++) {
            for (x=0;x<width;x++) {
                pos=y*width + x;
                gotoxy(x,y+2);
                cputc(textBuffer[pos]);
            }
        }
        gotoxy(0,height+2);
        k = cgetc();
        cprintf("q to quit, any other key to edit");
        clrscr();
    }


    return EXIT_SUCCESS;
} 


//C64 text routines
void C64TextModePETSCII() {
    __asm__("lda #$15");
    __asm__("sta $D018");    
}

void C64TextModeUpperLower() {
    __asm__("lda #$17");
    __asm__("sta $D018");
}
