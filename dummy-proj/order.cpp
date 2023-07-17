#include <order.h>
#include <iostream>

void Order::add_book(Book const& book)
{
    _books.emplace_back(book);
}

std::vector<Book> const& Order::books() const
{
    return _books;
}

Price Order::total() const
{
    auto total_price = Price{0, 0};
    for (auto& book : _books) {
        total_price += book.price();
    }
    return total_price;
}

void Order::print_summary()
{
    std::cout << "ORDER SUMMARY\n";
    for (auto& book : _books) {
        std::cout << "+ Book: " << book.title() << "\n";
    }
    std::cout << "TOTAL: " << this->total() << "\n";
}
