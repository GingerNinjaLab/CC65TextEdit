# CC65TextEdit
A simple text editor written for CC65

Works in Text mode

Include #include "TextEditor.h"
and compile TextEditor.c along with your code.

Initialize it by calling InitTextEditor
InitTextEditor(20,20,2,2);

It takes the following parameters:
InitTextEditor(unsigned char _width,unsigned char _height,unsigned char _x,unsigned char _y);
Width and Height of the text box
X/Y are the top left corner of the text box

Then to start the editor call:

unsigned char ShowTextEditor(char *buffer ,unsigned char showBorder,unsigned char showStats);

Passing in the char array.
ShowBorder = 1
Will draw a border around the edges of the text box.

ShowStats = 1
Will show stats for the text editor in the bottom frame of the text editor

The result is:

0 = Normal exit

<Others to come>
