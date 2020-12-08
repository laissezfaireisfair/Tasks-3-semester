#include "Point.h"

Point::Point(uint16 const x, uint16 const y) :
    m_x(x),
    m_y(y) {}

std::uint16_t Point::x() const {
    return m_x;
}

std::uint16_t Point::y() const {
    return m_y;
}

void Point::set_x(uint16 const x) {
    m_x = x;
}

void Point::set_y(uint16 const y) {
    m_y = y;
}