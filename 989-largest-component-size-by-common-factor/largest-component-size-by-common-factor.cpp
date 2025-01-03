class Solution {
public:
class DSU {
    vector<int> parent, rank, size;
public:
    DSU(int n) {
        parent.resize(n+1);
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        
        for(int i=0; i<=n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void UnionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v)
            return;

        if(rank[ulp_u]>rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_u]<rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else {
            parent[ulp_u] = ulp_v;
            rank[ulp_v] += 1;
        }
    }

    void UnionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v)
            return;

        if(size[ulp_u] > size[ulp_v]) {
            parent[ulp_v] = ulp_u;
        }
        else if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += 1;
        }
    }
};
    int largestComponentSize(vector<int>& v) {
        int n = v.size();
        int num = *max_element(v.begin(), v.end()) + 1;
    DSU ds(num);

    for(int val:v) {
        for(int i=2; i*i <= val; i++) {
            if(val % i == 0) {
                ds.UnionByRank(i, val);
                ds.UnionByRank(val, val/i);
            }
        }
    }

    //cout << "hi" << endl;

    int result = 0;
    unordered_map<int, int> um;

    for(int val:v) {
        int p = ds.findUPar(val);
        um[p] += 1;
        result = max(result, um[p]);
    }

    return result;
    }
};