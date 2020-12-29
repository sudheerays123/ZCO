#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f3f
#define MOD 1e9 + 7
#define ff first
#define ss second
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i spacef
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)

int main() {

	ll n,h;
	cin in n in h;

	vi a(n+5);
	fo(i,0,n-1) cin in a[i];

	ll point = 0;
	bool pick = false;

	while(true){
		ll x;
		cin in x;

		if(x == 0) break;

		if(x == 1){
			if(point != 0) point--;
		}
		if(x == 2){
			if(point != n-1 ) point++;
		}
		if(x == 3){
			if(pick == false && a[point] > 0){
				pick = true;
				a[point]--;
			}
		}
		if(x == 4){
			if(pick == true && a[point] < h){
				a[point]++;
				pick = false;
			}
		}
	}

	fo(i,0,n-1) cout out a[i] spacef;

	return 0;

}
