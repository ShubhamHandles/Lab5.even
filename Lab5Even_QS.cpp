/*
Q: Implement quick sort on an array.
*/

#include<iostream>
using namespace std;

int Part(int arr[], int low, int high){
	//set pivot
	int pivot = arr[high];
	int index = low; 
	
	//start comparing with pivot
	for(int i=low+1; i<high; i++){
		if(arr[i]<=pivot){
			swap(arr[i],arr[index]); //swap if lesser than pivot
			index++;
		}
	}
	swap(arr[index], arr[high]); //swap partion index element with pivot
	return index;	
}

void QS(int arr[], int low, int high){
	if(low<high){
		//pivot and partition
		int pivot = Part(arr,low,high);
		//recursion
		QS(arr,low,pivot-1);
		QS(arr,pivot+1,high);
	}
}

int main(){
	int s;
	cout << "Enter the size of your array:" << endl;
	cin >> s;
	
	int arr1[s];
	cout << "Enter the elements:" << endl;
	for(int i=0; i<s; i++){
		cin >> arr1[i];
	}
	
	QS(arr1, 0, s-1);
	
	cout << "Sorted array: " ;
	for(int i=0; i<s; i++){
		cout << arr1[i] << " ";  
	}
	
	return 0;	
}
