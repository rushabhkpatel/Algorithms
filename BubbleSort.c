#include <stdio.h>
#include <stdlib.h>

void display(int*, int);
void bubbleSort(int *, int);
void bubbleSortAlternate(int *, int);
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
	bubbleSortAlternate(a,n);
	display(a,n);
	printf("%d\n",count);
}

void display(int *a, int n) {
	for(int i = 0; i < n; i++) {
		printf("%d ",a[i]);
	}
	printf("\n");
}

void bubbleSort(int *a, int n) {
	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j < n - i - 1; j++) {
			if(a[j] > a[j+1]) {	
				count++;
				swap(&a[j], &a[j+1]);
			}
		}
	}	
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

/* Another way of implementing Bubble sort - 
 done on HackerRank YouTube channel - https://www.youtube.com/watch?v=6Gv8vg0kcHc
*/

void bubbleSortAlternate(int *a, int n) {
	int isSorted = 0;
	int unsortedLast = n - 1; //After first pass the biggest element will be at the end. Hence array will be unsorted from 0 to n - 1
	while(!isSorted) {
		isSorted = 1;
		for(int i = 0; i < unsortedLast; i++) {
			count++;
			if(a[i] > a[i+1]) {
				
				swap(&a[i], &a[i+1]);
				isSorted = 0;
			}
		}
		unsortedLast--;
	}

}