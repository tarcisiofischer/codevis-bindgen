#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <store.h>
#include <order.h>
#include <book.h>

namespace py = pybind11;

PYBIND11_MODULE(dummy, m) {
    py::class_<Store>(m, "Store")
            .def(py::init<>())
            .def("add_book", &Store::add_book)
            .def("create_order", &Store::create_order)
            ;
    py::class_<Book>(m, "Book")
            //.def(py::init<>())
            .def("price", &Book::price)
            .def("set_price", &Book::set_price)
            .def("title", &Book::title)
            ;
    py::class_<Price>(m, "Price")
            .def(py::init<int, int>())
            ;
    py::class_<Order>(m, "Order")
            .def(py::init<>())
            .def("books", &Order::books)
            .def("print_summary", &Order::print_summary)
            .def("total", &Order::total)
            .def("add_book", &Order::add_book)
            ;
}
