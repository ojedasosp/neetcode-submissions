class UnionFind {
public:
    unordered_map<int, int> par_;
    unordered_map<int, int> rank_;

    UnionFind(int n) {
        for(int i = 0; i < n; i++){
            par_[i] = i;
            rank_[i] = 0;
        }
    }

    int find(int x) {
        if(x != par_[x]){
            par_[x] = find(par_[x]);
        }
        return par_[x]; 
    }

    bool isSameComponent(int x, int y) {
        return find(x) == find(y);
    }

    // Union is a reserved keyword in C++, so we use _union instead
    bool _union(int x, int y) {
        int p1 = find(x), p2 = find(y);
        if(p1 == p2){
            return false;
        }
        
        if(rank_[p1] > rank_[p2]){
            par_[p2] = p1;
        }else if(rank_[p1] < rank_[p2]){
            par_[p1] = p2;
        }else {
            par_[p1] = p2;
            rank_[p2] = 1;
        }

        return true;
    }

    int getNumComponents() {
        unordered_set<int> s;
        for(auto& [key, val]: par_){
            s.insert(find(key));
        }
        return s.size();
    }
};
