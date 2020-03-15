#include <stdio.h>
#include <stdlib.h>
//too slow
void insertion_sort(long int n, long long *arr){
	long int k;
    	for(long int i=0; i<n; i++){
		k=i-1;
		while(k>=0 && arr[i] < arr[k]){
			k--;
		}
		long long tmp = arr[i];
		for(long int j=i; j>k+1; j--){ //shift
			arr[j] = arr[j-1];
		}
		arr[k+1] = tmp; //insert
    	}
}

long long find_leader(long int n, long long *arr){
	insertion_sort(n, arr);
	long int current = 1;
	long int longest = 1;
	long long leader = arr[0];
	for(long int i=0; i<n-1; i++){
		if(arr[i] == arr[i+1])
			current++;
		else{
			if(current > longest){
				longest = current;
				leader = arr[i-1]; //if i=0 then current == longest, thus won't enter this and won't cause segmentation error by calling arr[-1]
			}
			current = 1;
		}
	}
	if(current > longest){ //in case last element is leader
		longest = current;
		leader = arr[n-1];
	}
	if(longest > n/2)
		return leader;
	return -1;
}

int main(void){
	int t;
	scanf("%d", &t);
	while(t--){
		long int n;
		scanf("%li", &n);
		long long *arr = malloc(n * sizeof(unsigned long long));
		for(long int i=0; i<n; i++){
			long long x;
			scanf("%lli", &x);
			arr[i] = x;
		}
		printf("%lli\n", find_leader(n, arr));
	}
	return 0;
}
