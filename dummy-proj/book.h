#ifndef DUMMY_PROJ_BOOK_H
#define DUMMY_PROJ_BOOK_H

#include <string>

struct Price {
    int value;
    int cents;

    Price& operator+=(Price const& other)
    {
        auto tcents = this->cents + other.cents;
        this->value = this->value + other.value + (tcents / 100);
        this->cents = (tcents % 100);
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Price& price)
    {
        os << std::to_string(price.value) << std::string{"."} << std::to_string(price.cents);
        return os;
    }
};

class Book {
public:
    Book(std::string const& title, Price const& Price);

    std::string const& title() const;
    Price const& price() const;

    void set_price(Price const& new_price);

private:
    std::string _title;
    Price _price;
};

#endif //DUMMY_PROJ_BOOK_H
