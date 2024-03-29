#include<stdio.h>

typedef struct {
	float do_dai;
	int dau,cuoi;
}canh;



void read_file(canh arr[], int *n) {
	FILE *f = fopen("TSP.txt", "r");
	int i = 1,j,z,temp, k = 0;
	while (!feof(f)) {
		fscanf(f, "%d", n);
		for (z = 0; z < i; z++) {
			fscanf(f, "%d", &temp);
		}
		for (j = i; j < *n - 1; j++) {
			fscanf(f,"%f", &arr[k].do_dai);
			arr[k].dau = i;
			arr[k].cuoi = j;
		}
		i++;
	}
	*n = i;
}


int main() {
	canh arr[20];
	int n,i;
	read_file(arr, &n);
	for (i = 0; i < n; i++) {
		
	}
	return 0;
}
