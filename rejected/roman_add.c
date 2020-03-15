//https://pl.spoj.com/problems/JSUMRZYM/
#include <stdio.h>
#include <string.h>

struct number{
	int a;
	char r;
};

int roman_digit_to_arabic(char c){ //works
	switch(c){
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
	}
	return -1;
}

int roman_to_arabic(char r[], int len){ //works
	if(r[0] == 'M')
		return 1000;

	int result = 0;
	struct number roman[len];	
	for(int i=0; i<len; i++){
		struct number tmp;
		tmp.a = roman_digit_to_arabic(r[i]);
		tmp.r = r[i];
		roman[i] = tmp;
	}
	for(int i=0; i<len-1; i++){
		if(roman[i].a < roman[i+1].a)
			result -= roman[i].a;
		else
			result += roman[i].a;
	}
	result += roman[len-1].a; //last element outside loop so the loop ends before the last element, thus no risk of i+1 being outside array
	return result;
}

void arabic_to_roman(int a){
	if(a >= 1000){
		printf("M");
		a -= 1000;
	}
	if(a >= 900){
		printf("CM");
		a -= 900;
	}
	if(a >= 500){
		printf("D");
		a -= 500;
	}
	if(a >= 400){
		printf("CD");
		a -= 400;
	}
	while(a >= 100){
		printf("C");
		a -= 100;
	}
	if(a >= 90){
		printf("XC");
		a -= 90;
	}
	if(a >= 50){
		printf("L");
		a -= 50;
	}
	if(a >= 40){
		printf("XL");
		a -= 40;
	}
	while(a >= 10){
		printf("X");
		a -= 10;
	}
	if(a >= 9){
		printf("IX");
		a -= 9;
	}
	if(a >= 5){
		printf("V");
		a -= 5;
	}
	if(a >= 4){
		printf("IV");
		a -= 4;
	}
	while(a >= 1){
		printf("I");
		a--;
	}
	printf("\n");
}

int main(void){
	int t;
	scanf("%d", &t);
	char c1[12], c2[12];
	int x, y;
	while(t--){
		scanf("%s%s", c1, c2); 
		x = roman_to_arabic(c1, strlen(c1));
		y = roman_to_arabic(c2, strlen(c2));
		arabic_to_roman(x+y);
	}
	return 0;
}
