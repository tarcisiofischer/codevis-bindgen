#ifndef DUMMY_PROJ_ORDER_H
#define DUMMY_PROJ_ORDER_H

#include <book.h>
#include <vector>
#include <sstream>

class Order {
public:
    void add_book(Book const& book);
    std::vector<Book> const& books() const;
    Price total() const;
    void print_summary();

private:
    std::vector<Book> _books;
};

#endif //DUMMY_PROJ_ORDER_H
