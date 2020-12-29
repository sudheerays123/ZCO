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

ll findAns(vi a , vi b , ll k , ll n) {

	ll mi = INF;

	while (k--) {
		ll x = a[n - 1];
		ll y = b[0];

		a[n - 1] = y;
		b[0] = x;

		sort(a.begin(), a.begin() + n);
		sort(b.begin(), b.begin() + n);

		mmin(mi, a[n - 1] + b[n - 1]);
	}

	return mi;

}

int main() {

	ll n,k;
	cin in n in k;

	vi a(n + 5);
	fo(i, 0, n - 1) cin in a[i];

	vi b(n + 5);
	fo(i, 0, n - 1) cin in b[i];

	sort(a.begin(), a.begin() + n);
	sort(b.begin(), b.begin() + n);

	if(k == 0) cout out a[n-1]+b[n-1];
	else cout out min(findAns(a,b,k,n),findAns(b,a,k,n));

	return 0;
}
