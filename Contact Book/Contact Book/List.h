#pragma once
#include<iostream>
#include<string>
using namespace std;

template <typename T>
class List {
    T* array;
    int index;
    int size;
public:
    template <typename T>
    List(T*& ar, int& i, int& s) : index(i), size(s)
    {
        if (size == 0)
        {
            size++;
            s++;
        }
        array = new T[size];
        for (int i = 0; i < index; i++) { array[i] = ar[i]; }
    }

    ~List() {
        if (array != nullptr && size > 0)
        {
            delete[] array;
            //delete array;
            //array = nullptr;
        }

    }

    template <typename T>
    void addItem(T& t, int& curr_index) {
        if (curr_index < 0) {
            cout << "Error: Index out of bounds\n";
            return;
        }

        if (curr_index >= size) {
            // If the current index exceeds the size of the array, resize the array.
            int new_size = ++size; // Double the size.
            T** temp = new T * [1];
            temp[0] = new T[size];

            // Copy existing elements to the new array.
            for (int i = 0; i < index; i++) {
                temp[0][i] = array[i];
            }

            // Delete the old array and assign the new one.
            delete[] array;
            array = temp[0];
            size = new_size;
        }

        // Add the new element to the array.
        array[curr_index] = t;
        curr_index++;
        index++;
    }

    void removeItem(int& remove_index, int& curr_index) {
        if (remove_index < 0 || remove_index >= index)
        {
            cout << "Error: Index out of bounds\n";
            return;
        }

        T* temp = new T[size];
        for (int i = 0; i < remove_index; i++) { temp[i] = array[i]; }
        for (int i = remove_index + 1; i < index; i++) {
            temp[i - 1] = array[i];
        }
        curr_index--;
        index--; // Decrement the index after removing an item.
        if (array != nullptr)
            delete[] array;
        array = new T[size];
        {
            for (int i = 0; i < index; i++) { array[i] = temp[i]; }
        }
    }


    int getSize() { return size; }

    int getCurrentSize() { return index; }

    T*& getArray() {
        T* copyArray = new T[size];
        for (int i = 0; i < index; i++) { copyArray[i] = array[i]; }
        return copyArray;
    }
    int get_list_count() { return index; }
};
