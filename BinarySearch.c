#include <stdio.h>
#include <stdlib.h>
int BinarySearchRecursive(int*, int, int, int);
int BinarySearchIterative(int*, int, int, int);

int main() {
	int n,key,keyTwo;
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	int* p = (int *)malloc(n * sizeof(int));
	for(int i = 0; i < n; i++) {
		scanf("%d",&p[i]);
	}
	/*for(int i = 0; i < n; i++) {
		printf("%d",p[i]);
	}*/
	//Assumption array is already sorted
	printf("\nEnter the element to search for : ");
	scanf("%d",&key);
	int position = BinarySearchRecursive(p,0,n,key);
	printf("\n%d\n",position);
	scanf("%d",&keyTwo);
	int position2 = BinarySearchIterative(p,0,n,keyTwo);
	printf("\n%d\n",position2);
	return 0;
}

int BinarySearchRecursive(int *a, int l, int d, int key) {
	if(l > d) {
		return -1;
	}
	int mid = (l+d)/2;
	if(a[mid] == key){
		return mid + 1;
	}else if(a[mid] < key){
		return BinarySearchRecursive(a, mid+1, d, key);
	}else{
		return BinarySearchRecursive(a, l, mid-1, key);
	}
}

int BinarySearchIterative(int *a, int l, int d, int key) {	
	while(l <= d) {
		int mid = (l+d)/2;
		if(a[mid] == key) {
			return mid+1; 
		}else if(a[mid] < key) {
			l = mid + 1;
		}else {
			d = mid - 1;
		}
	}
	return -1;
}