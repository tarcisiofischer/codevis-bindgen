#include <store.h>
#include <stdexcept>

void Store::add_book(std::string const& title, Price const& price, unsigned int quantity)
{
    auto uid = _book_shelf.size();
    if (_book_shelf.contains(title)) {
        auto& desc = _book_shelf.at(title);
        desc.quantity += quantity;
        desc.book.set_price(price);
        return;
    }

    _book_shelf.emplace(title, BookDetails{uid, Book{title, price}, quantity});
}

Order Store::create_order(std::vector<std::string> const& book_titles)
{
    auto order = Order{};
    for (auto& title : book_titles) {
        if (!_book_shelf.contains(title)) {
            throw std::runtime_error("Book not found on shelf.");
        }
        auto& desc = _book_shelf.at(title);
        if (desc.quantity == 0) {
            throw std::runtime_error("Book register found, but there are 0 in the shelf.");
        }

        desc.quantity -= 1;
        order.add_book(desc.book);
    }
    return order;
}
