#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
template <class T>
class MaxPQ {
public:
	virtual~MaxPQ() {}
	virtual bool IsEmpty() const = 0;
	virtual const T& Top() const = 0;
	virtual void Push(const T&) = 0;
	virtual void Pop() = 0;
};
template <class T>
class Maxheap : public MaxPQ <T > {
public:
	Maxheap(int); // constructor
	Maxheap(); // default constructor: capacity를 임의로 설정. 
	~Maxheap();//파괴자
	void Push(const T& e);
	void Pop();
	bool IsEmpty() const { return (heapSize == 0); } // ?? 채우기
	const T& Top() const { return heap[1]; } // ?? 채우기
	template <class T2> friend ostream& operator<<(ostream&, Maxheap<T2>&);
private:
	void ChangeSize1D(T*&, int, int);
	T* heap; // element array
	int heapSize; // #elements in heap
	int capacity; // size of the array heap
};
template <class T>
Maxheap<T>::Maxheap()
{
	heapSize = 0;
	capacity = 10;
	heap = new T[capacity + 1];
}
template <class T>
Maxheap<T>::Maxheap(int t)
{
	if (t < 1) throw "capacity must be >= 1";
	heapSize = 0;
	capacity = t;
	heap = new T[capacity + 1];
}
template <class T>
ostream& operator<<(ostream& os, Maxheap<T>& H) {
	os << "<Heap Contents>";
	for (int i = 1; i < H.heapSize; i++) {
		os << i << ":" << H.heap[i] << " ";
	}
	os << endl;
	return os;
}
template <class T>
void Maxheap<T>::Push(const T& e)
{// Insert e into the max heap.
	if (heapSize == capacity) {// double the capacity
		ChangeSize1D(heap, capacity, 2 * capacity);
		capacity *= 2;
	}
	int currentNode = ++heapSize;
	while (currentNode != 1 && heap[currentNode / 2] < e)
	{// bubble up
		heap[currentNode] = heap[currentNode / 2]; // move parent down
		currentNode /= 2;
	}
	heap[currentNode] = e;
}
template <class T>
void Maxheap<T>::Pop()
{// Delete max element.
	if (IsEmpty()) throw "heap is empty.Cannot delete.";
	heap[1].~T(); // delete max element
	T lastE = heap[heapSize--]; // remove last element from heap
	// trickle down
	int currentNode = 1; // root
	int child = 2; // a child of currentNode
	while (child <= heapSize) // child가 있는 경우
	{ // set child to larger child of currentNode
		if (child < heapSize && heap[child] < heap[child + 1]) child++;
		if (lastE >= heap[child]) break; // can we put lastE in currentNode?
		heap[currentNode] = heap[child]; // move child up
		currentNode = child; child *= 2; // move down a level
	}
	heap[currentNode] = lastE;
}
template <class T>
Maxheap<T>::~Maxheap() // destructor
{
	if (heapSize) delete[] heap;
}
template <class T>
void Maxheap<T>::ChangeSize1D(T*& a, int oldsize, int newSize)
{
	if (newSize < 0) throw "New length must be >= 0";
	int* temp = new int[newSize];
	int number = min(oldsize, newSize);
	copy(a, a + number + 1, temp);
	delete[] a;
	a = temp;
}
int main() {
	int* commandarr;
	int command;
	Maxheap <int> mpq;
	scanf("%d", &command);
	commandarr = new int[command];
	for (int i = 0; i < command; i++) {
		scanf("%d", &commandarr[i]);
	}
	for (int i = 0; i < command; i++) {
		if (commandarr[i] == 0 && !mpq.IsEmpty()) {
			printf("%d\n", mpq.Top());
			mpq.Pop();
		}
		else if (commandarr[i] == 0 && mpq.IsEmpty()) {
			printf("0\n");
		}
		else {
			mpq.Push(commandarr[i]);
		}
	}
}