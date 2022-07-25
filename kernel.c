#define LINES 25
#define COLUMNS 80
#define SCREEN_SIZE LINES*COLUMNS

int current_loc = 0;
char *vidptr = (char*)0xb8000;

void clear_screen(void)
{
    int i = 0;
    while(i < SCREEN_SIZE)
    {
        vidptr[i++] = ' ';
        vidptr[i++] = 0x07;
    }
    current_loc = 0;
}

void kprint(const char* str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        vidptr[current_loc++] = str[i++];
        vidptr[current_loc++] = 0x07;
    }
}

void kmain(void){
    clear_screen();
    kprint("Welcome to MyOS");
}