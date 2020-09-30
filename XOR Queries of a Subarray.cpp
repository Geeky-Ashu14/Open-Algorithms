// XOR Queries of a Subarray
//Given the array arr of positive integers and the array queries where queries[i] = [Li, Ri], for //each query i compute the XOR of elements from Li to Ri (that is, arr[Li] xor arr[Li+1] xor ... xor //arr[Ri] ). Return an array containing the result for the given queries.

#include<bits/stdc++.h>
using namespace std;

 vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {

        if(arr.size()==0 || queries.size()==0){
            return {};
        }

        for(int i=1;i<arr.size();i++){
            arr[i]=arr[i]^arr[i-1];
        }

        vector<int> ans(queries.size());

        for(int i=0;i<queries.size();i++){

            if(queries[i][0]==0){

                ans[i]=arr[queries[i][1]];
            }
            else{
                int x= arr[queries[i][0]-1]^arr[queries[i][1]];
                ans[i]= x;
            }

        }

        return ans;
    }


int main(){
int n;
cin>>n;
vector<int> arr(n);
for(int i=0;i<n;i++){
cin>>arr[i];
}
int r,c;
cin>>r>>c;
vector<vector<int>>& queries (r,vector<int>(c));
for(int i=0;i<r;i++){
for(int j=0;j<c;j++){

cin>>queries[i][j];
}
} 
 vector<int> ans= xorQueries(arr,  queries);
for(int i=0;i<ans.size();i++){
cout<<ans[i]<<” “;
}
return 0;
}
