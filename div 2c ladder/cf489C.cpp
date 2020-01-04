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
	int m, s; 
	cin >> m >> s; 
	int count9 = s/9; 
	string maxans = ""; 
	if(s == 0 && m != 1){
		cout << -1 << " " << -1; 
		return 0; 
	}else if(m*9 < s){
		cout << -1 << " " << -1; 
		return 0;
	}
	for(int i = 0; i < count9; i++){
		maxans += "9"; 
	}
	if(count9 != m){
		maxans += to_string(s%9);  
	} 
	int l = maxans.size(); 
	string minans;  
	if(l < m){
		minans = maxans;
		if(minans[l-1] != '0'){
			minans[l-1] = minans[l-1] - 1;  
		}else{
			minans[l-2] -= 1; 
		}
		for(int i = l; i < m; i++){
			maxans += "0"; 
			minans += "0"; 
		}
		minans[m-1] = '1'; 
		reverse(minans.begin(), minans.end());


	}else{
		reverse(maxans.begin(), maxans.end()); 
		minans = maxans; 
		reverse(maxans.begin(), maxans.end());
	}
	cout << minans << " " << maxans; 
	 

}

/*5 32*/
