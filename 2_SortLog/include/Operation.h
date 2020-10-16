#pragma once

#include <string>

class Operation {
public:
    Operation(unsigned int leftElemPos, unsigned int rightElemPos);
    unsigned int get_left_elem_position() const;
    unsigned int get_right_elem_position() const;
    std::string get_description() const;
protected:
    unsigned int m_leftElemPosition;
    unsigned int m_rightElemPosition;
    std::string m_description;
};