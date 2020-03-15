#include <stdio.h>
#include <stdlib.h>

int n_k(long int n, long int k){
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	int *prev = malloc((n/2+1) * sizeof(int));
	int *curr = malloc((n/2+1) * sizeof(int));
	prev[0] = 1;
	prev[1] = 1;
	for(int i=2; i<=n; i++){ //generate half of Pascal's triangle (actually not rly, just storing info about whether numbers are odd or even
		curr[0] = 1;
		for(int j=1; j<i/2; j++)
			if((prev[j-1] + prev[j]) %2 == 0) //just to know if odd or even, 0 - even, 1 - odd
				curr[j] = 0;
			else
				curr[j] = 1;
		if(i%2 == 0)
			curr[i/2] = 0; //curr[i/2] = 2*prev[i/2] -> even
		else
			if((prev[i/2 -1] + prev[i/2]) %2 == 0)
				curr[i/2] = 0;
			else
				curr[i/2] = 1;
		for(int j=0; j<i/2+1; j++)
			prev[j] = curr[j];
	}
	if(k > n-k)
		k = n-k;
	return curr[k];
}

void print_answer(long int n, long int k){
	long int result = n_k(n, k);
	if(result%2 == 0)
		printf("P\n");
	else
		printf("N\n");
}

int main(void){
	int t;
	scanf("%d", &t);
	long int n, k;
	while(t--){
		scanf("%li%li", &n, &k);
		print_answer(n, k);
	}
	return 0;
}

