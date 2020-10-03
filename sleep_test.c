#include"syscalls.h"


void reverse(char str[], int length);
char* itoa(int num, char* str);

int main() {
	while (1) {
		int pid =getpid();
		print("process id = ");
		char strpid[4];
		print(itoa(pid,strpid));
		print("\n");
		print("running in background\n");
		print("sleeping for 5 seconds\n");
		sleep(5000);
	}
	return 0;
}

char* itoa(int num, char* str)
{
    int i = 0;
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    while (num != 0)
    {
        int rem = num % 10;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/10;
    }
    str[i] = '\0';
    reverse(str, i);
    return str;
}

void reverse(char str[], int length)
{
    int start = 0;
    int end = length -1;
    while (start < end)
    {
        char tmp=str[start];
        str[start]=str[end];
        str[end]=tmp;
        start++;
        end--;
    }
}
