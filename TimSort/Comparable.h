#pragma once
template <class T>class Comparable
{
protected:
	virtual int CompareTo(T item) = 0;
};

