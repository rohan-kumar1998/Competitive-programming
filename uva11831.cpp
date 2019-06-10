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
	int n,m,s; 
	while(cin >> n >> m >> s){
		if(n == 0 && m == 0 && s == 0){
			return 0; 
		}
		char arr[n+2][m+2]; 
		for(int i = 0; i < n+2; i++){
			fill(arr[i], arr[i] + m + 2, '#');
		}
		char curr;
		int r,c;  
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin >> arr[i][j]; 
				if(arr[i][j] == 'N' || arr[i][j] == 'S' || arr[i][j] == 'L' ||arr[i][j] == 'O'){//NSEW
					curr = arr[i][j]; 
					r = i, c = j; 
				}
			}
		}
		string str; 
		cin >> str; //D->right, E -> left
		int ans = 0; 
		for(int i = 0; i < s; i++){
			if(curr == 'N'){
				if(str[i] == 'F'){
					if(arr[r-1][c] != '#'){
						arr[r][c] = '.'; 
						r--; 
					}
				}else if(str[i] == 'D'){
					curr = 'L'; 
				}else if(str[i] == 'E'){
					curr = 'O'; 
				}
			}else if(curr == 'S'){
				if(str[i] == 'F'){
					if(arr[r+1][c] != '#'){
						arr[r][c] = '.'; 
						r++; 
					}
				}else if(str[i] == 'D'){
					curr = 'O'; 
				}else if(str[i] == 'E'){
					curr = 'L'; 
				}
			}else if(curr == 'L'){
				if(str[i] == 'F'){
					if(arr[r][c+1] != '#'){
						arr[r][c] = '.'; 
						c++; 
					}
				}else if(str[i] == 'D'){
					curr = 'S'; 
				}else if(str[i] == 'E'){
					curr = 'N'; 
				}
			}else if(curr == 'O'){
				if(str[i] == 'F'){
					if(arr[r][c-1] != '#'){
						arr[r][c] = '.'; 
						c--; 
					}
				}else if(str[i] == 'D'){
					curr = 'N'; 
				}else if(str[i] == 'E'){
					curr = 'S'; 
				}
			}
			if(arr[r][c] == '*'){
				ans++; 
				arr[r][c] = '.'; 
			}
		}
		cout << ans << endl; 
		/*
		for(int i = 0; i < n+2; i++){
			for(int j = 0; j < m+2; j++){
				cout << arr[i][j]<<" "; 
			}cout << endl; 
		}*/

	}
}
/*3 3 2
****N****
DE
4 4 5
...#*#O.*.*.*.#.
FFEFF
10 10 20
....*............*.......*......*.#........#N.*..*...*..............................................
FDFFFFFFEEFFFFFFEFDF
0 0 0*/