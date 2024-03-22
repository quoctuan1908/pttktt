#include<stdio.h>

typedef int keyType; 
typedef struct {
	keyType key;
	float otherKey;
} recordType;


void swap(recordType *a, recordType *b) {
	recordType temp = *a;
	*a = *b;
	*b = temp;
}

void SelectionSort(recordType arr[], int n) {
	int i,j,lowindex;
	keyType lowkey;
	
	for (i = 0;i <= n - 2;i++) {
		lowkey = arr[i].key;
		lowindex = i;
		for (j = i + 1; j < n ; j++) {
			if (arr[j].key < lowkey) {
				lowkey = arr[j].key;
				lowindex = j;
			}
		}
		swap(&arr[i], &arr[lowindex]);	
	}
	
}

void InsertionSort(recordType arr[], int n) {
	int i,j;
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j > 0; j--) {
			if (arr[j].key < arr[j - 1].key) {
				swap(&arr[j], &arr[j - 1]);
			}
		}	
	}
}

void BubbleSort(recordType arr[], int n) {
	int i ,j;
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1;j > 0 ; j--) {
			if (arr[j].key < arr[j-1].key) {
				swap(&arr[j], &arr[j-1]);
			}
		}
	}	
}


//Quick Sort

int findPivot(recordType arr[], int i, int j) {
	int k = i + 1;
	keyType firstKey = arr[i].key;
	while (arr[k].key == firstKey && (k <= j)) {
		k++;
	}
	if (k > j) return -1;
	if (arr[k].key > firstKey) {
		return k;
	}
	return i;
}

int Partition(recordType arr[], int i, int j, keyType pivot) {
	int L,R;
	L = i;
	R = j;
	while (L <= R) {
		while (arr[L].key < pivot) L++;
		while (arr[R].key >= pivot) R--;
		if (L < R) {
			swap(&arr[L], &arr[R]);
		}
	}
	return L;
}

void QuickSort(recordType arr[], int start, int end) {
	int pivotIndex = findPivot(arr, start, end);
	int k;
	if (pivotIndex != -1) {
		k = Partition(arr, start, end, arr[pivotIndex].key);	
		QuickSort(arr, start, k - 1);
		QuickSort(arr, k, end);
	} 
}

//QuickSortBIenThe

int FindPivotVariant(recordType arr[], int start, int end) {
	int k = start + 1;
	while (arr[k].key == arr[start].key && k <= end) {
		k++;
	}
	if (k >= end) return -1;
	if (arr[k].key > arr[start].key) return k;
	return start;
}

int PartitionVariant(recordType arr[], int start, int end, int pivot) {
	int L = start;
	int R = end;
	while (L <= R) {
		while (arr[L].key < arr[pivot].key) L++;
		while (arr[R].key >= arr[pivot].key) R--;
		if (L < R) swap(&arr[L], &arr[R]);
	}
	return L;
}

void QuickSortVariant(recordType arr[], int start, int end) {
	int pivot = FindPivotVariant(arr,start,end);
	if (pivot != -1) {
		int k = PartitionVariant(arr,start,end, pivot);
		QuickSort(arr,start,k-1);
		QuickSort(arr,k,end);
	}
}


//Heap Sort

void PushDown(recordType arr[], int first, int last) {
	int r = first;
	while (r <= (last - 1)/2) {
		if (2*r + 2 > last) {
			if (arr[r].key < arr[last].key) {
				swap(&arr[r], &arr[last]);
			}
			r = last;
		} else {
			if (arr[r].key < arr[2*r+1].key && arr[2*r+1].key >= arr[2*r+2].key) {
				swap(&arr[r], &arr[2*r+1]);
				r = 2*r+1;
			} else {
				if (arr[r].key < arr[2*r+2].key) {
					swap(&arr[r], &arr[2*r+2]);
					r = 2*r + 2;
				} else {
					r = last;
				}
			}
		}
	}
}

void HeapSort(recordType arr[], int n) {
	int i;
	for (i = (n-2)/2; i >= 0; i--) {
		PushDown(arr, i, n - 1);
	}
	for (i = n - 1; i >= 2 ; i--) {
		swap(&arr[0], &arr[i]);
		PushDown(arr, 0, i - 1);
	}
	swap(&arr[0], &arr[1]);
}


void Read_File(recordType arr[], int *n) {
	FILE *f = fopen("data.txt", "r");
	int key,index = 0;
	float otherKey;
	while (fscanf(f,"%d %f", &key, &otherKey) != EOF) {
		arr[index].key = key;
		arr[index].otherKey = otherKey;
		index++;
	}
	*n = index;
}



int main() {
	int i,n = 0;
	recordType arr[100];
	Read_File(arr, &n);	
	
	printf("Mang Truoc Khi Duoc Sap Xep \n");
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("\n");
	
	QuickSortVariant(arr,0, n - 1);
	printf("Mang Sau Khi Duoc Sap Xep \n");
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
