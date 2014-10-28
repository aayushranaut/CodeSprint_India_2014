#include<bits/stdc++.h>
using namespace std;
int main(){

	int t;
	cin >> t;
	while(t--){
		string str;
		cin >> str;
		int n=str.length();
		sort(str.begin(),str.end());
		vector<int> A;
		int i=0;
		while(i<n){

			char ch=str[i];
			int c=0;
			while(i<n&&ch==str[i])
				c++,i++;
			A.push_back(c);		
		}
		sort(A.rbegin(),A.rend());
		int moves=n-A[0];
		int k=A.size();
		for(int i=2;i<=26;i++){
		
			if(n%i==0){
				int m=0;
				for(int j=0;j<min(i,k);j++){
					m+=min(n/i,A[j]);
				}
				moves=min(moves,n-m);
			}	
		}
		cout << moves << endl;
	}
	return 0;
}