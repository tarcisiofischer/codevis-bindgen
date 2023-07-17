#include <book.h>

Book::Book(
    std::string const& title,
    Price const& price)
    : _title(title)
    , _price(price)
{}

std::string const& Book::title() const
{
    return _title;
}

Price const& Book::price() const
{
    return _price;
}

void Book::set_price(Price const& new_price)
{
    _price = new_price;
}
