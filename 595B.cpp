#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float double
const int mod = 1000000007 ;

bool cmp(const pair<int,int>&a, const pair<int,int>&b) {
    if(a.second!=b.second)
    return a.second < b.second;
    else
    return a.first<b.first;
}

bool isPrime(int n) {
    if (n <= 1)
        return false;

    for (int i = 2; i <= n / i; i++)
        if (n % i == 0)
            return false;

    return true;
}

bool dfs(int i, int j, int n, int m, vector<vector<char>>&v, vector<vector<int>>&vis, int p1, int p2) {
    if (i >= n || i < 0 || j >= m || j < 0)
        return false;

    if (p1 == -1 || p2 == -2);
    else if (v[i][j] != v[p1][p2])
        return false;
    if (vis[i][j] == 1)
        return true;

    vis[i][j] = 1;
    bool x = false;

    if (i < n - 1 && (p1 != i + 1 || p2 != j))
        x = x || dfs(i + 1, j, n, m, v, vis, i, j);
    if (i > 0 && (p1 != i - 1 || p2 != j))
        x = x || dfs(i - 1, j, n, m, v, vis, i, j);
    if (j < m - 1 && (p1 != i || p2 != j + 1))
        x = x || dfs(i, j + 1, n, m, v, vis, i, j);
    if (j > 0 && (p1 != i || p2 != j - 1))
        x = x || dfs(i, j - 1, n, m, v, vis, i, j);

    return x;
}

bool check(int kk, int nn) {
    int sum = 0;
    int cur = nn;
    while (cur > 0) {
        int o = min(cur, kk);
        sum += o;
        cur -= o;
        cur -= cur / 10;
    }
    return sum * 2 >= nn;
}

void dfs2(int it,vector<vector<int>>&adjlist,vector<int>&visited,int cnt,int k){
    if (k>=2){
        cnt++;
        return;
    }
    for (auto it2:adjlist[it]){
        if (!visited[it2]){
            visited[it2]=1;
            
        }
    }
    
}

int isSubstring(string s1, string s2)
{
    if (s2.find(s1) != string::npos)
        return s2.find(s1);
    return -1;
}
 
void overlap(vector<pair<int, int> > v)
{
    int ans = 0;
    int count = 0;
    vector<pair<int, char> > data;
 
    for (int i = 0; i < v.size(); i++) {
        data.push_back({ v[i].first, 'x' });
        data.push_back({ v[i].second, 'y' });
    }
 
    sort(data.begin(), data.end());
 
    for (int i = 0; i < data.size(); i++) {
 
        if (data[i].second == 'x')
            count++;
        if (data[i].second == 'y')
            count--;
 
        ans = max(ans, count);
    }
    cout << ans << endl;
}

string findSum(string str1, string str2)
{
    // Before proceeding further, make sure length
    // of str2 is larger.
    if (str1.length() > str2.length())
        swap(str1, str2);
 
    // Take an empty string for storing result
    string str = "";
 
    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
 
    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
 
        // Calculate carry for next step
        carry = sum/10;
    }
 
    // Add remaining digits of larger number
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
 
    // Add remaining carry
    if (carry)
        str.push_back(carry+'0');
 
    // reverse resultant string
    reverse(str.begin(), str.end());
 
    return str;
}

string sum(string s1,string s2)
{
	if(s1.size()<s2.size())
	{
		string temp=s1;
		s1=s2;
		s2=temp;
	}
	for(int i=s1.size()-1,j=s2.size()-1;i>=0;i--,j--)
	{
		s1[i]=char(s1[i]+(j>=0?s2[j]-'0':0));
		if(s1[i]-'0'>=10)
		{
			s1[i]=char((s1[i]-'0')%10+'0');
			if(i) s1[i-1]++;
			else s1='1'+s1;
		}
	}
	return s1;
}

// int po(int a,int n)
// {
// 	int ans=1;
// 	while(n)
// 	{
// 		if(n&1)	ans=ans*a%mod;
// 		a=a*a%mod;
// 		n>>=1;
// 	}
// 	return ans;
// }

bool check(int mid,int a,int b,int c){
    int grp1=0,grp2=0,grp3=0;
    int left=0;
    if (a>mid){
        grp1=mid;
        left=a-mid;
        grp2+=left;
        left=0;
        if (grp2>mid)
        return false;
        else{
            int u=mid-grp2;
            grp2=mid;
            if (b>=u){
                b-=u;
                grp3=b+c;
                if (grp3>mid)
                return false;
                else
                return true;
            }
            else{
                grp2-=u;
                grp2+=b;
                grp3=c;
                if (grp3>mid)
                return false;
                else
                return true;
            }
        }
    }
    else{
        grp1+=a;
        int u=mid-a;
        grp1=mid;
        if (b<u){
            grp1-=u;
            grp1+=b;
            grp2=(c+1)/2;
            grp3=c-grp2;
            if (grp2>mid||grp3>mid)
            return false;
            return true;
        }
        else{
            b-=u;
            if (b>mid){
                grp2=mid;
                left=b-mid;
                grp3=left+c;
                if (grp3>mid)
                return false;
                return true;
            }
            else{
                grp2=b;
                int u=mid-grp2;
                if (c<=mid)
                return true;
                else{
                    grp3=mid;
                    c-=mid;
                    if (c>u)
                    return false;
                    return true;
                }
            }
        }
    }
}

int divi(int n,int l,int r){
    for (int i=1;i*i<=n;i++){
        if (n%i==0){
            if (i>=l && i<=r)
            return i;
            else if ((n/i)>=l && (n/i)<=r)
            return (n/i);
        }
    }
    return -1;
}

// int gg(int i,vector<int>&v,int weight){
//     if (weight==0)
//     return 0;
//     if (i==5){
//         if (weight==0)
//         return 0;
//         else
//         return 1e9;
//     }
//     // if (dp[i][weight]!=-1)
//     // return dp[i][weight];
//     if (v[i]<=weight){
//         int take=1+gg(i,v,weight-v[i]);
//         int ntake=gg(i+1,v,weight);
//         return min(take,ntake);
//     }
//     else{
//         int ntake=gg(i+1,v,weight);
//         return (ntake);
//     }
// }

// int gg1(int i,int n,vector<string>&v,string s){
//     if (i>=n-1)
//     return 0;
//     string a="";
//     a+=s[i];
//     a+=s[i+1];
//     string b=a;
//     reverse(b.begin(),b.end());
//     if (count(v.begin(),v.end(),a)||count(v.begin(),v.end(),b)){
//         string r=s;
//         r.erase(i,1);
//         int x=1+gg(i-1,n-1,v,r);
//         string l=s;
//         l.erase(i+1,1);
//         int y=1+gg(i,n-1,v,l);
//         return min(x,y);
//     }
//     else{
//         return gg(i+1,n,v,s);
//     }
// }
// int d(int a, int b){
// 	return (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);
// }
 
// int square(int x1, int x2, int x3, int x4){
// 	return (d(x1,x2)==d(x2,x3))&&(d(x2,x3)==d(x3,x4))&&(d(x3,x4)==d(x4,x1))&&(d(x4,x1)==d(x1,x2))&&(d(x1,x3)==d(x2,x4));
// }
 
// int rectangle(int x1, int x2, int x3, int x4){
// 	return (d(x1,x2)==d(x3,x4))&&(d(x4,x1)==d(x3,x2))&&(d(x1,x3)==d(x2,x4));
// }

void primeFactors(int n,set<int>&s) 
{ 
    int cnt=0;
    while (n % 2 == 0) 
    {
        n = n/2;
        cnt++;
    } 
    if (cnt>0)
    s.insert(2);
    for (int i = 3; i <= sqrt(n); i+=2) 
    { 
        int cnt=0;
        while (n % i == 0) 
        { 
            cnt++;
            n = n/i; 
        } 
        if (cnt>0)
        s.insert(i);
    } 
    if (n>2)
    s.insert(n);
} 
 
// int gg(int i,int prev,int n,vector<pair<int,int>>&v,vector<vector<int>>&dp,int target){
//     if (i==n)
//     return 0;
//     if (dp[i][prev+1]!=-1)
//     return dp[i][prev+1];
    
//     if (prev==-1||abs(v[i].second-v[prev].second)+v[i].first<=target){
//         if (prev!=-1)
//         return dp[i][prev+1]=max(1+gg(i+1,i,n,v,dp,target-abs(v[i].second-v[prev].second)-v[i].first),gg(i+1,prev,n,v,dp,target));
//         else
//         return dp[i][prev+1]=max(1+gg(i+1,i,n,v,dp,target-v[i].first),gg(i+1,prev,n,v,dp,target));
//     }
//     else
//     return dp[i][prev+1]=gg(i+1,prev,n,v,dp,target);
// }

void pythagoreanTriplets(int limit,int&cnt) 
{ 
    int a, b, c = 0; 
    int m = 2; 
    while (c < limit) {

        for (int n = 1; n < m; ++n) { 
            a = m * m - n * n; 
            b = 2 * m * n; 
            c = m * m + n * n; 
            if (c > limit) 
            break; 
            if (c==a*a-b)
            cnt++;
        } 
        m++; 
    } 
}

int modFact(int n, int p)
{
    if (n >= p)
        return 0;
 
    int result = 1;
    for (int i = 1; i <= n; i++)
        result = (result * i) % p;
 
    return result;
}

const int N=1e5+10;
int a[N];
int b[N];
const int M=1e9+7;
int p(int a,int b)
{
	int ans=a;
	for(int i=1;i<=b;i++)
		ans*=10;
	return ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,k;
	int ans=1;
	cin >>n>>k;
	int cnt=n/k;
	for(int i=1;i<=cnt;i++)
	cin >>a[i];
	for(int i=1;i<=cnt;i++)
	cin >>b[i];
	for(int i=1;i<=cnt;i++)
	{
		int l,r;
		int now;
		if(b[i]!=0) 
		{
			l=p(b[i],k-1)-1;
			r=p(b[i]+1,k-1)-1;
			int r1=p(1,k)-1;
			now=(r1/a[i]+1)-(r/a[i]-l/a[i]);
		}
		else 
		{
			r=p(1,k-1)-1;
			int r1=p(1,k)-1;
			now=(r1/a[i]+1)-(r/a[i]+1);	
		}
		ans=ans*now%M;
	}
	cout<<ans<<endl;
}
