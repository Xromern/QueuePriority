#pragma once
#include<string>
#include<ctime>
#include<fstream>
#include<ostream>
#include<functional>
#include<exception>

#include"QueueException.h"
using namespace System;
using namespace Runtime::InteropServices;
#pragma warning(disable : 4661)
template<typename Type>
class QueuePriority
{
private:

	// �������
	Type * Wait;
	// ���������
	int * Pri;
	// ������������ ������ �������
	int MaxQueueLength;
	// ������� ������ �������
	int* QueueLength;
	//������� ���� �� ������ ��� ������ � ������
	Type* temp_wait;
	int* temp_priority;
	Type* temp_item_wait;
	int* temp_item_priority;
	int* TempQueueLength;

	//�������� �� �������� �������� �����������
	bool check = false;

	//������� ���'��� �� �������� ����, �� ������ ��� ������ � ������
	//(����������� ���������� �������� �����,����������� �������
	//�������� �����, ��������� �������� �����).
	void ini_field_temp();

	//�������� ���'��� ��� ���� ������� ����� void ini_field_temp();
	void delete_field_temp();

	//(����������� ���������� �������� �����,����������� �������
	//�������� �����, ��������� �������� �����).
	void show(Type* _wait, int* _priority, int* TempQueueLength, int* temp_priority, Type* temp_wait, int*);

	//����������� ������/������� ����������� �������� �����
	//bool b=true - ������� ����������
	//bool b=false - ������� ����������
	int front_back(const int* priority, const int* queue_length, bool b);

	//������ ������� �������� � ����
	void setQueueLength(int n);

	//��������� ������ ����� �� ������� ������� � ���������
	//���� true - ������� �������, ���� false - ���������
	int split_queue(std::string, bool);

	//������� ��� ���������� �����
	void reQeueu(int s);

public:
	QueuePriority();
	QueuePriority(const QueuePriority<Type>&);
	QueuePriority(int m);
	~QueuePriority();

	//����������� �������� ����� �����
	static const int MaximumPossibleQueueLength = 1250;

	//  ������� ��������
	int size()const;

	// ������� �������� true, ���� ����� �����;
	bool empty();

	// �������� �� ������������ �����
	bool full()const;

	//��������� �� ������ �������;
	int front();

	//��������� �� ������� �������;
	int  back();

	//���� ���������� � ����� ������;
	void swap(QueuePriority& right);

	// ������ ����� ������� � ����� �����;
	void push(Type c, int p);

	// �������� ������ �������;
	int pop();

	//�������� ����� ����������� �� ���������
	System::String^ show_priority();

	//������ �������
	int find(int item);

	//���� ��� ��������
	Type accumulate();

	//������ ��� ��������. �������� � ������� �� ��������� �������� �����.
	void for_each(std::function<void(Type&)> func);

	//������ ��� ��������. �������� � ������� �� �������� �������� �����.
	void for_each(std::function<void(Type)> func);

	//��������  ������� ������� �������� � ����/����������� ������ �������� � ����
	System::String^ state_queue();

	//������� ����������� �����
	float percentage_filled_queue();

	//������� �����
	void cleaning_queue();

	//����������� ������� � ����
	int max();

	//�������� ������� � ����
	int min();

	//�������� ���������� �����
	void random_filling();

	//�������� ������� ����� �� �������
	Type getWait(int index)const;

	//�������� ������� ����� �� �������
	int getPri(int index)const;

	int get_queue_len() const{
		return *QueueLength;
	}

	//�������� ���������� ��� ������� ����� �� �������
	//(��������, �������, ������)
	String^ infoItem(int index);

	int getMaxQueueLength()const;
	//������ ������� �������� �����
	Type& begin();

	//������ ���������� �������� �����
	Type& end();

	//�������� ����� ������� ���, ���� ����� ����� �� ����� ���
	QueuePriority* operator=(QueuePriority& right);

	//�������� ����� ������� ���
	void operator^(const QueuePriority& right);

	//�������� �� ������ ����
	bool operator==(const QueuePriority& right);

	//�������� �� �������� ����
	bool operator!=(const QueuePriority& right);

	//��������� ���� ���� � ����
	QueuePriority* operator+(QueuePriority<Type> &right);

	//���� �������
	void operator|(QueuePriority<Type> &right);

	//����� ����� � ����<<
	template <typename T1>
	friend  std::ofstream & operator<<(std::ofstream & fs, const QueuePriority<T1>* f);

	//����� ����� � ����>>
	template <typename T1>
	friend  std::ofstream & operator>>(std::ofstream & fs, const QueuePriority<T1>* f);

	//���� ����� � �����,� ����� � �����
	template <typename T1>
	friend  std::ifstream & operator<<(std::ifstream & fs, QueuePriority<T1>* f);

	//���� ����� � �����,� � �������� ���� �����
	template <typename T1>
	friend  QueuePriority<T1>* operator>>(std::ifstream & fs, QueuePriority<T1>*f);
};
template QueuePriority<int>;
template QueuePriority<float>;
template QueuePriority<double>;

template<typename T1>
inline std::ofstream  & operator<<(std::ofstream  & of, const QueuePriority<T1>* queue)
{
	std::string f = " ";
	for (int i = 0; i < queue->size(); i++) {
		of << std::to_string(queue->Wait[i]) + f + std::to_string(queue->Pri[i]) << std::endl;
	}
	return of;
}

template<typename T1>
inline std::ofstream  & operator>>(std::ofstream  & fs, const QueuePriority<T1>* queue)
{
	std::string f = " ";
	for (int i = 0; i < queue->size(); i++) {
		fs << std::to_string(queue->Wait[i]) + f + std::to_string(queue->Pri[i]) << std::endl;
	}
	return fs;
}

template<typename T1>
inline std::ifstream & operator<<(std::ifstream  & is, QueuePriority<T1>* queue) {
	int counter = 0;
	std::string s;
	std::string er;
	while (!is.eof())
	{
		getline(is, s);
		s.length()>2?counter++:0;
		er = std::to_string(counter);
		if (counter > queue->MaximumPossibleQueueLength) {
			throw QueueException("����� ������� ������. ", 3);
		}
	}

	if (counter > queue->getMaxQueueLength()) {
		throw QueueException("����� �������� ������. ʳ������ �������� " + er, 3);
	}
	is.clear();
	is.seekg(0, std::ios::beg);
	queue->cleaning_queue();

	while (!is.eof())
	{
		getline(is, s);
		if (s.length() > 2) {
			queue->push(queue->split_queue(s, true), queue->split_queue(s, false));
		}
	}
	return is;
}

template<typename T1>
inline QueuePriority<T1>* operator>>(std::ifstream  & is, QueuePriority<T1>*queue) {
	int counter = 0;
	std::string s;
	std::string er;

	while (!is.eof())
	{
		getline(is, s);
		s.length() > 2 ? counter++ : 0;
		er = std::to_string(counter);
		if (counter > queue->MaximumPossibleQueueLength) {
			throw QueueException("����� �������� ������. ", 3);
		}
	}

	is.clear();
	is.seekg(0, std::ios::beg);
	QueuePriority<T1>*ptr = new QueuePriority<T1>(counter);

	while (!is.eof())
	{
		getline(is, s);
		if (s.length() > 2) { 
			ptr->push(ptr->split_queue(s, true), ptr->split_queue(s, false));
		}
	}

	return ptr;
}
