#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void merge(vector<int>& arr, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;

        // Create temporary vectors
        vector<int> left(n1), right(n2);

        // Copy data to temp vectors
        for (int i = 0; i < n1; i++) left[i] = arr[l + i];
        for (int j = 0; j < n2; j++) right[j] = arr[m + 1 + j];

        // Merge the temp vectors back into arr[l..r]
        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                arr[k] = left[i];
                i++;
            } else {
                arr[k] = right[j];
                j++;
            }
            k++;
        }

        // Copy remaining elements of left[], if any
        while (i < n1) {
            arr[k] = left[i];
            i++;
            k++;
        }

        // Copy remaining elements of right[], if any
        while (j < n2) {
            arr[k] = right[j];
            j++;
            k++;
        }
    }

    void mergeSort(vector<int>& arr, int l, int r) {
        if (l >= r) return;

        int m = l + (r - l) / 2; // Find the midpoint

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
};

int main(){
    vector arr = {2, 9, 0, 1, 3, 6, 5, 7};
    int size = arr.size();

    Solution obj;

    obj.mergeSort(arr, 0, size - 1);

    for(int &ref : arr)
        cout << ref << endl;

    return 0;
}