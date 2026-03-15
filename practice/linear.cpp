#include<bits/stdc++.h>
using namespace std;

void linearSearch(vector<int> &arr, int key){
    int n = arr.size();
    int comparison = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] == key){
            comparison++;
            cout<<"Present"<<endl;
            cout<<"comparison: "<<comparison<<endl;
            return;
        }else{
            comparison++;
        }
    }
    cout<<"Not Present"<<endl;
    cout<<"Comparison: "<<comparison<<endl;
}
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0;  i<n; i++){
            cin>>arr[i];
        }
        cout<<"key: "<<endl;
        int k;
        cin>>k;
        linearSearch(arr,k);
    }
    return 0;
}