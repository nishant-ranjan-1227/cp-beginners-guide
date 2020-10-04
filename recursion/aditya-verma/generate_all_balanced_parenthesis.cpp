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




/* 
Ques - to print all the permutaion with case change. The only difference is here we can have upper case and also digits.
For the digits we will have ony one option.



*/

set<string> all_parenthesis;
void genearteAllBalancedParanthesis(int open,int close, string out){
	if(open == 0 and close == 0){
		all_parenthesis.insert(out);
		return;
	}

	// When we have equal number of open and close we can only open a new bracket.
	if(open == close){   
		string out1 = out;
		out1.push_back('(');
		genearteAllBalancedParanthesis(open-1,close,out1);
	}

	else if(close > open) {
		string out1 = out;
		string out2 = out;
		out1.push_back('(');
		out2.push_back(')');
		genearteAllBalancedParanthesis(open, close-1, out2);

		if(open != 0) //When we do not have any left we cannot use it.
			genearteAllBalancedParanthesis(open-1, close , out1);
		
	}
}
int solve()
{
	int n; //n is number of pairs of brackets available.
	cin>>n;
	string out = "";
	genearteAllBalancedParanthesis(n,n,out);

	for(auto it : all_parenthesis){
		cout<<it<<endl;
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