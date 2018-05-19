#include <stdio.h>
#include <stdlib.h>

void display(int*, int);
void swap(int *a, int *b);
void quickSortHoare(int *a, int l, int r);
void quickSortLomuto(int *a, int l, int r);
int HoarePartition(int *a, int s, int e);
int LomutoPartition(int *a, int l, int r);


int main() {
	int n;
	int *a,*b;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	a = (int *)malloc(n * sizeof(int));
	b = (int *)malloc(n * sizeof(int));
	for(int i = 0; i < n; i++) {
		scanf("%d",&a[i]);
		b[i] = a[i];
	}	
	display(a,n);
	printf("Using Hoare Partition Scheme \n");
	quickSortHoare(a,0,n-1);
	display(a,n);
	printf("\n");
	display(b,n);
	printf("Using Lomuto Partition Scheme \n");
	quickSortLomuto(b,0,n-1);
	display(b,n);


}

void display(int *a, int n) {
	for(int i = 0; i < n; i++) {
		printf("%d ",a[i]);
	}
	printf("\n");
}

// https://www.geeksforgeeks.org/hoares-vs-lomuto-partition-scheme-quicksort/

// Note the difference in implementation of partition. What I have done is, as soon as we get the partition index, I swap the pivot
// with the partition index element and then return the partition index.
void quickSortHoare(int *a, int l, int r) {
	if(l < r) {
		int partition = HoarePartition(a,l,r);
		quickSortHoare(a,l,partition-1);
		quickSortHoare(a,partition+1,r);
	}
}

void quickSortLomuto(int *a, int l, int r) {
	if(l < r) {
		int partition = LomutoPartition(a,l,r);
		quickSortLomuto(a,l,partition-1);
		quickSortLomuto(a,partition+1,r);
	}
}


void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;	
}

int HoarePartition(int *a, int s, int e) {
	int pivot = a[s];
	int i = s + 1;
	int j = e;
	while(i <= j) {
		while(i <= j && a[i] < pivot) i++;
		while(i <= j && a[j] > pivot) j--;
		if(i < j) {
			swap(&a[i],&a[j]);
			i++;
			j--;
		}
	}
	swap(&a[j], &a[s]);
	return j;
}

int LomutoPartition(int *a, int l, int r) {
	int pivot = a[r];
	int pIndex = l;
	for(int i = l; i < r; i++) {
		if(a[i] <= pivot) {
			swap(&a[i],&a[pIndex]);
			pIndex++;
		}
	}
	swap(&a[pIndex],&a[r]);
	return pIndex;
}

