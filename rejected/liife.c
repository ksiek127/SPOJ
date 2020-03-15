//https://pl.spoj.com/problems/JZYCIE/
#include <stdio.h>
#include <stdbool.h>
//no idea why fails test cases, imo works
int count_alive(int i, int j, int arr[5][5]){ //count alive neighbors of arr[i][j]
	int alive = 0;
	for(int k=-1; k<=1; k++){
		alive += arr[(i+k +5) %5][(j-1 +5) %5]; //upper row
		alive += arr[(i+k +5) %5][(j+1 +5) %5]; //lower row
	}
	alive += arr[(i-1 +5) %5][j]; //left neighbor
	alive += arr[(i+1 +5) %5][j]; //right neighbor
	return alive;
}

bool is_life(int arr[5][5]){
	int alive_neighbors;
	for(int k=0; k<100; k++){
		for(int i=0; i<5; i++){
			for(int j=0; j<5; j++){
				alive_neighbors = count_alive(i, j, arr);
				if(alive_neighbors < 2 || alive_neighbors > 3)
					arr[i][j] = 0;
				else if(alive_neighbors == 3)
					arr[i][j] = 1;
			}
		}
	}
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			if(arr[i][j] == 1)
				return true;
		}
	}
	return false;
}

void print_answer(int arr[5][5]){
	if(is_life(arr))
		printf("yes\n");
	else
		printf("no\n");
}

int main(void){
	int t;
	scanf("%d", &t);
	int arr[5][5];
	while(t--){
		for(int i=0; i<5; i++){
			char c[5];
			scanf("%s", c);
			for(int j=0; j<5; j++)
				arr[i][j] = (int)(c[j]) - 48;
		}
		print_answer(arr);
	}
	return 0;
}	

