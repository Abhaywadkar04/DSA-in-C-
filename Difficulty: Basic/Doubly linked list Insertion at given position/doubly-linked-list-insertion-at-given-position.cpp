//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* a Node of the doubly linked list */
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x)
  {
      data = x;
      next = prev = NULL;
  }
};

void addNode(Node *head, int pos, int data);

Node *insert(Node *head, int x)
{
    if (head == NULL)
    {
        return new Node(x);
    }
    Node *n = new Node(x);
    
    head->next = n;
    n->prev = head;
    head = n;
    return head;
}

void printList(Node *head)
{
  // The purpose of below two loops is
  // to test the created DLL
  Node *temp=head;
  if (temp != NULL) {
    int ct1=0,ct2=0;
  while (temp->next!=NULL)
    temp=temp->next,ct1++;
  while (temp->prev!=NULL)
   temp = temp->prev,ct2++;
   if(ct1!=ct2){
       cout<<-1<<"\n";
       return;
   }
  }
  while (temp != NULL)
  {
      printf("%d ",temp->data);
      temp=temp->next;
  }
  
  cout << endl;
}

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
  Node *head = NULL; 
  Node *root = NULL;
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
     int x;
     scanf("%d",&x);
     head = insert(head, x);
     if(root==NULL) root = head;
  }     
  head = root;
  int pos,data;
  cin>>pos>>data;
  addNode(head, pos, data);
  printList(head);
  }
  return 0;
}
// } Driver Code Ends


/* a Node of the doubly linked list 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

//Function to insert a new node at given position in doubly linked list.

// Function to add a node at a specific position
void addNode(Node *head, int pos, int data) {
    // Create a new node
    Node* newNode = new Node(data);
    
    // Handle inserting at the head (position 0)
    if (head == nullptr) {
    // Handle the case where the list is empty, if needed.
    // For instance, if you want to insert the new node as the only node in the list.
    head = newNode;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return;
}

if (pos == 0) {
    // Insert newNode after the head node
    newNode->next = head->next; // New node's next is the current head's next
    newNode->prev = head;       // New node's prev is the current head
    
    if (head->next != nullptr) {
        head->next->prev = newNode; // Update the current head's next node's prev to the new node
    }
    
    head->next = newNode; // Update the current head's next to the new node
    return;
}


    Node* temp = head;
    int count = pos;

    // Traverse to the node at the specified position
    while (count > 0 && temp != nullptr) {
        temp = temp->next;
        count--;
    }

    // If the position is out of bounds or the position is at the end of the list
    if (temp == nullptr) {
        cout << "Position out of bounds\n";
        return;
    }

    // Insert the new node immediately after the specified position
    newNode->next = temp->next; // New node's next is the node after temp
    newNode->prev = temp;       // New node's prev is temp

    if (temp->next != nullptr) {
        temp->next->prev = newNode; // Update the next node's prev to the new node
    }

    temp->next = newNode; // Update temp's next to the new node
}