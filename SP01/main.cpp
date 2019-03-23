#include<iostream>
#include <string>
#include<random>
using namespace std;
class Task{
protected:
	string name;
	int runtime;
public:
	virtual bool execute()=0;
	Task(string);
};

Task::Task(string _name){
	name=_name;
}

class SingleTask: public Task{
public:
	bool execute();
	SingleTask(string);
};
SingleTask::SingleTask(string _name):Task(_name){
	name = _name;
}
bool SingleTask::execute(){
	runtime = rand() % 60;
	if(runtime%2==0){
		cout << "Nombre de la tarea " << name << "\n";
		cout << "\tTipo : Simple\n";
		cout << "\tTiempo de ejecucion : " << runtime << "\n";
		cout << "\tResultado de ejecucion : exitosa\n";
		return true;
	}
	else{
		cout << "Nombre de la tarea " << name << "\n";
		cout << "\tTipo : Simple\n";
		cout << "\tTiempo de ejecucion : " << runtime << "\n";
		cout << "\tResultado de ejecucion : fallida\n";
		return false;
	}
}
class FaultToleranceTask:public Task{
private:
	int maxAttempts;
public:
	bool execute();
	FaultToleranceTask(string,int);
};
FaultToleranceTask::FaultToleranceTask(string _name, int _maxAttempts):Task(_name){
	name = _name;
	maxAttempts = _maxAttempts;
}
bool FaultToleranceTask::execute(){
	cout<<"Nombre de la tarea tolerante a fallos "<<name<<"\n";
	cout << "\tTipo : Tolerante a fallos\n";
	cout << "\tMaximo de intentos : "<<maxAttempts<<endl;
	for(int i = 1 ; i <= maxAttempts ; i++){
		runtime = rand() % 60 + 60;
		cout << "\tIntento No " << i<<"\n";
		cout << "\tTiempo de ejecucion :" << runtime;
		if(runtime%2==1){
			cout << "\n\tResultado de ejecucion : exitosa\n";
			return true;
		}
		else{
			cout << "\n\tResultado de ejecucion : fallida\n";
		}

	}
	return false;
}

class Node{
friend class Queue;
private:
	Node* next;
	Task* task;
public:
	Node(Task* , Node*);
};

Node::Node(Task* task , Node* next){
	this -> task = task;
	this -> next = next;
}
class Queue{
private:
	Node* first = nullptr;
	Node* last = nullptr;
public:
	Queue();
	void enqueue(Task*);
	Task* dequeue();
	bool isEmpty();
	~Queue();
};
Queue::Queue(){
	first=nullptr;
	last=nullptr;
}
Queue::~Queue(){
	first=nullptr;
	last=nullptr;
}
void Queue::enqueue(Task* _task){
	if(last == nullptr){
		Node* p = new Node(_task , nullptr);
		first = p;
		last = p;
	}
	else{
		Node* p = new Node(_task , nullptr);
		last -> next = p;
		last = p;
	}
}
Task* Queue::dequeue(){
	Task* output;
	Node* borrar;
	if(first != nullptr){
		borrar = first;
		output = first -> task;
		first = first -> next;
		delete borrar;
	}
	else{
		return nullptr;
	}
	return output;
}

int main(){
	srand(time(0));
	Queue* hello = new Queue();
	Task* ft1 = new FaultToleranceTask("ols" , 10);
	Task* ft2 = new FaultToleranceTask("oli" , 8);
	Task* ft3 = new FaultToleranceTask("uwu" , 6);
	Task* ft4 = new FaultToleranceTask("dis" , 15);
	Task* ft5 = new FaultToleranceTask("per" , 8);
	Task* st1 = new SingleTask("aja");
	Task* st2 = new SingleTask("dsl");
	Task* st3 = new SingleTask("acm");
	Task* st4 = new SingleTask("cpc");
	Task* st5 = new SingleTask("her");
	hello->enqueue(ft1);
	hello->enqueue(st1);
	hello->enqueue(ft2);
	hello->enqueue(st2);
	hello->enqueue(ft3);
	hello->enqueue(st3);
	hello->enqueue(ft4);
	hello->enqueue(st4);
	hello->enqueue(ft5);
	hello->enqueue(st5);
	for(int i = 0 ; i < 10 ; i++){
		hello->dequeue()->execute();	
	}
	delete hello;
	return 0;
}