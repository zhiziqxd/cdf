#include <stdint.h>
using namespace std;
char* name;
char* password;
bool check_n(){
	if(name==""){
		return false;
	}
	else{
		return true;
	}
}
char* out_;
void sign_up(){
 out_="����:\n";
 out(out_);
 name=in();
 out_="����:\n";
 out(out_);
 return;
}
bool login(){
  out_="����:\n";
  out(out_);
  if(in()!=name){
  	out_="����:\n";
  	out(out_);
  	return false;
  }
  out_="����:\n";
  out(out_);
  if(in()!=password){
		out_="����:/n";
		out(out_);
		return false;
	}
	return true;
}
