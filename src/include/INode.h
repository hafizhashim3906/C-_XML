#pragma once

#include <string>

class INode;

#include "IVisitable.h"

/*abstract*/
class INode : public IVisitable
{
public:
    virtual std::string GetElementName() const = 0;
    virtual void print(const std::size_t indentLevel) const = 0;

    virtual bool isCategory(const std::string &categoryName) const = 0;
    virtual float getBookPrice() const = 0;
};
