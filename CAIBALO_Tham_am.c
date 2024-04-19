#include<stdio.h>

typedef int keyType;

typedef struct {
	int TL,GT,SL;
	char Ten[30];
	float DG;
}Do_Vat;



void swap(Do_Vat *a, Do_Vat *b) {
	Do_Vat c = *a;
	*a = *b;
	*b = c;
}

int FindPivot(Do_Vat arr[], int left, int right) {
	int k = left + 1;
	float firstkey = arr[left].DG;
	while (k <= right && firstkey == arr[k].DG) k++;
	if (k > right) return -1;
	if (firstkey > arr[k].DG) return left;
	return k;
}

int Partition(Do_Vat arr[], int left, int right, float pivot) {
	int L = left, R = right;
	while (L <= R) {
		while (arr[L].DG >= pivot) L++;
		while (arr[R].DG < pivot) R--;
		if (L < R) swap(&arr[L], &arr[R]);
	}
	return L; 
}

void QuickSort(Do_Vat arr[], int left, int right) {
	int pivotIndex = FindPivot(arr,left,right),k;
	float pivot;
	if (pivotIndex != -1) {
		pivot = arr[pivotIndex].DG;
		k = Partition(arr,left,right, pivot);
		QuickSort(arr,left,k-1);
		QuickSort(arr,k,right);
	}	
}

void Read_File(Do_Vat arr[], int *tongTL, int *n) {
	FILE *f = fopen("CaiBaLo1.txt", "r");
	int temp;
	fscanf(f, "%d", &temp);
	*tongTL = temp;
	int i = 0;
	while(!feof(f)) {
		fscanf(f,"%d%d%[^\n]", &arr[i].TL, &arr[i].GT,&arr[i].Ten);
		arr[i].DG = arr[i].GT*1.0/arr[i].TL;
		arr[i].SL = 0;
		i++;
	}
	*n = i;
	fclose(f);
}


void Greedy(Do_Vat arr[], int n, int tongTL) {
	int i = 0;
	while (tongTL > 0 && i < n) {
		arr[i].SL = tongTL/arr[i].TL;
		tongTL -= arr[i].SL*arr[i].TL;
		i++;
	}
}

int main() {
	Do_Vat arr[50];
	int n = 0, tongTL;
	Read_File(arr,&tongTL,&n);
	QuickSort(arr,0,n-1);
	Greedy(arr,n, tongTL);
	int i;
	for (i = 0;i < n;i++) {
		printf("%d %d %s %.1f\t\t %d\n",arr[i].TL,arr[i].GT,arr[i].Ten,arr[i].DG, arr[i].SL);
	}
	return 0;
}
