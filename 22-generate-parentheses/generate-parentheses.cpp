class Solution {
public:

    void generate_parenthesis(int open, int closed, int n, string par, vector<string>& ans) {
        cout << open << " " << closed << " " << par << endl;
        if(open == n && closed == n) {
            ans.push_back(par);
            return;
        }
        // else {
        //     return;
        // }

        if(open < n) {
            par += '(';
            generate_parenthesis(open+1, closed, n, par, ans);
            par.pop_back();
            //open -= 1;
        }
        if(closed < open) {
            par += ')';
            generate_parenthesis(open, closed+1, n, par, ans);
            par.pop_back();
            //closed -= 1;
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string par = "";
        int open = 0, closed = 0;

        generate_parenthesis(open, closed, n, par, ans);

        return ans;
    }
};