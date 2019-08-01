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

int n,m;	 
int timer = 0; 
bool comp(pair <int,int> i, pair <int,int> j){
		if(i.F == j.F){
			return(i.S > j.S); 
		}else{
			return(i.F < j.F); 
		} 
}
class graph{ 
public: 
	vector <vector <int> > adj;
	vector <int> tin,low; 
	vector <bool> visited;  
	vector <int> cnt; 
	vector <pair <int,int> > tcnt; 
	graph(int n){
		timer = 0; 
		adj.resize(n); 
		tin.assign(n,-1); 
		low.assign(n,-1); 
		visited.assign(n,0); 
		timer = 0; 
		cnt.assign(n,1); 
	}

	void addedge(int a, int b){
		adj[a].pb(b); 
		adj[b].pb(a); 
	}

	void dfs(int v, int p = -1){
		visited[v] = 1; 
		tin[v] = low[v] = timer++;
		for(int to : adj[v]){
			if(p == to){
				continue; 
			}else if(visited[to]){
				low[v] = min(low[v], tin[to]); 
			}else{
				dfs(to, v); 
				low[v] =  min(low[v], low[to]); 
				if(low[to] >= tin[v] && p != -1){
					cnt[v]++; 
				}
			}
		}
		if(p == -1){
			int l = adj[v].size(); 
			cnt[v] += min( l - 1 , 0); 
		} 
	}

	

	void bleh(){
		int i = 0; 
		for(int x : cnt){
			 tcnt.pb({x,i}); 
			 i++; 
		}
		sort(tcnt.begin(), tcnt.end(), comp);
		reverse(tcnt.begin(), tcnt.end()); 
		for(int i = 0; i < m; i++){
			cout << tcnt[i].S << " " << tcnt[i].F << endl;
		}
		cout << endl; 
	}

}; 
int main(){
	while(cin >> n >> m){
		if(n == 0 && m == 0){
			return 0; 
		}
		int x,y;
		graph g(n);  
		while(cin >> x >> y){
			if(x == -1 && y == -1){
				break; 
			}
			g.addedge(x,y); 
		}

		for(int i = 0; i < n; i++){
			if(!g.visited[i]){
				g.dfs(i); 
			}
		}
		g.bleh(); 
	} 
}
/*8  4
0  4
1  2
2  3
2  4
3  5
3  6
3  7
6  7
-1  -1
0  0*/
