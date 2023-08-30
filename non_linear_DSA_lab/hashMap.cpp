#include<bits/stdc++.h>
using namespace std;

class HashTable {
    int size; // Size of the hash table
    vector<int> *table; // Array to store elements
    
public:
    HashTable(int s) {
        size = s;
        table = new vector<int>[size];
    }
    
    // Hash function to get index for a key
    int hashFunction(int key) {
        return key % size;
    }
    
    // Insert a key-value pair into the hash table
    void insert(int key, int value) {
        int index = hashFunction(key);
        table[index].push_back(value);
    }
    
    // Print the hash table
    void printTable() {
        for (int i = 0; i < size; i++) {
            cout << "Elements at index " << i << ": ";
            for (int j = 0; j < table[i].size(); j++)
                cout << table[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    HashTable ht(10); // Create a hash table with size 10
    
    ht.insert(1, 10);
    ht.insert(11, 20);
    ht.insert(21, 30);
    ht.insert(2, 40);
    ht.insert(12, 50);
    
    ht.printTable();
    
    return 0;
}