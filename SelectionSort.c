#include <stdio.h>
#include <stdlib.h>

void display(int*, int);
void selectionSort(int *, int);
void swap(int* , int*);
int count = 0;

int main() {
	int n;
	int *a;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	a = (int *)malloc(n * sizeof(int));
	for(int i = 0; i < n; i++) {
		scanf("%d",&a[i]);
	}
	display(a,n);
	selectionSort(a,n);
	display(a,n);
	printf("%d\n",count);
}

void display(int *a, int n) {
	for(int i = 0; i < n; i++) {
		printf("%d ",a[i]);
	}
	printf("\n");
}


void selectionSort(int *a, int n) {
	for(int i = 0; i < n; i++) {
		int min = i;
		for(int j = i+1; j < n; j++){
			if(a[j] < a[min]) {
				min = j;
			}
		}
		swap(&a[min], &a[i]);
	}
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	count++;
}