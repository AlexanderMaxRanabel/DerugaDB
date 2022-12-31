#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 100;  // maximum size of the database

// structure to store a person's information
struct Person {
    string name;
    int age;
};

// array to store the database
Person database[MAX_SIZE];
int size = 0;  // current size of the database

// function to add a person to the database
void addPerson(string name, int age) {
    if (size < MAX_SIZE) {
        database[size].name = name;
        database[size].age = age;
        size++;
    } else {
        cout << "Error: Database is full." << endl;
    }
}

// function to remove a person from the database
void removePerson(string name) {
    // search for the person in the database
    for (int i = 0; i < size; i++) {
        if (database[i].name == name) {
            // person found, remove them by shifting all the subsequent entries back one position
            for (int j = i; j < size - 1; j++) {
                database[j] = database[j + 1];
            }
            size--;
            return;
        }
    }

    // person not found
    cout << "Error: Person not found in the database." << endl;
}

// function to modify a person's age in the database
void modifyAge(string name, int age) {
    // search for the person in the database
    for (int i = 0; i < size; i++) {
        if (database[i].name == name) {
            // person found, update their age
            database[i].age = age;
            return;
        }
    }

    // person not found
    cout << "Error: Person not found in the database." << endl;
}

int main() {
    // add some people to the database
    addPerson("Alice", 25);
    addPerson("Bob", 30);
    addPerson("Charlie", 35);

    // modify Bob's age
    modifyAge("Bob", 32);

    // remove Charlie from the database
    removePerson("Charlie");

    // print the contents of the database
    for (int i = 0; i < size; i++) {
        cout << database[i].name << ": " << database[i].age << endl;
    }

    return 0;
}
