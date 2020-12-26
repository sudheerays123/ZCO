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

	//freopen("input.in", "r", stdin);
	//freopen("input.out", "w", stdout);

	ll n,x,y;
	cin in n in x in y;

	vector<vi> a(n+5,vi(2));

	fo(i,0,n-1) cin in a[i][0] in a[i][1];

	vi v(x+5) , w(0);

	fo(i,0,x-1) cin in v[i];
	fo(i,0,y-1) {
		ll x;
		cin in x;
		w.pb(x);
	}

	sort(v.begin(),v.begin()+x);
	sort(w.begin(),w.end());

	ll minans = INF;
	fo(i,0,n-1){

		ll start = a[i][0];
		ll end = a[i][1];

		vi :: iterator lowstart = lower_bound(v.begin(),v.begin()+x,start);
		if(lowstart == v.begin()) continue;
		ll minstart;
		if(v[lowstart-v.begin()] == start) minstart = v[lowstart - v.begin()];
		else minstart = v[lowstart - v.begin()-1];

		vi :: iterator lowend = lower_bound(w.begin(),w.end(),end);
		if(lowend == w.end()) continue;
		ll minend = w[lowend-w.begin()];

		mmin(minans,minend-minstart+1);
	}

	cout out minans;

	return 0;

}
