class ProductOfNumbers {
public:

    unordered_map<int,int>mp;
    int i;
    int index;
    int mul;
    ProductOfNumbers() {
        index=-1;
        mul=1;
        i=0;
    }
    
    void add(int num) {
        if(num==0){
            index=i;
            mul=1;
            mp[i]=0;
        }else{
            mp[i]=num*mul;
            mul*=num;
        }
        i++;
    }
    
    int getProduct(int k) {
        
        int ind=i-1-k;

        if(ind==index)
        return mp[i-1];
        else if(ind<index)
        return 0;

        return mp[i-1]/mp[ind];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */