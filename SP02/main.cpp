#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <queue>
#include <cmath>
#include <algorithm>
#include <thread>
#include <future>
#include <ctime>
#include <random>
#define FOR(i,n,m) for(int i=n;i<m;i++)
#define REP(i,n) FOR(i,0,n)
#define pb(x) push_back(x)
#define MAX MAX_INT
#define fst first
#define snd second
#define sz(x) int(x.size())
#define all(v) v.begin(),v.end()
#define mp(x,y) make_pair(x,y)
#define fastcin std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
using namespace std;
int sumar(int par , vector<int> numeros){
    int resultado = 0;
    for(int i = par ; i < numeros.size() ; i+=2){
        resultado += numeros[i];
    }
    return resultado;
}
int mayort(int par , vector<int> numeros){
    int resultado = 0;
    for(int i = par ; i < numeros.size() ; i+=2){
        if(numeros[i]>resultado)
            resultado = numeros[i];
    }
    return resultado;
}
int menort(int par , vector<int> numeros){
    int resultado = INT_MAX;
    for(int i = par ; i < numeros.size() ; i+=2){
        if(numeros[i] < resultado)
            resultado = numeros[i];
    }
    return resultado;
}

class numbers{
public:
    vector<int> numeros;
    void generarnumeros(int num){
        for(int i = 0 ; i < num ; i++){
            numeros.push_back((rand()%100)+1);
        }

    }
    void mostrarElementos(){
        for(auto i:numeros){
            cout << i << ' ';
        }
    }

    int suma(){
        auto future1 = async(sumar,0,numeros);
        auto future2 = async(sumar,1,numeros);
        int suma = future1.get()+future2.get();
        return suma;
    }
    int mayor(){
        auto future1 = async(mayort , 0 , numeros);
        auto future2 = async(mayort , 1 , numeros);
        int mayor = max(future1.get() , future2.get());
        return mayor;
    }
    int menor(){
        auto future1 = async(menort , 0 , numeros);
        auto future2 = async(menort , 1 , numeros);
        int menor = min(future1.get() , future2.get());
        return menor;
    }



};

int main(){
    srand(time(0));
    numbers a;
    a.generarnumeros(20000);
    cout << "La suma de todos los numeros es: " << a.suma() << "\n";
    cout << "El numero mayor es: " << a.mayor() << "\n";
    cout << "El numero menor es: " << a.menor();
    return 0;
}