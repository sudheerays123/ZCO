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

	ll n, k;
	cin in n in k;

	vi a(0);
	fo(i, 0, n - 1) {
		ll x;
		cin in x;
		if(x < k ) a.pb(x);
	}

	sort(a.begin(),a.end());

	ll ans = 0;

	fo(i,0,a.size()-1){

		ll Notpossible = k-a[i];

		vi :: iterator 	low;
		low = lower_bound(a.begin()+i+1,a.end(),Notpossible);
		ll x = low - a.begin()-i-1;
		ans += x;

	}

	cout out ans;

	return 0;

}
