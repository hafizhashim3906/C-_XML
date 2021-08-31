#pragma once

#include "INode.h"

/*abstract*/
class IVisitor
{
public:
    virtual void VisitBefore(INode &node) = 0;
    virtual void VisitAfter(INode &node) = 0;

    virtual ~IVisitor() = default;
};
