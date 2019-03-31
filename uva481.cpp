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
 
/*int bisearch(int l, int r, int x){
	//cout << l << ' ' << r << endl; 
	if(l < r){  
		int mid = (l+r+1)/2; 
		if(arr[mid].F >= x){
			//cout << arr[mid].F << endl; 
			return bisearch(l, mid, x); 
		}else{ 
			return bisearch(mid + 1, r , x); 
		}
	}else{
		return r; 
	} 
		
}*/
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
	vector <int> arr; 
	int x; 
	while(cin >> x){
		arr.pb(x); 
	}
	int n = arr.size();  
    int dp1[n], dp2[n];
    int val[n];
    fill(val,val+n,-1);
    fill(dp1,dp1+n,-1);
    fill(dp2,dp2+n,-1);
    dp1[0] = 0; 
    val[0] = arr[0]; 
    int len = 1; 
    for(int i = 1; i <n; i++){
        if(arr[i] > val[len-1]){
            dp1[len] = i; 
            val[len] = arr[i]; 
            dp2[i] = dp1[len-1]; 
            len++;   
        }else{
            int it = bisearch(val,0,len-1,arr[i]);
            val[it] = arr[i]; 
            dp1[it] = i;   
            if(it > 0)dp2[i] = dp1[it-1]; 
        }
    } 
    cout << len << endl; 
    cout << "-" << endl;
    int it = dp1[len -1]; 
	vector <int> v;
	while(it != -1){
		v.pb(arr[it]);
		it = dp2[it]; 
	} 
	for(int i = len-1; i >= 0; i--){
		cout << v[i] << endl; 
	}
	

}

/*-7
10
9
2
3
8
8
6*/
