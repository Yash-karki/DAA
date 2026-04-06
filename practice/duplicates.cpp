#include<bits/stdc++.h>
using namespace std;

bool FindDuplicates(vector<int> &arr){
    bool ans = false;
    int n = arr.size();
    sort(arr.begin(),arr.end());

    for(int i = 0; i<n-1; i++){
        if(arr[i] == arr[i+1]){
            ans = true;
            return ans;
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;

        vector<int> arr(n);
        for(int i = 0; i<n; i++){
            cin>>arr[i];
        }

        bool result = FindDuplicates(arr);
        if(result){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}