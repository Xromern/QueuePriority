#include"QueuePriority.h"


template<typename Type>
QueuePriority<Type>* QueuePriority<Type>::operator=(QueuePriority & right)
{
	if (check == false) { return &right; }

	if (this->getMaxQueueLength() < right.getMaxQueueLength()) {
		throw QueueException("Неможливо просвоїти, так як права черга більше.", 0);
	}

	if (this == &right) {
		throw QueueException("Помилка", 0);
	}
	cleaning_queue();
	for (int i = 0; i < int(right.size()); i++) {
		push(right.getWait(i), right.getPri(i));
	}

	return this;
}

template<typename Type>
void QueuePriority<Type>::reQeueu(int s) {
	delete Wait;
	delete Pri;
	Wait = new Type[s];
	Pri = new int[s];
	MaxQueueLength = s;
	*QueueLength = 0;
}

template<typename Type>
void QueuePriority<Type>::operator^(const QueuePriority& right)
{
	this->reQeueu(right.getMaxQueueLength());
	for (int i = 0; i < right.size(); i++) {
		this->push(right.getWait(i), right.getPri(i));
	}
}

template<typename Type>
bool QueuePriority<Type>::operator==(const QueuePriority & right)
{
	if (get_queue_len() != right.get_queue_len()) {
		return false;
	}
	for (int i = 0; i < get_queue_len(); i++) {
		if (getWait(i) != right.getWait(i) || getPri(i) != right.getPri(i)) {
			return false;
		}
	}
	return true;
}

template<typename Type>
bool QueuePriority<Type>::operator!=(const QueuePriority& right)
{
	bool flag = true;

	if (get_queue_len() != right.get_queue_len()) {
		flag = false;
	}
	for (int i = 0; i < get_queue_len(); i++) {
		if (getWait(i) != right.getWait(i) || getPri(i) != right.getPri(i)) {
			flag = false;
		}
	}
	return !flag;
}

template<typename Type>
QueuePriority<Type>* QueuePriority<Type>::operator+(QueuePriority<Type>& right)
{
	if (this->getMaxQueueLength() + right.getMaxQueueLength() > MaximumPossibleQueueLength) {
		std::string s = "Максимальна довжина черги може бути" + std::to_string(MaximumPossibleQueueLength);
		throw QueueException(s, 0);
	}

	QueuePriority *temp = new QueuePriority(this->getMaxQueueLength() + right.getMaxQueueLength());
	for (int i = 0; i < size(); i++) {
		temp->push(this->getWait(i), this->getPri(i));
	}

	for (int i = 0; i < right.size(); i++) {
		temp->push(right.getWait(i), right.getPri(i));
	}
	return temp;
}

template<typename Type>
void QueuePriority<Type>::operator|(QueuePriority<Type>& right)
{
	if (*this == right) {
		throw QueueException("Зеркальний обмін неможливий", 4);
	}
	int*pri_temp = right.Pri;
	Type*wait_temp = right.Wait;
	int que_len = right.size();
	int max_len = right.getMaxQueueLength();

	right.Pri = Pri;
	right.Wait = Wait;
	right.setQueueLength(*QueueLength);
	right.MaxQueueLength = MaxQueueLength;

	Pri = pri_temp;
	Wait = wait_temp;
	MaxQueueLength = max_len;
	setQueueLength(que_len);

}

