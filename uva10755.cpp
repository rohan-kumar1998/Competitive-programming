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
		int a,b,c; 
		cin >> a >> b >> c; 
		ll arr[a][b][c];
		for(int i = 0; i < a; i++){
			for(int j = 0; j < b; j++){
				for(int k = 0; k < c; k++){
					cin >> arr[i][j][k];
				}
			}
		}
		ll dp[a+1][b+1][c+1]; 
		memset(dp, 0, sizeof(dp)); 
		for(int i = 1; i <= a; i++){
			for(int j= 1; j <= b; j++){
				dp[i][j][1] = arr[i-1][j-1][0]; 
			}
		}
		for(int i = 1; i <= a; i++){
			for(int j = 1; j <= b; j++){
				for(int k = 1; k <= c; k++){
					dp[i][j][k] = dp[i][j][k-1] + arr[i-1][j-1][k-1];
				}
			}
		}
		for(int i = 1; i <= a; i++){
			for(int j = 1; j <= b; j++){
				for(int k = 1; k <= c; k++){
					dp[i][j][k] += dp[i][j-1][k]; 
				}
			}
		}
		for(int i = 1; i <= a; i++){
			for(int j = 1; j <= b; j++){
				for(int k = 1; k <= c; k++){
					dp[i][j][k] += dp[i-1][j][k]; 
				}
			}
		}
		ll mx = dp[1][1][1];  
		for(int i1 = 1; i1 <= a; i1++){
			for(int j1 = 1; j1 <= b; j1++){
				for(int k1 = 1; k1 <= c; k1++){
					for(int i2 = i1; i2 <= a; i2++){
						for(int j2 = j1; j2 <= b; j2++){
							for(int k2 = k1; k2 <= c; k2++){
								mx = max(mx, dp[i2][j2][k2] - dp[i1-1][j2][k2] - dp[i2][j2][k1-1] + dp[i1-1][j2][k1-1] - dp[i2][j1-1][k2] + dp[i2][j1-1][k1-1] + dp[i1-1][j1-1][k2] - dp[i1-1][j1-1][k1-1]); 	
							}
						}
					}
				}
			}
		}
		cout << mx << endl; 
		 if(t)printf("\n") ; 
	}
}
