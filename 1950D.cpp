#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const int mod = 1000000007;

// int longestCommonSubstr(string x, string y, int n, int m, int cnt)
// {
//   if(n == 0 || m == 0) return cnt;
//   if(x[n - 1] == y[m - 1])
//   {
//       cnt = longestCommonSubstr(x, y, n - 1, m - 1, cnt + 1); 
//   }
//   int cnt1 = longestCommonSubstr(x, y, n, m - 1, 0); 
//   int cnt2 = longestCommonSubstr(x, y, n - 1, m , 0);
//   cnt = max({cnt, cnt1, cnt2});
//   return cnt;
// }
 
// int unboundKnapsack(vector<int>& wt, vector<int>& val, int w, int n)
// {
//   if(n == 0 || w == 0) return 0;
//   if(wt[n - 1] <= w)
//   {
//       return max(val[n - 1] + unboundKnapsack(wt, val, w - wt[n - 1], n),
//       0 + unboundKnapsack(wt, val, w - 0, n - 1));
//   }
//   else return 0 + unboundKnapsack(wt, val, w, n - 1);
// }
ll square(int x) {
    return x * (ll) x;
}
 
// int knapsack(vector<int>& wt, vector<int>& val, int w, int n, vector<vector<int>>&ans)
// {
//   if(n == 0 || w == 0) return 0;
//   if(ans[n][w] != -1) return ans[n][w];
//   if(wt[n - 1] <= w)
//   {
//       return ans[n][w] = max (val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1, ans), 
//       0 + knapsack(wt, val, w - 0, n - 1, ans));
//   }
//   else return ans[n][w] = 0 + knapsack(wt, val, w - 0, n - 1, ans);
// }
 
 
// int knapsackDP(vector<int>& wt, vector<int>& val, int capacity, int n, vector<vector<int>>& ans)
// {
//   //if(n == 0 || capacity == 0) return 0;
//   for(int i = 0; i < ans.size(); i++)
//   {
//   for(int j = 0; j < ans[0].size(); j++)
//   {
//          if(i == 0 || j == 0) ans[i][j] = 0;
//      }
//   }
//   //if(ans[n][capacity] != -1) return ans[n][capacity];
//   for(int i = 1; i < ans.size(); i++)
//   {
//      for (int j = 1; j < ans[0].size(); j++)
//      {
//          if(wt[i - 1] <= j)
//          {
//              //return ans[n][capacity] = max(val[n - 1] + knapsack(wt, val, capacity - wt[n - 1], n - 1, ans)
//              //0 + knapsack(wt, val, capacity - 0, n - 1, ans));
//              ans[i][j] = max(val[i - 1] + ans[i - 1][j - wt[i - 1]], 
//                                      0 + ans[i - 1][j]);
//          }
//          else 
//          {
//              //return ans[n][capacity] = 0 + knapsack(wt, val, capacity - 0, n - 1, ans);
//              ans[i][j] = 0 + ans[i - 1][j];
//          }
         
//      }
//   }
//   for(int i = 0; i < ans.size(); i++)
//   {
//      for(int j = 0; j < ans[0].size(); j++)
//      {
//          cout << ans[i][j] << " ";
//      }
//      cout << endl;
//   }
//   return ans[n][capacity];
// }
 
// void subsetgenerator2(vector<int>& given, int n, vector<int> subset, vector<vector<int>>& ans)
// {
//   if(n == 0)
//   {
//      ans.push_back(subset);
//      return;
//   }
//   subsetgenerator2(given, n - 1, subset, ans);
//   subset.push_back(given[n - 1]);
//   subsetgenerator2(given, n - 1, subset, ans);
// }
 
void subsetgenerator3withbacktrack(vector<int>& given, int n, vector<int>& subset, vector<vector<int>>& ans)
{
   if(n == 0)
   {
     ans.push_back(subset);
     return;
   }
   subsetgenerator3withbacktrack(given, n - 1, subset, ans);
   subset.push_back(given[n - 1]);
   subsetgenerator3withbacktrack(given, n - 1, subset, ans);
   subset.pop_back();
}
 
 
 
void subsetWithKElements(vector<int>&given, int k, vector<vector<int>>& ans)
{
   int n = given.size();
   for(int i = 1; i < pow(2, n); i++)
   {
     int z = i;
     vector<int> binary;
     while(z > 0)
     {
         int rem = z % 2;
         binary.push_back(rem);
         z = z / 2;
     }
     int p = n - binary.size();
   
     for(int j = 1; j <= p; j++) binary.push_back(0);
     reverse(binary.begin(), binary.end());
   
     //for(auto elem : binary) cout << elem << " "; cout << endl;
     int cnt = 0;
   
     for(int j = 0; j < binary.size(); j++)
     {
         if(binary[j] == 1) cnt++;
     }
     //cout << cnt << endl;
     if(cnt == k)
     {
         vector<int> subset;
         for(int j = 0; j < binary.size(); j++)
         {
             if(binary[j] == 1) subset.push_back(given[j]);
         }
         ans.push_back(subset);
     }
     //binary.clear();
   }
}
void power(int a, int n)
{
   int res = 1;
   while(n > 0)
   {
     if(n % 2 == 1)
     {
         res *= a;
         n--;
     }
     else 
     {
         a = a * a;
         n = n / 2;
     }
   }
   cout << res << endl;
}
 
void power(ll a, ll n, ll p)
{
   ll res = 1;
   while(n > 0)
   {
     if(n % 2 == 1)
     {
         res = (res * a) % p;
         n--;
     }
     else
     {
         a = (a * a) % p;
         n /= 2;
     }
   }
   cout << res << endl;
}
 
 
bool isPrime(ll n)
{
   if(n <= 1) return false;
   for(ll i = 2; i * i <= n; i++)
   {
     if(n % i == 0) return false;
   }
   return true;
}
 
void primefact(ll n)
{
   for(ll i = 2; i * i <= n; i++)
   {
     if(n % i == 0)
     {
         int cnt = 0;
         while(n % i == 0)
         {
            n = n / i;
            cnt++;
         }
         cout << i << " ^ " << cnt << endl;
     }
   }
   if(n > 1) cout << n << " ^ " << 1 << endl;
}
 
 
void eulertotientfunction(int n)
{
   int res = n;
   for(int i = 2; i * i <= n; i++)
   {
     if(n % i == 0)
     {
         res /= i;
         res *= (i - 1);
     }
     while(n%i == 0) n /= i;
   }
   if(n > 1)
   {
     res /= n;
     res *= n - 1;
   }
   cout << res << endl;
}
 
 
void sieveprimefact()
{
   vector<int> a(51, -1);
   a[0] = a[1] = 0;
   for(int i = 2; i < 51; i++)
   {
     if(a[i] == -1)
     {
         for(int j = i; j < 51; j += i)
         {
             if(a[j] == -1) a[j] = i;
         }
     }
   }
   
   
   int n = 40;
   while(n > 1)
   {
     cout << a[n] << " ";
     n /= a[n];
   }
}
// int bubblesort(vector<int>& a, vector<int>& b, vector<pair<int, int>>& ans)
// {
//   int moves = 0;
//   int n = a.size();
//   for(int i = 0; i < n; i++)
//   {
//      for(int j = 0; j < n - 1; j++)
//      {
//          if(a[j] > a[j + 1] || b[j] > b[j + 1]) 
//          {
//              swap(a[j], a[j + 1]);
//              swap(b[j], b[j + 1]);
//              ans.push_back({j, j + 1});
//              moves++;
//          }
//      }
//   }
//   return moves;
// }
 
// int merge2(vector<pair<int, int>>&c,int left, int mid, int right, vector<pair<int, int>>& temp, vector<pair<int,int>>& ans)
// {
//   //cout <<"merge2 "<< left<<" " << right << endl;
//   int i, j, k, moves = 0;
//   i = left, j = mid, k = left;
//   while(i <= mid - 1 && j <= right)
//   {
//      if(c[i].first > c[j].first || (c[i].first == c[j].first && c[i].second > c[j].second ))
//      {
//          for(int p = j; p >= k + 1; p--)
//          {
//              ans.push_back({p, p - 1});
//              moves++;
//          }
//          temp[k++] = c[j++];
//      }
//      else 
//      {
//          temp[k++] = c[i++];
//      }
//   }
//   while(i <= mid - 1) temp[k++] = c[i++];
//   while(j <= right) temp[k++] = c[j++];
   
//   for(int i = left; i <= right; i++) c[i] = temp[i];
//   return moves;
// }
 
// int mergesort2(vector<pair<int, int>>&c,int left, int right, vector<pair<int, int>>& temp, vector<pair<int,int>>& ans)
// {
//   //cout <<"sort2 "<< left <<" " << right  << endl;
//   int moves = 0, mid;
//   if(right - left > 0)
//   {
//      mid = (left + right) / 2;
//      moves += mergesort2(c, left, mid, temp, ans);
//      moves += mergesort2(c, mid + 1, right,temp, ans);
//      moves += merge2(c, left, mid + 1, right, temp, ans);
//   }
//   return moves;
//   }
   
//   int mergesort2util(vector<pair<int, int>>&c, vector<pair<int,int>>& ans)
//   {
//   //cout <<"util" << endl;
//   int n = c.size();
//   vector<pair<int, int>> temp(n);
//   return mergesort2(c, 0, n - 1, temp, ans);
// }

bool dfs(int i,int j,int n, int m,vector<vector<char>>&v,vector<vector<int>>&vis,int p1,int p2){
    if (i>=n||i<0||j>=m||j<0)
    return false;
   
    if (p1==-1||p2==-2);
    else if (v[i][j]!=v[p1][p2])
    return false;
     if (vis[i][j]==1)
    return true;
    vis[i][j]=1;
    bool x=false;
    if (i<n-1 && (p1!=i+1 || p2!=j))
    x=x||dfs(i+1,j,n,m,v,vis,i,j);
    if (i>0 && (p1!=i-1 || p2!=j))
    x=x||dfs(i-1,j,n,m,v,vis,i,j);
    if (j<m-1 && (p1!=i || p2!=j+1))
    x=x||dfs(i,j+1,n,m,v,vis,i,j);
    if (j>0 && (p1!=i || p2!=j-1))
    x=x||dfs(i,j-1,n,m,v,vis,i,j);
    return x;
}
int isSubstring(string s1, string s2)
{
    // using find method to check if s1 is
    // a substring of s2
    if (s2.find(s1) != string::npos)
        return s2.find(s1);
    return -1;
}
bool isValidSubstring(const string& s, int start, const string& target) {
    if (start + target.length() > s.length()) {
        return false; // Substring goes beyond the end of the string
    }

    for (int i = 0; i < target.length(); ++i) {
        if (s[start + i] != target[i] && s[start + i] != '?') {
            return false;
        }
    }
    return true;
}


bool canReplace(const string& s, const string& target) {
    for (int i = 0; i <= s.length() - target.length(); ++i) {
        if (isValidSubstring(s, i, target)) {
            return true;
        }
    }
    return false;
}

bool isLexicographicallySmaller(const string& str1, const string& str2) {
    int minLength = min(str1.length(), str2.length());
    
    for (int i = 0; i < minLength; ++i) {
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;
    }
    
    // If the common prefix is the same, the shorter string is lexicographically smaller
    return (str1.length() < str2.length());
}

int maxSubarraySum(const vector<int>& nums) {
    int maxSum = nums[0]; // Initialize the maximum sum with the first element
    int currentSum = nums[0]; // Initialize the current sum with the first element

    for (int i = 1; i < nums.size(); ++i) {
        // Update the current sum by adding the current element or starting a new subarray
        currentSum = max(nums[i], currentSum + nums[i]);
        // Update the maximum sum found so far
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

bool comp(pair<int,int> a, pair<int,int> b){
    return a.second<b.second;
}
bool isBinaryDecimal(int num) {
    while (num > 0) {
        int digit = num % 10;
        if (digit != 0 && digit != 1) {
            return false;
        }
        num /= 10;
    }
    return true;
}

// bool canRepresentAsProduct(int n) {
//     // Define the binary decimals
    

//     return dp[n];
// }

signed main() {
    int t;
    cin >> t;
    vector<int> binary_decimals = {10, 11, 111, 100, 101, 110, 1001, 1010, 1100, 1011, 1101, 1110, 1000,1111,10000,
10001,
10010,
10011,
10100,
10101,
10110,
10111,
11000,
11001,
11010,
11011,
11100,
11101,
11110,
11111,
    };
    
    // Initialize DP array
    vector<bool> dp(1e5 + 1, false);
    dp[0] = false;
    dp[1] = true;

    // Iterate from 2 to n
    for (int i = 2; i <= 1e5; ++i) {
        // Check if i can be represented as a product of binary decimals
        for (int bd : binary_decimals) {
            if (i % bd == 0 && dp[i / bd]) {
                dp[i] = true;
                break;
            }
        }
    }
    while (t--) {
        int n;
        cin >> n;
        if (dp[n]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}