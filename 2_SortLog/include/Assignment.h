#pragma once

#include "Operation.h"

class Assignment : public Operation {
public:
    Assignment(unsigned int leftElemPos, unsigned int rightElemPos);
};