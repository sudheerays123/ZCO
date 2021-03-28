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

	ll n;
	cin in n;

	vi a(n+5);
	fo(i,0,n-1) cin in a[i];

	// Optimal Subproblem :

	// dp[i] = Minimum number of minutes Nikhil has to spend
   // to satisfy the condition and he does the activity on ith day

	vi dp(n+5);

	// Base Case :

	dp[0] = a[0];
	dp[1] = a[1];
	dp[2] = a[2];

	// Recurrence Relation :

	fo(i,3,n-1) dp[i] = a[i] + min(dp[i-1],min(dp[i-2],dp[i-3]));

	// Optimal Answer :

	cout out min(dp[n-1],min(dp[n-2],dp[n-3]));

	return 0;

}
