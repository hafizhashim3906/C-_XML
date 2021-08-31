#pragma once

#include "INode.h"
#include "IVisitor.h"

class PrintVisitor: public IVisitor
{
    int m_Indent;

public:

    PrintVisitor(): m_Indent(0) {};

    virtual void VisitBefore(INode &node) {
        //(void) node;
        node.print(m_Indent);

        m_Indent++;
    }

    virtual void VisitAfter(INode &node) {
        (void) node;
        --m_Indent;
    }
};
