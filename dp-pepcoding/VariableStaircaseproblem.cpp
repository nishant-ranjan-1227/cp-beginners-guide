#include <bits/stdc++.h>
using namespace std;
#define ll           long long 
#define rep(i,j,n)   for(ll i=j;i<n;i++)
#define scn(a)       scanf("%lld",&a)
#define nl           printf("\n")
#define scns(a,b)    scanf("%lld %lld",&a,&b)
#define print(a)     printf("%lld",a)
#define tc           ll t; scn(t); while(t--)
#define vec          vector<ll>
#define pb           push_back
#define pairs        pair<ll,ll>
#define fi           first
#define se           second
#define all(v)       v.begin(),v.end()
#define srt(v)       sort(v.rbegin(),v.rend())
#define mem(a,b)     memset(a,b,sizeof(a))
#define maxx         5000005
#define inf          LLONG_MAX
#define zer          LLONG_MIN
#define dbug(a)      cout<<"dbug : "<<a<<endl
#define debug(a,b)   cout<<a<<" "<<b<<endl
#define read(v)      vec v(n,0); rep(i,0,n) {cin>>v[i];}
#define write(a,n)   rep(i,0,n) {cout<<a[i]<<" ";}
#define All          rep(i,0,n) 

ll zero =0;



int solve()
{
	ll n;
	cin>>n;
	read(a);

	vec v(n+1,0);

	v[0]=1;
	rep(i,0,n){
		ll steps = a[i];
		rep(j,i+1,min(n+1,i+steps+1)){
			v[j] += v[i];		}
	}

	cout<<v[n];



	return 0;
}



int main()
{

int test;
test = 1;
//cin>>test;

while(test--)
{
	solve();
}

    
return 0;
}
