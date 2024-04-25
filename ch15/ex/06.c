/*
// Design a bit-field structure that holds the following information:
// 	  Font ID: A number in the range 0–255
// 	  Font Size: A number in the range 0–127
// 	  Alignment: A number in the range 0–2 represented the choices Left,
// 	    Center, and Right
//    Bold: Off (0) or on (1)
// 	  Italic: Off (0) or on (1)
// 	  Underline: Off (0) or on (1)
// Use this structure in a program that displays the font parameters and uses a
// looped menu to let the user change parameters. For example, a sample run
// might look like this:

// 	   ID SIZE ALIGNMENT  B   I   U 
//     1  12   left      off off off
    
//     f)change fonts	s)change size 	 a)change alignment
//     b)toggle bold 	i)toggle italic  u)toggle underline
// 	   q)quit
// 	   s
// 	   Enter font size (0-127): 36

// 	   ID SIZE ALIGNMENT  B   I   U 
//     1  36   left      off off off

//     f)change fonts	s)change size 	 a)change alignment
//     b)toggle bold 	i)toggle italic  u)toggle underline
// 	   q)quit
// 	   a
// 	   Select alignment:
// 	   l)left    c)center   r)right
// 	   r
// 	   ...
*/

#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <string.h>

typedef struct {
	uint32_t id: 8;
	uint32_t size: 7;
	uint32_t alignment: 2;
	uint32_t bold: 1;
	uint32_t italic: 1;
	uint32_t underline: 1;
}font_para_t;

#define ALIGN_LEFT 0
#define ALIGN_CENTER 1
#define ALIGN_RIGHT 2

#define ON 1
#define OFF 0	

static font_para_t font = { .id = 1, .size = 12,
		.alignment = ALIGN_LEFT, .bold = OFF,
		.italic = OFF, .underline = OFF, };

void show_paras(void);
void show_menu(void);
void change_font(void);
void change_size(void);
void change_align(void);
void toggle_bold(void);
void toggle_italic(void);
void toggle_underline(void);

int main() {
	//char line[MAX_LINE];
	int ch;	
	show_paras();
	show_menu();	
	
	while((ch = getchar())!= EOF) {
		switch(ch){
			case 'f':
				change_font();
				show_paras();
				break;
			case 's':
				change_size();
				puts("");
				show_paras();
				puts("");
				break;
			case 'a':
				change_align();
				puts("");
				show_paras();
				break;
			case 'b':
				toggle_bold();
				show_paras();
				break;
			case 'i':
				toggle_italic();
				show_paras();
				break;
			case 'u':
				toggle_underline();
				show_paras();
				break;
			case 'q':
				goto exit;

			default:
				printf("Invailid selection\n");	
				break;

		}
	
		while(getchar() != '\n');
		show_menu();
	}
exit:
	

	return 0;
}

void show_menu(void) {
	puts("f)change fonts	s)change size 	 a)change alignment");
	puts("b)toggle bold 	i)toggle italic  u)toggle underline");
	puts("q)quit");
}

static const char* align(uint32_t mode){
	switch(mode){
		case ALIGN_LEFT:
			return "left";
		case ALIGN_CENTER:
			return "center";
		case ALIGN_RIGHT:
			return "right";
		default:
			return "";
	}
}

static const char* onoff(uint32_t mode) {
	return mode ? "on" : "off";
}

void show_paras(void){
	printf("ID SIZE ALIGNMENT     B     I     U\n");

	printf("%2d %4d %9s   %3s   %3s   %3s\n",
		font.id, font.size, align(font.alignment), 
		onoff(font.bold), onoff(font.italic), onoff(font.underline));
}

void change_font(void) {
	uint32_t id;
	printf("Enter font id (0 - 255): ");
	if (scanf("%u", &id) == 1 && id >= 0 && id <= 255){
		font.id = id;
	}else{
		printf("Wrong id\n");
	}
}

void change_size(){	
	uint32_t size;
	printf("Enter font size (0-127): ");
	if (scanf("%u", &size) == 1 && size >=0 && size <= 127) {
			font.size = size;	
	}else{
		printf("Wrong Input!\n");
	}
}


void change_align(void) {
	char align;
	
	while(getchar() != '\n');

	printf("Select alignment:\n");
	printf("l)left	c)center  r)right\n");
	if(scanf("%c", &align) == 1 && strchr("lcr", align) ){
		if(align == 'l')
			font.alignment = ALIGN_LEFT;
		else if(align == 'c')
			font.alignment = ALIGN_CENTER;
		else
			font.alignment = ALIGN_RIGHT;
	}

	//while(getchar() != '\n');

}	

void toggle_bold(void){
	font.bold ^= 1;
}

void toggle_italic(void) {
	font.italic ^= 1;
}

void toggle_underline(void){
	font.underline ^= 1;
}
