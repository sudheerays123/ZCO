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

bool isPalindrome(vi v , ll start , ll end ){

	while(start < end){
		if(v[start] != v[end]) return false;
		start++;
		end--;
	}

	return true;
}

int main() {

	//freopen("input.in","r",stdin);
	//freopen("input.out","w",stdout);

	ll n;
	cin in n;

	vi a(n+5);
	fo(i,1,n) cin in a[i];

	vi dp(n+5);

	// OPTIMAL SUBPROBLEM : 

	// DP[i] = Minimum number of palindromic subsequences 0...i can be breaked

	// BASE CASE :

	dp[1] = 1;

	// RECURRENCE RELATION :

	fo(i,2,n){
		dp[i] = dp[i-1]+1;

		fo(j,1,i-1){
			if(isPalindrome(a,j,i) == true) mmin(dp[i] , dp[j-1]+1);
		}
	}

	// OPTIMAL ANSWER : 

	cout out dp[n];

	return 0;

}
