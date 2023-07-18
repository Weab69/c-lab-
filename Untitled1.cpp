#include <algorithm> 
#include <vector>
 #include <iostream>
using namespace std;
void multiply_matrix(vector< vector<int> > &matrix, int low, 
                     int mid, int high) ;

void divide_matrix(vector< vector<int> > &matrix, 
                   int low, int high) { 
    if (low < high) { 
        int mid = low + (high - low) / 2;
        // Divide the matrix recursively 
        divide_matrix(matrix, low, mid); 
        divide_matrix(matrix, mid + 1, high); 
  
        // Conquer the sub matrices 
        multiply_matrix(matrix, low, mid, high); 
    } 
} 

// Function to calculate the product of two sub-matrices 
void multiply_matrix(vector< vector<int> > &matrix, int low, 
                     int mid, int high) { 
    for (int i = low; i <= high; i++) { 
        int leftStart = 0; 
        int leftEnd = mid - low; 
        int rightStart = mid + 1; 
        int rightEnd = high; 
  
        // Iteratively multiply the sub-matrices and  
        // store the result 
        for (int j = leftStart; j <= leftEnd; j++) { 
            for (int k = rightStart; k <= rightEnd; k++) { 
                matrix[i][k] = matrix[i][j] * matrix[j][k]; 
            } 
        } 
    } 
} 

int main() 
{ 
    vector< vector<int> > matrix {
        {1, 4, 3}, 
        {2, 5, 8}, 
        {3, 5, 4}, 
        {4, 6, 9}, 
    }; 
    int rowSize = matrix.size(); 
  
    // Function calling 
    divide_matrix(matrix, 0, rowSize - 1); 

 return 0;
} 
