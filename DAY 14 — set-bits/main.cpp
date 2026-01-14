#include <iostream>

class Solution {
  public:
    int setBits(int n) {
        int counter = 0;
        
        while(n){
            if(n % 2 == 1)
                counter++;
                
            n /= 2;
            
        }
        
        return counter;
    }
};

int main(){
    Solution obj;

    std::cout << obj.setBits(8); 


    return 0;
}