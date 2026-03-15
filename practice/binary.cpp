#include<bits/stdc++.h>
using namespace std;

void binSearch(vector<int> &arr, int key){
    sort(arr.begin(),arr.end());
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int comparison = 0;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] == key){
            comparison++;
            cout<<"Present"<<endl;
            cout<<"comparison: "<<comparison<<endl;
            return;
        }else if(arr[mid] > key){
            high = mid - 1;
            comparison++;
        }else{
            low = mid + 1;
            comparison++;
        }
    }
    cout<<"Not Present"<<endl;
    cout<<"Comparisons: "<<comparison<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i<n; i++){
            cin>>arr[i];
        }
        int key;
        cin>>key;
        binSearch(arr,key);
    }
    return 0;
}