#include "Operation.h"

Operation::Operation(unsigned int const leftElemPos, unsigned int const rightElemPos) {
    m_leftElemPosition = leftElemPos;
    m_rightElemPosition = rightElemPos;
    m_description = "Operation";
}

unsigned int Operation::get_left_elem_position() const {
    return m_leftElemPosition;
}

unsigned int Operation::get_right_elem_position() const {
    return m_rightElemPosition;
}

std::string Operation::get_description() const {
    return m_description;
}