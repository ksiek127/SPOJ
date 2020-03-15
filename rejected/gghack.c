//https://pl.spoj.com/problems/JGGHACK/
#include <stdio.h>
#include <string.h>
//program works but it seems like gcc can't display characters with ASCII 128-255
void hack(char *c){
	int size = strlen(c);
	int current;
	for(int i=0; i<size; i+=2){ //length of c always equals 20
		current = c[i] - 65 + 16*(c[i+1] -65); //decoding
		printf("%c", current);
	}
	printf("\n");
}

int main(void){
	int t;
	scanf("%d", &t);
	char password[20];
	while(t--){
		scanf("%s", password);
		hack(password);
	}
	return 0;
}
