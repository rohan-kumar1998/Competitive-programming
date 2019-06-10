#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>
#include <set>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <fstream>
#include <numeric>
#define endl '\n'
#define ll long long 
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);   
#define F first 
#define S second
#define err cout << "err" << endl; 
const ll INF = std::numeric_limits<long long>::max(); 
const int IINF = std::numeric_limits<int>::max(); 
//const int MOD = 1e9 + 7; 
const int MOD =998244353; 
/*rrrohan*/ 
using namespace std; 
 
/*less than or equal to -> l + r + 1*/
/*upper_bound -> greater than x 
lower_bound -> greater than or equal to x*/
/*unordered_map -> O(1)/O(n) 
map -> O(logn)/O(logn)*/ 
/*(a - b) MOD p = ((a MOD p - b MOD p) + p) MOD p
(a / b) MOD p = ((a MOD p) * (b^(-1) MOD p)) MOD p
(a * b) MOD p = ((a MOD p) * (b MOD p)) (MOD p)*/

ll gcd(ll a, ll b) //O(log(a+b))
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
}  

ll lcm(ll a, ll b){
	return a*b/gcd(a,b); 
}
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

int main(){
	int t; 
	cin >> t; 
	int it = 1; 
	while(t--){
		int r,c,m,n; 
		cin >> r >> c >> m >> n; 
		char arr[r][c];
		for(int i = 0; i < r; i++){
			fill(arr[i],arr[i]+c, '.'); 
		} 
		int w; 
		cin >> w; 
		int x,y; 
		for(int i =0; i < w; i++){
			cin >> x >> y; 
			arr[x][y] = 'w'; 
		}
		//int l = 0, k = 0; 
		queue <pair<int,int>> q; 
		q.push({0,0}); 
		pair <int,int> p[] = {{m,n},{m,-n},{-m,n},{-m,-n},{n,m},{n,-m},{-n,m},{-n,-m}};  
		while(!q.empty()){
			auto f = q.front();
			int cnt = 0; 
			q.pop();  
			map <pair <int,int>,int> mp; 
			bool chk = 0; 
			if(f.F == 0 && f.S == 3){
				chk = 1; 
			}
			for(int k = 0; k < 8; k++){
				int i = p[k].F, j = p[k].S; 
				if(f.F + i < r && f.F + i >= 0 && f.S + j < c && f.S + j >= 0){
					if(arr[f.F + i][f.S + j] == '.'){
						q.push({f.F + i, f.S + j}); 
						arr[f.F + i][f.S + j] = '#'; 							
					}
					if(mp[{f.F + i, f.S + j}] == 0 && arr[f.F + i][f.S + j] != 'w'){
						cnt++; 
						mp[{f.F + i, f.S + j}] = 1; 
						//if(chk)cout << f.F + i << " " << f.S + j << "this" << endl; 
					}
				}
			}
			if(cnt%2 == 0){
				arr[f.F][f.S] = 'e'; 
			}else{
				arr[f.F][f.S] = 'o'; 
			}
		}
		int ev = 0, od = 0; 
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				if(arr[i][j] == 'e'){
					ev++; 
				}else if(arr[i][j] == 'o'){
					od++; 
				}
			}
		}
		cout <<"Case "<<it<<": " << ev << " " << od << endl;
		it++; 

	}
}

/*2
3  3  2  1
0
4  4  1  2
2
3  3
1  1*/