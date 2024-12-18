class Solution {
public:

    /*
            A         RRRRRRRRR   II  OOOOOOOO    NN       N          DDDDDDDDD          A          SSSSSSSS                 II   II   II   TTTTTTTTTTT   RRRRRRRRR
           A A        R       R   II  O      O    N N      N          D       D         A A         S                        II   II   II        T        R       R
          A   A       R       R   II  O      O    N  N     N          D       D        A   A        S                        II   II   II        T        R       R
         A     A      R       R   II  O      O    N   N    N          D       D       A     A       S                        II   II   II        T        R       R
        AAAAAAAAA     RRRRRRRRR   II  O      O    N    N   N          D       D      AAAAAAAAA      SSSSSSSS                 II   II   II        T        RRRRRRRRR
       A         A    RR          II  O      O    N     N  N          D       D     A         A            S                 II   II   II        T        RR     
      A           A   R  R        II  O      O    N      N N          D       D    A           A           S                 II   II   II        T        R  R     
     A             A  R    R      II  O      O    N       NN          D       D   A             A          S                 II   II   II        T        R    R
    A               A R       R   II  OOOOOOOO    N        N          DDDDDDDDD  A               A  SSSSSSSS                 II   II   II        T        R       R

*/



//#include<bits/stdc++.h>
#define lli long long int
#define ll long long
#define V vector<ll>
#define VV vector<vector<ll>> 
#define M map<ll,ll>
#define UM unordered_map<ll,ll>
#define S set<ll>
#define US unordered_set<ll>
#define ST stack<ll>
#define Q queue<ll>
#define DQ deque<ll>
#define PQ priority_queue<ll>


#define MP make_pair
#define PB push_back
#define F first
//#define S second
#define LB lower_bound
#define UB upper_bound
#define SZ(x) ((int)x.size())
#define LEN(x) ((int)x.length())
#define ALL(x) begin(x), end(x)
#define RSZ resize
#define ASS assign
#define REV(x) reverse(x.begin(), x.end());
#define trav(a, x) for (auto& a : x)


#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define FOR(i, n) for (ll i = 0; i < n; i++) 
#define FOR1(i, n) for (ll i = 1; i <= n; i++) 
#define SORT(x) sort(x.begin(), x.end())
#define RSORT(x) sort(x.rbegin(), x.rend())
#define SUM(x) accumulate(x.begin(), x.end(), 0LL)
//using namespace std;


// #pragma GCC optimize("O3,unroll-loops")

// #include<bits/stdc++.h>
// // #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

// using namespace std;
// using namespace chrono;
// using namespace __gnu_pbds;

// #define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
// #define MOD 1000000007
// #define MOD1 998244353
// #define INF 1e18
// #define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
// #define PI 3.141592653589793238462
// #define set_bits __builtin_popcountll
// #define sz(x) ((int)(x).size())
// #define all(x) (x).begin(), (x).end()

// #define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
// //#else
// #define debug(x);
// //#endif

// //typedef long long ll;
// typedef unsigned long long ull;
// typedef long double lld;
// typedef __int128 ell;
// //typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

// void _print(ll t) {cerr << t;}
// void _print(int t) {cerr << t;}
// void _print(string t) {cerr << t;}
// void _print(char t) {cerr << t;}
// void _print(lld t) {cerr << t;}
// void _print(double t) {cerr << t;}
// void _print(ull t) {cerr << t;}

// template <class T, class V> void _print(pair <T, V> p);
// template <class T> void _print(vector <T> v);
// template <class T> void _print(set <T> v);
// template <class T, class V> void _print(map <T, V> v);
// template <class T> void _print(multiset <T> v);
// template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
// template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
// ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
ll power(ll a, ll b) {
    ll result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result *= a;
        }
        a *= a;
        b /= 2;
    }
    return result;
}

// take vector input
V take_array(V a, ll n) {for(ll i=0; i<n; i++) cin >> a[i]; return a;}
void print_array(V a) {for(ll num:a) cout << num << " "; cout << endl;}

vector<vector<ll>> matrix_prefix_sum(vector<vector<ll>>& grid) {
    ll n = grid.size();
    ll m = grid[0].size();
    vector<vector<ll>> psum(n+1, vector<ll>(m+1,0));
        
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++) {
            psum[i][j] = grid[i - 1][j - 1] + psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
        }
    }

    return psum;
}

// ------------------------------ BIT MANIPULATION TRICKS -------------------------------------

// printing the binary representation
void print_binary(ll num){
    for(ll i=10;i>=0;i--) cout<<((num>>i)&1);
        cout<<endl;
}

// checking if the ith bit is set or not.
bool check_ith_bit_set(ll num, ll i) {
    return (num & (1 << i)) != 0;
}

// checking if power of two
bool check_power_of_two(ll x)
{
    return (x && !(x & (x - 1)));
}

// clear right most set bit
ll clear_right_most_bit(ll n) {
    return n & (n-1);
}

// lowercase to uppercase
char lower_to_upper(char c) {
    return c|' ';
}

// uppercase to lowercase
char upper_to_lower(char c) {
    return c|'_';
}

// checking if power of 4
bool check_power_Of_four(ll n)
{
    // return true if n is a power of 2, and
    // the remainder is 1 when divided by 3
    return !(n & (n - 1))&& (n % 3 == 1);
}

// count number of set bits
ll countSetBits(ll n)
{
    ll count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

// clear all trailing zeros
ll clear_all_trailing_zeros(ll n) {
     return n&(n+1);
}

// set the last bit which is not set
ll set_last_cleared_bit(ll n) {
     return n|(n+1);
}

// just keeps the last set bit
ll keep_the_last_set_bit(ll n) {
     return n & (-n);
}

// ------------------------------------------ XXX--------------------------------------------


// ---------------------------- BINARY SEARCH METHODS -------------------------------------------

ll squareRoot(ll a)
{
	ll ans = 0;
	ll low = 0;
	ll high = a;

	while(low<=high) {
		ll mid = low + (high-low)/2;

		if(mid * mid < a) {
			ans = mid;
			low = mid+1;
		}
		else if(mid * mid > a) {
			high = mid-1;
		}
		else {
			return mid;
		}
	}

	return ans;
}

// ------------------------------------------ XXX--------------------------------------------



// ---------------------------- TREE METHODS -------------------------------------------

// Find Maximum Path Sum
// ll find_sum(Node* root, ll sum) {
// 	if(root==NULL)
// 		return 0;
// 	ll l_sum = max(0,find_sum(root->left, sum));
// 	ll r_sum = max(0,find_sum*root->right, sum));
// 	sum = max(sum, l_sum + r_sum + root->val);

// 	return max(l_sum,r_sum) + root->val;
// }

// ll findMaxSum(Node* root) {
// 	ll sum = 0;
// 	find_sum(root, sum);
// 	return sum;
// }

// ------------------------------------------ XXX--------------------------------------------

// ---------------------------- NUMERICAL METHODS -------------------------------------------

// LAGRANGE'S FOUR SQUARE METHOD

//--------------->according to the LAGRNGE'S FOUR SQUARE THEOREM which state that
        // every natural number can be represented as sum of 4 integer square so.
        // n=x^2+y^2+z^2+w^2;
        // so our ANS will be always less than or equal to 4
        //if the number n is a perfect square itself,
        // then our answer will be 1. 
        //Otherwise, we check whether we can represent it as the sum of 2 perfect squares. 
        //So we need to check whether n = x^2 + y^2.
        // We iterate overall all x from 1 to sqrt(n), 
        //and check whether n-x^2 is a perfect square or not. If we get a perfect square for some x,
        // then the answer is 2.
        //Now, for numbers which neither have answer as 1 nor 2,
        // we need to decide whether they can be represented
        // as sum of 3 perfect squares or 4 perfect squares
        // For this we need to know lagrange's four square theorem 
        //, which states that every natural number can be represented 
        //as the sum of 3 perfect squares i.e. n = x^2 + y^2 + x^2 if
        // and only if n is not of the form 4^a (8b+7) i.e. 
        //if n = 4^a (8b+7), it cannot be represented as the sum of 3 perfect squares.
// ------------------------------------------ XXX--------------------------------------------

// GRAPH ALGORITHMS

// DFS
void dfs(int node, vector<int> &vis, stack<int> &st, vector<vector<int>> &adj) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) 
			dfs(it, vis, st, adj);
    }
    st.push(node);
}


// TOPOLOGICAL SORTING - using DFS
vector<int> topoSort(int vertices, vector<vector<int>> &adj) {
    vector<int> vis(vertices, 0);
    stack<int> st;

    for (int i = 0; i < vertices; i++) {
        if (!vis[i]) {
            dfs(i, vis, st, adj);
        }
    }

    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        int n = prices.size();

        vector<int> ans(n,0);

        ans[n-1] = prices[n-1];
        st.push(prices[n-1]);

        for(int i=n-2; i>=0; i--) {
            int ele = prices[i];

            while(!st.empty() && ele < st.top())
                st.pop();
            
            if(st.empty())
                ans[i] = ele;
            else
                ans[i] = ele - st.top();

            st.push(ele);
        }
        return ans;
    }
};