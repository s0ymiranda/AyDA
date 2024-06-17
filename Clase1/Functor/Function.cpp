#include <bits/stdc++.h>
using namespace std;
  
int increment(int x) 
{  
    return (x+1); 
}
  
int main()
{
    int n = 5;
    int arr[n] = {1, 2, 3, 4, 5};

    transform(arr, arr+n, arr, increment);
  
    std::cout << "Output: " << std::endl;
    for (int i=0; i<n; i++)
        cout << arr[i] <<" " ;
    
    std::cout << std::endl;
    return 0;
}