#include <iostream>
#include <cstdlib>
using namespace std;
int parent(int index){
	return (index+1)/2-1;
}

int right(int index){
	return (index+1)*2;
}

int left(int index){
	return (index+1)*2-1;
}

void max_heapify(int *a,int index,int size){
	if (left(index)>size-1 && right(index)>size-1){
		return;
	}
	else if(left(index)>size-1 && a[right(index)]>a[index]){
		int temp=a[index];
		a[index]=a[right(index)];a[right(index)]=temp;
		max_heapify(a,right(index),size);
	}
	else if(right(index)>size-1 && a[left(index)]>a[index]){
		int temp=a[index];
		a[index]=a[left(index)];a[left(index)]=temp;
		max_heapify(a,left(index),size);
	}
	else if(left(index)<=size-1 && right(index)<=size-1){
		if (a[left(index)]>=a[right(index)] && a[left(index)]>a[index]){
			int temp=a[index];
			a[index]=a[left(index)];a[left(index)]=temp;
			max_heapify(a,left(index),size);	
		}
		else if(a[right(index)]>=a[left(index)] && a[right(index)]>a[index]){
			int temp=a[index];
			a[index]=a[right(index)];a[right(index)]=temp;
			max_heapify(a,right(index),size);	
		}
	}
}

void build_heap(int *a,int size){
	for (int i=(size+1)/2-1;i>=0;i--){
		max_heapify(a,i,size);
	}
}

void heap_sort(int *a,int size,int *a_sorted){
	int a_size=size;
	for (int i=0;i<size;i++){
		a_sorted[i]=a[0];
		a[0]=a[a_size];
		a_size--;
		max_heapify(a,0,a_size);
	}
}

int main(){
	const int size=10000000;
	int *a=new int[size];
	int *a_sorted=new int[size];
	srand(time(NULL));
	for (int i=0;i<size;i++){
		a[i]=rand()%(2*size);
	}
	clock_t start1=clock();
	build_heap(a,size);
	clock_t end1=clock();

	clock_t start2=clock();
	heap_sort(a,size,a_sorted);
	clock_t end2=clock();
	/*for (int i=0;i<size;i++){
		cout<<a_sorted[i]<<endl;
	}*/

	cout<<"Time taken for heap_sort: "<< (double)(end2-start2)/(CLOCKS_PER_SEC)<<endl;
	cout<<"Time taken for heap_build: "<< (double)(end1-start1)/(CLOCKS_PER_SEC)<<endl;



}