#ifndef LO21_LITERAL_DEFINITION_PROGRAM_H
#define LO21_LITERAL_DEFINITION_PROGRAM_H


#include <iostream>
#include <regex>
#include "interface.h"
#include "../literal/program.h"

using namespace std;

/*
 * Definition of a program literal.
 */
class ProgramLiteralDefinition : public LiteralDefinitionInterface {
public:
    string getPattern() const {
        return "\\[[^\\]]*\\]";
    }

    LiteralInterface* createInstance(string value) const {
        return new ProgramLiteral(value);
    }
};


#endif // LO21_LITERAL_DEFINITION_PROGRAM_H