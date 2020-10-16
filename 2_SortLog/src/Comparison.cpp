#include "Comparison.h"

Comparison::Comparison(unsigned int leftElemPos, unsigned int rightElemPos) : Operation(leftElemPos, rightElemPos) {
    m_description = "Comparison";
}