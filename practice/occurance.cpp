#include<bits/stdc++.h>
using namespace std;

int FirstOccurance(vector<int> &arr, int n, int key){
    int low = 0;
    int high = n-1;
    int res = -1;

    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == key){
            res = mid;
            high = mid-1;
        }else if(arr[mid] < key){
            low = mid + 1;
        }else{
            high = mid-1;
        }
    }
    return res;
}

int LastOccurance(vector<int> arr, int n, int key){
    int low = 0;
    int high = n-1;
    int res = -1;

    while(low<=high){
        int mid = low + (high - low)/2;
        if(arr[mid] == key){
            res = mid;
            low = mid+1;
        }else if(arr[mid] < key){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,key;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i<n; i++){
            cin>>arr[i];
        }
        cin>>key;

        int first = FirstOccurance(arr,n,key);

        if(first == -1){
            cout<<"Key not found"<<endl;
        }else{
            int last = LastOccurance(arr,n,key);
            cout<<key<<"-"<<last-first+1<<endl;
        }
    }
    return 0;
}