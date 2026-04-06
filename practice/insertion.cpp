#include<bits/stdc++.h>
using namespace std;

int Comparison,shifts;

void InsertionSort(vector<int> &arr){
    int n = arr.size();

    for(int i = 1; i<n; i++){
        int key = arr[i];
        int j = i-1;

        while(j>=0){
            Comparison++;

            if(arr[j] > key){
                arr[j+1] = arr[j];
                shifts++;
                j--;
            }else{
                break;
            }
        }
        arr[j+1] = key;
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
            cin >> arr[i];
        }

        Comparison = 0;
        shifts = 0;

        InsertionSort(arr);
        for(int i= 0; i<n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        cout<<"Comparison: "<<Comparison<<endl;
        cout<<"Shifts: "<<shifts<<endl;
    }

    return 0;
}