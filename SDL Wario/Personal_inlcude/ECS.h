#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Entity;
class Component; // declaring the classes

using ComponentTypeID = std::size_t;

inline ComponentTypeID getUniqueComponentID() {
	static ComponentTypeID lastID = 0u;
	return lastID++;
}

template<typename T>
inline ComponentTypeID getComponentTypeID() noexcept { //noexcept if the function were to throw an error it ignores it
	static_assert(std::is_base_of<Component, T>::value, "Type Not base on Component!"); //is basically an asseertion (an assumption) ran at compile time 
	static const ComponentTypeID typeID = getUniqueComponentID();						//is_base_of checks if <base, dervived> "base" is the base class for "Derived"..
	return typeID;
}

constexpr ComponentTypeID MaxEntities = 5000;
constexpr ComponentTypeID Max_Components = 32;

using ComponenetBitSet = std::bitset<Max_Components>;
using ComponentList = std::array<Component*, Max_Components>;
