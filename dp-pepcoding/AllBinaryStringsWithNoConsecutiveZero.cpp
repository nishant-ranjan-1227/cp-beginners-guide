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

/*  Count of binary string with no consecutive zero.

	For counting we can directly use fibbonacci -> 1 2 3 5 8 13 21 ...
	But for printing we use the recursion method where we pas a empty string. 
	This is kind of input output method tought by aditya verma in recursion.

	input 6 :
	output :    ans 21
				010101
				010110
				010111
				011010
				011011
				011101
				011110
				011111
				101010
				101011
				101101
				101110
				101111
				110101
				110110
				110111
				111010
				111011
				111101
				111110
				111111


*/

vector<string> v;

void fun(string s,int n){
	if(s.length() == n){
		v.push_back(s);
		return;
	}

	if(s.length() == 0) {
		string s1 = s;
		string s2 = s;
		s1.push_back('0');
		s2.push_back('1');
		// v.push_back(s1);
		// v.push_back(s2);
		fun(s1, n);
		fun(s2, n);
 	}

 	else {
 		string s1 = s;
		string s2 = s;
		if(s.back() == '1'){
			s1.push_back('0');
			s2.push_back('1');
			// v.push_back(s1);
			// v.push_back(s2);
			fun(s1, n);
			fun(s2, n);
		}

		else {
			s2.push_back('1');
			//v.push_back(s2);
			fun(s2, n);
		}
 	}
}

int solve()
{
	int n;
	cin>>n;
	string s="";
	fun(s,n);

	int ans = v.size();
	cout<<"ans "<<ans<<endl;
	for(auto u : v){
		cout<<u<<endl;
	}
	
	
	
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
