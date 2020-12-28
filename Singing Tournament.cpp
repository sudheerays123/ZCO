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

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    tc
    {
        ll n;
        cin in n;

        vector<vi> low(n + 5, vi(2));
        vector<vi> up(n + 5, vi(2));

        fo(i, 0, n - 1)
        {
            cin in low[i][0] in up[i][0];
            low[i][1] = i;
            up[i][1] = i;
        }

        vi score(n + 5, 0);

        sort(low.begin(), low.begin() + n);
        sort(up.rbegin(), up.rend());

        fo(i, 0, n - 1) score[low[i][1]] += n - i - 1;
        fo(i, 0, n - 1) score[up[i][1]] += n - i - 1;

        fo(i, 0, n - 1) cout out score[i] spacef;
        cout nextline;
    }

    return 0;
}
