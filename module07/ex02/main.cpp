/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 10:25:48 by shonakam          #+#    #+#             */
/*   Updated: 2025/05/04 11:06:59 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Array.hpp>

#define MAX_VAL 750
// class mini {
//     public:
//         mini() : name(""), age(0) {}
//         std::string     name;
//         unsigned int    age;
// };

static void handout() {
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return ;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
}

static void defaultFunc()
{
    unsigned int size = 5;
    try {
        // default constructor
        Array<int> a;
        std::cout << "a.size() = " << a.size() << std::endl;

        // overloaded constructor
        Array<int> b(size);
        std::cout << "b.size() = " << b.size() << std::endl;
        for (unsigned int i = 0; i < b.size(); ++i)
            std::cout << "b[" << i << "] = " << b[i] << std::endl;

        // copy constructor
        b[0] = 10;
        Array<int> c(b);
        std::cout << "c[0] (copied) = " << c[0] << std::endl;
        b[0] = 99;
        std::cout << "After modifying b[0], c[0] = " << c[0] << std::endl;

        // assignment operator
        Array<int> d;
        d = c;
        std::cout << "d[0] (assigned) = " << d[0] << std::endl;
        c[0] = 77;
        std::cout << "After modifying c[0], d[0] = " << d[0] << std::endl;

        // self assignment
        Array<int> self(2);
        self[0] = 123;
        self = self;
        std::cout << "After self assignment, self[0] = " << self[0] << std::endl;

        // out of range access
        try {
            std::cout << b[size + 1] << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Unhandled exception: " << e.what() << std::endl;
    }
}


static void genericsTest()
{
    
    unsigned int size = 3;
    try {
        Array<long> longArray(size);
        for (unsigned int i = 0; i < longArray.size(); ++i) {
            longArray[i] = static_cast<long>(i) * 1000;
            std::cout << "longArray[" << i << "] = " << longArray[i] << std::endl;
        }

        Array<double> doubleArray(size);
        for (unsigned int i = 0; i < doubleArray.size(); ++i) {
            doubleArray[i] = static_cast<double>(i) * 1.1;
            std::cout << "doubleArray[" << i << "] = " << doubleArray[i] << std::endl;
        }
        
        Array<std::string> stringArr(size);
        stringArr[0] = "Hello";
        stringArr[1] = "World";
        stringArr[2] = "Generics!";
        for (unsigned int i = 0; i < stringArr.size(); ++i) {
            std::cout << "stringArr[" << i << "] = " << stringArr[i] << std::endl;
        }

        // Array<mini> miniArr(size);
        // miniArr[0].name = "Alice";
        // miniArr[0].age = 25;
        // miniArr[1].name = "Bob";
        // miniArr[1].age = 30;
        // miniArr[2].name = "Charlie";
        // miniArr[2].age = 35;
        // for (unsigned int i = 0; i < miniArr.size(); ++i) {
        //     std::cout << "miniArr[" << i << "] = " << miniArr[i].name << ", " << miniArr[i].age << std::endl;
        // }
        
    } catch (const std::exception& e) {
        std::cerr << "Unhandled exception: " << e.what() << std::endl;
    }
}

int main(int, char**)
{
    handout();
    defaultFunc();
    genericsTest();
}