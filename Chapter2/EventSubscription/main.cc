#include "Editor.h"
#include <iostream>
#include <memory>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char *argv[]) {
    string filePath;
    cout << "Please enter the path to the file you want to open in the editor."
         << endl;
    getline(cin, filePath);
    auto editor = Editor(filePath);
    while (true) {
        string type;
        cout << "Please subscribe Editor's event types" << endl;
        cout << "1 - open" << endl
             << "2 - save" << endl
             << "Any keys without 1 or 2 - No more observers" << endl;
        cin >> type;
        if (type == "1") {
            editor.subscribe("open");
        } else if (type == "2") {
            editor.subscribe("save");
        } else {
            break;
        }
    }
    editor.open();
    editor.save();
    editor.open();
}