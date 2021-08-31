#pragma once

#include <iostream>

#include "BaseNode.h"

class Category: public BaseNode
{
    std::string m_Name;

public:
    Category(): m_Name("") {};

    virtual std::string GetElementName() const override {
        return "Category";
    }

    virtual void print(const std::size_t indentLevel) const override {
        printIndent(indentLevel);
        std::cout << GetElementName() << "(" << getName() << ")" << std::endl;
    }

    virtual bool isCategory(const std::string &categoryName) const override {
        return m_Name == categoryName;
    }

    virtual float getBookPrice() const override {
        return 0.0f;
    }

    std::string getName() const {
        return m_Name;
    }

    void setName(std::string name) {
        m_Name = name;
    }
};
