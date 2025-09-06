#include <iostream>
#include <vector>
using namespace std;

/*
 * Problem: Range Sum Queries
 * Given an array of integers and multiple queries asking for the sum of elements
 * in a given range [L, R], efficiently answer all queries using cumulative sum.
 * 
 * Example:
 * Array: [1, 3, 6, 7, 9, 4, 10, 7, 6]
 * Query 1: Sum from index 2 to 6 -> 6 + 7 + 9 + 4 + 10 = 36
 * Query 2: Sum from index 0 to 4 -> 1 + 3 + 6 + 7 + 9 = 26
 */

class CumulativeSum {
private:
    vector<long long> prefixSum;
    
public:
    // Constructor to build cumulative sum array
    CumulativeSum(vector<int>& arr) {
        int n = arr.size();
        prefixSum.resize(n + 1, 0);
        
        // Build prefix sum array
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + arr[i];
        }
    }
    
    // Function to get sum in range [L, R] (0-indexed)
    long long getRangeSum(int L, int R) {
        if (L > R || L < 0) return 0;
        return prefixSum[R + 1] - prefixSum[L];
    }
    
    // Function to get sum from index 0 to R
    long long getPrefixSum(int R) {
        if (R < 0) return 0;
        return prefixSum[R + 1];
    }
};

int main() {
    // Example usage
    vector<int> arr = {1, 3, 6, 7, 9, 4, 10, 7, 6};
    
    cout << "Original Array: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
    
    // Create cumulative sum object
    CumulativeSum cs(arr);
    
    // Test queries
    cout << "\n--- Range Sum Queries ---" << endl;
    cout << "Sum from index 2 to 6: " << cs.getRangeSum(2, 6) << endl;  // Should be 36
    cout << "Sum from index 0 to 4: " << cs.getRangeSum(0, 4) << endl;  // Should be 26
    cout << "Sum from index 1 to 3: " << cs.getRangeSum(1, 3) << endl;  // Should be 16
    cout << "Sum from index 5 to 8: " << cs.getRangeSum(5, 8) << endl;  // Should be 27
    
    cout << "\n--- Prefix Sum Queries ---" << endl;
    cout << "Sum from index 0 to 3: " << cs.getPrefixSum(3) << endl;    // Should be 17
    cout << "Sum from index 0 to 6: " << cs.getPrefixSum(6) << endl;    // Should be 40
    
    // Interactive mode
    cout << "\n--- Interactive Mode ---" << endl;
    cout << "Array size: " << arr.size() << " (indices 0 to " << arr.size()-1 << ")" << endl;
    
    int queries;
    cout << "Enter number of queries: ";
    cin >> queries;
    
    while (queries--) {
        int L, R;
        cout << "Enter range [L R]: ";
        cin >> L >> R;
        
        if (L < 0 || R >= arr.size() || L > R) {
            cout << "Invalid range!" << endl;
        } else {
            cout << "Sum from index " << L << " to " << R << ": " << cs.getRangeSum(L, R) << endl;
        }
    }
    
    return 0;
}

/*
 * Time Complexity:
 * - Preprocessing: O(n)
 * - Each query: O(1)
 * 
 * Space Complexity: O(n) for storing prefix sum array
 * 
 * Key Insight:
 * Instead of calculating sum for each query from scratch (which would be O(n) per query),
 * we preprocess the array to build cumulative sum, then answer each query in O(1) time.
 * 
 * Formula: sum(L, R) = prefixSum[R+1] - prefixSum[L]
 */
