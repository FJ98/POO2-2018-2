#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <limits>
#include <queue>
#include <cmath>
#include <algorithm>
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

template <class T>
class Conjunto{
private:
    vector<T>* elementos;
public:
    Conjunto(){
        elementos = new vector<T>;
    };
    void adicionarElemento(T a){
        if(elementos->empty())
            elementos->push_back(a);
        else if(count(elementos->begin(),elementos->end(),a)==0){
            elementos->push_back(a);
        }
    }
    void mostrarElementos(){
        for(auto i:*elementos){
            cout << i << ' ';
        }
    }
    Conjunto* realizarUnion(Conjunto* conjunto){
        Conjunto<T>* resultado = new Conjunto<T>;
        for(auto i:*elementos){
            resultado->adicionarElemento(i);
        }
        for(auto i:*conjunto->elementos){
            if(count(elementos->begin(),elementos->end(),i)==0){
                resultado->adicionarElemento(i);
            }
        }
        return resultado;
    };
    Conjunto* realizarInterseccion(Conjunto* conjunto){
        Conjunto<T>* resultado = new Conjunto<T>;
        for(auto i:*conjunto->elementos){
            if(count(elementos->begin(),elementos->end(),i)!=0){
                resultado->adicionarElemento(i);
            }
        }
        return resultado;
    };
    Conjunto* realizarDiferencia(Conjunto* conjunto){
        Conjunto<T>* resultado = new Conjunto<T>;
        for(auto i:*elementos){
            if(count(conjunto->elementos->begin(),conjunto->elementos->end(),i)==0)
                resultado->adicionarElemento(i);
        }
        return resultado;
    };
    Conjunto* realizarDiferenciaSimetrica(Conjunto* conjunto){
        Conjunto<T>* resultado = new Conjunto<T>;
        for(auto i:*elementos){
            if(count(conjunto->elementos->begin(),conjunto->elementos->end(),i)==0)
                resultado->adicionarElemento(i);
        }
        for(auto i:*conjunto->elementos){
            if(count(elementos->begin(),elementos->end(),i)==0)
                resultado->adicionarElemento(i);
        }
        return resultado;
    };
    Conjunto* realizarComplemento(Conjunto* conjunto){
        Conjunto<T>* resultado = new Conjunto<T>;
        for(auto i:*conjunto->elementos){
            if(count(elementos->begin(),elementos->end(),i)==0)
                resultado->adicionarElemento(i);
        }
        return resultado;

    };
    ~Conjunto(){
        delete elementos;
    };

};

int main() {
    fastcin
    Conjunto<char>* A = new Conjunto<char>;
    Conjunto<char>* B = new Conjunto<char>;
    Conjunto<char>* C = new Conjunto<char>;
    A->adicionarElemento('e');
    A->adicionarElemento('d');
    A->adicionarElemento('y');
    A->adicionarElemento('4');
    A->adicionarElemento('$');
    A->adicionarElemento('i');
    A->adicionarElemento('t');
    A->adicionarElemento('7');
    A->adicionarElemento('i');
    A->adicionarElemento('{');
    A->adicionarElemento('[');
    A->adicionarElemento('-');
    B->adicionarElemento('h');
    B->adicionarElemento('E');
    B->adicionarElemento('d');
    B->adicionarElemento('y');
    B->adicionarElemento('x');
    B->adicionarElemento('u');
    B->adicionarElemento('r');
    B->adicionarElemento('5');
    B->adicionarElemento('#');
    B->adicionarElemento('@');
    B->adicionarElemento('^');
    B->adicionarElemento('n');
    C->adicionarElemento('u');
    C->adicionarElemento('w');
    C->adicionarElemento('o');
    C->adicionarElemento('<');
    C->adicionarElemento('(');
    C->adicionarElemento('^');
    C->adicionarElemento('_');
    C->adicionarElemento('-');
    C->adicionarElemento(')');
    C->adicionarElemento('>');
    C->adicionarElemento('W');
    C->adicionarElemento('O');
    A->mostrarElementos();
    cout << "\n";
    B->mostrarElementos();
    cout << "\n";
    C->mostrarElementos();
    cout << "\n";
    //Asumiendo que el conjunto universo es la union entre los tres conjuntos:
    cout << "El conjunto universal: ";
    A->realizarUnion(B)->realizarUnion(C)->mostrarElementos();
    cout << "\nConjunto AuB: ";
    A->realizarUnion(B)->mostrarElementos();
    cout << "\nConjunto AnB: ";
    A->realizarInterseccion(B)->mostrarElementos();
    cout << "\nConjunto A-B: ";
    A->realizarDiferencia(B)->mostrarElementos();
    cout << "\nConjunto A^C: ";
    A->realizarComplemento(C)->mostrarElementos();
    cout << "\nConjunto A delta B: ";
    A->realizarDiferenciaSimetrica(B)->mostrarElementos();


    return 0;
}