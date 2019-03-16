#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int size){
	for (int i=0; i<size; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int compare_max(int a, int b){
	if(a > b){
		return a;
	}else{
		return b;
	}
}
int lcs2(int *a, int n,  int *b, int m) {
	//write your code here
	int c = 0;
	int result;
	int** table = (int**)malloc((n+1) * sizeof(int*));
	for(int i=0; i<n+1; i++){
		table[i] = (int*)malloc((m+1)*sizeof(int));
	}
	for(int i=0; i<m+1; i++){
		table[0][i] = 0;
	}
	for(int i=0; i<n+1; i++){
		table[i][0] = 0;
	}

	for(int i = 1; i < n+1; i++){
		for(int j = 1; j < m+1; j++){
			if(a[i-1] == b[j-1]){
				c = table[i-1][j-1] + 1;
			}
			table[i][j] = compare_max(table[i][j-1], compare_max(table[i-1][j], c));
			c = 0;
		}
	}

	result = table[n][m];
	for(int i=0; i<n+1; i++){
		free(table[i]);
	}
	free(table);
	return result;
}

int main() {
	int n, m;

	printf("Enter value of n: ");
	fflush(stdout);
	scanf("%d", &n);

	int * a = malloc(n*sizeof(int));
	printf("Enter %d values for array a, separated by spaces:\n", n);
	fflush(stdout);
	for (int i=0; i < n; i++){
		scanf("%d", &a[i]);
	}

	printf("Enter value of m: ");
	fflush(stdout);
	scanf("%d", &m);

	int * b = malloc(m*sizeof(int));
	printf("Enter %d values for array b:\n", m);
	fflush(stdout);
	for (int i=0; i < m; i++){
		scanf("%d", &b[i]);
	}

	printf("Input sequences are:\n");
	print_array(a, n);
	print_array(b, m);
	fflush(stdout);

	int lcs = lcs2(a, n, b, m);
	printf("LCS = %d\n",lcs);

	return 0;
}
