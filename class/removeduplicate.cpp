// dupicate element
#include <iostream>
using namespace std;

void bubblesort(int arr[],int n){
	 for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int removeduplicate(int arr[],int n){
	
	 for(int i=0;i<=n;i++){
		 if (arr[i]==arr[i+1]){
		 	      for(int k=i;k<=n-1;k++){
		 	      	         arr[k]=arr[k+1];
				   }
				               i--;
				                           n--;		                           
		 }  	 
	}
	   return n;
	
}

int main(){
	int arr[]={8,3,5,8,7,5};
	int n=6;
	bubblesort(arr,n);
	   cout<<"sorted array"<<endl;
    for(int i=0;i<n;i++){
	    cout<<arr[i] ;
	}
	cout<<endl;	  
    n=removeduplicate(arr,n);
       cout<<"unique array"<< endl;
	for(int i=0;i<n;i++){
	    cout<<arr[i] ;
	} 
}
