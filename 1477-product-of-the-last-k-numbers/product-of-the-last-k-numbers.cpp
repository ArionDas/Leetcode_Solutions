class ProductOfNumbers {
public:
    deque<int> dq;
    vector<int> nums;
    long long prod = 1;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num == 0) {
            nums.clear();
            prod = 1;
        }
        else {
            prod *= num;
            nums.push_back(prod);
        }
        //dq.push_back(num);
    }
    
    int getProduct(int k) {
        if(nums.size() < k) return 0;
        if(nums.size() == k) return nums.back();
        int n = nums.size();
        return nums[n-1] / nums[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */