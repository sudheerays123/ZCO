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

	// nesting depth :

	ll nest = 0 , maxnest = -INF , ansnest , startnest;

	fo(i,0,n-1){
		if(nest == 0) startnest = i+1;

		if(a[i] == 1){
			 nest++;
			 startnest = i+1;
		}
		else nest--;

		if(nest > maxnest){
			maxnest = nest;
			ansnest = startnest;
		}
	}

	cout out maxnest space ansnest spacef;

	// Maximum number of brackets inside matching brackets :

	ll brackets = 0 , maxbrackets = -INF , ansbrackets , nbrackets = 0 , startbrackets;

	fo(i,0,n-1){
		if(brackets == 0) startbrackets = i+1;
		if(a[i] == 1) brackets++;
		else brackets--;
		nbrackets++;

		if(brackets == 0){
			if(nbrackets > maxbrackets){
				maxbrackets = nbrackets;
				ansbrackets = startbrackets;
			}
			nbrackets = 0;
		}

	}

	cout out maxbrackets space ansbrackets;

	return 0;

}
