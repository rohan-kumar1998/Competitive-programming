#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <fstream>
#include <numeric>
#define ll long long 
#define pb push_back
#define MAX 100000000
#define MIN -100000000 
#define MOD 1000000000 + 7
#define F first 
#define S second
#define sp << " " << 
/*rrrohan*/ 
using namespace std; 
 
/*class dsu{
private: 
	vector <int> r,p; 
public: 
	dsu(int n){
		p.resize(n+1);
		r.resize(n+1);  
		for(int i = 0; i < n+1; i++){
			p[i] = i; 
			r[i] = 0; 
		}
	}
	int findset(int i){
		return (p[i] == i) ? i : (p[i] = findset(p[i])); 
	}
	bool issameset(int a, int b){
		return findset(a) == findset(b); 
	}
	void unionset(int i, int j){
		if(!issameset(i,j)){
			int x = findset(i), y = findset(j); 
			if(r[x] > r[y]){
				p[y]  = x; 
			}else{
				p[x] = y; 
				if(r[x] == r[y]){
					r[y]++; 
				}
			}
		}
	}
};
*/ 
 
/*int bisearch(int l, int r, int x){
	//cout << l << ' ' << r << endl; 
	if(l < r){  
		int mid = (l+r)/2; 
		if(arr[mid].F >= x){
			//cout << arr[mid].F << endl; 
			return bisearch(l, mid, x); 
		}else{ 
			return bisearch(mid + 1, r , x); 
		}
	}else{
		return r; 
	} 
		
}*/

int main(){
	int t; 
	cin >> t; 
	while(t--){
		int n; 
		cin >> n; 	
		int arr[2*n][2*n]; 
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> arr[i][j]; 
				arr[i][j+n] = arr[i][j]; 
				arr[i+n][j] = arr[i][j]; 
				arr[i+n][j+n] = arr[i][j]; 
			}
		}
		ll dp[2*n + 1][2*n + 1]; 
		memset(dp, 0, sizeof(dp)); 
		for(int i =1; i <= 2*n; i++){
			for(int j =1 ; j <= 2*n; j++){
				dp[i][j] = dp[i][j-1] + arr[i-1][j-1];
			}
		}
		for(int i = 1; i <= 2*n; i++){
			for(int j = 1; j <= 2*n; j++){
				dp[i][j] += dp[i-1][j]; 
			}
		}
		ll mx = dp[1][1];  
		for(int i1 = 1; i1 <= 2*n; i1++){
			for(int j1 = 1; j1 <= 2*n; j1++){
				for(int i2 = i1; i2 <= min(i1 + n-1, 2*n); i2++){
					for(int j2 = j1 ; j2 <= min(j1 + n-1,2*n); j2++){
						mx = max(mx,dp[i2][j2] - dp[i1-1][j2] - dp[i2][j1-1] + dp[i1-1][j1-1]); 
					}
				}
			}
		}
		cout << mx << endl; 
	}
}

/*2
5
1  -1  0  0  -4
2  3  -2  -3  2
4  1  -1  5  0
3  -2  1  -3  2
-3  2  4  1  -4
3
1  2  3
4  5  6
7  8  9*/
