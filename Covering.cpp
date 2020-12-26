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

	ll n;
	cin in n;

	vector<vi> a(n+5,vi(2));

	fo(i,0,n-1) cin in a[i][1] in a[i][0];

	sort(a.begin(),a.begin()+n);

	ll ans = 1;
	ll last = a[0][0];

	fo(i,1,n-1){
		if(a[i][1] > last){
			ans++;
			last = a[i][0];
		}
	}

	cout out ans;

	return 0;

}
