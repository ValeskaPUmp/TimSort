#include "TimSortImpl.h"
#include <iostream>
#include "Item.h"
#include <array>
using namespace std;
template<typename T, int capacity>
static void TimSortImpl<T, capacity>::sort(array<T,capacity>& objects) {
	int minimal_distance = min_distance(MIN_Value_Of_Distance);
	for (int i = 0; i < capacity; ++i) {
		insertion_sort(objects, i, Math_MIN((i + MIN_Value_Of_Distance - 1), (capacity - 1)));
	}
	for (int i = minimal_distance; i < capacity; i+=2*i) {
		for (int j = 0; j < capacity; j+=2*j) {
			int middle = j +i - 1;
			int right = Math_MIN((j + 2 * i - 1), capacity - 1);
			if (middle < right) merge_sort(data, j, middle, right);
		}
	}
}
template<typename T, int capacity>
static void TimSortImpl<T, capacity>::insertion_sort(array<T, capacity>& data, int left, int right)
{
	for (int i = left + 1; i <= right; ++i) {
		T temporary = data[i];
		int k = i - 1;
		while (data[k] > temporary && k >= left) {
			data[k + 1] = data[k];
			--k;
		}

		data[k + 1] = temporary;
	}
}

template<typename T, int capacity>
static void TimSortImpl<T, capacity>::merge_sort(array<T, capacity>& data, int l, int m, int r)
{
	int length1 = r - m;
	int length2 = m - l + 1;
	array<T, length1> left_array =array<T, length2>();
	array<T, length2> right_array = array<T, length1>();
	for (int i = 0; i < length2; ++i) {
		left_array[i] = data[l + i];
	}
	for (int i = 0; i < length2; ++i) {
		right_array[i] = data[m + i + 1];
	}
	int k = 0;
	int c = 0;
	int koeff = l;
	while (c < length1 && k < length2) {
		if (left_array[k] <= right_array[c]) {
			data[koeff] = left_array[k];
			k++;
		}
		else {
			data[koeff] = right_array[c];
			c++;
		}
		koeff++;
	}
	while (k < length2) {
		data[koeff] = left_array[k];
		koeff++;
		k++;
	}
	while (c < length1) {
		data[koeff] = right_array[c];
		koeff++;
		c++;
	}
}

template<typename T, int capacity>
static void TimSortImpl<T, capacity>::min_distance(int& n)
{
	int r = 0;
	while (n >= MIN_Value_Of_Distance) {
		r |= (n & 1);
		n >>= 1;
	}
	n += r;
}

template<typename T, int capacity>
int TimSortImpl<T, capacity>::Math_MIN(int number1, int number2)
{
	return number1 > number2 ? number2 : number1;
}
