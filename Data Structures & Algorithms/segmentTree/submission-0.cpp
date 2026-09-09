class SegmentTreeNode {
    public:
        int sum;
        SegmentTreeNode* left;
        SegmentTreeNode* right;
        int L;
        int R;

        SegmentTreeNode(int sum, int L, int R){
            this->sum = sum;
            this->L = L;
            this->R = R;
            left = nullptr;
            right = nullptr; 
        }     

        static SegmentTreeNode* build(vector<int>& nums, int L, int R){
            if(L == R){
                return new SegmentTreeNode(nums[L], L, R);
            }

            SegmentTreeNode* root = new SegmentTreeNode(0, L, R);
            int M = (L + R) / 2;
            root->left = SegmentTreeNode::build(nums, L, M);
            root->right = SegmentTreeNode::build(nums, M + 1, R);
            root->sum = root->left->sum + root->right->sum;

            return root;
        } 
};

class SegmentTree {
private:
    SegmentTreeNode* root;
    vector<int> nums;

    void updateHelper(vector<int>& nums, int L, int R, int index, SegmentTreeNode* node){
        if(L == R){
            node->sum = nums[L];
            return;
        }
        int M = (L + R) / 2;
        if(index <= M){
            updateHelper(nums, L, M, index, node->left);
        } else {
            updateHelper(nums, M + 1, R, index, node->right);
        }
        node->sum = node->left->sum + node->right->sum;
    }

    int queryHelper(int L, int R, SegmentTreeNode* node){
        if(L == node->L && R == node->R) return node->sum;
        int M = (node->L + node->R) / 2;
        if(R <= M) return queryHelper(L, R, node->left);
        if(L >= M + 1) return queryHelper(L, R, node->right);
        return queryHelper(L, M, node->left) + queryHelper(M + 1, R, node->right);
    }

public:
    SegmentTree(vector<int>& nums) {
        root = SegmentTreeNode::build(nums, 0, nums.size() - 1);
        this->nums = nums;
    }

    void update(int index, int val) {
        nums[index] = val;
        updateHelper(nums, 0, nums.size() - 1, index, root);
    }

    int query(int L, int R) {
        return queryHelper(L, R, root);
    }
};
