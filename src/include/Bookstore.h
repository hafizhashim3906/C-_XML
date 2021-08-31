#pragma once

#include <iostream>

#include "BaseNode.h"

class Bookstore: public BaseNode
{
public:
    virtual std::string GetElementName() const override {
        return "Bookstore";
    }

    virtual void print(const std::size_t indentLevel) const override {
        printIndent(indentLevel);
        std::cout << GetElementName() << std::endl;
    }

    virtual bool isCategory(const std::string &/*categoryName*/) const override {
        return false;
    }

    virtual float getBookPrice() const override {
        return 0.0f;
    }
};

