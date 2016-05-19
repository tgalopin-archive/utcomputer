#ifndef LO21_DEBUG_TOKEN_DUMPER_H
#define LO21_DEBUG_TOKEN_DUMPER_H


#include <iostream>
#include <vector>
#include "../literal/interface.h"

using namespace std;

/*
 * The token dumper is a tool for debugging able to dump a list of tokens generated by the
 * Lexer in a nice, useful display.
 */
class TokensDumper {
public:
    static void dump(ostream& stream, LiteralVector tokens) {
        int i = 0;

        for (LiteralVector::iterator it = tokens.begin(); it != tokens.end(); ++it) {
            stream << i << " : " << (*it)->toString() << endl;
            i++;
        }
    }
};


#endif //LO21_DEBUG_TOKEN_DUMPER_H
