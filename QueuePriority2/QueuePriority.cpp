#include "QueuePriority.h"

template<class Type>
QueuePriority<Type>::QueuePriority()
{
}

template<typename Type>
QueuePriority<Type>::QueuePriority(const QueuePriority<Type>& right)
{
	*this^right;
}

template <class Type>
QueuePriority<Type>::QueuePriority(int m)
{
	if (m <= 1) {
		throw QueueException("����� �� ���� ���� ����� 2", 7);
	}
	if (m > MaximumPossibleQueueLength) {
		throw QueueException("����� �� ���� ���� ����� " + std::to_string(MaximumPossibleQueueLength), 7);
	}

	MaxQueueLength = m;

	Wait = new Type[MaxQueueLength];
	Pri = new int[MaxQueueLength];
	QueueLength = new int(0);
	check = true;
}

template <class Type>
QueuePriority<Type>::~QueuePriority()
{
	//�������� �������
	delete QueueLength;
	delete[]Wait;
	delete[]Pri;
	if (temp_wait != nullptr) {
		delete_field_temp();
	}
}

template <class Type>
void QueuePriority<Type>::ini_field_temp()
{
	temp_item_wait = new Type;
	temp_item_priority = new int;
	TempQueueLength = new int(*QueueLength);
	temp_wait = new Type[*QueueLength];
	temp_priority = new int[*QueueLength];
	memcpy(temp_wait, Wait, sizeof(Type)**QueueLength);
	memcpy(temp_priority, Pri, sizeof(Type)**QueueLength);
}

template <class Type>
void QueuePriority<Type>::delete_field_temp()
{
	delete[] temp_wait;
	delete[] temp_priority;
	delete temp_item_wait;
	delete temp_item_priority;
	delete TempQueueLength;
	temp_wait = nullptr;
	temp_priority = nullptr;
	temp_item_wait = nullptr;
	temp_item_priority = nullptr;
	TempQueueLength = nullptr;
}

template <class Type>
bool QueuePriority<Type>::empty()
{
	// ����?
	return *QueueLength == 0;
}

template <class Type>
bool QueuePriority<Type>::full()const
{
	// �����?
	return *QueueLength == MaxQueueLength;
}

template <class Type>
int QueuePriority<Type>::size()const
{
	// ���������� �������������� � ����� ���������
	return int(*QueueLength);
}

template <class Type>
void QueuePriority<Type>::push(Type c, int p)
{
	// ���� � ������� ���� ��������� �����, �� ����������� ����������
	// �������� � ��������� ����� �������
	if (!full()) {
		Wait[*QueueLength] = c;
		Pri[*QueueLength] = p;
		(*QueueLength)++;
	}
}

template <class Type>
int QueuePriority<Type>::pop()
{
	//���������� � ������� ��������� �������� � ������� show
	temp_item_priority = new int;
	temp_item_wait = new Type;
	int*temp_max = new int(-1);
	show(temp_item_wait, temp_item_priority, QueueLength, Pri, Wait, temp_max);
	delete temp_item_priority;
	delete temp_item_wait;
	int item = *temp_max;
	delete temp_max;
	return item;
}

template <class Type>
void QueuePriority<Type>::show(Type* item_wait, int* item_priority, int* TempQueueLength, int* temp_priority, Type* temp_wait, int* max) {
	if (!empty()) {
		//������ �������������� �������
		int pos_max_pri = front_back(temp_priority, TempQueueLength, true);

		*max = pos_max_pri;
		//����������� ������������ �������
		*item_wait = temp_wait[pos_max_pri];
		*item_priority = temp_priority[pos_max_pri];

		//�������� ��� ��������
		for (int i = pos_max_pri; i < *TempQueueLength - 1; i++) {
			temp_wait[i] = temp_wait[i + 1];
			temp_priority[i] = temp_priority[i + 1];
		}
		//��������� ����������
		(*TempQueueLength)--;
		// ������� ������������ ��������
	}
}

template<class Type>
int QueuePriority<Type>::front_back(const int* priority, const int* queue_length, bool b) {
	int max_pri = priority[0];
	//� ������������ ������ = 0
	int pos_max_pri = 0;

	//���� ���������
	for (int i = 1; i < *queue_length; i++)
		//���� �������� ����� ������������ �������

		if ((max_pri < (priority[i])) == b) {//���� true ���� ����� ������������, ���� false ����� ������������
			max_pri = priority[i];
			pos_max_pri = i;
		}

	return pos_max_pri;
}

template<typename Type>
void QueuePriority<Type>::setQueueLength(int n)
{
	*QueueLength = n;
}

template <class Type>
System::String^ QueuePriority<Type>::show_priority()
{
	//����������� ������� ���, ����������������� ������ �������� �� ���������
	ini_field_temp();
	int*temp_max = new int(0);
	// ���� � ������� ���� ��������, �� ���������� ���,
	// � �������� ��������� ��������� � �������� �������
	System::String^ str_temp = "";
	for (unsigned int i = 0; *TempQueueLength != 0; i++) {
		show(temp_item_wait, temp_item_priority, TempQueueLength, temp_priority, temp_wait, temp_max);
		str_temp += "��������: \t" + *temp_item_wait + "\t ���������: \t" + *temp_item_priority +"\n";
	}
	delete temp_max;
	delete_field_temp();
	return str_temp;
}

template <class Type>
int  QueuePriority<Type>::front() {
	return front_back(Pri, QueueLength, true);
}

template <class Type>
int QueuePriority<Type>::back() {
	return front_back(Pri, QueueLength, false);
}

template <class Type>
void QueuePriority<Type>::swap(QueuePriority& right) {
}

template <class Type>
int QueuePriority<Type>::find(int item) {
	for (int i = 0; i < *QueueLength; i++) {
		if (item == Wait[i]) {
			return i;
		}
	}
	return -1;
}

template<typename Type>
Type QueuePriority<Type>::accumulate()
{
	Type accum = 0;
	for_each([&](Type& wait) { accum += wait; });
	return accum;
}

template<typename Type>
void QueuePriority<Type>::for_each(std::function<void(Type &g)> func)
{
	for (int i = 0; i < *QueueLength; i++) {
		func(Wait[i]);
	}
}

template <class Type>
int QueuePriority<Type>::max() {
	Type max = Wait[0];
	int max_index = 0;
	for (int i = 1; i < *QueueLength; i++) {
		if (max < Wait[i]) {
			max = Wait[i];
			max_index = i;
		}
	}

	return max_index;
}

template <class Type>
int QueuePriority<Type>::min() {
	Type min = Wait[0];
	int min_index = 0;
	for (int i = 1; i < *QueueLength; i++) {
		if (!(min < Wait[i])) {
			min = Wait[i];
			min_index = i;
		}
	}
	return min_index;
}

template <class Type>
void QueuePriority<Type>::random_filling() {
	srand((unsigned)time(0));
	for (int i = 0; i < MaxQueueLength; i++) {
		push(int(1 + rand() % 999), int(1 + rand() % 7));
	}
}

template<typename Type>
Type QueuePriority<Type>::getWait(int index)const
{
	if (index > size()) {
		throw QueueException("������ �������� �� ����", 4);
	}
	return Wait[index];
}

template<typename Type>
String ^ QueuePriority<Type>::infoItem(int index)
{
	return "��������: " + getWait(index) + "; ���������: " + getPri(index) + "; ������: " + index + ";";
}

template<typename Type>
int QueuePriority<Type>::getPri(int index)const
{
	if (index > size()) {
		throw QueueException("������ �������� �� ����", 4);
	}
	return Pri[index];
}

template<typename Type>
int QueuePriority<Type>::getMaxQueueLength()const
{
	try {
		return MaxQueueLength;
	}
	catch (System::NullReferenceException^) {
		throw QueueException("����� �� ��������", 8);
	}
}

template<typename Type>
int QueuePriority<Type>::split_queue(std::string str, bool n)
{
	int counter = 0;
	std::string temp;
	for (unsigned int  i = 0; i < str.size(); i++) {//��� ������
		counter++;
		if (str[i] == ' ') {//���� ����� ������ ������������� ������
			break;
		}
	}
	if (n) {//���� true ���� ������� �������
		for (int i = 0; i < counter - 1; i++) {
			temp += str[i];
		}
	}
	else {//���� false ���� ��������� �������
		for (unsigned int  i = counter; i < str.size(); i++) {
			temp += str[i];
		}
	}
	return atoi(temp.c_str());
}

template <class Type>
System::String^ QueuePriority<Type>::state_queue() {
	return *QueueLength + "/" + MaxQueueLength;
}

template <class Type>
float QueuePriority<Type>::percentage_filled_queue() {
	try {
		if (*QueueLength != 0) {
			float percent = (float(MaxQueueLength) / float(*QueueLength));
			percent = 100 / float(percent);

			return percent > 100 ? 100 : percent;
		}
	}
	catch (NullReferenceException^) {
		throw QueueException("�������. ����� �� ��������.", 6);
	}
	return 0;
}

template<typename Type>
void QueuePriority<Type>::cleaning_queue()
{
	for (int i = 0; i < *QueueLength; i++) {
		Pri[i] = NULL;
		Wait[i] = NULL;
	}
	*QueueLength = 0;
}

template<class Type>
Type& QueuePriority<Type>::begin()
{
	return Wait[*QueueLength];
}

template<class Type>
Type& QueuePriority<Type>::end()
{
	return Wait[0];
}

