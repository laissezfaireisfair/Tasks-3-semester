#pragma once

class Object;

class ObjectBehaviour {
public:
    virtual void do_on_interact(Player & caller, Map & map) = 0;
private:
    Object *obj;
};