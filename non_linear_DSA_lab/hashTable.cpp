#include <iostream>
#include <list>
using namespace std;

class Hash {
    // No. of buckets
    int BUCKET;

    // pointer to an array containing buckets
    list<int>* table;

public:
    // Constructor
    Hash(int v);
    
    // insert a key into hash table
    void insertItem(int x);

    // delete a key from hash table
    void deleteItem(int key);

    // hash function to map values to key
    int hashFunction(int x) {
        return (x % BUCKET);
    }

    // function to display hash table
    void displayHash();
};

Hash::Hash(int b) {
    this->BUCKET = b;
    table = new list<int>[BUCKET];
}

void Hash::insertItem(int key) {
    int index = hashFunction(key);
    table[index].push_back(key);
}

void Hash::deleteItem(int key) {
    // get the hash index of key
    int index = hashFunction(key);

    // find the key in (index)th list
    list<int>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++) {
        if (*i == key)
            break;
    }

    if (i != table[index].end())
        table[index].erase(i);
}

void Hash::displayHash() {
    for (int i = 0; i < BUCKET; i++) {
        cout << i;
        for (auto x : table[i])
            cout << "-->" << x;
        cout << endl;
    }
}

int main() {
    // create a hash table with size 10
    Hash hashTable(10);

    // insert data into the hash table
    hashTable.insertItem(0);
    hashTable.insertItem(1);
    hashTable.insertItem(2);
    hashTable.insertItem(3);
    hashTable.insertItem(4);
    hashTable.insertItem(5);
    hashTable.insertItem(6);
    hashTable.insertItem(7);
    hashTable.insertItem(8);
    hashTable.insertItem(9);

    // display the hash table after inserting data
    cout << "Hash Table after inserting data:\n";
    hashTable.displayHash();

    // delete key 12 from the hash table
    hashTable.deleteItem(12);

    // display the hash table after deleting key 12
    cout << "\nHash Table after deleting 12:\n";
    hashTable.displayHash();

    // look for collision event
    cout << "\nCollision events:\n";
    
    // insert key 13 to cause collision at index 3
    hashTable.insertItem(13);
    cout << "Collision at index 3:\n";
    hashTable.displayHash();
    
    // insert key 57 to cause collision at index 7
    hashTable.insertItem(17);
    cout << "\nCollision at index 7:\n";
    hashTable.displayHash();

    return 0;
}