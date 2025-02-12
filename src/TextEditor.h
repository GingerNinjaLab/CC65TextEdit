#define TXTEDITOR_KEY_UP 145
#define TXTEDITOR_KEY_DOWN 17
#define TXTEDITOR_KEY_LEFT 157
#define TXTEDITOR_KEY_RIGHT 29
#define TXTEDITOR_KEY_RETURN 13
#define TXTEDITOR_KEY_DELETE 20
#define TXTEDITOR_KEY_ESCAPE 3


void InitTextEditor(unsigned char _width,unsigned char _height,unsigned char _x,unsigned char _y);
unsigned char ShowTextEditor(char *title,char *buffer ,unsigned char showBorder,unsigned char showStats);
void ShowStats();
