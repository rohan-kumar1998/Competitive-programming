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
	int n;   
	while(cin >> n){
		if(n == 0){
			return 0; 
		}  
		vector <vector <int> > v(n+1); 
		int a,b; 
		while(cin >> a >> b){
			if(a == 0 && b == 0){
				break; 
			}else{
				v[a].pb(b); 
				v[b].pb(a); 
			}
		}
		int color[n+1]; 
		fill(color,color + n+1, IINF); 
		queue <int> q; 
		bool vis[n]; 
		fill(vis,vis+n+1, 0); 
		bool bipartite = 1; 
		for(int i = 0; i < n+1; i++){
			//int tot = 0, tmp = 0; 
			if(vis[i] == 0){
				color[i] = 1; 
				vis[i] = 1; 
				q.push(i); 
				//tmp++; 
				while(!q.empty() && bipartite){
					auto f = q.front(); 
					q.pop(); 
					//tot++; 
					int l = v[f].size(); 
					for(int i = 0; i < l; i++){
						if(color[v[f][i]] == IINF){
							color[v[f][i]] = 1 - color[f]; 
							q.push(v[f][i]); 
							vis[v[f][i]] = 1; 
							//tmp += 1 - color[f]; 
						}else if(color[v[f][i]] == color[f]){
							bipartite = 0; 
							break; 
						}
					}
				}
			}    
		}
		if(bipartite){
			cout << "YES" << endl;  
		}else{
			cout << "NO" << endl;
		}
	}
}
