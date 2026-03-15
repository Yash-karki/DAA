#include<bits/stdc++.h>
using namespace std;


int Comparison;
int Swaps;
int partition(vector<int> &arr, int low, int high){
    int pivot = arr[high];
    int i = low-1;

    for(int j = low; j<high; j++){
        Comparison++;

        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
            Swaps++;
        }
    }

    swap(arr[i+1],arr[high]);
    Swaps++;
    return i+1;
}


void QuickSort(vector<int> &arr, int low, int high){

    if(low<high){
        int p = partition(arr,low,high);

        QuickSort(arr,low,p-1);
        QuickSort(arr,p+1,high);
    }
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i<n; i++){
            cin >> arr[i];
        }
        Comparison = 0;
        Swaps = 0;

        QuickSort(arr,0,n-1);

        for(int i = 0; i<n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;

        cout<<"Comparison: "<<Comparison<<endl;
        cout<<"Swaps: "<<Swaps<<endl;

    }
}