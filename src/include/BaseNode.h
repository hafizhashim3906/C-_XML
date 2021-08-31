#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

#include "INode.h"

class BaseNode : public INode
{
    vector<unique_ptr<INode>> m_Children;

public:
    virtual void setChildren(vector<unique_ptr<INode>> children) {
        m_Children = move(children);
    }

    virtual vector<INode*> getChildren() {
        vector<INode*> out(m_Children.size());
        transform(m_Children.begin(), m_Children.end(), out.begin(),
                [](unique_ptr<INode> &item) -> INode * {
                return item.get();
                });
        return out;
    }

    virtual void Accept(IVisitor &visitor) {
        visitor.VisitBefore(*this);
        for (auto &item : m_Children) {
            item->Accept(visitor);
        }
        visitor.VisitAfter(*this);
    }

    void printIndent(std::size_t indentLevel) const {
        for (std::size_t i = 0; i < indentLevel; ++i) {
            std::cout << "\t";
        }
    }
};
