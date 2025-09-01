/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:11:21 by jose-gon          #+#    #+#             */
/*   Updated: 2025/09/01 19:15:04 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iomanip>
#include <iostream>
#include <exception>
#include <limits>
#include <algorithm>

class Span
{
	private:
		std::vector<int> _values;
		Span();
		//unsigned int _size;
	public:
		Span(unsigned int N);
		Span(Span const & obj);
		Span & operator=(Span const & obj);
		~Span();

		void addNumber(int val);
		
		template <typename T>
		void addNumbers(T begin, T end)
		{
			if (_values.size() + std::distance(begin, end) > _values.capacity())
				throw Span::NotEoughtException();
			else
				_values.insert(_values.end(), begin, end);
		}
					
		int shortestSpan();
		int longestSpan();

		class SpanIsFullException : public std::exception
		{
			public:
			const char* what() const throw() {return "Error: Span is full, there is no more room for more numbers";};
		};
		
		class NotEoughtException : public std::exception
		{
			public:
			const char* what() const throw() {return "Error: There are not enough numbers in span";};
		};
};

#endif

// Develop a Span class that can store a maximum of N integers. N is an unsigned int
// variable and will be the only parameter passed to the constructor.
// This class will have a member function called addNumber() to add a single number
// to the Span. It will be used in order to fill it. Any attempt to add a new element if there
// are already N elements stored should throw an exception.
// Next, implement two member functions: shortestSpan() and longestSpan()
// They will respectively find out the shortest span or the longest span (or distance, if
// you prefer) between all the numbers stored, and return it. If there are no numbers stored,
// or only one, no span can be found. Thus, throw an exception.
// Of course, you will write your own tests and they will be way more thorough than the
// ones below. Test your Span at least with a minimum of 10 000 numbers. More would be
// even better
