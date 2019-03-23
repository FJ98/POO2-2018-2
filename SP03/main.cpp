#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <random>
#include <set>
#include <climits>
#include <queue>
#include <cmath>
#include <future>
#include <thread>
#include <algorithm>
using namespace std;
string gender[2] = {"Femenino" , "Masculino"};
string education[5] = {"Sin educacion" , "Primaria" , "Secundaria" , "Superior Tecnica" , "Superior Universitaria"};
string profession[16] = {"Otros", "Educación", "Ingeniería", "Arquitectura", "Odontología","Obstetricia", "Humanidades","Psicología", "Economía", "Medicina Veterinaria", "Medicina Humana", "Biología", "Enfermería", "Derecho", "Administración de Empresas", "Ciencias Contables y Financieras"};
class Encuesta{
public:
	int edad;
	int genero;
	int educacion;
	int profesion;
	int sueldo;
	Encuesta(int _edad , int _genero , int _educacion , int _profesion , int _sueldo){
		edad = _edad;
		genero = _genero;
		educacion = _educacion;
		profesion = _profesion;
		sueldo = _sueldo;
	}

};
void MostrarEncuesta(Encuesta* encuesta){
	cout << "Edad: " <<encuesta->edad;
	cout << "\nGenero: " << gender[encuesta->genero];
	cout << "\nNivel de educacion: " << education[encuesta->educacion];
	cout << "\nProfesion: " << profession[encuesta->profesion];
	cout << "\nSueldo: " << encuesta->sueldo;
	cout << "\n";
}
class Repositorio{
private:
	vector<Encuesta*> encuestas;
public:
	void respuesta(int _edad , int _genero , int _educacion , int _profesion , int _sueldo){
		Encuesta* esta = new Encuesta(_edad , _genero , _educacion , _profesion , _sueldo);
		encuestas.push_back(esta);
	}
	void ProcesarTodos(void (*f)(Encuesta* encuesta)){
		for(auto i:encuestas){
			f(i);
		}

	}
	int ContarSi(function<bool(Encuesta* encuesta)> condicion){
		int counter = 0;
		for(auto i:encuestas){
			if(condicion(i))
				counter++;
		}
		return counter;
	}
};

int main(){
	int queries = 2000;
	srand(time(0));
	Repositorio rep;
	while(--queries){
		rep.respuesta(rand()%76 + 15 , rand()%2 , rand()%5 , rand()%16 , rand()%99801 + 200);
	}
	rep.ProcesarTodos(MostrarEncuesta);
	for(int i = 0 ; i < 2 ; i++){
		cout << "Encuestados " << gender[i] << "s: " << rep.ContarSi([i](Encuesta* temp){return temp->genero==i;}) << endl;
	}
	for(int i = 0 ; i < 5 ; i++){
		cout << "Encuestados de nivel de educacion " << education[i] << ": " << rep.ContarSi([i](Encuesta* temp){return temp->educacion==i;}) << endl;
	}
	for(int i = 0 ; i < 16 ; i++){
		cout << "Encuestados con titulo en " << profession[i] << ": " << rep.ContarSi([i](Encuesta* temp){return temp->profesion==i;}) << endl;
	}
	cout << rep.ContarSi([](Encuesta* temp){return temp->genero==0&&(temp->educacion==1 || temp->educacion==2);}) << " mujeres tienen educacion primaria o secundaria\n";
	cout << rep.ContarSi([](Encuesta* temp){return temp->genero==1&&(temp->educacion==1 || temp->educacion==2);}) << " hombres tienen educacion primaria o secundaria\n";
	cout << rep.ContarSi([](Encuesta* temp){return temp->genero==0&&(temp->educacion==3 || temp->educacion==4);}) << " mujeres tienen educacion superior tecnica o universitaria\n";
	cout << rep.ContarSi([](Encuesta* temp){return temp->genero==1&&(temp->educacion==3 || temp->educacion==4);}) << " hombres tienen educacion superior tecnica o universitaria\n";
	cout << "Hay " << rep.ContarSi([](Encuesta* temp){return temp->genero==0 && temp->educacion==4 && temp->sueldo>3000;}) << " mujeres mayores de 40 años, que tienen una educacion superior universitaria, y ganan un sueldo mayor a 3,000\n";
	cout << "Hay " << rep.ContarSi([](Encuesta* temp){return temp->genero==1 && temp->educacion==4 && temp->sueldo>3000;}) << " hombres mayores de 40 años, que tienen una educacion superior universitaria, y ganan un sueldo mayor a 3,000\n";
	cout << "Hay " << rep.ContarSi([](Encuesta* temp){return temp->profesion!=2;}) <<" profesionales que no son ingenieros";
	return 0;
}