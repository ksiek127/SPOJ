//https://pl.spoj.com/problems/NWW/
#include <stdio.h>
//too slow
long long int gcd(long long int x, long long int y){ //greatest common divisor
	int gcd_part = 1;
	while(x%2 == 0 && y%2 == 0){
		x /= 2;
		y /= 2;
		gcd_part *= 2;
	}
	while(x%3 == 0 && y%3 == 0){
		x /= 3;
		y /= 3;
		gcd_part *= 3;
	}
	while(x != y){
		if(x > y){
			x -= y;
		}else{
			y -= x;
		}
	}
	return x * gcd_part;
}

long long int lcm(long long int x, long long int y){ //least common multiple for 2 numbers
	return x*y/gcd(x, y);
}

long long int lcm_n(long long int arr[], int n){ //lcm for n numbers
	//if(left == right)
	//	return left;
	//if(left +1 == right)
	//	return lcm(arr[left], arr[right];
	//int mid = (left + right)/2;
	//return lcm_n(left, mid);
	//return lcm_n(mid+1, right);
	while(n>1){
		for(int i=0; i<n/2; i++){
                        arr[i] = lcm(arr[i], arr[i+n/2]);
		}
		if(n%2 == 0)
			n /= 2;
		else{
			arr[n/2] = arr[n-1];
			n = (n+1)/2;
		}
	}
	return arr[0];
}

int main(void){
	int t;
	int n;
	long long int a;
	long long int arr[4000];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%lli", &a);
			arr[i] = a;
		}
		printf("%lli\n", lcm_n(arr, n));
	}
	return 0;
}
