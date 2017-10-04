#include <iostream>
#include <fstream>
using namespace std;


class Node {
	private:
 		string Data;
 		Node* Next;

	public:
		Node(string data,Node* n){
			Data = data;
			Next = n;
		
		}
		void setNext(Node* next){
			Next = next;
		}
	
		Node* getNext(){
			return Next;
		}
	
		string getData(){
			return Data;
	}	
};

class LinkedList{
	private:	
		Node* First;
		Node* Last;
		int*Size;

	public:
		LinkedList(){
			First = NULL;
			Last = NULL;
			Size = 0;
		}
		
		int compareThem(string x, string y){
			for(int i =0 ;i<x.length();i++){
				x[i]=toupper(x[i]);	
			}
			for(int i =0 ;i<y.length();i++){
				y[i]=toupper(y[i]);	
			}
		return x.compare(y);
		}

		void Insert(string data){
			Node* newNode = new Node(data,NULL);
			
			if(isEmpty())
				addLast(newNode);
			
			else{
				Node* currentNode = First;
				
				while(currentNode!=NULL){
					
					if(compareThem(currentNode->getData(),newNode->getData()) <0 && currentNode->getNext()==NULL){
						addLast(newNode);
						break;
					}
					else if(compareThem(currentNode->getData(),newNode->getData()) >0){
						addFirst(newNode);
						break;
					}
					else if(compareThem(currentNode->getData(),newNode->getData()) <0 && compareThem(currentNode->getNext()->getData(),newNode->getData()) >0){
						newNode->setNext(currentNode->getNext());
						currentNode->setNext(newNode);
						break;
					}
					
					else if(compareThem(currentNode->getData(),newNode->getData()) == 0){
						newNode->setNext(currentNode->getNext());
						currentNode->setNext(newNode);
						break;
					}
				
					currentNode=currentNode->getNext();
					
				}	
						
			}
			
		}
					
		
		bool isEmpty(){
			return(Size==0);
		}
		
		void Print(){
			Node* p = First;
			int count = 0;
			while(p!=NULL && count<15){
				cout<<p->getData()<<"\n";
				count++;
				p=p->getNext();
				
			}

		}
		
		void  addLast(Node* newNode){
			if(isEmpty())
				First = newNode;
			else	
				Last->setNext(newNode);
			Last = newNode;
			Size++;
		
		}
	
		void addFirst(Node* newNode){
			newNode->setNext(First);
			First = newNode;
			Size++;
	
		}
};


int main(int argc, char** argv) {
	ifstream inFile;
	string num;
	LinkedList l;
	
	inFile.open(argv[1]);
	if(!inFile){
		cout<<"Cannot Find File Specified";
		exit(1);
	}
	else{
	
	while(inFile>>num){
		cout<<"OutPut1:"<<num<<"\n";
		l.Insert(num);
		cout<<"OutPut2:"<<"\n";
		l.Print();
	}
	
	
	}
	inFile.close();
	
}


