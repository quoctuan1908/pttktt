#include<stdio.h>

typedef struct {
	char ten[100];
	int TL,GT,PA,SL;
}Do_Vat;
typedef int Bang[50][100];

void Read_File(Do_Vat arr[], int *n, int *g) {
	int i = 0;
	FILE *f = fopen("QHD_CaiBaLo2.txt", "r");
	fscanf(f,"%d", g);
	while (!feof(f)) {
		fscanf(f,"%d %d %d",&arr[i].TL,&arr[i].GT, &arr[i].SL);
		fgets(arr[i].ten, 50, f);
		arr[i].PA = 0;
		i++;
	}
	*n = i;
}

int min(int a, int b) {
	return a < b ? a : b;
}

void Tao_Bang(Do_Vat ds_vat[], int n, int W, Bang F, Bang X) {
	int xk,yk,k,FMax,XMax,V;
	for (V = 0; V <= W; V++) {
		X[0][V] = V/ds_vat[0].TL;
		F[0][V] = X[0][V]*ds_vat[0].GT;
	}
	
	for (k = 1; k < n; k++) {
		for (V = 0; V <= W; V++) {
			FMax = 0;
			yk = min(V/ds_vat[k].TL,ds_vat[k].SL);
			for (xk = 0; xk <= yk; xk++) {
				if (F[k-1][V-xk*ds_vat[k].TL]+xk*ds_vat[k].GT > FMax) {
					FMax = F[k-1][V-xk*ds_vat[k].TL]+xk*ds_vat[k].GT;
					XMax = xk;
				}
				F[k][V] = FMax;
				X[k][V] = XMax;
			}
		}
	}
}

void Tra_Bang(Do_Vat ds_vat[], int n, int W, Bang X) {
	int k, V = W;
	for (k = n-1; k >= 0; k--) {
		ds_vat[k].PA = X[k][V];
		V = V - X[k][V]*ds_vat[k].TL;
	}
}

void In_Bang(Do_Vat ds_vat[], int n,int W, Bang F, Bang X) {
	int i,j;
	for (i = 0; i < n; i++) {
		for (j = 0; j <= W; j++) {
			printf("%2d%2d|", F[i][j], X[i][j]);
		}
		printf("\n");
	}
}

int main() {
	Do_Vat arr[100];
	Bang F,X;
	int n,g,i,TGT = 0,TTL = 0;
	Read_File(arr,&n,&g);
	Tao_Bang(arr,n,g,F,X);
	Tra_Bang(arr,n,g,X);
	In_Bang(arr,n,g,F,X);
	printf("\n\n\n");
	
	printf("| TL| TG| PA| Ten\n");
	for (i = 0; i < n; i++) {
		TGT += arr[i].GT*arr[i].PA;
		TTL += arr[i].TL*arr[i].PA;
		printf("|%3d|%3d|%3d|%s", arr[i].TL, arr[i].GT, arr[i].PA, arr[i].ten);
	}
	printf("\nTGT = %d, TTL = %d", TGT, TTL);
	return 0;
}
