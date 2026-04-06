#include<bits/stdc++.h>
using namespace std;

int Comparison,Swaps;


void SelectionSort(vector<int> &arr){
    int n = arr.size();

    for(int i = 0; i<n-1; i++){
        int mini = i;
        for(int j = i+1; j<n; j++){
            Comparison++;

            if(arr[j] < arr[mini]){
                mini = j;
            }

        }
            if(mini != i){
                swap(arr[i], arr[mini]);
                Swaps++;
            }
        }
    }

int main(){
    int t;
    cin>> t;

    while(t--){
        int n ;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i<n; i++){
            cin>>arr[i];
        }

        SelectionSort(arr);

        for(int i = 0; i<n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;

        cout<<"Comparison: "<<Comparison<<endl;
        cout<<"Swaps: "<<Swaps<<endl;
    }

    return 0;
}