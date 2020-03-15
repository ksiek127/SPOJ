#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int last_dig(char *a, char *b){
	int last = (int)(a[strlen(a)-1] -48); //last digit of a, -48 coz ascii
	if(last == 1 || last == 5 || last == 6 || last == 0){ //those have same last digit in every power
		return last;
	}else if(last == 4 || last == 9){
		int last_b_dig = (int)(b[strlen(b)-1] -48);
		if(last_b_dig%2 == 0)
			return (last*last)%10;
		return last;
	}else{
		int last_b_dig = (int)(b[strlen(b)-1] -48);
		int pre_last_b_dig;
		if(strlen(b) == 1)
			pre_last_b_dig = 0;
		else
			pre_last_b_dig = (int)(b[strlen(b)-2] -48);
		int last_two_b_digs = pre_last_b_dig*10 + last_b_dig;
		switch(last_two_b_digs%4){
			case 0:
				return (last*last*last*last)%10;
			case 1:
				return last;
			case 2:
				return (last*last)%10;
			case 3:
				return (last*last*last)%10;
		}
	}
	return last;
}

int main(void){
	int t;
	scanf("%d", &t);
	char *a = malloc(1000000000 * sizeof(char));
	char *b = malloc(1000000000 * sizeof(char));
	while(t--){
		scanf("%s%s", a, b);
		printf("%d\n", last_dig(a, b));
	}
	return 0;
}
