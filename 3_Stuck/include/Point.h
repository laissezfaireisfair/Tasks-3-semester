#pragma once
#include <cstdint>

/// Point describes the place in field
class Point {
    using uint16 = std::uint16_t;
public:
    Point(uint16 x, uint16 y);

    uint16 x() const;

    uint16 y() const;

    void set_x(uint16 xNew);

    void set_y(uint16 yNew);
private:
    uint16 m_x;
    uint16 m_y;
};
