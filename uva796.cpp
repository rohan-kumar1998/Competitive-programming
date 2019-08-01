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
int timer = 0; 
set <pair <int,int> >  bridges; 
class graph{
public:
	vector <vector <int> > adj; 
	vector <int> tin,low; 
	vector <bool> visited; 

	graph(int n){
		adj.resize(n); 
		tin.assign(n,-1);
		low.assign(n,-1); 
		visited.assign(n,0);  
		bridges.clear() ;  

	}
	void addedge(int a, int b){
		adj[a].pb(b);  
	}

	void dfs(int v, int p = -1){
		visited[v] = 1; 
		tin[v] = low[v] = timer; 
		timer++; 
		for(int to : adj[v]){
			if(to == p){
				continue; 
			}
			else if(visited[to]){
				low[v] = min(tin[to], low[v]); 
			}else{
				dfs(to, v); 
				low[v] = min(low[v], low[to]); 
				if(low[to] > tin[v] && p != -1){
					bridges.insert({min(v,to), max(v,to)}); 
				}
			}
		}
		if(p == -1){
			if(!adj[v].empty()){
				for(int x : adj[v]){
					bridges.insert({min(v,x), max(v,x)});
				}
			} 	
		}
	}

	void prgraph(){
		for(int i = 0; i < adj.size(); i++){
			cout << i << " -> ";  
			for(int to : adj[i]){
				cout << to << " "; 
			}		
			cout << endl; 
		}
	}
};


int main(){
	int n; 
	while(cin >> n){
		graph g(n); 
		int a; 
		for(int i = 0; i < n; i++){
			cin >> a;
			string s; 
			cin >> s;
			s = s[1];  
			int x = stoi(s); 
			int b; 
			for(int j = 0; j < x; j++){
				cin >> b; 
				g.addedge(a,b); 
			}

		}
		//g.prgraph();
		for(int i = 0; i < n; i++){
			if(!g.visited[i]){
				g.dfs(i); 
			}
		} 
		cout << bridges.size() <<" critical links"<< endl; 
		for(pair <int,int> x : bridges){
			cout << x.F << " - " << x.S << endl; 
		}
	}
}

/*8
0 (1) 1
1 (3) 2 0 3
2 (2) 1 3
3 (3) 1 2 4
4 (1) 3
7 (1) 6
6 (1) 7
5 (0)

0

*/
