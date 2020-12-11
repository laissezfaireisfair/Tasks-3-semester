#pragma once

class ObjectBehaviour;

class Player;

class Map;

class Object{
public:
    bool is_stepable() const;
    char symbol() const;
    void interact(Player & caller, Map & map);
protected:
    Object(char symbolIn, bool stepableIn); // Set m_onInteract nullptr
private:
    char m_symbol;
    bool m_stepable;
    ObjectBehaviour *m_onInteract;
};