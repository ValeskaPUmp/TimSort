
#pragma once
#include <iostream>
#include "Item.h"
#include <array>
template <typename T,int capacity> 
class TimSortImpl
{
public:
	static void sort(array<T,capacity>& objects);
private:
	static void insertion_sort(array<T, capacity>& data, int left, int right);
	static void merge_sort(array<T, capacity>& data, int l, int m, int r);
	static void min_distance(int& n);
	const static int MIN_Value_Of_Distance = 32;
	static int Math_MIN(int number1, int number2);
};
