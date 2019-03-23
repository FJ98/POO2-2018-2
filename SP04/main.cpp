#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Frecuencia{
private:
    int variable;
    int freabs;
    int freabsac;
    double frerel;
    double frerelac;
    int barra;
    vector<int> poblacion;
public:
    Frecuencia(int a,vector<int> b){
        variable = a;
        poblacion = b;
    }
    void setvariable(int _variable){
        variable = _variable;
    }
    void setfreabs(int _freabs){
        freabs = _freabs;
    }
    void setfreabsac(int _freabsac){
        freabsac = _freabsac;
    }
    void setfrerel(int _frerel){
        frerel = _frerel;
    }
    void setfrerelac(int _frerelac){
        frerelac = _frerelac;
    }
    void setbarra(int _barra){
        barra = _barra;
    }
    void setpoblacion(vector<int> _poblacion){
        poblacion = _poblacion;
    }
    int getvariable(){
        return variable;
    }
    int getfreabs(){
        return freabs;
    }
    int getfreabsac(){
        return freabsac;
    }
    double getfrerel(){
        return frerel;
    }
    double getfrerelac(){
        return frerelac;
    }
    int getbarra(){
        return barra;
    }
    void calcfreabs(){
        int contador = 0;
        for(auto i:poblacion){
            if(i==variable)
                contador++;
        }
        freabs = contador;
    }
    void calcfreabsac(){
        int contador = 0;
        for(auto i:poblacion){
            if(i<=variable)
                contador++;
        }
        freabsac = contador;
    }
    void calcfrerel(){
        frerel = double(freabs) / poblacion.size();
    }
    void calcfrerelac(){
        frerelac = double(freabsac) / poblacion.size();
    }
    void calcbarra(){
        barra = frerel*20;
    }
};

class DescriptivaContinua{
private:
    vector<int> poblacion;
    vector<Frecuencia*> frecuencias;
    set<int> variables;
public:
    DescriptivaContinua(){};
    vector<int> getpoblacion(){
        return poblacion;
    }
    vector<Frecuencia*> getfrecuencias(){
        return frecuencias;
    }
    void registrarPoblacion(vector<int> _poblacion){
        poblacion = _poblacion;
        sort(poblacion.begin(),poblacion.end());
    }
    void calcular(){
        int size = poblacion.size();
        for( unsigned i = 0; i < size; ++i ) variables.insert( poblacion[i]);
        for(auto i:variables){
            Frecuencia* temp = new Frecuencia(i,poblacion);
            frecuencias.push_back(temp);
        }
    }
    void mostrarTablaFrecuencias(){
        int size = variables.size();
        cout << "XI" << string(5,' ') << "fi" << string(5,' ') << "Fi" << string(5,' ') << "hi"<< string(5,' ') << "Hi";
        for(int i = 0 ; i < size ; i++){
            Frecuencia* temp = frecuencias[i];
            temp->calcfreabs();
            temp->calcfreabsac();
            temp->calcfrerel();
            temp->calcfrerelac();
            cout << endl << temp->getvariable() << string(7-to_string(temp->getvariable()).length(),' ') << temp->getfreabs() << string(7-to_string(temp->getfreabs()).length(),' ')  << temp->getfreabsac() << string(7-to_string(temp->getfreabsac()).length(),' ')  << temp->getfrerel() << string(6,' ') << temp->getfrerelac();
        }
    }
    void mostrarBarrasHorizontales(){
        for(int i = 0 ; i < variables.size() ; i++){
            Frecuencia* temp = frecuencias[i];
            temp->calcbarra();
            cout << temp->getvariable() << string(4-to_string(temp->getvariable()).length(),' ') << string(temp->getbarra(),'*') << endl;
        }
    }

};

int main() {
    vector<int> datos= {1,2,8,5,8,3,8,5,6,10,5,7,9,4,10,2,7,6,5,10};
    DescriptivaContinua SP4;
    SP4.registrarPoblacion(datos);
    SP4.calcular();
    SP4.mostrarTablaFrecuencias();
    cout << endl;
    SP4.mostrarBarrasHorizontales();
    return 0;
}