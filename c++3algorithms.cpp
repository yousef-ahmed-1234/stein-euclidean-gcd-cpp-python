#include <iostream>
using namespace std;


int euclidean(int a, int b) {
    if (b == 0) {
        return a;
    }
    return euclidean(b, a % b);
}


int stein(int a, int b, int c = 1) {
    if (a == 0) return b * c;
    if (b == 0) return a * c;

    
    if (a % 2 == 0 && b % 2 == 0) {
        return stein(a / 2, b / 2, c * 2);
    }
  
    else if (a % 2 == 0) {
        return stein(a / 2, b, c);
    }
    
    else if (b % 2 == 0) {
        return stein(a, b / 2, c);
    }
   
    else if (a > b) {
        return stein(a - b, b, c);
    } else {
        return stein(a, b - a, c);
    }
}
int euler(int n) {
    int result = n;

    
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) { 
            
            while (n % p == 0) {
                n /= p;
            }
          
            result -= result / p;
        }
    }
    
   
    if (n > 1) {
        result -= result / n;
    }

    return result;
}





int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    int n;
   cout << "enter 1 number";
   cin>> n;

    cout << "Euclidean GCD is: " << euclidean(a, b) <<endl ;
    cout << "Stein GCD is: " << stein(a, b)<<endl ;
    cout << "euler is :" << euler(n) << endl;

    return 0;
}

