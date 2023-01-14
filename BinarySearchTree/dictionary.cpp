#include <iostream>
#include <fstream>
using namespace std;

class Node
{
public:
   Node *left;
   Node *right;
   string word;
   string mean;
};
class Dictionary
{
public:
   Node *root;

   Dictionary()
   {
      root = NULL;
   }
   void addWord(Node *temp, string word, string mean);
   void readFile(string fileName);
   void viewDictionary(Node *temp);
   void viewDictionary(Node *temp, string w1, string w2);
   Node *searchWord(string word, Node *temp);
   Node *searchWordPerent(string word, Node *temp);
   void changeMean(string word, string mean);
   int howManyWords(Node *temp);
   void deleteWord(string word);
   void searchPrintWord(string word);
};

void Dictionary::addWord(Node *temp, string word, string mean)
{
   if (root == NULL)
   {
      Node *newWord = new Node();
      newWord->word = word;
      newWord->mean = mean;
      root = newWord;
   }
   else
   {
      if (word > temp->word)
      {
         if (temp->right != NULL)
         {
            addWord(temp->right, word, mean);
            return;
         }
         else
         {
            Node *newWord = new Node();
            newWord->word = word;
            newWord->mean = mean;
            temp->right = newWord;
            return;
         }
      }
      else if (word < temp->word)
      {
         if (temp->left != NULL)
         {
            addWord(temp->left, word, mean);
            return;
         }
         else
         {
            Node *newWord = new Node();
            newWord->word = word;
            newWord->mean = mean;
            temp->left = newWord;
            return;
         }
      }
      return;
   }
}
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
void Dictionary::readFile(string fileName)
{
   ifstream infile("./" + fileName);
   if (!infile.is_open())
   {
      cerr << "Error: Could not open file " << fileName << endl;
      return;
   }
   string line;
   while (getline(infile, line))
   {
      int wordSize = line.find("-");
      string word = line.substr(0, wordSize - 1);
      string mean = line.substr(wordSize + 1);
      addWord(root, word, mean);
   }
   infile.close();
}
Node *Dictionary::searchWord(string word, Node *temp)
{
   Node *rNode = NULL;
   if (temp->word == word)
   {
      rNode = temp;
      return rNode;
   }
   else if (temp->left != NULL || temp->right != NULL)
   {
      if (temp->word < word && temp->right != NULL)
      {
         return searchWord(word, temp->right);
      }
      else if (temp->left != NULL)
      {
         return searchWord(word, temp->left);
      }
   }
   else
   {
      cout << word << " -> The Word is not exist." << endl;
      return rNode;
   }
   return rNode;
}
Node *Dictionary::searchWordPerent(string word, Node *temp)
{
   Node *rNode = NULL;
   if ((temp->left)->word == word || (temp->right)->word == word)
   {
      rNode = temp;
      // cout << temp->word << " -> The Word is exist." << endl;
      // cout << temp->word << ": " << temp->mean << endl;
      return rNode;
   }
   else if (temp->left != NULL || temp->right != NULL)
   {
      for (int i = 0; i < word.length(); i++)
      {
         if (int(temp->word[i]) < int(word[i]) && temp->right != NULL)
         {
            return searchWordPerent(word, temp->right);
         }
         else if (temp->left != NULL)
         {
            return searchWordPerent(word, temp->left);
         }
      }
   }
   else
   {
      cout << word << " -> The Word is not exist." << endl;
      return rNode;
   }
   return rNode;
};
void Dictionary::changeMean(string word, string mean)
{
   (searchWord(word, root))->mean = mean;
   cout << "Changed: " << (searchWord(word, root))->word << " - " << (searchWord(word, root))->mean << endl;
}
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
void Dictionary::deleteWord(string word)
{
   Node *delNode = searchWord(word, root);
   if (delNode->left == NULL && delNode->right == NULL) // leaf ise
   {
      Node *perent = searchWordPerent(word, root);
      if (perent->left == delNode)
      {
         perent->left = NULL;
         delete delNode;
      }
      else if (perent->right == delNode)
      {
         perent->right = NULL;
         delete delNode;
      }
      // viewDictionary(root);
   }
   if (delNode->left == NULL && delNode->right != NULL) // solu bos ise
   {
      Node *perent = searchWordPerent(word, root);
      if (perent->left == delNode)
      {
         perent->left = delNode->right;
         delete delNode;
      }
      if (perent->right == delNode)
      {
         perent->right = delNode->right;
         delete delNode;
      }
   }
   if (delNode->left != NULL && delNode->right == NULL) // sagi bos ise
   {
      Node *perent = searchWordPerent(word, root);
      if (perent->left == delNode)
      {
         perent->left = delNode->left;
         delete delNode;
      }
      if (perent->right == delNode)
      {
         perent->right = delNode->left;
         delete delNode;
      }
   }
   if (delNode->left != NULL && delNode->right != NULL) // iki tarafi da dolu ise
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
   cout << "The word \"" << delNode->word << "\" has been deleted." << endl;
}
void Dictionary::searchPrintWord(string word)
{
   Node *sWord = searchWord(word, root);
   if (sWord != NULL)
   {
      cout << sWord->word << ": " << sWord->mean << endl;
   }
}
int main()
{
   Dictionary EnglishDictionary;
   cout << "All the words of the dictionary: ";
   EnglishDictionary.viewDictionary(EnglishDictionary.root);
   cout << "   The addWord function is run... " << endl;
   EnglishDictionary.addWord(EnglishDictionary.root, "input", "data that is entered into a computer.");
   EnglishDictionary.addWord(EnglishDictionary.root, "data", "information that is processed by a computer.");
   EnglishDictionary.addWord(EnglishDictionary.root, "software", "a collection of instructions that tells a computer what to do.");
   cout << "All the words of the dictionary: ";
   EnglishDictionary.viewDictionary(EnglishDictionary.root);
   cout << endl;
   cout << "   The readFile function is run... " << endl;
   EnglishDictionary.readFile("words.txt");
   cout << "All the words of the dictionary: ";
   EnglishDictionary.viewDictionary(EnglishDictionary.root);
   cout << endl;
   cout << "The number of words in the dictionary: " << EnglishDictionary.howManyWords(EnglishDictionary.root) << endl;
   cout << "   The searchPrintWord function is run... " << endl;
   EnglishDictionary.searchPrintWord("data");
   cout << "   The searchPrintWord function is run... " << endl;
   EnglishDictionary.searchPrintWord("veri");
   cout << "   The viewDictionary function is run... " << endl;
   EnglishDictionary.viewDictionary(EnglishDictionary.root, "input", "sofware");
   cout << endl;
   EnglishDictionary.changeMean("data", "veri");
   cout << "   The searchPrintWord function is run... " << endl;
   EnglishDictionary.searchPrintWord("data");
   cout << "   The readFile function is run... " << endl;
   EnglishDictionary.readFile("terimler.txt");
   cout << "The number of words in the dictionary: " << EnglishDictionary.howManyWords(EnglishDictionary.root) << endl;
   EnglishDictionary.deleteWord("data");
   cout << "The number of words in the dictionary: " << EnglishDictionary.howManyWords(EnglishDictionary.root) << endl;
   return 0;
}