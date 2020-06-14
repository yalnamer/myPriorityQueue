#pragma once

#include <iostream>


class Person
{

public:
	std::string name;
	int priority;




	Person(std::string name = "NoName",int priority = -1)
	{
		this->name = name;
		this->priority = priority;
	}

};