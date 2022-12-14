#include <iostream>
//#include <vector>
//#include <iterator>

#include "array.h"
#include "vector.h"

struct Vector3 {
	float x = 0.0f, y = 0.0f, z = 0.0f;
	int *m_MemoryBlock = nullptr;

	Vector3() {
		m_MemoryBlock = new int[5];
	}
	Vector3(float scalar) : x(scalar), y(scalar), z(scalar) {
		m_MemoryBlock = new int[5];
	}
	Vector3(float x, float y, float z) : x(x), y(y), z(z) {
		m_MemoryBlock = new int[5];
	}
	Vector3(const Vector3 &other) = delete;

	Vector3(Vector3 &&other) : x(other.x), y(other.y), z(other.z) {
		m_MemoryBlock = other.m_MemoryBlock;
		other.m_MemoryBlock = nullptr;
		std::cout << "Move\n";
	}
	~Vector3() {
		std::cout << "Destroy\n";
		delete[] m_MemoryBlock;
	}
	Vector3 &operator=(const Vector3 &other) = delete;
	Vector3 &operator=(Vector3 &&other) {
		m_MemoryBlock = other.m_MemoryBlock;
		other.m_MemoryBlock = nullptr;
		std::cout << "Move\n";
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}
};

template <typename T> void PrintVector(const Vector<T> &vector) {
	for (size_t i = 0; i < vector.Size(); i++) {
		std::cout << vector[i] << std::endl;
	}
	std::cout << "----------------------------" << std::endl;
}

template <> void PrintVector(const Vector<Vector3> &vector) {
	for (size_t i = 0; i < vector.Size(); i++) {
		std::cout << vector[i].x << ", " << vector[i].y << ", "
			  << vector[i].z << std::endl;
	}
	std::cout << "----------------------------" << std::endl;
}

int main() {
	Array<std::string, 2> data;
	data[0] = "Cherno";
	data[1] = "C++";

	{
		Vector<Vector3> vector;
		/*	vector.PushBack(Vector3(1.0f));
			vector.PushBack(Vector3(2, 3, 4));
			vector.PushBack(Vector3());
		*/
		vector.EmplaceBack(1.0f);
		vector.EmplaceBack(2, 3, 4);
		vector.EmplaceBack(5, 3, 4);
		vector.EmplaceBack();
		vector.PopBack();
		vector.PopBack();
		PrintVector(vector);

		vector.EmplaceBack(0, 5, 4);
		vector.EmplaceBack(2, 3, 5);
		PrintVector(vector);

		vector.Clear();
		PrintVector(vector);
		vector.EmplaceBack(7, 5, 4);
		vector.EmplaceBack(2, 3, 5);
		PrintVector(vector);
		PrintVector(vector);
	}
	Vector<int> intVector;
	intVector.PushBack(5);
	intVector.EmplaceBack(2);
	intVector.EmplaceBack(2);
	intVector.EmplaceBack(2);
	PrintVector(intVector);
	intVector.EmplaceBack(2);
	intVector.EmplaceBack(2);
	intVector.PopBack();
	PrintVector(intVector);
	intVector.Clear();
	{
		Vector<int> values;
		values.EmplaceBack(1);
		values.EmplaceBack(2);
		values.EmplaceBack(3);
		values.EmplaceBack(4);
		values.EmplaceBack(5);
		
		std::cout << "Not using iterators:\n";
		for (size_t i = 0; i < values.Size(); i++){
			std::cout << values[i] << std::endl;
		}
		
		std::cout << "Range-based for loop\n";
		for (int value : values)
			std::cout << value << std::endl;
		
		std::cout << "Iterators:\n";
		for (Vector<int>::Iterator it = values.begin(); 
			it != values.end(); it++)
			std::cout << *it << std::endl;
		std::cout << "----------------------------" << std::endl;
	}
	{
		Vector<std::string> values;
		values.EmplaceBack("1");
		values.EmplaceBack("2");
		values.EmplaceBack("3");
		values.EmplaceBack("Soraia");
		values.EmplaceBack("4");
		values.EmplaceBack("5");
		
		std::cout << "Not using iterators:\n";
		for (size_t i = 0; i < values.Size(); i++){
			std::cout << values[i] << std::endl;
		}
		
		std::cout << "Range-based for loop\n";
		for (auto& value : values)
			std::cout << value << std::endl;
		
		std::cout << "Iterators:\n";
		for (Vector<std::string>::Iterator it = values.begin(); 
			it != values.end(); it++)
			std::cout << *it << std::endl;
	}
#if 0
	{
		std::vector<int> values = {1,2,3,4,5};
		
		for (int i = 0; i < values.size(); i++){
			std::cout << values[i] << std::endl;
		}
		
		for (int value : values)
			std::cout << value << std::endl;
		for (std::vector<int>::iterator it = values.begin(); it != values.end(); it++)
			std::cout << *it << std::endl;
	}
#endif
	std::cin.get();
}