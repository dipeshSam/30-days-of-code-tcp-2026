#include <iostream>
#include <vector>

int min(int a, int b){
    return (a < b) ? a : b;
}


int findMinPath(std::vector<std::vector<int>> &V, int r, int c){
    int R = V.size();
    int C = V[0].size();

    if (r >= R || c >= C)
        return 100000000; // Infinity
    if (r == R - 1 && c == C - 1)
        return 0;

    return V[r][c] + min(findMinPath(V, r + 1, c), findMinPath(V, r, c + 1));
}

int main(){

    // My Answer: O(2^(R + C))


    return 0;
}