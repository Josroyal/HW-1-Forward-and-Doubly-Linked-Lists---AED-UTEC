#include <iostream>
using namespace std;

template <typename T>
struct Node{
    T data;
    Node<T> *next = NULL;
    Node<T> *prev = NULL;

    Node(T data){
        this->data = data;
    }
};

template <typename T>
class List{
private:
    Node<T> *head = NULL;
    Node<T> *tail = NULL;
public:
    T front(){
        if (head != NULL){
            return head->data;
        }
        else{
            return NULL;
        }
    }

    T back(){
        if (tail != NULL){
            return tail->data;
        }
        else{
            return NULL;
        }
    }

    void push_front(T t){
        Node<T> *nodo = new Node<T>(t);

        if (head == NULL){
            head = nodo;
            tail = nodo;
        }
        else {
            nodo->next = head;
            head->prev = nodo;
            head = nodo;
        }

    }

    void push_back(T t){
        Node<T> *nodo = new Node<T>(t);

        if (head == NULL){
            head = nodo;
            tail = nodo;
        }
        else {
            nodo->prev = tail;
            tail->next = nodo;
            tail = nodo;
        }

    }

    void pop_front(){
        if (head == NULL){
            return;
        }
        else if (head->next == NULL){
            delete head;
            head = NULL;
            tail = NULL;
        }
        else {
            head = head->next;
            delete head->prev;
            head->prev = NULL;
        }
    }

    void pop_back(){
        if (head == NULL){
            return;
        }
        else if (head->next == NULL){
            delete head;
            head = NULL;
            tail = NULL;
        }
        else {
            tail = tail->prev;
            delete tail->next;
            tail->next = NULL;
        }
    }

    void insert(T t, int pos){
        Node<T>* nodo = new Node<T>(t);
        if (head == NULL) {
            cout<<"Lista vacia, insertando en primera posición..."<<endl;
            head = nodo;
            tail = nodo;
        }else{
            Node<T>* temp = head;
            for(int i=0; i< pos-1; i++){
                temp = temp->next;
                if (temp == NULL){
              throw out_of_range("Fuera de rango.");
            }
            }
            nodo->next = temp->next;
            nodo->prev = temp;
            temp->next = nodo;
            nodo->next->prev = nodo;
        }

    }

    void remove(int pos){
        if (head == NULL) {
            cout<<"No hay nada que eliminar"<<endl;
        }else{
            Node<T>* temp = head;
            for(int i=0; i< pos-1; i++){
                temp = temp->next;
                if (temp == NULL){
              throw out_of_range("Fuera de rango.");
            }
            }
            Node<T>* removed = temp->next;
            temp->next = temp->next->next;
            temp->next->prev = temp;
            delete removed;

        }
    }

    T operator[](int pos){
      Node<T>* temp = head;
      if (temp == NULL){
        throw out_of_range("La lista está vacia.");
      }
      else{
        if (pos == 0)
          return temp->data;
        else{
          for(int i=0; i< pos; i++){
            temp = temp->next;
            if (temp == NULL){
              throw out_of_range("Fuera de rango.");
            }
          }
          return temp->data;
        }

      }
    }

    bool empty(){
        return head == NULL ? true : false;
    }

    int size(){
        if (head == NULL){
            return 0;
        }

        if (head == tail){
            return 1;
        }

        int count = 1;
        Node<T> *temp = head;

        while (temp != tail){
            temp = temp->next;
            count++;
        }

        return count;
    }

    void clear(){
        Node<T> *temp = head;
        Node<T> *deleted = head;
        while (temp != nullptr){
            Node<T> *deleted = temp;
            temp = temp->next;
            delete deleted;
        }
    }

    void reverse() {
        Node<T>* temp = head;
        Node<T>* new_next = nullptr;

        while (temp != nullptr) {
            new_next = temp->prev;
            temp->prev = temp->next;
            temp->next = new_next;
            temp = temp->prev;
        }

        // Swap del head y tail
        if (new_next != nullptr) {
            tail = head;
            head = new_next->prev;
        }
    }

    void print(){
        if (head == NULL){
            return;
        }

        Node<T> *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != NULL);
        cout << endl;
    }
};
