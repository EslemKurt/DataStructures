#include <iostream>
using namespace std;

class Node
{
public:
   int data;
   Node *next;
   Node *prev;
};

class DoubleLinkedList
{
public:
   Node *head;

public:
   DoubleLinkedList()
   {
      head = NULL;
   }
   void printList();
   void addItemFront(int data);
   void addItemTail(int data);
   void addItemMiddel(int n, int data);
   void getItemFront();
   void getItemTail();
   void removeItemFront();
   void removeItemTail();
   void removeAllItemList();
};

void DoubleLinkedList::printList()
{
   Node *iNode = head;
   if (head != NULL)
   {
      while (iNode->next != NULL)
      {
         cout << iNode->data << ' ';
         iNode = iNode->next;
      }
      cout << iNode->data << ' ' << endl;
   }
   else
   {
      cout << "List is empty " << endl;
   }
};

void DoubleLinkedList::addItemFront(int data)
{
   Node *temp = new Node();
   temp->data = data;
   temp->next = head;
   temp->prev = NULL;
   if (head != NULL)
   {
      head->prev = temp;
   }
   head = temp;
};

void DoubleLinkedList::addItemTail(int data)
{
   Node *temp = new Node();
   temp->data = data;
   temp->next = NULL;
   Node *iNode = head;
   while (iNode->next != NULL)
   {
      iNode = iNode->next;
   }
   iNode->next = temp;
   temp->prev = iNode;
};

void DoubleLinkedList::addItemMiddel(int n, int data)
{
   Node *temp = new Node();
   Node *iNode = head;
   Node *jNode = head;
   temp->data = data;

   if (n == 1)
   {
      addItemFront(data);
   }
   else
   {
      for (int i = 1; i < n; i++)
      {
         iNode = iNode->next;
      }
      temp->next = iNode;
      while (jNode->next != iNode)
      {
         jNode = jNode->next;
      }
      jNode->next = temp;
      temp->prev = jNode;
      iNode->prev = temp;
   }
};

void DoubleLinkedList::getItemFront()
{
   Node *iNode = head;
   cout << iNode->data << ' ' << endl;
};

void DoubleLinkedList::getItemTail()
{
   Node *iNode = head;
   while (iNode->next != NULL)
   {
      iNode = iNode->next;
   }
   cout << iNode->data << ' ' << endl;
};

void DoubleLinkedList::removeItemFront()
{
   Node *iNode = head;
   Node *jNode = iNode->next;
   head = jNode;
   iNode->next = NULL;
   jNode->prev = NULL;
};

void DoubleLinkedList::removeItemTail()
{
   Node *iNode = head;
   while (iNode->next->next != NULL)
   {
      iNode = iNode->next;
   }
   (iNode->next)->prev = NULL;
   iNode->next = NULL;
};

void DoubleLinkedList::removeAllItemList()
{
   Node *iNode = head;
   Node *jNode = iNode->next;
   while (jNode->next != NULL)
   {
      iNode->next = NULL;
      iNode = jNode;
      jNode->prev = NULL;
      jNode = jNode->next;
   }
   iNode->next = NULL;
   jNode->prev = NULL;
   head = NULL;
}

int main()
{
   DoubleLinkedList doubleList;
   Node *head = NULL;
   doubleList.addItemFront(40);
   doubleList.addItemFront(30);
   doubleList.addItemFront(20);
   doubleList.addItemFront(10);
   doubleList.addItemTail(50);
   doubleList.addItemMiddel(2, 17);
   doubleList.printList();
   doubleList.getItemFront();
   doubleList.getItemTail();
   doubleList.removeItemFront();
   doubleList.printList();
   doubleList.removeItemTail();
   doubleList.printList();
   doubleList.removeAllItemList();
   doubleList.printList();

   return 0;
}