#include "Molecule.h"

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

void Molecule::load(const string& filename) {
    ifstream fin(filename);
    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        string cmd;
        ss >> cmd;
        if (cmd == "TITL") {
        } else if (cmd == "CELL") {
        } else if (cmd == "SFAC") {
        } else if (cmd == "END") {
        } else if (cmd == "FMOL") {
        } else if (cmd == "MPLN") {
        } else if (cmd == "UNDO") {
        } else if (cmd == "LINK") {
        } else {
            const string& name = cmd;
            int type;
            ss >> type;
            vec pos;
            ss >> pos;
            insert(new Atom(name, type, pos));
        }
    }
}
