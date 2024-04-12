#include<stdio.h>

void Read_File(int arr[][100], int *n) {
	FILE *f = fopen("tam_giac_so.txt", "r");
	int i = 0,j,temp;
	
	while (!feof(f)) {
		for (j = 0; j <= i; j++) {
			fscanf(f,"%d ",&arr[i][j]);
		}
		i++;
	}
	*n = i;
}

int CS_max(int F[][100], int i, int j) {
	if (j == 0) return (F[i-1][0] > F[i-1][1] ? 0 : 1);
	if (j == i) return i - 1;
	if (j == i-1) return (F[i-1][i-2] > F[i-1][i-1] ? i-2 : i-1);
	if (F[i-1][j-1] > F[i-1][j] && F[i-1][j-1] > F[i-1][j+1]) return j-1;
	if (F[i-1][j] > F[i-1][j-1] && F[i-1][j] > F[i-1][j+1]) return j;
	if (F[i-1][j+1] > F[i-1][j-1] && F[i-1][j+1] > F[i-1][j]) return j+1;
	
}

int Tao_Bang(int arr[][100], int F[][100], int n) {
	F[0][0] = arr[0][0];
	F[1][0] = F[0][0] + arr[1][0];
	F[1][1] = F[0][0] + arr[1][1];
	int i,j;
	for (i = 2; i < n; i++) {
		for (j = 0; j < n; j++) {
			int k = CS_max(arr,i,j);
			F[i][j] = arr[i][j] + F[i-1][k];
		}
	}
}

int CS_max_dong_cuoi(int F[][100], int j) {
	int csmax = F[j][0];
	int csmaxindex = 0;
	int i;
	for (i = 1; i <= j; i++) {
		if (F[j][i] > csmax) {
			csmax = F[j][i];
			csmaxindex = i;
		}
	}
	return csmaxindex;
}

void Tra_Bang(int arr[][100], int n, int F[][100], int PA[]) {
	int i,j;
	j = CS_max_dong_cuoi(F, n-1);
	PA[n-1] = F[n-1][j];
	for (i = n-1; i >= 1; i--) {
		j = CS_max(F,i,j);
		PA[i-1] = F[i-1][j];
	}
}

void In_Bang(int PA[], int n) {
	int i;
	printf("%d", PA[0]);
	for (i = 1; i < n; i++) {
		printf(" => %d", PA[i]);
	};
	printf("\nPhuong an tot nhat la : %d", PA[n-1]);
}
int main() {
	int arr[100][100], F[100][100], PA[100];
	int n,i,j;
	Read_File(arr, &n);
	Tao_Bang(arr,F,n);
	Tra_Bang(arr,n,F,PA);
	In_Bang(PA,n);
	return 0;
}
