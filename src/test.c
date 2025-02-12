
#include "unity.h"
#include "TextEditor.h"
#include "test.h"

unsigned char textBuffer[800];
unsigned char x,y,result;
int pos;

int main (void)
{

    clrscr();

    //Clear the text buffer
    for (pos=0;pos<strlen(textBuffer);pos++) {
        textBuffer[pos]=' ';
    }
    InitTextEditor(20,20,2,2);
    result = ShowTextEditor(textBuffer,1,1);

    clrscr();
    gotoxy(0,0);
    cprintf("Text editor result: %i Buffer:",result);
    for (y=0;y<20;y++) {
        for (x=0;x<20;x++) {
            pos=y*20 + x;
            gotoxy(x,y+2);
            cputc(textBuffer[pos]);
        }
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
