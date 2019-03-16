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

int lcs3(int *a, int n,  int *b, int m, int *c, int l) {
	//write your code here
	int d = 0;
	int result;
	int*** table = (int***)malloc((n+1) * sizeof(int**));
	for(int i=0; i<n+1; i++){
		table[i] = (int**)malloc((m+1) * sizeof(int*));
		for(int j=0; j<m+1; j++){
			table[i][j] = (int*)malloc((l+1) * sizeof(int));
		}
	}

	for(int i = 0; i < n+1; i++){
		for(int j = 0; j < m+1; j++){
			table[i][j][0] = 0;
		}
	}
	for(int i = 0; i < n+1; i++){
		for(int j = 0; j < l+1; j++){
			table[i][0][j] = 0;
		}
	}
	for(int i = 0; i < m+1; i++){
		for(int j = 0; j < l+1; j++){
			table[0][i][j] = 0;
		}
	}

	for(int i = 1; i < n+1; i++){
		for(int j = 1; j < m+1; j++){
			for(int k = 1; k < l+1; k++){
				if(a[i-1] == b[j-1] && a[i-1] == c[k-1]){
					d = table[i-1][j-1][k-1] + 1;
				}
				table[i][j][k] = compare_max(table[i-1][j][k], compare_max(table[i][j-1][k], compare_max(table[i][j][k-1], d)));
				d = 0;
			}
		}
	}

	result = table[n][m][l];
	for(int i=0; i<n+1; i++){
		for(int j=0; j<m+1; j++){
			free(table[i][j]);
		}
	}

	for(int i=0; i<n+1; i++){
		free(table[i]);
	}

	free(table);
	return result;
}

int main() {
	int n, m, l;

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

	printf("Enter value of l: ");
	fflush(stdout);
	scanf("%d", &l);

	int * c = malloc(l*sizeof(int));
	printf("Enter %d values for array c:\n", l);
	fflush(stdout);
	for (int i=0; i < l; i++){
		scanf("%d", &c[i]);
	}

	printf("Input sequences are:\n");
	print_array(a, n);
	print_array(b, m);
	print_array(c, l);
	fflush(stdout);

	int lcs = lcs3(a, n, b, m, c, l);
	printf("LCS = %d\n",lcs);

	return 0;
}
