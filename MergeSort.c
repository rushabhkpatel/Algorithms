#include <stdio.h>
#include <stdlib.h>

void display(int *, int );
void mergeSort(int *array, int n);
void merge(int *a, int m,int *b, int n, int *array);

int main() {
	int n;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	int *array = (int *)malloc(n * sizeof(int));
	int *temp = (int *)malloc(n * sizeof(int));
	for(int i = 0; i < n; i++) {
		scanf("%d",&array[i]);
	}
	display(array,n);
	mergeSort(array,n);
	display(array,n);
	return 0;
}


void display(int *a, int n) {
	for(int i = 0; i < n; i++) {
		printf("%d ",a[i]);
	}
	printf("\n");
}

void mergeSort(int *array, int n) {
	int middle = n / 2;
	int *a = (int *)malloc(middle * sizeof(int));
	int *b = (int *)malloc((n - middle) * sizeof(int));
	if(n > 1) {
		for(int i = 0; i < middle; i++){
			a[i] = array[i];	
		}
		for(int i = middle; i < n; i++) {
			b[i - middle] = array[i];
		}
		mergeSort(a,middle);
		mergeSort(b,n-middle);
		merge(a,middle,b,n-middle,array);
		free(a);
		free(b);
	}
}

void merge(int *a, int m,int *b, int n, int *array) {
	int i = 0, j = 0, k = 0;
	while(i < m && j < n) {
		if(a[i] <= b[j]) {
			array[k] = a[i];
			i++;
		}else {
			array[k] = b[j];
			j++;
		}
		k++;
	}
	while(i < m){
		array[k] = a[i];
		i++;k++;
	}
	while(j < n){
		array[k] = b[j];
		j++;k++;
	}
}