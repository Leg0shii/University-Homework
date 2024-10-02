#include <stdio.h>

void selectionSort(int *a, int n) {
	
	int i, j, min, t;
	
	for(i = 0; i < n; i++) {
		
		min = i;

		for(j = i + 1; j < n; j++) {
			
			if(a[j] < a[min])  min = j;
			
		}
		
		t = a[min];
		a[min] =  a[i];
		a[i] = t;
	
	}
	
}

void insertSort(int *a, int n) {
	
	int i, j, v;
	
	for(i = 1; i < n; i++) {
		
		v = a[i];
		j = i;
		
		while(a[j-1] > v && j >= 1) {
			
			a[j] = a[j-1];
			j--;
			
		}
		
		a[j] = v;
		
	}	
	
}

void bubbleSort(int *a, int n) {
	
	int i, j, v;
	
	for(i = 0; i < n; i++) {
		
		for(j = 0; j < n - i; j++) {
			
			if(a[j+1] < a[j]) {
				
				v = a[j];
				a[j] = a[j+1];
				a[j+1] = v;
				
			}
			
		}
		
	}
	
}


int main() {
	
	int a[] = {9,4,1,5,7,3,2};
	
	bubbleSort(a, 7);
	
	for(int i = 0; i < 7; i++) {
		
		printf("%d\n", a[i]);
		
	}
	
	return 0;
	
}