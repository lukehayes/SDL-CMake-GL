#ifndef COMPONENT_H
#define COMPONENT_H

/**
 * A root component that all other components will inherit
 */
class Component {
    public:
        Component() {}
        virtual ~Component() {}
        virtual void update() = 0;
};


#endif

