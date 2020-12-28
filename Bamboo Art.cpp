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

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll n;
	cin in n;

	vi a(n + 5);
	vector<bool> num(100, false);

	fo(i, 0, n - 1) {
		cin in a[i];
		num[a[i]] = true;
	}

	sort(a.begin(),a.begin()+n);

	ll ans = 1;

	fo(i,0,n-1){
		fo(j,i+1,n-1){
			ll diff = a[j] - a[i];
			ll cnt = 2;
			ll start = a[j];
			while(num[start+diff] == true){
				cnt++;
				start += diff;
			}

			mmax(ans,cnt);
		}
	}

	cout out ans;

	return 0;

}
