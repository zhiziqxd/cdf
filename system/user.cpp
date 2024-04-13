#include <stdint.h>
using namespace std;
struct text{
	char* name;
	char* txt;
}t[100000];
int ans;
char* out_;
char* str;
void cmd(char* x){
	char* str;
	int i=0;
	while(x[i]){
		if(x[i]!=' '){
			str+=x[i];
		}
		else{
			system(str);
			str="";
		}
	}
}
void user(){
	out_="欢迎使用cdf";
	out(out_);
	while(true){
		str=in();
    if(str=="/add"){
    	ans++;
    	t[ans].name=in();
    	t[ans].txt=in();
		}
		else if(str=="/open"){
			str=in();
			for(int i=1;i<=ans;i++){
				if(str==t[i].name){
					out(t[i].name);
					out_="\n";
					out(out_);
					out(t[i].txt);
				}
			}
		}
		else if(str=="/del"){
			str=in();
			int flag;
			for(int i=1;i<=ans;i++){
				if(str==t[i].name){
					flag=i;
					break;
				}
			}
			for(int i=flag;i<=ans-1;i++){
				t[i].name=t[i+1].name;
				t[i].txt=t[i+1].txt;
			}
		}
	  else if(str=="cmd"){
			str=in();
			for(int i=1;i<=ans;i++){
				if(str==t[i].name){
					cmd(t[i].txt);
				}
			}
		}
		else if(str=="/count"){
			str=in();
			count(str);
		}
		else if(str=="1"){
			t1();//自己编写此软件
		}
		else if(str=="2"){
			t2();//自己编写此软件
		}
		else if(str=="3"){
			t3();//自己编写此软件
		}
		else if(str=="4"){
			t4();//自己编写此软件
		}
		else if(str=="5"){
			t5();//自己编写此软件
		}
		else{
			out_="?";
			out(out_);
		}
	}
}
