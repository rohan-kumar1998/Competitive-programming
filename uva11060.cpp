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
	int t = 1; 
	while(cin >> n){
		map <string,int> mp;
		map <int,string> mp2; 
		string s; 
		for(int i = 0; i < n; i++){
			cin >> s; 
			mp[s] = i+1; 
			mp2[i+1] = s; 
		}
		int m; 
		cin >> m; 
		vector <vector <int>> v(n+1);
		string a,b; 
		int dp[n+1]; 
		fill(dp,dp+n+1, 0); 
		for(int i = 0; i < m; i++){
			cin >> a >> b; 
			v[mp[a]].pb(mp[b]); 
			dp[mp[b]]++; 
		} 
		queue <int> q; 
		for(int i = 1; i <= n; i++){
			if(dp[i] == 0){
				q.push(i); 
			}
		}
		bool vis[n+1]; 
		fill(vis,vis+n+1, 0); 
		cout << "Case #"<<t<<": Dilbert should drink beverages in this order: "; 
		t++; 
		vector <string> ans; 
		while(!q.empty()){
			auto f = q.front(); 
			q.pop(); 
			vis[f] = 1; 
			int l = v[f].size();
			ans.pb(mp2[f]);  
			//cout << mp2[f] << " "; 
			for(int i = 0; i <l ; i++){
				if(vis[v[f][i]] == 0){
					dp[v[f][i]]--; 
					if(dp[v[f][i]] == 0){
						q.push(v[f][i]); 
					}
				}
			} 

		}
		int l = ans.size(); 
		for(int i = 0; i < l-1; i++){
			cout << ans[i] << ' '; 
		}
		cout << ans[n-1] << "." << endl; 
		cout << endl; 

	}
}

//wasn't accepted because uva is a stupid judge and doesn't really care if there are multiple answers to a question. 
