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
 out_="Ãû×Ö:\n";
 out(out_);
 name=in();
 out_="ÃÜÂë:\n";
 out(out_);
 return;
}
bool login(){
  out_="Ãû×Ö:\n";
  out(out_);
  if(in()!=name){
  	out_="´íÎó:\n";
  	out(out_);
  	return false;
  }
  out_="ÃÜÂë:\n";
  out(out_);
  if(in()!=password){
		out_="´íÎó:/n";
		out(out_);
		return false;
	}
	return true;
}
