#include <iostream>
#include <vector>
using namespace std;

double binarySearchLastLessThanOrEqual(vector<double>& arr, double target, int left, int right){
    double result = -1;
    while(left <= right){
        int mid = left + (right - left)/2;

        double midVal = arr[mid];

        if(midVal <= target){
            result = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return result;
}

double binarySearchFirstGreaterThanOrEqual(vector<double>& arr, double target, int left, int right){
    double result = -1;
    while(left <= right){
        int mid = left + (right - left)/2;

        double midVal = arr[mid];

        if(midVal >= target){
            result = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return result;
}


int main(){
    vector<double> hola = {1,1,1,2,2,3,3};

    //Definir los targets
    double a = 0;
    double b = 1.1;

    //Inicializar variables
    double menor, mayor;

    if (a < b){
        menor = binarySearchFirstGreaterThanOrEqual(hola,a,0,hola.size()-1);
        mayor = binarySearchLastLessThanOrEqual(hola, b, 0, hola.size()-1);
    }
    else{
        menor = binarySearchFirstGreaterThanOrEqual(hola,b,0,hola.size()-1);
        mayor = binarySearchLastLessThanOrEqual(hola, a, 0, hola.size()-1);    
    }

    cout << menor << endl;
    cout << mayor << endl;

    if(menor > mayor){
        swap(menor,mayor);
    }
    
    //Imprimir rango de números
    for(menor; menor <= mayor; menor++){
        cout << hola[menor] << endl;
    }
    
    return 0;
}