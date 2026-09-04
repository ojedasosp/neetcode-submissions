class MinHeap {
private:
    vector<int> heap;
public:
    MinHeap() {
        heap.push_back(0);
    }

    void push(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;

        while(i > 1 && heap[i] < heap[i/2]){
            int temp = heap[i];
            heap[i] = heap[i/2];
            heap[i/2] = temp;
            i = i/2;
        }
    }

    int pop() {
        if (heap.size() == 1) {
            return -1;
        }
        if (heap.size() == 2) {
            int res = heap[heap.size() - 1];
            heap.pop_back();
            return res;
        }

        int res = heap[1];
        heap[1] = heap[heap.size() - 1];
        heap.pop_back();
        int i = 1;
        while(2 * i < heap.size()){
            if(2 * i + 1 < heap.size() && 
            heap[2 * i + 1] < heap[2 * i] && 
            heap[i] > heap[2 * i + 1]){
                int tmp = heap[i];
                heap[i] = heap[2*i+1];
                heap[2*i+1] = tmp;
                i = 2 * i + 1;
            }else if (heap[i] > heap[2 * i]){
                int tmp = heap[i];
                heap[i] = heap[2 * i];
                heap[2 * i] = tmp;

                i = 2 * i; 
            }else{
                break;
            }
        } 

        return res;
    }

    int top() {
        if(heap.size() == 1){
            return -1;
        }
        return heap[1];
    }

    void heapify(const vector<int>& arr) {
        heap.clear();
        heap.push_back(0);
        
        for(int val : arr) {
            heap.push_back(val);
        }
    
        for(int i = (heap.size() - 1) / 2; i >= 1; i--) {
            int index = i;
            while(2 * index < heap.size()) {
                if(2 * index + 1 < heap.size() && 
                heap[2 * index + 1] < heap[2 * index] && 
                heap[index] > heap[2 * index + 1]){
                    int temp = heap[index];
                    heap[index] = heap[2*index+1];
                    heap[2*index+1] = temp;
                    index = 2 * index + 1;
                } else if (heap[index] > heap[2 * index]){
                    int temp = heap[index];
                    heap[index] = heap[2 * index];
                    heap[2 * index] = temp;
                    index = 2 * index; 
                } else {
                    break;
                }
            }
        }
    }
};
