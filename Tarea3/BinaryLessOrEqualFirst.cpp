#include <iostream>
#include <vector>
using namespace std;

double busquedaBinariaLeastGreater(vector<double>& arr, double target, int left, int right){
    double result = -1;
 
    while (left <= right) {
        int mid = left + (right - left + 1) / 2;
        int midVal = arr[mid];
 
        if (midVal < target) {
 
            // if mid is less than target, all elements
            // in range [left, mid - 1] are <= target
            // then we search in right side of mid
            // so we now search in [mid + 1, right]
            left = mid + 1;
        }
        else if (midVal > target) {
 
            // if mid is greater than target, all elements
            // in range [mid + 1, right] are >= target
            // we note down the last found index, then
            // we search in left side of mid
            // so we now search in [left, mid - 1]
            result = mid;
            right = mid - 1;
        }
        else if (midVal == target) {
 
            // if mid is equal to target, all elements in
            // range [left, mid] are <= target
            // so we now search in [mid + 1, right]
            left = mid + 1;
        }
    }
 
    return result;
}

double busquedaBinariaGreatestLesser(vector<double>& arr, double target, int left, int right){
    double result = -1;
 
    while (left <= right) {
        int mid = left + (right - left + 1) / 2;
        int midVal = arr[mid];
 
        if (midVal < target) {
 
            // if mid is less than target, all elements
            // in range [left, mid - 1] are < target
            // we note down the last found index, then
            // we search in right side of mid
            // so we now search in [mid + 1, right]
            result = mid;
            left = mid + 1;
        }
        else if (midVal > target) {
 
            // if mid is greater than target, all elements
            // in range [mid + 1, right] are > target
            // then we search in left side of mid
            // so we now search in [left, mid - 1]
            right = mid - 1;
        }
        else if (midVal == target) {
 
            // if mid is equal to target, all elements
            // in range [mid + 1, right] are >= target
            // then we search in left side of mid
            // so we now search in [left, mid - 1]
            right = mid - 1;
        }
    }
 
    return result;
}

int main(){
    vector<double> hola = {0,0,1,1,2,2,3,3,4,4};
    cout << busquedaBinariaGreatestLesser(hola, 2, 0, hola.size()-1) << endl;
    cout << busquedaBinariaLeastGreater(hola, 2, 0, hola.size()-1) << endl;
    return 0;
}