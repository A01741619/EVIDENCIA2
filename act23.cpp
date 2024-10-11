#include "act23.h"
using namespace std;
#include <stdexcept>
#include <iostream>
//Juan Pablo Gil, A01741619


MyLinkedList::MyLinkedList(){//complejidad computacional O(1)
    this->head=nullptr;
    this->size=0;
    this->tail=nullptr;
}

MyLinkedList::~MyLinkedList(){//complejidad computacional O(n)
    MyNodoLL* aux=this->head;
    while (aux != nullptr) {
        MyNodoLL* nextNode=aux->next;
        delete aux;
        aux=nextNode;
    }
    this->head=nullptr;
    this->tail=nullptr;
    this->size=0;
}


int MyLinkedList::length(){//complejidad computacional O(1)
    return this->size;
}

bool MyLinkedList::isEmpty(){//complejidad computacional O(1)
    //this->head==nullptr;
    return this->size==0;
}

int MyLinkedList::first(){//complejidad computacional O(1)
    if(this->size>0){
        return this->head->data;
    }else{
        throw invalid_argument ("no se puede regresar el primer elemento de una lista");
    }
}

int MyLinkedList::last(){//complejidad computacional O(1)
    if(this->size>0){
        return this->tail->data;
    }else{
        throw invalid_argument ("no se puede regresar el primer elemento de una lista");
    }
}   



int MyLinkedList::getAt(int pos){//complejidad computacional O(n), ya que requiere recorrer la lista
    if(pos<0 || pos>=this->size){
        throw invalid_argument ("indice fuera de rango");
    }
    MyNodoLL *aux=this->head;
    for(int i=0;i<pos;i++){
        aux=aux->next;//O(n)
    }
    return aux->data;//O(1)
}

void MyLinkedList::setAt(int pos, int data){//complejidad computacional O(n)
    if(pos<0 || pos>=this->size){
        throw invalid_argument ("El indice esta fuera del rango");
    }
    MyNodoLL *aux=this->head;
    for(int i=0;i<pos;i++){
        aux=aux->next;//O(n)
    }
    aux->data=data;//O(1)

}

void MyLinkedList::insertFirst(int data){//complejidad computacional O(1)
    //si la lista esta vacia?
    MyNodoLL* nuevo=new MyNodoLL(data, this->head);
    nuevo->next=this->head;
    this->head=nuevo;
    this->size++;//O(1)
}

void MyLinkedList::insertLast(int data){//complejidad computacional O(1)
    MyNodoLL* nuevo=new MyNodoLL(data);
    if(this->size==0){
        this->head=nuevo;
    }else{
        this->tail->next=nuevo;
    }
    this->tail=nuevo;
    this->size++;//O(1)

}

void MyLinkedList::insertAt(int pos, int data){//complejidad computacional O(n)
    if(pos<0 || pos>this->size){
        throw invalid_argument ("El indice esta fuera del rango");
    }
    if(pos==0){
        this->insertFirst(data);
    }else if(pos==this->size){
        this->insertLast(data);
    }else{
        MyNodoLL* aux=this->head;
        for(int i=0;i<pos-1;i++){
            aux=aux->next;//O(n)
        }
        MyNodoLL* nuevo=new MyNodoLL(data, aux->next);
        aux->next=nuevo;
        this->size++;
    }

}

void MyLinkedList::removeFirst(){//complejidad computacional O(1)
    if(this->size>0){
    MyNodoLL* tmp=this->head;
    this -> head=this->head->next;
    delete tmp;
    this->size--;
    if(this->size==0){
        this->tail=nullptr;
    }

}else{
    throw invalid_argument ("no se puede remover el primer elemento de una lista vacia");
}
}

void MyLinkedList::removeLast(){//complejidad computacional O(n), tambien recorre 
    if(this->size>0){
        if(this->size==1){
            delete this->head;
            this->head=nullptr;
            this->tail=nullptr;
        }else{
            MyNodoLL* aux=this->head;
            while(aux->next!=this->tail){
                aux=aux->next;//O(n)
            }
            delete this->tail;
            this->tail=aux;
            this->tail->next=nullptr;
        }
        this->size--;
    }else{
        throw invalid_argument ("no se puede remover el ultimo elemento de una lista vacia");
    }
}

void MyLinkedList::removeAt(int pos){//complejidad computacional O(n)
    if(pos<0 || pos>=this->size){
        throw invalid_argument ("El indice esta fuera del rango");
    }
    if(pos==0){
        this->removeFirst();
    }else if(pos==this->size-1){
        this->removeLast();
    }else{
        MyNodoLL* aux=this->head;
        for(int i=0;i<pos-1;i++){
            aux=aux->next;//O(n)
        }
        MyNodoLL* tmp=aux->next;
        aux->next=tmp->next;
        delete tmp;
        this->size--;
    }

}

ostream& operator<<(ostream& os, const MyLinkedList& ll) {
    MyNodoLL* current = ll.head;
    while (current != nullptr) {
        os << current->data;
        current = current->next;
        if (current != nullptr) {
            os << ","; 
        }
    }
    return os;
}

