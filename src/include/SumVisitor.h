#pragma once

#include <iomanip>
#include <iostream>
#include <string>

#include "IVisitor.h"

class SumVisitor: public IVisitor
{
    float m_Sum;
    std::string m_CatergoryName;
    bool m_IsCategorySubtree;

public:

    SumVisitor(std::string categoryName): m_Sum(0.0F), m_CatergoryName(categoryName) {};

    virtual void VisitBefore(INode &node) {
        if(node.isCategory(m_CatergoryName))
         {
            m_IsCategorySubtree = true;
        }
        if( m_IsCategorySubtree )
        {
            m_Sum += node.getBookPrice();
        }
    }

    virtual void VisitAfter(INode &node) {
        if(node.isCategory(m_CatergoryName))
         {
            m_IsCategorySubtree = false;
        }
    }

    float getSum() { return m_Sum; }
};
