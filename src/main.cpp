#include <iostream>
#include <array>

using namespace std;

template<typename T>
void testfunc(const T a){
    static int counter=0;
    counter++;

    cout<< "counter value:" << counter << endl;
}

/* Link list node */
struct Node {
    int data;
    struct Node* next;
    struct Node* head;
    Node(int data, Node* h)
    {
        this->data = data;
        this->head = h;
        next = NULL;
    }
};

Node * reveseLI(Node *head)
{
        // Initialize current, previous and
        // next pointers
        Node *current = head;
        Node *prev = nullptr, *next = nullptr;
 
        while (current != nullptr) {
            // Store next
            next = current->next;
 
            // Reverse current node's pointer
            current->next = prev;
 
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
        return head;
}

Node * reverseRR(Node * head) {
  // no need to reverse if head is nullptr 
  // or there is only 1 node.
  if (head == nullptr || head->next == nullptr) {
    return head;
  }

  Node * reversed_list = reverseRR(head->next);

  head->next->next = head;
  head->next = nullptr;
  return reversed_list;
}

void printLl (Node *h){
    /*if(h!=nullptr){
        cout << h->data << ",";
    } else{
        cout << " END" << endl;
        return;
    }*/
    Node *temp = h;
    while(temp != nullptr){
        cout << temp->data << ",";
        temp = temp->next;
    }
    cout << " END" << endl;
}

array<long double,1000> refFib = {0};

long double fibExercise (int n){

    if(n<=1){
        refFib[n]=1;
        return refFib[n];
    }

    if(refFib[n-1]==0)
        fibExercise(n-1);
    if(refFib[n-2]==0)
        fibExercise(n-2);

    refFib[n] = refFib[n-1] + refFib[n-2];  

    return refFib[n];
}



int main() {
    
    Node *n = new Node(0,n);
    Node *next= n->next;
    Node *head = n;
    // Node *next = n.next;
    /*cout << endl;
    for ( int i = 0 ; i<1000 ; i++){
        long double fibTry = fibExercise(i);
        cout << fibTry << ",";
    }
    cout << endl;*/

    for ( int i = 1 ; i<10 ; i++){
        Node *newNode = new Node(i,head);
        n->next = newNode;
        n = n->next;

    }

    printLl(head);

    head = reverseRR(head);

    printLl(head);
    

    system("PAUSE");
}