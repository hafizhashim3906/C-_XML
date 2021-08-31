#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <rapidxml.hpp>

using namespace std;
using namespace rapidxml;

#include "Book.h"
#include "Bookstore.h"
#include "Category.h"
#include "PrintVisitor.h"
#include "SumVisitor.h"

vector<unique_ptr<INode>> GetBooks(xml_node<>* category) {
    vector<unique_ptr<INode>> booklist;

    for (xml_node<>* n = category->first_node("book"); n != nullptr; n = n->next_sibling("book")) {
        unique_ptr<Book> book(new Book());

        xml_node<>* titleNode = n->first_node("title");
        if (titleNode != nullptr) {
            book->setTitle(titleNode->value());
        }
        xml_node<>* authorNode = n->first_node("author");
        if (authorNode != nullptr) {
            book->setAuthor(authorNode->value());
        }
        xml_node<>* priceNode = n->first_node("price");
        if (priceNode != nullptr) {
            book->setPrice(static_cast<float>(atof(priceNode->value())));
        }
        xml_node<>* yearNode = n->first_node("year");
        if (yearNode != nullptr) {
            book->setYear(atoi(yearNode->value()));
        }

        booklist.push_back(move(book));
    }
    return booklist;
}

void PrintBookstore(Bookstore& bookstore) {
    cout << bookstore.GetElementName() << endl;
    vector<INode *> categories = bookstore.getChildren();
    for (auto *item : categories) {
        Category *category = dynamic_cast<Category*>(item);
        if (category != nullptr) {
            cout << "\t" << category->GetElementName() << "(" << category->getName() << ")" << endl;
            vector<INode *> books = category->getChildren();
            for (auto &item : books) {
                Book *book = dynamic_cast<Book *>(item);
                if (book != nullptr) {
                    cout << "\t\t" << book->GetElementName() << "(" << book->getTitle() << ")" << endl;
                    cout << "\t\t\t" << "Author:     " << book->getAuthor() << endl;
                    cout << "\t\t\t" << "Year:       " << book->getYear() << endl;
                    cout << setprecision(2) << fixed;
                    cout << "\t\t\t" << "Price in $: " << book->getPrice() << endl;
                }
            }
        }
    }
}

int main()
{
    // 1. Read in XML file
    ifstream f("Library.xml", ios::in);
    vector<char> xmlContents((istreambuf_iterator<char>(f)), istreambuf_iterator<char>());
    xmlContents.push_back('\0');

    // 2. Parse XML document
    xml_document<> xmlDoc; //* create an xml document object.
    xmlDoc.parse<0>(&xmlContents[0]); //* load the XML document from the specified file.

    // 3. fill in data model
    Bookstore bookstore;

    xml_node<> *root = xmlDoc.first_node("bookstore");

    vector<unique_ptr<INode>> categories;
    for (xml_node<> *n = root->first_node("category"); n != nullptr; n = n->next_sibling("category")) {
        unique_ptr<Category> category(new Category());
        xml_attribute<>* a = n->first_attribute("name");
        if (a != nullptr) {
            category->setName(a->value());
            auto children = GetBooks(n);
            category->setChildren(move(children));

            categories.push_back(move(category));
        }
    }
    bookstore.setChildren(move(categories));

    // 4. print output by function
    PrintBookstore(bookstore);

    // 5 Create and apply visitors for...

    // 5.1 ...printing:
    PrintVisitor printVisitor;
    bookstore.Accept(printVisitor);

    // 5.2 ...building sum by category:
    SumVisitor sumVisitor("web");
    bookstore.Accept(sumVisitor);
    cout << "Sum of prices for books about \"web\" is " << sumVisitor.getSum() << endl;

    // Done!
    return 0;
}
