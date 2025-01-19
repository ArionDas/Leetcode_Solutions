class DisjointSet {
public:
    vector<int> parent, rank;
    DisjointSet(int n) {
        rank.resize(30, 0);
        parent.resize(30, 0);
        for(int i=0; i<30; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void UnionByRank(int u, int v) {
        int u_par = findUPar(u);
        int v_par = findUPar(v);

        if(u_par == v_par)
            return;

        if(rank[u_par] > rank[v_par]) {
            parent[v_par] = u_par;
        }
        else if(rank[u_par] > rank[v_par]) {
            parent[u_par] = v_par;
        }
        else {
            parent[v_par] = u_par;
            rank[u_par] += 1;
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& eq) {
        int n = eq.size();
        DisjointSet dsu(n);

        for(int i=0; i<n; i++) {
            string str = eq[i];
            int a = str[0] - 'a';
            int b = str[3] - 'a';

            //cout << a << " " << b << endl;

            if(str[1] == '=') {
                dsu.UnionByRank(a, b);
            }
        }

        for(int i=0; i<n; i++) {
            string str = eq[i];
            int a = str[0] - 'a';
            int b = str[3] - 'a';

            int a_par = dsu.findUPar(a);
            int b_par = dsu.findUPar(b);

            //cout << a << " " << a_par << " " << b << " " << b_par << endl;

            if(str[1] == '!') {
                if(a_par == b_par) {
                    return 0;
                }
            }
            else {
                if(a_par != b_par) {
                    return 0;
                }
            }
        }

        return 1;
    }
};