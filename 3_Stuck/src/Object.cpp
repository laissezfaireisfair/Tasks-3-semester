#include "Object.h"

bool Object::is_stepable() const {
    return m_stepable;
}

char Object::symbol() const {
    return m_symbol;
}

void Object::interact(Player & caller, Map & map) {
    if (m_onInteract != nullptr)
        m_onInteract->do_on_interact(caller, map);
}

Object::Object(char symbolIn, bool stepableIn) {
    m_symbol = symbolIn;
    m_stepable = stepableIn;
    m_onInteract = nullptr;
}