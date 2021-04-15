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

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const int N = 5005;
int dp[N][N][2];
int n;
vec a(N);



int fun(int st, int end, int turn) {

    if(st == end) {
        if(turn == 0)  { dp[st][end][turn] = a[st]; return a[st]; }
        else { dp[st][end][turn] = 0; return 0; }
    }

    if(dp[st][end][turn] != -1) return dp[st][end][turn];

    if(turn == 0) {
        int ans1 = a[st] + fun(st+1, end, !turn);   //choose st elemt
        int ans2 = a[end] + fun(st, end-1, !turn); //choose last

        int ans = max(ans1, ans2);
        dp[st][end][turn] = ans;
        return ans;
    }

    else {
        int ans1 = fun(st+1, end, !turn);
        int ans2 = fun(st, end-1, !turn);

        int ans = min(ans1 , ans2); //here we return the minimum because 2nd will also play optimally
                                    // and will give minum value to the 1st
        dp[st][end][turn] = ans;
        return ans;
    }

}



void solve()
{
    cin >> n;
    rep(i,1,n+1) cin >> a[i]; // 1 based

    mem(dp, -1);

    int st = 1;
    int end = n;
    int turn = 0;

    int ans = fun(st, end, turn);

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
