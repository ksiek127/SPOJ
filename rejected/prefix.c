#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void print_pref(char *c){
	if(strlen(c) == 0){ //just in case rly nasty input
		printf("\n");
		return;
	}
	printf("0 ");
	if(strlen(c) == 1){
		printf("\n");
		return;
	}
	if(c[0] == c[1])
		printf("1 ");
	else
		printf("0 ");
	bool f;
	for(int i=2; i<strlen(c); i++){ //for each subword 1..n
		int len = 0;
		for(int j=0; j<=(i+1)/2; j++){ //for each letter in the first half of first word
			f = true;
			for(int k=0; k<=j; k++){ //check if can make a suffix
				if(c[k] != c[i-j+k])
					f = false;
			}
			if(f)
				len = j+1;
		}
		printf("%d ", len);
	}
	printf("\n");
}

int main(void){
	int t;
	scanf("%d", &t);
	char c[1000000];
	while(t--){
		scanf("%s", c);
		print_pref(c);
	}
	return 0;
}
