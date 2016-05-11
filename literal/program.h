#ifndef LO21_LITERAL_PROGRAM_H
#define LO21_LITERAL_PROGRAM_H


#include "literal_interface.h"

/*
 * A program literal represents a string surrounded by brackets.
 * For instance :
 *      [ DUP 0 < NEG ]
 */
struct ProgramLiteral : public NumericLiteralInterface {
private:
    std::string value;

public:
    ProgramLiteral(std::string value): value(value) {}

    const std::string &getValue() const {
        return value;
    }

    std::string toString() const {
        return value;
    };
};


#endif // LO21_LITERAL_PROGRAM_H