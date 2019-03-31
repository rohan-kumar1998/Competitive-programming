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
 
int bisearch(int arr[], int l, int r, int x){
    if(l < r){
        int mid = (l + r)/2; 
        if(arr[mid] >= x){
            return bisearch(arr,l,mid, x); 
        }else{
            return bisearch(arr,mid+1, r, x); 
        }
    }else{
        return r; 
    }
}
int main(){
	int t; 
	cin >> t; 
	while(t--){
		int n; 
		cin >> n; 
		int arr[n]; 
		for(int i = 0; i < n; i++){
			cin >> arr[i]; 
		}
		int lis[n]; 
		fill(lis,lis + n, 1);
		int lds[n];
		fill(lds, lis + n, 1); 
		reverse(arr,arr+n);
		for(int i = 1; i < n; i++){
			for(int j = 0; j < i; j++){
				if(arr[i] > arr[j]){
					lis[i] = max(lis[i],lis[j] + 1); 
				}else if(arr[i] < arr[j]){
					lds[i] = max(lds[i],lds[j] + 1); 
				}
			}
		}
		int ans = 0; 
		for(int i = 0; i < n; i++){
			ans = max(ans, lis[i] + lds[i] - 1); 
		}
		cout << ans << endl; 
	}
}

/*1
3
1
2
3
*/

