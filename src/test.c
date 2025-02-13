
#include "unity.h"
#include "TextEditor.h"
#include "test.h"

unsigned char textBuffer[800];
unsigned char x,y,result,k,running;
int pos;
unsigned char width,height;
FILE *fp;

int main (void)
{

    clrscr();
    running=1;

    width=10;
    height=20;
    //Clear the text buffer
    for (pos=0;pos<800;pos++) {
        textBuffer[pos]=' ';
    }

    //Load the file
    cprintf("loading...\r\n");
    fp = fopen("test.txt", "r");
    fgets(textBuffer,800,fp);
    fclose(fp);
    cprintf("done\r\n");

    InitTextEditor(width,height,2,2);

    k=0;
    while (running) {
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
        cprintf("What next?\r\n");
        cprintf("l. load\r\n");
        cprintf("s. Save file\r\n");
        cprintf("n. New file\r\n");
        cprintf("q. quit\r\n");
        k = cgetc();
        if (k=='s') {
            //Save the file
            cprintf("saving...\r\n");
            fp = fopen("test.txt", "w");
            fputs(textBuffer,fp);
            if (fp == EOF) {
                perror("fputs()");
            }
            fclose(fp);
            cprintf("done\r\n");
        }

        if (k=='q') {
            running=0;
        }
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
