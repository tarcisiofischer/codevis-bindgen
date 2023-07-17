#ifndef DUMMY_PROJ_STORE_H
#define DUMMY_PROJ_STORE_H

#include <book.h>
#include <order.h>
#include <map>

class Store {
public:
    void add_book(std::string const& book, Price const& price, unsigned int quantity);
    Order create_order(std::vector<std::string> const& book_titles);

private:
    using Uid = unsigned long long;
    using BookTitle = std::string;
    struct BookDetails {
        Uid id;
        Book book;
        unsigned int quantity;
    };
    using Shelf = std::map<BookTitle, BookDetails>;

    Shelf _book_shelf;
};

#endif //DUMMY_PROJ_STORE_H
