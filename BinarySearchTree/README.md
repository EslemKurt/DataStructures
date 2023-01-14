# Binary Search Tree - Dictionary

## Create a node class

```cpp
class Node
{
public:
   Node *left;
   Node *right;
   string word;
   string mean;
};
```

![aNode.png](Binary%20Search%20Tree%20-%20Dictionary%2094e40f0d96b945f6bd1c840dd3d9f366/aNode.png)

## Create a Dictionary class

```cpp
class Dictionary
{
public:
   Node *root;
   Dictionary()
   {
      root = NULL;
   }
};
```

![BST.png](Binary%20Search%20Tree%20-%20Dictionary%2094e40f0d96b945f6bd1c840dd3d9f366/BST.png)

## Explanation of the addWord function

```cpp
void addWord(Node *temp, string word, string mean){
   if (root == NULL){
      Node *newWord = new Node();
      newWord->word = word;
      newWord->mean = mean;
      root = newWord;}
   else{
      if (word > temp->word){
         if (temp->right != NULL){
            addWord(temp->right, word, mean);
            return;}
         else{
            Node *newWord = new Node();
            newWord->word = word;
            newWord->mean = mean;
            temp->right = newWord;
            return;}}
      else if (word < temp->word){
         if (temp->left != NULL){
            addWord(temp->left, word, mean);
            return;}
         else{
            Node *newWord = new Node();
            newWord->word = word;
            newWord->mean = mean;
            temp->left = newWord;
            return;}}
      return;}
}
```

![addWord.png](Binary%20Search%20Tree%20-%20Dictionary%2094e40f0d96b945f6bd1c840dd3d9f366/addWord.png)

## Explanation of the searchWord function

```cpp
Node *Dictionary::searchWord(string word, Node *temp)
{
   Node *rNode = NULL;
   if (temp->word == word){
      rNode = temp;
      cout << temp->word << " -> The Word is exist." << endl;
      cout << temp->word << ": " << temp->mean << endl;
      return rNode;
   }
   else if (temp->left != NULL || temp->right != NULL){
      if (temp->word < word && temp->right != NULL){
         return searchWord(word, temp->right);
      }
      else if (temp->left != NULL){
         return searchWord(word, temp->left);
      }
   }
   else{
      cout << word << " -> The Word is not exist." << endl;
      return rNode;
   }
   return rNode;
}
```

![seachWord.png](Binary%20Search%20Tree%20-%20Dictionary%2094e40f0d96b945f6bd1c840dd3d9f366/seachWord.png)

## Explanation of the viewDictionary function

```cpp
void Dictionary::viewDictionary(Node *temp)
{
   if (root == NULL)
   {
      cout << "Dictionary is empty" << endl;
   }
   else
   {
      if (temp->left != NULL)
      {
         viewDictionary(temp->left);
      }
      cout << temp->word << ", ";
      if (temp->right != NULL)
      {
         viewDictionary(temp->right);
      }
   }
}
```

Start from the temp and if temp has a left child recursive with temp’s left.
After printing all the values on the left side of temp respectively, temp is printed.
Then if temp has a right child recursive with temp’s right.
When the function is completed, all elements are written.

![view.png](Binary%20Search%20Tree%20-%20Dictionary%2094e40f0d96b945f6bd1c840dd3d9f366/view.png)

## Overload of the viewDictionary function

### This function is for s**earching** and **listing efficiently** a group of words given an **interval of two words**.

This function work like view Dictionary function however, if the word is not in the desired position, this function does not print the word.

```cpp
void Dictionary::viewDictionary(Node *temp, string w1, string w2)
{
   if (root == NULL)
   {
      cout << "Dictionary is empty" << endl;
   }
   else
   {
      if (temp->left != NULL)
      {
         viewDictionary(temp->left, w1, w2);
      }
      if ((w1 >= temp->word && w2 <= temp->word) || (w1 <= temp->word && w2 >= temp->word))
      {
         cout << temp->word << ", ";
      }
      if (temp->right != NULL)
      {
         viewDictionary(temp->right, w1, w2);
      }
   }
}
```

![viewOverload.png](Binary%20Search%20Tree%20-%20Dictionary%2094e40f0d96b945f6bd1c840dd3d9f366/viewOverload.png)

## Explanation of the deleteWord function

```cpp
void Dictionary::deleteWord(string word)
{
   Node *delNode = searchWord(word, root);
   if (delNode->left == NULL && delNode->right == NULL){
      Node *perent = searchWordPerent(word, root);
      if (perent->left == delNode){
         perent->left = NULL;
         delete delNode;
      }
      else if (perent->right == delNode){
         perent->right = NULL;
         delete delNode;
      }
   }
   if (delNode->left == NULL && delNode->right != NULL)
	 {
      Node *perent = searchWordPerent(word, root);
      if (perent->left == delNode){
         perent->left = delNode->right;
         delete delNode;
      }
      if (perent->right == delNode){
         perent->right = delNode->right;
         delete delNode;
      }
   }
   if (delNode->left != NULL && delNode->right == NULL)
	 {
      Node *perent = searchWordPerent(word, root);
      if (perent->left == delNode){
         perent->left = delNode->left;
         delete delNode;
      }
      if (perent->right == delNode){
         perent->right = delNode->left;
         delete delNode;
      }
   }
   if (delNode->left != NULL && delNode->right != NULL)
	 {
      Node *iNode = delNode->right;
      while (iNode->left->left != NULL)
			{
         iNode = iNode->left;
      }
      delNode->word = iNode->left->word;
      delNode->mean = iNode->left->mean;
      delete iNode->left;
      iNode->left = NULL;
   }
}
```

### If the word desired to be deleted is in the leaf:

![delete1.png](Binary%20Search%20Tree%20-%20Dictionary%2094e40f0d96b945f6bd1c840dd3d9f366/delete1.png)

### If the word you want to delete has a child:

![delete2.png](Binary%20Search%20Tree%20-%20Dictionary%2094e40f0d96b945f6bd1c840dd3d9f366/delete2.png)

### If the word you want to delete has two children:

![delete3.png](Binary%20Search%20Tree%20-%20Dictionary%2094e40f0d96b945f6bd1c840dd3d9f366/delete3.png)

## Explanation of the changeMean function

```cpp
void Dictionary::changeMean(string word, string mean)
{
   (searchWord(word, root))->mean = mean;
   cout << "Changed: " << (searchWord(word, root))->word << " - " << (searchWord(word, root))->mean << endl;
}
```

This function use the serchWord function and changes the meaning of the node it obtains.

![change main.png](Binary%20Search%20Tree%20-%20Dictionary%2094e40f0d96b945f6bd1c840dd3d9f366/change_main.png)

## Explanation of the howManyWords function

```cpp
int Dictionary::howManyWords(Node *temp)
{
   if (temp == NULL)
   {
      return 0;
   }
   else
   {
      return 1 + howManyWords(temp->right) + howManyWords(temp->left);
   }
}
```

![howManyW.png](Binary%20Search%20Tree%20-%20Dictionary%2094e40f0d96b945f6bd1c840dd3d9f366/howManyW.png)