#ifndef CIRCLE_H
#define  CIRCLE_H
#include <stdint.h>
using namespace std;
struct var{
	char* name;
	int cnt;
}v[1000];
int ans;
char* out_;
int pow(int a,int b){
	int cnt=1;
	for(int i=1;i<=b;i++){
		cnt*=a;
	}
	return cnt;
}
void init(){
	for(int i=1;i<=999;i++){
		v[i].cnt=0;
		v[i].name="";
	}
}
void cls(){
	unsigned short *Memory=(unsigned short*)0xb8000;
	for(int i=0;i<25;i++){
		for(int j=0;j<80;j++){
			Memory[i*80+j]=Memory[i*80+j]&0xff00|' ';
		}
	}
	return;
}
int abs(int x) {
  return (x<0)?-x:x;
}
void pause(){
	out_="°´enter¼ü¼ÌĞø...\n";
	out(out_);
	out_=in();
	return;
}
char* digit(int flag){
	char* ab;
	if(flag<0){
		flag=abs(flag);
		while(flag>0){
	    int t=flag%10;
	    ab=char_add(ab,char(t-48));
	  }
		return '-'+ab;
	}
	flag=abs(flag);
	while(flag>0){
    int t=flag%10;
    ab=char_add(ab,char(t-48));
  }
	return ab;
}
void count(char* x){
	char* a;
	char* b,ab;
	char c;
	int ans1,ans2;
	int cnt1=0;cnt2=0;
	int flag;
	for(int i=0;x[i]>='0'&&x[i]<='9';i++){
		cnt1++;
		char_add(a,x[i]);
	}
	c=x[i];
	for(int i=cnt1+1;x[i];i++){
		cnt2++;
		char_add(b,x[i]);
	}
	for(int i=0;a[i];i++){
		ans1+=(a[i]-48)*cnt1;
		cnt1--;
	}
  for(int i=0;b[i];i++){
		ans2+=(b[i]-48)*cnt2;
		cnt2--;
	}
	if(c=='+'){
		flag=ans1+ans2;
		ab=digit(flag);
		out(ab);
	}
	else if(c=='-'){
		flag=ans1-ans2;
		ab=digit(flag);
		out(ab);
	}
	else if(c=='*'){
		flag=ans1*ans2;
		ab=digit(flag);
		out(ab);
	}
	else if(c=='/'){
		flag=ans1/ans2;
		ab=digit(flag);
		out(ab);
	}
	else if(c=='^'){
		flag=pow(ans1,ans2);
		ab=digit(flag);
		out(ab);
	}
	else{
		out_="´íÎó";
		out(out_);
	}
}
void system(char* x){
	char* str;
	if(x=="cls"){
		cls();
	}
	else if(x=="pause"){
		pause();
	}
	else if(x=="abs"){
		str=in();
		int cnt=0,ans=0;
		for(int i=0;str[i];i++){
		  cnt++;
	  }
    for(int i=0;a[i];i++){
		  ans+=(a[i]-48)*cnt1;
		  cnt--;
    }
	  int flag=abs(ans);
	  while(flag>0){
			char_add(str,char(flag%10-48));
			flag/=10;
    }
		out(str);
	}
	else if(x=="count"){
		str=in();
		count(str);
	}
	else if(x=="out"){
		str=in();
		out(str);
	}
	else{
		out_="?";
		out(out_);
	}
}
#endif
