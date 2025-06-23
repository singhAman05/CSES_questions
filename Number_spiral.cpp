// Problem: Number Spiral
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1071
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef map<int, int> mpi;
typedef set<int> seti;
typedef unordered_map<int,int> uom;
typedef unordered_map<char,int> uocm;

void fun(){
	long long y,x;cin>>y>>x;
	if(y>x){
		if(y%2){
			cout<<(y-1)*(y-1) + x;
		}
		else{
			cout<< y*y - (x-1);
		}
	}
	else{
		if(x%2){
			cout<<x*x - (y-1);
		}
		else{
			cout<< (x-1)*(x-1) + y;
		}
	}
	
	cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	ll t;cin>>t;
    while(t--){
    	fun();
    }
    
    return 0;
}
