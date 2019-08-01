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
int n; 

int timer; 
set <int> cut_point; 
vector <bool> visited; 
class graph{ 
public:
	vector <vector <int> > adj; 
	vector <int> tin, low; 
	int timer = 0; 
	graph(int n){
		adj.resize(n+1); 
		cut_point.clear(); 
		visited.assign(n+1,false); 
		tin.assign(n+1,-1); 
		low.assign(n+1,-1); 
	}

	void addedge(int a, int b){
		adj[a].pb(b); 
		adj[b].pb(a); 
	}

	void dfs(int v, int p  = -1){
		visited[v] = 1; 
		tin[v] = low[v] = timer++; 
		int children = 0; 
		for(int to : adj[v]){
			if(to == p) continue; 
			else if(visited[to]){
				low[v] = min(low[v], tin[to]); 
			}else{
				dfs(to, v); 
				low[v] = min(low[v], low[to]); 
				if(low[to] >= tin[v] && p != -1){
					cut_point.insert(v); 
				}
				children++; 
			}
		}
		if(p == -1 && children > 1){
			cut_point.insert(v); 
		}
	}

	void bleh(){
		cout << endl; 
		for(int x : tin){
			cout << x << " "; 
		}
		cout << endl; 
		for(int x : low){
			cout << x << " "; 
		}
		cout << endl; 		
	}
}; 


int main(){
	int n; 
	while(cin >> n){
		if(n == 0){
			//err 
			return 0; 
		}
		graph g(n); 
		int x; 
		while(cin >> x){ 
			if(x == 0){
				//cout << 'T'; 
				break; 
			}
			//cout << x << endl; 
			int y; char c; 
			while(scanf("%d%c", &y, &c)){
				g.addedge(x,y); 
				//cout << x << " " << y << endl; 
				if(c == '\n'){
					break; 
				}
				//cout << y << endl; 

			}
		}
		for(int i = 1; i <= n; i++){
			if(!visited[i]){
				//cout << i <<"--" << endl; 
				g.dfs(i); 
			}
		}
		/*for(int point : cut_point){
			cout << point << " "; 
		}*/
		//cout << endl; 
		cout << cut_point.size() << endl; 
	}
}

/*5
5  1  2  3  4
0
6
2  1  3
5  4  6  2
0
0*/
