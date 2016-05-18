#ifndef LO21_REPOSITORY_OPERATORS_H
#define LO21_REPOSITORY_OPERATORS_H


#include "interface.h"
#include "hashmap.h"
#include "../operator/interface.h"

using namespace std;

/**
 * Repository storing all the available operators of UTComputer.
 * This repository is a hash map.
 */
class OperatorsRepository : public HashmapRepository<OperatorInterface> {};


#endif // LO21_REPOSITORY_OPERATORS_H