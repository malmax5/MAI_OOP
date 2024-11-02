#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include "Figure.hpp"

template <typename TFigure>
class Array {
public:
    Array() : size(0), capacity(1) {
        data = std::make_unique<std::shared_ptr<TFigure>[]>(capacity);
    }

    void push_back(std::shared_ptr<TFigure> element) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        data[size++] = std::move(element);
    }

    void remove(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        for (size_t i = index; i < size - 1; ++i) {
            data[i] = std::move(data[i + 1]);
        }
        --size;
    }

    double totalArea() const {
        double total = 0.0;
        for (size_t i = 0; i < size; ++i) {
            total += data[i]->CalculateArea();
        }
        return total;
    }

    void printInfo() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << "Figure " << i << ":\n";
            std::cout << "Center: " << data[i]->CalculateCentroid() << "\n";
            std::cout << "Vertices: " << *data[i] << "\n";
            std::cout << "Area: " << data[i]->CalculateArea() << "\n\n";
        }
    }

    size_t getSize() const {
        return size;
    }

private:
    void resize(size_t newCapacity) {
        auto newData = std::make_unique<std::shared_ptr<TFigure>[]>(newCapacity);
        for (size_t i = 0; i < size; ++i) {
            newData[i] = std::move(data[i]);
        }
        data = std::move(newData);
        capacity = newCapacity;
    }

    std::unique_ptr<std::shared_ptr<TFigure>[]> data;
    size_t size;
    size_t capacity;
};