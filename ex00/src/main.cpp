/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 19:19:05 by jose-gon          #+#    #+#             */
/*   Updated: 2025/08/25 20:10:09 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <easyfind.hpp>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include "easyfind.hpp"

int main() {
    try {
        // Vector
        std::vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        std::cout << "Vector: " << *easyfind(v, 2) << std::endl;

        // List
        std::list<int> l;
        l.push_back(10);
        l.push_back(20);
        l.push_back(30);
        std::cout << "List: " << *easyfind(l, 30) << std::endl;

        // Deque
        std::deque<int> d;
        d.push_back(100);
        d.push_back(200);
        d.push_back(300);
        std::cout << "Deque: " << *easyfind(d, 200) << std::endl;

        // Set
        std::set<int> s;
        s.insert(5);
        s.insert(15);
        s.insert(25);
        std::cout << "Set: " << *easyfind(s, 15) << std::endl;

        // Map (busca en los values, no en las keys)
        std::map<std::string, int> m;
        m["uno"] = 1;
        m["dos"] = 2;
        m["tres"] = 3;
        std::map<std::string, int>::const_iterator it = easyfind(m, 3);
        std::cout << "Map: key=" << it->first << ", value=" << it->second << std::endl;

        // Prueba de excepción
        easyfind(v, 42);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
