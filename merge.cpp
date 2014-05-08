#include <iostream>
#include <stdlib.h>
using namespace std;

void merge(int a[],int mid,int len){
	int *tmp=new int[len];
	int l=0,r=mid,k=0;
	while (l<mid || r<len){
		if ((a[l]<=a[r] && l<mid) || (r>=len && l<mid)){
			tmp[k]=a[l];
			k++;l++;
		}
		else{
			tmp[k]=a[r];
			k++;r++;
		}
	}
	for (int i=0;i<len;i++){
		a[i]=tmp[i];
	}
	delete []tmp;
}

void mergesort(int a[],int len){
	if (len==1){
		return;
	}
	mergesort(a,len/2);
	mergesort(a+len/2,len-len/2);
	merge(a,len/2,len);
}

int main(){
	const int s=100000000;

	clock_t start1=clock();
	int *a=new int[s];
	srand(time(0));
	for (int i=0;i<s;i++){
		a[i]=rand()%(s*2);
	}
	clock_t end1=clock();
	clock_t start2=clock();
	mergesort(a,s);
	clock_t end2=clock();
	/*for (int i=0;i<s;i++){
		cout<<a[i]<<endl;
	}*/

	cout<<"Time taken for mergesort: "<< (double)(end2-start2)/(CLOCKS_PER_SEC)<<endl;
	cout<<"Time taken for generate array: "<< (double)(end1-start1)/(CLOCKS_PER_SEC)<<endl;

}