#include <bits/stdc++.h>
using namespace std;
#define int          long long
#define rep(i,j,n)   for(int i=j;i<n;i++)
#define scn(a)       scanf("%lld",&a)
#define nl           cout << endl
#define scns(a,b)    scanf("%lld %lld",&a,&b)
#define pri(a)       printf("%lld",a)
#define prinl(a)     printf("%lld\n",a)
#define tc           int t; scn(t); while(t--)
#define vec          vector<int>
#define pb           push_back
#define pairs        pair<int,int>
#define fi           first
#define se           second
#define all(v)       v.begin(),v.end()
#define srt(v)       sort(v.rbegin(),v.rend())
#define mem(a,b)     memset(a,b,sizeof(a))
#define dbug(a)      cout<<"dbug : "<<a<<endl
#define debug(a,b)   cout<<"debug "<<a<<" "<<b<<endl
#define read(v,w)    vec v(w,0); rep(i,0,w) {cin>>v[i];}
#define write(a,w)   rep(i,0,w) {cout<<a[i]<<" ";}
#define All          rep(i,0,n) 
#define IOS          ios_base::sync_with_stdio(false); cin.tie(NULL);

const int N = 1000+5;
int n,x;

int price[N];
int pages[N];


void solve()
{
    cin >> n >> x;
    rep(i,1,n+1) cin >> price[i];
    rep(i,1,n+1) cin >> pages[i];

    int prev[x+1];
    int cur[x+1];


    rep(i,0,x+1) prev[i] = 0;

    rep(item, 1, n+1) {
        cur[0] = 0;
        rep(j, 1, x+1) {
            if(price[item] <= j) {
                cur[j] = max(prev[j], prev[j-price[item]] + pages[item]);

            }

            else {
                cur[j] = prev[j];
            }
        }

        rep(i,0,x+1) prev[i] = cur[i];
    }

    int ans = cur[x];
    prinl(ans);
}

//Check for test cases
signed main(){


int test=1;
//cin>>test;

while(test--)
{
    solve();
}

return 0;
}
