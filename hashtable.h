#include <iostream>
#include <string>
using namespace std;
template<typename T>
class Node{
public:
	string key;
	T value;
	Node* next;

	Node(string key, T value){
		this->key= key;
		this->value= value;
		next=NULL;
	}
	~Node(){
		if(next!=NULL){
			delete next;
		}
	}
};

template<typename T>
class Hashtable{

	Node<T> ** table;
	int cs; //current size
	int ts; //table size

	int HashFn(string key){
		int idx=0;
		int power=1;
		for(auto ch : key){
			idx= (idx+ ch*power)%ts;
			power= (power*29)%ts;
		}
		return idx;
	}

	void rehash(){
		// Save the ptr of old Table and we will do insertions in the new table
		Node<T> ** oldTable= table;
		int oldTs= ts;
		ts= 2*ts+1;
		cs=0;
		table= new Node<T>* [ts];
		for(int i=0; i<ts;i++){
			table[i]=NULL;
		}
		for(int i=0; i<oldTs; i++){
			Node<T>* temp= oldTable[i];
			while(temp!=NULL){
				string key= temp->key;
				T value= temp->value;
				insert(key, value);
				temp=temp->next;
			}
			// destroy the ith linked list
			if(oldTable[i]!=NULL){
				delete oldTable[i];
			}
		}
		delete [] oldTable;
	}


public:
	Hashtable(int default_size = 7){
		cs=0;
		ts=default_size;

		table = new Node<T>* [ts];
		for(int i=0; i<ts; i++){
			table[i]=NULL;
		}
	}

	void insert(string key, T value){

		int idx= HashFn(key);
		Node<T> * n= new Node<T> (key, value);
		n->next= table[idx];
		table[idx]=n;
		cs++;
		float loadFactor= cs/float(ts);
		if(loadFactor>0.7) rehash();
	}

	void print(){
		for(int i=0; i<ts; i++){
			cout<<"bucket "<<i<<" ";

			Node<T> * temp= table[i];
			while(temp!=NULL){
				cout<<temp->key<<" ";
				temp=temp->next;
			}
			cout<<endl;
		}
	}

	bool isPresent(string key){
		int idx= HashFn(key);
		Node<T>* temp= table[idx];

		while(temp!=NULL){
			if(temp->key==key)
				return true;
			temp=temp->next;
		}
		return false;
	}


	T* search(string key){
		int idx= HashFn(key);
		Node<T>* temp= table[idx];

		while(temp!=NULL){
			if(temp->key==key)
				return & temp->value;
			temp=temp->next;
		}
		return NULL;
	}


	void erase(string key){
		int idx= HashFn(key);
		Node<T>* temp= table[idx];
		if(temp->key==key){
			Node<T>* n= temp->next;
			table[idx]=n;
			temp->next=NULL;
			delete temp;
			return;
		}

		while(temp->next!=NULL){
			if(temp->next->key==key){
				Node<T>* todelete= temp->next;
				temp->next= temp->next->next;
				todelete->next= NULL;
				delete todelete;
				return;
			}
			temp=temp->next;
		}
	}
	T& operator[](string key){
		T* valueFound= search(key);
		if(valueFound==NULL){
			T object;
			insert(key, object);
			valueFound=search(key);
		}
		return *valueFound;
	}
};
