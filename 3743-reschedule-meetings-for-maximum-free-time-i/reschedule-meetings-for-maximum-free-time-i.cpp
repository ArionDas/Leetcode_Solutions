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



#include<bits/stdc++.h>
#define lli long long int
#define ll long long
#define V vector<ll>
#define VV vector<vector<ll>> 
#define M map<ll,ll>
#define UM unordered_map<ll,ll>
#define SET set<ll>
#define US unordered_set<ll>
#define MS multiset<ll>
#define ST stack<ll>
#define Q queue<ll>
#define DQ deque<ll>
#define PQ priority_queue<ll>


#define MP make_pair
#define PB push_back
#define F first
#define S second
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
using namespace std;



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


// ------------------------------------------ XXX--------------------------------------------

// ---------------------------- DYNAMIC PROGRAMMING -------------------------------------------

// Number of unique paths from top left corner to bottom right corner
ll Grid_unique_paths(ll n, ll m) {
	vector<ll> prev(m,1);
	for(ll i=1; i<n; i++) {
		vector<ll> curr(m,0);
		curr[0] = 1;
		for(ll j=1; j<m; j++) {
            ll up = 0, left = 0;
            if(i>0)	up = prev[j];
            if(j>0)	left = curr[j-1];
            curr[j] = up + left;
        }
        prev = curr;
    }
    return prev[m-1];
}


// Longest Common Subsequence
ll l_c_subsequence(string s1, string s2) {
    ll n = s1.size();
    ll m = s2.size();
    V prev(m + 1, 0), cur(m + 1, 0);
    for (ll ind1 = 1; ind1 <= n; ind1++) {
        for (ll ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                cur[ind2] = 1 + prev[ind2 - 1];
            else
                cur[ind2] = max(prev[ind2], cur[ind2 - 1]);
        }
        prev = cur;
    }
    return prev[m];
}


// Longest Common Substring
ll l_c_substring(string &s1, string &s2){
    ll n = s1.size(); ll m = s2.size();
    V prev(m+1, 0); V cur(m+1, 0);
    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1]){
                ll val = 1 + prev[j-1];
                cur[j] = val;
                ans = max(ans, val);
            }
            else cur[j] = 0;
        }
        prev = cur;
    }
    return ans;
}


// Longest Increasing Subsequence
ll getAns(vector<ll> &arr, ll n, ll ind, ll prev_ind, vector<vector<ll>> &dp) {
	if(ind==n) {
		return 0;
    }
    
    if(dp[ind][prev_ind] != -1) {
    	return dp[ind][prev_ind];
    }
    
    ll not_take = 0 + getAns(arr, n, ind+1, prev_ind, dp);
    ll take = 0;
    if(prev_ind == -1 || arr[ind] > arr[prev_ind])
    	take = getAns(arr, n, ind+1, ind, dp);
    
    return dp[ind][prev_ind+1] = max(take, not_take);
} 

ll longestIncreasingSubsequence(vector<ll> &arr, ll n) {
    vector<vector<ll>> dp(n, vector<ll>(n + 1, -1));
    return getAns(arr, n, 0, -1, dp);
}



// ---------------------------- GRAPH ALGORITHMS -------------------------------------------

// DFS
void dfs(int node, vector<int> &vis, stack<int> &st, vector<vector<int>> &adj) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) 
			dfs(it, vis, st, adj);
    }
    st.push(node);
}


// Detect Cycle
bool detect(ll src, vector<vector<ll>> adj, vector<bool> &vis) {
    
    vis[src] = 1; 
    queue<pair<ll,ll>> q; 
    q.push({src, -1}); 
    
    while(!q.empty()) {
        ll node = q.front().first; 
        ll parent = q.front().second; 
        q.pop(); 
          
        for(auto adjacentNode: adj[node]) {
            if(!vis[adjacentNode]) {
                vis[adjacentNode] = 1; 
                q.push({adjacentNode, node}); 
            }
            else if(parent != adjacentNode) {
                return true; 
            }
        }
    }
    return false; 
}

bool Detect_Cycle_in_Undirected_Graph(ll vertices, vector<vector<ll>> adj) {
    
    vector<bool> vis(vertices, 0);
    
    for(ll i = 0; i<vertices; i++) {
        if(!vis[i]) {
            if(detect(i, adj, vis)) return 1; 
        }
    }
    
    return 0; 
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


// Shortest Distance to all nodes from source node
vector<int> shortest_path_from_source_to_all_nodes(vector<vector<int>>& adj, int src) {
    int n = adj.size();
	vector<int> dist(n, INT_MAX);
	dist[src] = 0;
	queue<int> q; q.push(src);

	while(!q.empty()) {
		int node = q.front(); q.pop();
		
		for(auto it : adj[node]) {
			if(dist[node] + 1 < dist[it]) {
				dist[it] = dist[node] + 1;
				q.push(it);
            }
        }
    }
    vector<int> ans(n, -1);
    for(int i=0; i<n; i++) {
    	if(dist[i] != INT_MAX)
    		ans[i] = dist[i];
    }
    return ans;
}


// Minimum Spanning Tree Edge Weights Sum - Prim's Algorithm
ll Minimum_Spanning_Tree_Sum(ll vertices, vector<vector<vector<ll>>> &adj) {
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
	vector<ll> vis(vertices, 0);
	ll sum = 0;
	
	pq.push({0,0});
	while(!pq.empty()) {
		pair<ll,ll> p = pq.top();
		pq.pop();
		ll node = p.second;
		ll wt = p.first;

		if(vis[node]) continue;

		vis[node] = 1;
		sum += wt;

		for(auto it : adj[node]) {
			ll adjNode = it[0];
			ll edW = it[1];
			if(!vis[adjNode])
			pq.push({edW, adjNode});
        }
    }
    return sum;
}

// Bellman Ford's Algorithm to detect negative cycle in a GRAPH
vector<ll> bellmanFord(ll vertices, vector<vector<ll>>& edges, ll src) {
    vector<ll> dist(vertices, 1e9);
    dist[src] = 0;
        
    for(ll i=0; i<vertices; i++) {
        for(auto it : edges) {
            ll u = it[0];
            ll v = it[1];
            ll wt = it[2];
                
            if(dist[u] != 1e9 && dist[u]+wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }
        
    for(auto it : edges) {
        ll u = it[0];
        ll v = it[1];
        ll wt = it[2];
                
        if(dist[u] != 1e9 && dist[u]+wt < dist[v]) {
            return {-1};
        }
    }
        
    return dist;
}


// DisjointSet - Union By Rank & Size

class DisjointSet {
	vector<ll> rank, parent, size;
        public:
        	DisjointSet(ll n) {
        		rank.resize(n+1, 0);
        		parent.resize(n+1);
        		size.resize(n+1);
        		for(ll i=0; i<=n; i++) {
        			parent[i] = i;
        			size[i] = 1;
                }
            }
        
            int findUPar(ll node) {
            	if(node == parent[node])
            		return node;
            	return parent[node] = findUPar(parent[node]);
            }
            
            void unionByRank(ll u, ll v) {
            	ll ulp_u = findUPar(u);
            	ll ulp_v = findUPar(v);
            	if(ulp_u == ulp_v) return;
            	if(rank[ulp_u] < rank[ulp_v]) {
            		parent[ulp_u] = ulp_v;
                }
                else if (rank[ulp_v] < rank[ulp_u]) {
                	parent[ulp_v] = ulp_u;
                }
                else {
                	parent[ulp_v] = ulp_u;
                    rank[ulp_u]++;
                    }
            }
            
            void unionBySize(ll u, ll v) {
            	ll ulp_u = findUPar(u);
            	ll ulp_v = findUPar(v);
            	if(ulp_u == ulp_v) return;
            	if(size[ulp_u] < size[ulp_v]) {
            		parent[ulp_u] = ulp_v;
            		size[ulp_v] += size[ulp_u];
                }
                else {
                	parent[ulp_v] = ulp_u;
                	size[ulp_u] += size[ulp_v];
                }
            }
};

class Solution {
public:
    int maxFreeTime(int evt, int k, vector<int>& st, vector<int>& et) {
        int n = st.size();
        vector<int> fr;
        
        for(int i=0; i<n; i++) {
            int diff;
            
            if(i==0) {
                diff = st[i] - 0;
            }
            else {
                diff = st[i] - et[i-1];
            }
                fr.push_back(diff);
        }

        int diff = evt - et[n-1];
        if(diff > 0)
            fr.push_back(diff);

        int ans = 0;
        int i=0, j=0;
        int m = fr.size();
        int sum = 0; k+= 1;

        while(j<m) {
            sum += fr[j];
            ans = max(sum, ans);
            if(j-i+1 == k) {
                ans = max(ans, sum);
                sum -= fr[i];
                i += 1;
            }
            j += 1;
        }

        return ans;
        
    }
};