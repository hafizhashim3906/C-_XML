#pragma once

class IVisitable;

#include "IVisitor.h"

/*abstract*/
class IVisitable
{
public:
    virtual void Accept(IVisitor &visitor) = 0;
    virtual ~IVisitable() = default;
};
