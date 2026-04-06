#include<bits/stdc++.h>
using namespace std;

int Comparison;
int Inversions;

void merge(vector<int> &arr, int low, int mid, int high){
    int n1 = mid-low+1;
    int n2 = high-mid;

    int L[n1],R[n2];

    for(int i = 0; i<n1; i++){
        L[i] = arr[low+i];
    }
    for(int i = 0; i<n2; i++){
        R[i] = arr[mid+i+1];
    }

    int i = 0,j = 0,k = low;

    while(i<n1 && j<n2){
        Comparison++;

        if(L[i] <= R[j]){
            arr[k++] = L[i++];
        }else{
            arr[k++] = R[j++];
            Inversions += n1-i;
        }
    }

    while(i<n1){
        arr[k++] = L[i++];
    }
    while(j<n2){
        arr[k++] = R[j++];
    }
}


void MergeSort(vector<int> &arr, int low, int high){
    if(low<high){
        int mid = (low+high)/2;

        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);

        merge(arr,low,mid,high);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i<n; i++){
            cin>>arr[i];
        }

        Comparison = 0;
        Inversions = 0;

        MergeSort(arr,0,n-1);

        for(int i = 0; i<n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;

        cout<<"Comparison: "<<Comparison<<endl;
        cout<<"Inversions: "<<Inversions<<endl;
    }

    return 0;
}