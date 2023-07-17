#include <store.h>
#include <order.h>

int main()
{
    auto my_store = Store{};
    my_store.add_book("The lord of the wings", Price{6, 99}, 7);
    my_store.add_book("Introduction to C++", Price{36, 99}, 5);
    my_store.add_book("Introduction to Rust", Price{36, 99}, 1);

    auto order1 = my_store.create_order({
        "The lord of the wings",
        "Introduction to C++"
    });
    order1.print_summary();
    return 0;
}
