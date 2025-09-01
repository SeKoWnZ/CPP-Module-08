/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:25:49 by jose-gon          #+#    #+#             */
/*   Updated: 2025/09/01 19:11:40 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Span.hpp>

Span::Span(){}

Span::Span(unsigned int N)
{
	_values.reserve(N);
}

Span::Span(Span const & obj)
{
	*this = obj;
}

Span & Span::operator=(Span const & obj)
{
	if (this != &obj)
		_values = obj._values;
	return *this;
}

Span::~Span(){};

void Span::addNumber(int val)
{
	if (_values.size() < _values.capacity())
		_values.push_back(val);
	else 
		throw Span::SpanIsFullException();
}

int Span::shortestSpan()
{
	if (_values.size() < 2)
		throw Span::NotEoughtException();
	std::vector<int> sorted = _values;
	std::sort(sorted.begin(), sorted.end());
	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sorted.size(); i++)
	{
		int diff = sorted[i] - sorted[i - 1];
		if (diff < minSpan)
			minSpan = diff;
	}
	return minSpan;
}

int	Span::longestSpan()
{
	if (_values.size() < 2)
		throw Span::NotEoughtException();
	// std::vector<int> sorted = _values;
	// std::sort(sorted.begin(), sorted.end());
	// int maxSpan = sorted[sorted.size() - 1] - sorted[0];
	int minVal = *std::min_element(_values.begin(), _values.end());
	int maxVal = *std::max_element(_values.begin(), _values.end());
	return maxVal - minVal;
}
