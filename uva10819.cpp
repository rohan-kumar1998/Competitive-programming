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
int n, m; 
pair <int,int> arr[100+1]; 
int memo[110][11000];
int dp(int i, int sum){
	if(sum > n && n < 1800)
        return -1000;
    if(sum > n + 200)
        return -1000;
    if(i == m) {
        if(sum > n && sum <= 2000)
            return -1000;
        return 0;
    }
	if(memo[i][sum] != -1){
		return memo[i][sum]; 
	}
	memo[i][sum] = max(dp(i+1, sum), arr[i].S + dp(i+1, sum + arr[i].F)); 
	//cout << i << " " << sum << " " << memo[i][sum] << endl;
	return memo[i][sum]; 
}


int main(){
	while(cin >> n >> m){//n -> 100 m -> 1e4 
		for(int i = 0; i <m; i++){
			cin >> arr[i].F >> arr[i].S; 
		}	
		memset(memo, -1, sizeof(memo));  
		cout << dp(0,0) << endl; 
	}
}

/*500  4
100  2
100  3
200  3
400  4*/
