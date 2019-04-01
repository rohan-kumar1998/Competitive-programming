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
int n,q; 
int d, m; 
int arr[10000000]; 
int memo[205][205][15]; 

int dp(int i, int sum, int c){
	if(sum == 0 && c == m){
		return 1; //memo[i][0][m] = 1
	}
	if(c == m && sum != 0){
		return 0; 
	}if(i == n){ 
		return 0;
	}if(memo[i][sum][c] != -1){
		return memo[i][sum][c];
	}

	memo[i][sum][c] = dp(i + 1, sum%d, c) + dp(i+1, (sum + arr[i])%d  , c + 1); 
	return memo[i][sum][c]; 
}

int main(){
	int x = 1; 
	while(cin >> n >> q){
		if(n== 0 && q == 0){
			return 0; 
		}
		for(int i = 0; i < n; i++){
			cin >> arr[i]; 
		}
		printf("SET %d:\n", x);
		x++; 
		for(int i = 0; i < q; i++){
			cin >> d >> m; 
			memset(memo, -1, sizeof(memo)); 
			int res = dp(0,0,0); 
			cout << "QUERY " << i+1 << ": " << res << endl;   
		}
	} 

}

