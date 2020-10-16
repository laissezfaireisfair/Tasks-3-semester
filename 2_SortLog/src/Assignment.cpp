#include "Assignment.h"

Assignment::Assignment(unsigned int leftElemPos, unsigned int rightElemPos) : Operation(leftElemPos, rightElemPos) {
    m_description = "Assignment";
}