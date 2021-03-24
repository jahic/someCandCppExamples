#include <iostream>
#include <vector>

using namespace std;
#define N 4
  
// Function to get cofactor of A[p][q] in temp[][]. n is current
// dimension of A[][]
void getCofactor(std::vector<int> & A, std::vector<int> & temp, int p, int q, int n)
{
    int i = 0, j = 0;
  
    // Looping for each element of the matrix
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            //  Copying into temporary matrix only those element
            //  which are not in given row and column
            if (row != p && col != q)
            {
                temp[i * N + j++] = A[row * N + col];
  
                // Row is filled, so increase row index and
                // reset col index
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

/* Recursive function for finding determinant of matrix.
   n is current dimension of A[][]. */
int determinant(std::vector<int> & A, int n)
{
    int D = 0; // Initialize result
  
    //  Base case : if matrix contains single element
    if (n == 1)
        return A[0];
  
    std::vector<int> temp; temp.reserve(16); // To store cofactors
  
    int sign = 1;  // To store sign multiplier
  
     // Iterate for each element of first row
    for (int f = 0; f < n; f++)
    {
        // Getting Cofactor of A[0][f]
        getCofactor(A, temp, 0, f, n);
        D += sign * A[0 * N + f] * determinant(temp, n - 1);
  
        // terms are to be added with alternate sign
        sign = -sign;
    }
  
    return D;
}

// Function to get adjoint of A[N][N] in adj[N][N].
void adjoint(std::vector<int> A, std::vector<int> & adj)
{
    if (N == 1)
    {
        adj[0] = 1;
        return;
    }
  
    // temp is used to store cofactors of A[][]
    int sign = 1;
    std::vector<int> temp; temp.reserve(16);
  
   
    
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            // Get cofactor of A[i][j]
            getCofactor(A, temp, i, j, N);
  
            // sign of adj[j][i] positive if sum of row
            // and column indexes is even.
            sign = ((i+j)%2==0)? 1: -1;
  
            // Interchanging rows and columns to get the
            // transpose of the cofactor matrix
            adj[j * N + i] = (sign)*(determinant(temp, N-1));
        }
    }
    
}
  
// Function to calculate and store inverse, returns false if
// matrix is singular
bool inverse(std::vector<int> A, std::vector<float> & inverse)
{
    // Find determinant of A[][]
    int det = determinant(A, N);
    if (det == 0)
    {
        cout << "Singular matrix, can't find its inverse";
        return false;
    }
  
    // Find adjoint
    std::vector<int> adj; adj.reserve(16);
    adjoint(A, adj);
  
    // Find Inverse using formula "inverse(A) = adj(A)/det(A)"
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            inverse[i * N + j] = adj[i * N + j]/float(det);
  
    return true;
}

template<class T>
void display(const std::vector<T> & A)
{
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
            cout << A[i * N + j] << " ";
        cout << endl;
    }
}
  



template<unsigned long long int n>
struct factorial
{
    enum { value = n * factorial<n - 1>::value};
};

template<>
struct factorial<1>
{
    enum { value = 1 };
};

// Driver program
int main(int argc, const char ** argv)
{

    //std::vector<int> A{5, -2, 2, 7,1, 0, 0, 3,-3, 1, 5, 0,3, -1, -9, 4};
  
    //std::vector<int> adj; adj.reserve(16);
    //std::vector<float> inv; inv.reserve(16);  // To store adjoint of A[][]
  
    
    std::cout << factorial<20>::value << std::endl;
    
    //adjoint(A, adj);
    //display(adj);
  /*
    cout << "\nThe Inverse is :\n";
    if (inverse(A, inv))
        display(inv);
  */
    return 0;

}