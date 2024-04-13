#include <stdint.h>
using namespace std;
int x,y;
bool shift=false;
void sleep(int n){
	unsigned short i=n*43;
	while(i--);
	return;
}
bool check(){
	if(x>=80){
		x=0;
		y++;
	}
	if(y>=25){
		return true;
	}
	return false;
}
void out(char* str){
	unsigned short *Memory=(unsigned short*)0xb8000;
	for(int i=0;str[i];i++){
		if(str[i]=='\n'){
			y++;
			x=0;
		}
		else{
			Memory[i*y+x]=Memory[i*y+x]&0xff00|str[i];
		}
		if(check()){
			for(y=0;y<25;y++){
				for(x=0;x<80;x++){
					Memory[80*y+x]=Memory[80*y+x]&0xff00|' ';
				}
			}
		}
	}
	return;
}
void str_add(char* dest, const char* src) {
  while (*dest != '\0') {
    dest++;
  }
  while(*src!='\0'){
   *dest = *src;
    dest++;
    src++;
  }
  *dest='\0';
}
void char_add(char* dest,char src) {
  while(*dest!='\0'){
    dest++;
  }
  *dest=src;
  *(dest+1)='\0';
}
char* in(){
  char* key=0;
	while(true){
		char in_to=*(char*)0x60;//根据实际情况修改接口
		if(in_to=='\n'){
			y++;
			x=0;
			break;
		}
		else if(in_to==0x10){
			shift=!shift;
		}
		else{
			char* in_;
			char_add(in_,in_to);
			out(in_);
			key+=in_to;
		}
	}
	return key;
}
