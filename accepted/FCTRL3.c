#include <stdio.h>

void factorial(int n){
	if(n >= 10){
		printf("%d %d\n", 0, 0);
		return;
	}
	int f = 1;
	for(int i=1; i<=n; i++){
		f *= i;
	}
	if(f > 9){
		printf("%d %d\n", (f%100)/10, f%10);
	}else{
		printf("%d %d\n", 0, f%10);
	}
}

int main(void){
	int d;
	scanf("%d", &d);
	int n;
	while(d--){
		scanf("%d", &n);
		factorial(n);
	}
	return 0;
}	
