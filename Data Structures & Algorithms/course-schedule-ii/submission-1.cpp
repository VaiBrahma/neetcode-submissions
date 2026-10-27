class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inorder(numCourses, 0);
        vector<int> adj[numCourses];
        for(auto &v1: prerequisites){
            int u = v1[1];
            int v = v1[0];
            adj[u].push_back(v);
            inorder[v]++;
        }

        queue<int> q;
        for(int i = 0; i<numCourses; i++){
            if(inorder[i]==0){
                q.push(i);
            } 
        }


        vector<int> ans;
        while(!q.empty()){
            int u = q.front();
            ans.push_back(u);
            q.pop();

            for(auto &v: adj[u]){
                inorder[v]--;
                if(inorder[v] <= 0) q.push(v);
            }
        }
        if(ans.size() != numCourses) return {};
        return ans;
    }
};
