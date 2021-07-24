#include "Molecule.h"

#include "../Matrix/Matrix.h"

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

void Molecule::load(const string& filename) {
    ifstream fin(filename);
    string line;
    while (getline(fin, line)) {
        if (line.back() == '\r') {
            line.pop_back();
        }
        if (line.empty()) {
            continue;
        }
        while (line.back() == '=') {
            string nextline;
            getline(fin, nextline);
            line.pop_back();
            line += nextline;
        }
        stringstream ss(line);
        string cmd;
        ss >> cmd;
        if (cmd == "TITL") {
        } else if (cmd == "CELL") {
            double _, szx, szy, szz, a, b, c;
            ss >> _ >> szx >> szy >> szz >> a >> b >> c;
            a *= M_PI / 180;
            b *= M_PI / 180;
            c *= M_PI / 180;
            const double n2 = cos(a) - cos(c) * cos(b) / sin(c);
            cell_ = Matrix({
                {szx, szy * cos(c), szz * cos(b)},
                {0, szy * sin(c), szz * n2},
                {0, 0, szz * sqrt(sin(b) * sin(b) - n2 * n2)},
            });
        } else if (cmd == "SFAC") {
            string name;
            while (ss >> name) {
                sfac_.push_back(name);
            }
        } else if (cmd == "END") {
        } else if (cmd == "FMOL") {
        } else if (cmd == "MPLN") {
        } else if (cmd == "UNDO") {
        } else if (cmd == "ZERR") {
        } else if (cmd == "LATT") {
            int x;
            ss >> x;
            if (x > 0) {
                std::string s = "-X, -Y, -Z";
                symms_.push_back(new Symm(s));
            }
        } else if (cmd == "SYMM") {
            string s;
            getline(ss, s);
            symms_.push_back(new Symm(s));
        } else if (cmd == "UNIT") {
        } else if (cmd == "L.S.") {
        } else if (cmd == "LIST") {
        } else if (cmd == "BOND") {
        } else if (cmd == "ACTA") {
        } else if (cmd == "CONF") {
        } else if (cmd == "FMAP") {
        } else if (cmd == "PLAN") {
        } else if (cmd == "WGHT") {
        } else if (cmd == "FVAR") {
        } else if (cmd == "AFIX") {
        } else if (cmd == "HKLF") {
        } else if (cmd == "LINK") {
        } else {
            const string& name = cmd;
            int type;
            ss >> type;
            --type;
            vec pos;
            ss >> pos;
            insert(new Atom(name, type, pos));
        }
    }
    fin.close();
}
