/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:12:34 by snovaes           #+#    #+#             */
/*   Updated: 2022/09/04 17:42:56 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample2.class.hpp"
#include "Sample1.class.hpp"

int main(){

	Sample1 instance1('a', 42, 4.2f);
	Sample2 instance2('z', 13, 2.14f);
	
	return 0;
}
