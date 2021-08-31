#pragma once

#include <iomanip>
#include <iostream>

#include "BaseNode.h"

class Book: public BaseNode
{
    std::string m_Title;
    std::string m_Author;
    int         m_Year;
    float       m_Price;

public:
    Book(): m_Title(""), m_Author(""), m_Year(0), m_Price(0.0) {};

    virtual std::string GetElementName() const override {
        return "Book";
    }

    virtual void print(std::size_t indentLevel) const override {
        printIndent(indentLevel);
        std::cout << GetElementName() << "(" << getTitle() << ")" << std::endl;
        printIndent(indentLevel + 1);
        std::cout << "Author:     " << getAuthor() << std::endl;
        printIndent(indentLevel + 1);
        std::cout << "Year:       " << getYear() << std::endl;
        printIndent(indentLevel + 1);
        std::cout << std::setprecision(2) << std::fixed;
        std::cout << "Price in $: " << getPrice() << std::endl;
    }

    virtual bool isCategory(const std::string &/*categoryName*/) const override {
        return false;
    }

    virtual float getBookPrice() const override {
        return getPrice();
    }

    std::string getTitle() const {
        return m_Title;
    }

    void setTitle(std::string name) {
        m_Title = name;
    }

    std::string getAuthor() const {
        return m_Author;
    }

    void setAuthor(std::string name) {
        m_Author = name;
    }

    int getYear() const {
        return m_Year;
    }

    void setYear(int year) {
        m_Year = year;
    }

    float getPrice() const {
        return m_Price;
    }

    void setPrice(float price) {
        m_Price = price;
    }
};
