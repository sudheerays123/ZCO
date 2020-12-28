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
	fo(i, 0, n - 1) cin in a[i];

	// MAXIMUM ALTERNATING DEPTH

	stack<ll> brackets;
	stack<ll> depth;
	ll maxdepth = -INF;

	fo(i, 0, n - 1) {
		if (a[i] == 1) {
			if (depth.empty() == true) {
				depth.push(1);
				mmax(maxdepth, depth.top());
			}
			else if (brackets.top() == 3) {
				depth.push(depth.top() + 1);
				mmax(maxdepth, depth.top());
			}
			else {
				depth.push(depth.top());
				mmax(maxdepth, depth.top());
			}
			brackets.push(1);

		}
		else if (a[i] == 3) {
			if (depth.empty() == true) {
				depth.push(1);
				mmax(maxdepth, depth.top());
			}
			else if (brackets.top() == 1) {
				depth.push(depth.top() + 1);
				mmax(maxdepth, depth.top());
			}
			else {
				depth.push(depth.top());
				mmax(maxdepth, depth.top());
			}
			brackets.push(3);
		}
		else if(brackets.empty() == false){
			brackets.pop();
			depth.pop();
		}
	}

	cout out maxdepth spacef;


	// MAXIMUM NUMBER OF BRACKETS WITHIN ( )

	ll curr12 = 0 , pm12 = 0 , ans12 = -INF;
	bool foudn12 = false;

	fo(i, 0, n - 1) {
		if (a[i] == 1) {
			curr12++;
			pm12++;
			foudn12 = true;
		}
		if (a[i] == 3 || a[i] == 4) if (foudn12 == true) curr12++;
		if (a[i] == 2) {
			curr12++;
			pm12--;
			if (pm12 == 0) {
				mmax(ans12, curr12);
				curr12 = 0;
				foudn12 = false;
			}
		}
	}

	cout out ans12 spacef;

	// MAXIMUM NUMBER OF BRACKETS WITHIN [ ]

	ll curr34 = 0 , pm34 = 0 , ans34 = -INF;
	bool foudn34 = false;

	fo(i, 0, n - 1) {
		if (a[i] == 3) {
			curr34++;
			pm34++;
			foudn34 = true;
		}
		if (a[i] == 1 || a[i] == 2) if (foudn34 == true) curr34++;
		if (a[i] == 4) {
			curr34++;
			pm34--;
			if (pm34 == 0) {
				mmax(ans34, curr34);
				curr34 = 0;
				foudn34 = false;
			}
		}
	}

	cout out ans34;

	return 0;
}
