#include <stdint.h>
using namespace std;
int main(){
	if(check_n()==false){
		sign_up();
	}
	else{
		if(login()){
			user();
		}
		else{
			return 0;
		}
	}
}
