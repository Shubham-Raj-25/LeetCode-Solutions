class ProductOfNumbers {
public:
    vector<int> products;
    int lastZero = INT_MIN;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(products.size() == 0 || num == 0 || products.back() == 0){
            products.push_back(num);
            if(num == 0){
                lastZero = products.size()-1;
            }
        }
        else{
            products.push_back(num*products.back());
        }
    }
    
    int getProduct(int k) {
        int toGoBack = products.size()-k-1;
        if(toGoBack < lastZero){
            return 0;
        }
        if(toGoBack == lastZero || toGoBack < 0){
            return products.back();
        }
        return products.back() / products[toGoBack];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

/*
0 1 2 3
a b c d
a ab abc abcd

getProduct(2) : c * d
getProduct(3) : b * c * d

1 <= k <= 4 * 10^4
0 <= num <= 100


3 4 0 5 6
0 1 2 3 4

0 indexes: 2

a b 0 d 0 f g h 0 i j k l

a ab 0 d 0 f fg fgh 0 i ij ijk ijkl
                        -
                    if it's after last 0 or before last 0
                             |                |
                        simply cal          return 0

lastZero=1

3 0 2 10 40

*/  