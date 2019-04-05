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

	// Очередь
	Type * Wait;
	// Приоритет
	int * Pri;
	// Максимальный размер очереди
	int MaxQueueLength;
	// Текущий размер очереди
	int* QueueLength;
	//тимасові поля які потрібні для роботи з чергою
	Type* temp_wait;
	int* temp_priority;
	Type* temp_item_wait;
	int* temp_item_priority;
	int* TempQueueLength;

	//перевірка чи визвався головний конструктор
	bool check = false;

	//виділити пам'ять під тимчасові поля, які потрібні для роботы з чергою
	//(знаходження останнього елемента черги,знаходження першого
	//елемента черги, видалення елемента черги).
	void ini_field_temp();

	//звільнити пам'ять яка була виділена через void ini_field_temp();
	void delete_field_temp();

	//(знаходження останнього елемента черги,знаходження першого
	//елемента черги, видалення елемента черги).
	void show(Type* _wait, int* _priority, int* TempQueueLength, int* temp_priority, Type* temp_wait, int*);

	//Знаходження найбіль/найменш пріорітетного елемента черги
	//bool b=true - найбільш пріорітетний
	//bool b=false - найменш пріорітетний
	int front_back(const int* priority, const int* queue_length, bool b);

	//Задати кількість елементів в черзі
	void setQueueLength(int n);

	//разбиение строки файла на елемент очереди и приоритет
	//если true - елемент очереди, если false - приоритет
	int split_queue(std::string, bool);

	//функція для перезапису черги
	void reQeueu(int s);

public:
	QueuePriority();
	QueuePriority(const QueuePriority<Type>&);
	QueuePriority(int m);
	~QueuePriority();

	//максимально можливий розмір черги
	static const int MaximumPossibleQueueLength = 1250;

	//  кількість елементів
	int size()const;

	// повертає значення true, якщо черга пуста;
	bool empty();

	// Перевірка на переповнення черги
	bool full()const;

	//посилання на перший елемент;
	int front();

	//посилання на останній елемент;
	int  back();

	//обмін значеннями з іншою чергою;
	void swap(QueuePriority& right);

	// додати новий елемент у кінець черги;
	void push(Type c, int p);

	// вилучити перший елемент;
	int pop();

	//Показати чергу відсортовону за пріорітетом
	System::String^ show_priority();

	//Знайти елемент
	int find(int item);

	//сума всіх елементів
	Type accumulate();

	//перебір всіх елементів. Передача в функцію по посиланню елемента черги.
	void for_each(std::function<void(Type&)> func);

	//перебір всіх елементів. Передача в функцію по значенню елемента черги.
	void for_each(std::function<void(Type)> func);

	//Показати  поточну кількість елементів в черзі/максимальну кілкість елементів в черзі
	System::String^ state_queue();

	//Процент заповненості черги
	float percentage_filled_queue();

	//Очистка черги
	void cleaning_queue();

	//максимальній елемент в черзі
	int max();

	//мінімальній елемент в черзі
	int min();

	//Рандомне заповнення черги
	void random_filling();

	//отримати елемент черги по индексу
	Type getWait(int index)const;

	//отримати пріорітет черги по индексу
	int getPri(int index)const;

	int get_queue_len() const{
		return *QueueLength;
	}

	//отримати інформацію про елемент черги по индуксу
	//(Значение, Пріорітет, Індекс)
	String^ infoItem(int index);

	int getMaxQueueLength()const;
	//адреса першого елемента черги
	Type& begin();

	//адреса останнього елемента черги
	Type& end();

	//присвоює праву сторону лівій, якщо права стора не більше лівої
	QueuePriority* operator=(QueuePriority& right);

	//присвоїти праву сторону лівій
	void operator^(const QueuePriority& right);

	//Перевірка на рівність черг
	bool operator==(const QueuePriority& right);

	//Перевірка на нерівність черг
	bool operator!=(const QueuePriority& right);

	//додавання двух черг в одну
	QueuePriority* operator+(QueuePriority<Type> &right);

	//обмін чергами
	void operator|(QueuePriority<Type> &right);

	//Запис черги у файл<<
	template <typename T1>
	friend  std::ofstream & operator<<(std::ofstream & fs, const QueuePriority<T1>* f);

	//Запис черги у файл>>
	template <typename T1>
	friend  std::ofstream & operator>>(std::ofstream & fs, const QueuePriority<T1>* f);

	//вивід черги з файлу,і запис в чергу
	template <typename T1>
	friend  std::ifstream & operator<<(std::ifstream & fs, QueuePriority<T1>* f);

	//вивід черги з файлу,і с творення нової черги
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
			throw QueueException("Черга занадто велика. ", 3);
		}
	}

	if (counter > queue->getMaxQueueLength()) {
		throw QueueException("Черга занадтно велика. Кількість елементів " + er, 3);
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
			throw QueueException("Черга занадтно велика. ", 3);
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
