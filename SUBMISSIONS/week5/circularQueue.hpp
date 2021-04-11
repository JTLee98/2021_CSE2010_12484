#pragma once

constexpr int CAPACITY = 5;

class cQueue
{
private:
	int m_data[CAPACITY];
	int m_front;
	int m_rear;
public:
	cQueue();
	~cQueue();

	int front() const;
	int rear() const;
	void enqueue(int p_data);
	bool isFull() const;
	bool isEmpty() const;
	void show() const;
	void deque();
};