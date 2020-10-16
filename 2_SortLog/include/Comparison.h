#pragma once

#include "Operation.h"

class Comparison : public Operation {
public:
    Comparison(unsigned int leftElemPos, unsigned int rightElemPos);
};