#include <iostream>
#include <string>

using namespace std;

// ?로 끝나면 -> Quack!
// .로 끝나면 -> *Nod*
// I quacked the code! -> exit

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string monologue;
    while(1) {
        getline(cin, monologue);
        if(monologue == "") continue;
        else if(monologue == "I quacked the code!")
            break;
        else if(monologue[monologue.size()-1] == '.')
            cout << "*Nod*" << endl;
        else if(monologue[monologue.size()-1] == '?')
            cout << "Quack!" << endl;
    }
}