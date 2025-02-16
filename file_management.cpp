#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void writeFile(const string& filename) {
    ofstream outFile(filename, ios::out);
    if (!outFile) {
        cerr << "Error: Unable to open file for writing!\n";
        return;
    }

    cout << "Enter text to write to the file (type 'EXIT' to stop):\n";
    string line;
    while (getline(cin, line)) {
        if (line == "EXIT") break;
        outFile << line << endl;
    }

    outFile.close();
    cout << "Data written to " << filename << " successfully.\n";
}

void appendFile(const string& filename) {
    ofstream outFile(filename, ios::app);
    if (!outFile) {
        cerr << "Error: Unable to open file for appending!\n";
        return;
    }

    cout << "Enter text to append to the file (type 'EXIT' to stop):\n";
    string line;
    while (getline(cin, line)) {
        if (line == "EXIT") break;
        outFile << line << endl;
    }

    outFile.close();
    cout << "Data appended to " << filename << " successfully.\n";
}

void readFile(const string& filename) {
    ifstream inFile(filename, ios::in);
    if (!inFile) {
        cerr << "Error: Unable to open file for reading!\n";
        return;
    }

    cout << "Contents of " << filename << ":\n";
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
}

int main() {
    string filename;
    int choice;

    cout << "Enter the filename: ";
    cin >> filename;
    cin.ignore(); // Clear the newline character from the input buffer

    do {
        cout << "\nFile Management Tool\n";
        cout << "1. Write to file\n";
        cout << "2. Append to file\n";
        cout << "3. Read from file\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the newline character from the input buffer

        switch (choice) {
        case 1:
            writeFile(filename);
            break;
        case 2:
            appendFile(filename);
            break;
        case 3:
            readFile(filename);
            break;
        case 4:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
