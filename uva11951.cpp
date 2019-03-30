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
	int x = 1; 
	while(t--){
		int n, m;
		ll k;  
		cin >> n >> m >> k;
		int arr[n][m]; 
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> arr[i][j]; 
			}
		} 
		ll dp[n+1][m+1]; 
		memset(dp, 0, sizeof(dp)); 
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				dp[i][j] = arr[i-1][j-1]; 
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				dp[i][j] += dp[i][j-1]; 
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				dp[i][j] += dp[i-1][j]; 
			}
		}
		ll mx = 0, plot = 0;
		for(int i1 = 1; i1 <= n; i1++){
			for(int j1 = 1; j1 <= m; j1++){
				for(int i2 = i1 ; i2 <= n; i2++){
					for(int j2 = j1; j2 <= m; j2++){
						ll sum = dp[i2][j2] - dp[i1-1][j2] - dp[i2][j1-1] + dp[i1-1][j1-1]; 
						if(sum <= k && (j2 - j1 + 1)*(i2 - i1 + 1) >= plot){
							if(plot == (j2 - j1 + 1)*(i2 - i1 + 1)){
								mx = min(mx,sum); 
							}else{
								plot = (j2 - j1 + 1)*(i2 - i1 + 1);
								mx = sum; 
							}
						}
					}
				}
			}
		}
		cout <<"Case #"<< x <<": "<< plot <<" "<< mx <<endl; 
		x++; 
	}
}
/*1
5  6  15
10  1  10  20  10  10
30  1  1  5  1  1
50  1  1  20  1  1
10  5  5  10  5  1
40  10  90  1  10  10*/

