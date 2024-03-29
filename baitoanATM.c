#include<stdio.h>


typedef struct {
	int value, PA;
	char name[];
}money;

void read_file(money arr[], int *n) {
	FILE *f = fopen("ATM.txt", "r");
	int i = 0;
	while (!feof(f)) {
		fscanf(f,"%d", &arr[i].value);
		fgets(arr[i].name, 50, f);
		arr[i].PA = 0;
		i++;
	}
	*n = i;
}

void swap(money *a, money *b) {
	int c = a->value;
	a->value = b->value;
	b->value = c;
}

void bubbleSort(money arr[], int n) {
	int i,j;
	for (i = 0; i <= n - 2; i++) {
		for (j = n - 1; j >= i + 1; j--) {
			if (arr[j].value > arr[j - 1].value) {
				swap(&arr[j], &arr[j-1]);
			}	
		}
	}	
}

void Greedy(money arr[], int input) {
	int i = 0, temp = input;
	while (temp > 0) {
		arr[i].PA = temp/arr[i].value;
		temp -= arr[i].PA*arr[i].value;
		i++;
	}
}

int main() {
	money arr[10];
	int n,i, temp;
	read_file(arr,&n);
	bubbleSort(arr,n);
	printf("Nhap so luong tien can quy doi :");
	scanf("%d", &temp);
	Greedy(arr, temp);
	for (i = 0; i < n; i++) {
		if (arr[i].PA > 0) {
			printf("To tien co menh gia :%d, so to can phai su dung la :%d\n", arr[i].value, arr[i].PA);
		}
	}
	return 0;
}
