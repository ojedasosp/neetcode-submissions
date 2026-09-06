class Graph {
private:
    unordered_map<int, unordered_set<int>> graph;

    bool hasPathHelper(int src, int dst, unordered_set<int>& visited){
        if(visited.count(src)) return false;
        visited.insert(src);

        auto it = graph.find(src);
        if(it == graph.end()) return false;

        for (int val : graph[src]) {
            if(val == dst) return true;
            if(hasPathHelper(val, dst, visited)) return true;
        }
        return false;  
    }

public:
    Graph() {}

    void addEdge(int src, int dst) {
        graph[src].insert(dst); 
    }

    bool removeEdge(int src, int dst) {
        if( graph[src].count(dst) && graph.count(src)){
            graph[src].erase(dst);
            return true;
        }
        return false;
    }

    bool hasPath(int src, int dst) {
        unordered_set<int> visited;
        return hasPathHelper(src, dst, visited);
    }
};
