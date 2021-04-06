/*Bankers Algorithm
The banker’s algorithm is a resource allocation and deadlock avoidance algorithm that tests for safety by simulating the allocation for predetermined maximum possible amounts of all resources, then makes an “s-state” check to test for possible activities, before deciding whether allocation should be allowed to continue.
Banker’s algorithm is named so because it is used in banking system to check whether loan can be sanctioned to a person or not. Suppose there are X number of account holders in a bank and the total sum of their money is Y. If a person applies for a loan then the bank first subtracts the loan amount from the total money that bank has and if the remaining amount is greater than Y then only the loan is sanctioned. It is done because if all the account holders come to withdraw their money then the bank can easily do it.

In other words, the bank would never allocate its money in such a way that it can no longer satisfy the needs of all its customers. The bank would try to be in safe state always.

*/
#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 

// P0, P1, P2, P3, P4 are the Process names here 
{ 
    int n, m, i, j, k; 
    n = 5; // Number of processes 
    m = 3; // Number of resources 
    int alloc[5][3] = { { 0, 1, 0 }, // P0 // Allocation Matrix 
                        { 2, 0, 0 }, // P1 
                        { 3, 0, 2 }, // P2 
                        { 2, 1, 1 }, // P3 
                        { 0, 0, 2 } }; // P4 
  
    int max[5][3] = { { 7, 5, 3 }, // P0 // MAX Matrix 
                    { 3, 2, 2 }, // P1 
                    { 9, 0, 2 }, // P2 
                    { 2, 2, 2 }, // P3 
                    { 4, 3, 3 } }; // P4 
  
    int avail[3] = { 3, 3, 2 }; // Available Resources 
  
    int f[n], ans[n], ind = 0; 
    for (k = 0; k < n; k++) { 
        f[k] = 0; 
    } 
    int need[n][m]; 
    for (i = 0; i < n; i++) { 
        for (j = 0; j < m; j++) 
            need[i][j] = max[i][j] - alloc[i][j]; 
    } 
    int y = 0; 
    for (k = 0; k < 5; k++) { 
        for (i = 0; i < n; i++) { 
            if (f[i] == 0) { 
  
                int flag = 0; 
                for (j = 0; j < m; j++) { 
                    if (need[i][j] > avail[j]){ 
                        flag = 1; 
                        break; 
                    } 
                } 
  
                if (flag == 0) { 
                    ans[ind++] = i; 
                    for (y = 0; y < m; y++) 
                        avail[y] += alloc[i][y]; 
                    f[i] = 1; 
                } 
            } 
        } 
    } 
  
    cout << "Following is the SAFE Sequence" << endl; 
    for (i = 0; i < n - 1; i++) 
        cout << " P" << ans[i] << " ->"; 
    cout << " P" << ans[n - 1] <<endl; 
  

	return 0;

}