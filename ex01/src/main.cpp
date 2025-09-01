/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:07:01 by jose-gon          #+#    #+#             */
/*   Updated: 2025/09/01 19:18:53 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Span.hpp>
#include <climits>
#include <ctime>

int main()
{
	{
		std::cout << "\033[32m----------Pruebas simples AddNumber----------\033[0m" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		try {
			sp.addNumber(2000);
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "\033[32m----------Pruebas simples AddNumbers----------\033[0m" << std::endl;
		
		std::vector<int> sp;
		Span sr = Span(25);

		std::srand(std::time(0));
		
		while (sp.size() < 25)
		{
			int n = rand() % 25;
			if (std::find(sp.begin(), sp.end(), n) == sp.end())
			{
				sp.push_back(n);
				std::cout << "--> " << sp.back() << std::endl;
			}
		}
		sr.addNumbers(sp.begin(), sp.end());
		std::cout << sr.shortestSpan() << std::endl;
		std::cout << sr.longestSpan() << std::endl;		
	}
	return 0;
}
