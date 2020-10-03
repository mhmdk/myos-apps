#include"syscalls.h"


int main(){
	print("hello from ring 3\n");
	print("hello is calling exit() \n");
	exit(0);
	return 0;
}

