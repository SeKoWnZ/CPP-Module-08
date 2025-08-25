/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:07:07 by jose-gon          #+#    #+#             */
/*   Updated: 2025/08/25 20:13:52 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iterator>
#include <algorithm>
#include <stdexcept>
#include <map>

template <typename T>
typename T::const_iterator easyfind(const T& container, int val)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), val);
	if (it == container.end())
		throw std::runtime_error("Value not found in the container");
	return it;
}

template <typename U, typename V>
typename std::map<U,V>::const_iterator easyfind(const std::map<U,V>& container, int val)
{
	typename std::map<U,V>::const_iterator it;
	for (it = container.begin(); it != container.end(); it++)
	{
		if (it->second == val)
			return it;
	}
	throw std::runtime_error("Value not found in the container");
}

#endif