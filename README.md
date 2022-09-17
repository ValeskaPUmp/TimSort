![Typing SVG](https://readme-typing-svg.herokuapp.com?font=Fira+Code&duration=2000&pause=10000&color=F76357FF&center=true&vCenter=true&width=512&lines=Tim+Sort)

## `Structure`
- *TimSort.cpp* : It`s directly the main class.
- *TimSortImpl.cpp and TimSortimpl.h* :It`s actually the implementation of TimSort.
- *Item.cpp ans Item.h* : It`s class for show example of working sort algorithm.

## `Explanation`

- Tim Sort algorithm has been created by Tim Peters in 2002.He is a hybrid sorting algorithm, that include in self the Insertion Sort and Merge Sort.

[![Typing SVG](https://readme-typing-svg.herokuapp.com?font=Eras+Bold+ITC&pause=1000&color=6963F7&center=true&vCenter=true&width=512&lines=PART+I;Calculation+of+the+Min+Distance)](https://git.io/typing-svg)

Firstly,we should make the method min_distance that will calculate a minimum length the subarrays which appear after split.

Eigenly,implementation:
```c++
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
```
Secondly,this value is determinate based on N which equal to the amount of facilities in collection.
Here we gonna take the six most sagnificant bits and add 1 bit,if the remaining least significant bits contain at least one off bit.

[![Typing SVG](https://readme-typing-svg.herokuapp.com?font=Eras+Bold+ITC&pause=1000&color=F7B530&center=true&vCenter=true&width=512&lines=PART+II;Splitting+into+subarrays+and+their+sorting)](https://git.io/typing-svg)

Therefore,we have an input array with N size and a calculated min_distance.Let devide algorithm on few steps:

1.`The base address of the current element is set at the beginning of the input array.`

2.`I just started with current array and searched min_distance for him`
```c++
for (int i = 0; i < capacity; ++i) {
		insertion_sort(objects, i, Math_MIN((i + MIN_Value_Of_Distance - 1), (capacity - 1)));
	}
```
3.`Then the insertion sort starts.`

4.`The base address of the current element is set at the element following this run.`

5.`If the end of the input array has not been reached, go to point 2, otherwise it is the end of this step.`

```c++
for (int i = minimal_distance; i < capacity; i+=2*i) {
		for (int j = 0; j < capacity; j+=2*j) {
			int middle = j +i - 1;
			int right = Math_MIN((j + 2 * i - 1), capacity - 1);
			if (middle < right) merge_sort(objects, j, middle, right);
		}
	}
```

6.`By including,default implementation of Insertion Sort:`
```c++
template<typename T, int capacity>
static void TimSortImpl<T, capacity>::insertion_sort(std::array<T, capacity>& data, int left, int right)
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
```

7.`And Merge Sort:`
```c++
template<typename T, int capacity>
static void TimSortImpl<T, capacity>::merge_sort(std::array<T, capacity>& data, int l, int m, int r)
{
	int length1 = r - m;
	int length2 = m - l + 1;
	std::array<T, length1> left_array;
	std::array<T, length2> right_array;
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
```
## `Complexity`
| Case          | Complexity    |
| ------------- |:-------------:|
| Best case     | O(n)          |
| Average       | O(n*log(n))   |
| Worse case    |O(n*log(n))    |
|Space          |O(n)           |
|Stable         |Yes            |
## `Additional explanation video by Timurul Hoque Kazi`
[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/_dlzWEJoU7I/0.jpg)](http://www.youtube.com/watch?v=_dlzWEJoU7I)














