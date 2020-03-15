//https://pl.spoj.com/problems/JSZYFR2/
#include <stdio.h>
#include <stdbool.h>
//issue when can decypher one word with two keys, so for some words there are several translations
int find_key(int arr[25], int n){
	bool is_prime[150];
	for(int i=2; i<150; i++)
		is_prime[i] = true;
	for(int i=2; i<150; i++){ //sieve of Sundaram
		if(is_prime[i]){
			int tmp = 2*i;
			while(tmp < 150){
				is_prime[tmp] = false;
				tmp += i;
			}
		}
	}
	bool is_key;
	for(int i=123; i<150; i++){ //find key
		is_key = true;
		if(is_prime[i]){
			for(int j=0; j<n; j++){
				if(arr[j] % i < 65 || arr[j] % i > 90)
					is_key = false;
			}
		if(is_key)
			return i;
		}
	}
	return -1;
}

void decode(int arr[25], int n){
	int key = find_key(arr, n);
	if(key == -1)
		printf("NIECZYTELNE\n");
	else{
		printf("%d ", key);
		for(int i=0; i<n; i++)
			printf("%c", (char)(arr[i] % key));
		printf("\n");
	}
}

int main(void){
	int t;
	scanf("%d", &t);
	int n;
	int arr[25];
	while(t--){
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			int x;
			scanf("%d", &x);
			arr[i] = x;
		}
		decode(arr, n);
	}
	return 0;
}
