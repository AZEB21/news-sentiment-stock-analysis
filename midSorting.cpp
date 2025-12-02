#include <iostream>
using namespace std;
void bubleSort(int arr[],int n){
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }

        }
    }

}
void selectionSort(int arr[],int n){
    for(int i=0;i<=n-2;i++){
        int Mindex=i;
        for(int j=i+1;j<=n-1;j++){
            if(arr[Mindex]>arr[j]){
                Mindex=j;
            }
            
            
        }
        if(Mindex!=i){
                int temp=arr[Mindex];
                arr[Mindex]=arr[i];
                arr[i]=temp;
            }

    }
}
void insertionSort(int arr[],int n){
    for(int i=1;i<n-1;i++){
        for(int j=0;j<n-1;j++)
{
if(arr[i]>arr[j]){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;}
}    }
}
void binaryInsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int left = 0, right = i - 1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (arr[mid] > key)
                right = mid - 1;
            else
                left = mid + 1;
        }
        for (int j = i - 1; j >= left; j--) {
            arr[j + 1] = arr[j];
        }

        arr[left] = key;
    }
}


int main (){
int array[5]={3,1,5,6,7};
 binaryInsertionSort(array,5);
for(int i=0;i<5;i++){
    cout<<array[i]<<" ";
}
cout<<endl;


    return 0;
}