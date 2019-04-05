#pragma once

#include"QueuePriority.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace Microsoft::VisualBasic;
//створити чергу
template<class T>
inline void CreateQueue(array<QueuePriority<T>*>^ queuelist, QueueComponentForm^ QComponent)
{
	if (!check_text_box_name_queue(queuelist, QComponent)) {
		return;
	}

	try {
		//виділення пам'яті під нову чергу
		
		queuelist[QComponent->getCounter()] = new QueuePriority<T>(Convert::ToInt32(QComponent->TextBoxCreateQueue->Text));

		after_create_queue(queuelist, QComponent);
	}
	catch (FormatException^ e) {
		MessageBox::Show(e->Message);
	}
	catch (QueueException e) {
		MessageBox::Show(gcnew String(e.get_string_exception().c_str()));
	}
	catch (IndexOutOfRangeException^) {
		MessageBox::Show("Досягнута максимальная кількість черг.");
	}
}

//Перевірка на правильність імені черги
template<class T>
bool check_text_box_name_queue(array<QueuePriority<T>*>^ queuelist, QueueComponentForm^ QComponent) {
	if (QComponent->TextBoxNameQueue->Text->Length == 0) {
		MessageBox::Show("Введіть назву черги");
		return false;
	}
	if (QComponent->QListBox1->FindStringExact(QComponent->TextBoxNameQueue->Text) != -1) {
		MessageBox::Show("Черга за таким ім'я вже існує");
		return false;
	}
	return true;
}

//метод який выконуеться після створення структури
template<class T>
void after_create_queue(array<QueuePriority<T>*>^ queuelist, QueueComponentForm^ QComponent) {
	//якшо створюється перша черга, розблокувати елементи
	if (!QComponent->getFlag()) {
		enable_component(QComponent, true);
	}
	//вибрати сворену черги як поточну
	QComponent->setCurrent(QComponent->getCounter());
	//інкрементувати лічильник черг
	QComponent->incrementCounter();
	set_listbox(QComponent);
	QueuePriorityDraw::clear_component(QComponent, 0);
	QueuePriorityDraw::clear_component(QComponent, 1);
	SetQueue(queuelist, QComponent, 0);
	SetQueueFirst(queuelist, QComponent);
	SetQueueLast(queuelist, QComponent);
	QComponent->TextBoxCreateQueue->Text = "";
	QComponent->TextBoxNameQueue->Text = "";
}

//виключити/включити всю компонети якщо структури відсутні
void enable_component(QueueComponentForm^ QComponent, bool falg) {
	QComponent->ContainerListBox->Enabled = falg;
	QComponent->ContainerMethod->Enabled = falg;
	QComponent->ContainerPush->Enabled = falg;
	QComponent->ContainerSaveOpen->Enabled = falg;
	QComponent->ProgressBar1->Visible = falg;
	QComponent->ProgressBar2->Visible = falg;
	QComponent->setFlag(falg);
	QueuePriorityDraw::clear_component(QComponent, 0);
	QueuePriorityDraw::clear_component(QComponent, 1);
}

//додати чергу до listbox і вибрати її
inline void set_listbox(QueueComponentForm^ QComponent)
{
	QComponent->QListBox1->Items->Insert(QComponent->getCounter() - 1, QComponent->TextBoxNameQueue->Text);
	QComponent->QListBox2->Items->Insert(QComponent->getCounter() - 1, QComponent->TextBoxNameQueue->Text);
	QComponent->QListBox1->SetSelected(QComponent->QListBox1->Items->Count - 1, true);
	QComponent->QListBox2->SetSelected(QComponent->QListBox1->Items->Count - 1, true);
}

//Вивести інформацію про черги
template<class T>
inline void SetQueue(array<QueuePriority<T>*>^ queuelist, QueueComponentForm^ QComponent, int numPanel)
{
	int current;
	// Очистити компоненти для нової черги
	QueuePriorityDraw::clear_component(QComponent, numPanel);
	//якощо вибрана перша черги
	if (numPanel == 0) {
		SetQueueFirst(queuelist, QComponent);
		current = QComponent->getCurrent();
		QComponent->LabelShowQueue->Text = queuelist[current]->show_priority();
	}//якощо вибрана друга черги
	else {
		current = QComponent->getCurrentTwo();
		SetQueueLast(queuelist, QComponent);
	}

	QueuePriorityDraw::draw_item(queuelist, QComponent, Brushes::Green, -1, numPanel);
}

//Вивести інформацію про першу чергу (прогресс бар,номер черги, заповненість черги)
template<class T>
inline void SetQueueFirst(array<QueuePriority<T>*>^ queuelist, QueueComponentForm^ QComponent) {
	QComponent->ProgressBar1->Value = int(queuelist[QComponent->getCurrent()]->percentage_filled_queue());
	QComponent->LabelNumQueue1->Text = "№ " + QComponent->getCurrent();
	QComponent->LabelStateQueue1->Text = queuelist[QComponent->getCurrent()]->size() + " / " + queuelist[QComponent->getCurrent()]->getMaxQueueLength();
}

//Вивести інформацію про дргугу чергу (прогресс бар,номер черги, заповненість черги)
template<class T>
inline void SetQueueLast(array<QueuePriority<T>*>^ queuelist, QueueComponentForm^ QComponent) {
	QComponent->ProgressBar2->Value = int(queuelist[QComponent->getCurrentTwo()]->percentage_filled_queue());
	QComponent->LabelNumQueue2->Text = "№ " + QComponent->getCurrentTwo();
	QComponent->LabelStateQueue2->Text = queuelist[QComponent->getCurrentTwo()]->size() + " / " + queuelist[QComponent->getCurrentTwo()]->getMaxQueueLength();
}

//якщо вибрана ліва структура, ініціалізю  її елементи даними
template<class T>
inline void SelectedChangeLeft(array<QueuePriority<T>*>^ queuelist, QueueComponentForm^ QComponent) {

	if (QComponent->QListBox1->Items->Count > 0) {
		if (QComponent->QListBox1->SelectedIndex != -1) {
			QComponent->setCurrent(QComponent->QListBox1->SelectedIndex);
			SetQueue(queuelist, QComponent, 0);
			SetQueueFirst(queuelist, QComponent);

		}
	}
	else {
		enable_component(QComponent, false);
	}
}

//якщо вибрана права структура, ініціалізю елементи її даними
template<class T>
inline void SelectedChangeRight(array<QueuePriority<T>*>^ queuelist, QueueComponentForm^ QComponent) {
	if (QComponent->QListBox2->Items->Count > 0) {
		if (QComponent->QListBox2->SelectedIndex != -1) {
			QComponent->setCurrentTwo(QComponent->QListBox2->SelectedIndex);
			SetQueue(queuelist, QComponent, 1);
			SetQueueLast(queuelist, QComponent);
		}
	}
	else {
		enable_component(QComponent, false);
	}
}

//Рандомне заповнення черги
template<class T>
inline void RandomFillingQueue(array<QueuePriority<T>*>^ queuelist, QueueComponentForm^ QComponent)
{
	queuelist[QComponent->getCurrent()]->random_filling();
	SetQueue(queuelist, QComponent, 0);
	SetQueue(queuelist, QComponent, 1);
}

//вилиучити елемент черги
///pop
template<class T>
inline void PopQueue(array<QueuePriority<T>*>^ queuelist, QueueComponentForm^ QComponent)
{
	//показати вилученый елемент черги
	QueuePriorityDraw::draw_item(queuelist, QComponent, Brushes::Red, queuelist[QComponent->getCurrent()]->front(), 0);
	//вилучити елемент
	if (queuelist[QComponent->getCurrent()]->pop() != -1) {
		QComponent->LabelShowQueue->Text = queuelist[QComponent->getCurrent()]->show_priority();
	}
	else {
		MessageBox::Show("Черга пута.");
		QComponent->PictureBox1->Image = nullptr;
		QComponent->PictureBox1->Refresh();
	}
	SetQueueFirst(queuelist, QComponent);
	SetQueueLast(queuelist, QComponent);
	QComponent->QListBox2->SetSelected(QComponent->getCurrentTwo(), true);
}

//функція на занесення елементу в чергу
///push
template<class T>
inline void PushQueue(array<QueuePriority<T>*>^ queuelist, QueueComponentForm^ QComponent)
{
	//перевірка на коректність віхдних даних
	try {
		//якащо черга не повна
		if (!queuelist[QComponent->getCurrent()]->full()) {
			queuelist[QComponent->getCurrent()]->push(Convert::ToInt32(QComponent->TextBoxWait->Text), Convert::ToInt32(QComponent->TextBoxPriority->Text));
			SetQueue(queuelist, QComponent, 0);
			SetQueue(queuelist, QComponent, 1);
			//показати доданий елемент черги
			QueuePriorityDraw::draw_item(queuelist, QComponent, Brushes::GreenYellow, queuelist[QComponent->getCurrent()]->size() - 1, 0);
			QComponent->TextBoxPriority->Text = "";
			QComponent->TextBoxWait->Text = "";
		}
		else {
			MessageBox::Show("Черга повна.");
		}
	}
	catch (FormatException ^e) {
		MessageBox::Show(e->Message);
	}
	catch (OverflowException^e) {
		MessageBox::Show(e->Message);
	}

}

//Функція знаходження першого елементу черги
///front
template<class T>
inline void FrontQueue(array<QueuePriority<T>*>^ queuelist, QueueComponentForm^ QComponent) {
	QueuePriorityDraw::draw_item(queuelist, QComponent, Brushes::LawnGreen, queuelist[QComponent->getCurrent()]->front(), 0);
}

//Функція знаходження останнього елементу черги
///back
template<class T>
inline void BackQueue(array<QueuePriority<T>*>^ queuelist, QueueComponentForm^ QComponent) {
	QueuePriorityDraw::draw_item(queuelist, QComponent, Brushes::LawnGreen, queuelist[QComponent->getCurrent()]->back(), 0);
}

//Функція знаходження максимального елементу черги
///max
template<class T>
inline void MaxQueue(array<QueuePriority<T>*>^ queuelist, QueueComponentForm^ QComponent) {
	QueuePriorityDraw::draw_item(queuelist, QComponent, Brushes::Coral, queuelist[QComponent->getCurrent()]->max(), 0);
}

//Функція знаходження мінімального елементу черги
///min
template<class T>
inline void MinQueue(array<QueuePriority<T>*>^ queuelist, QueueComponentForm^ QComponent) {
	QueuePriorityDraw::draw_item(queuelist, QComponent, Brushes::Coral, queuelist[QComponent->getCurrent()]->min(), 0);
}

//Функція на перевірку черги на пустоту
///empty
template<class T>
inline void EmptyQueue(array<QueuePriority<T>*>^ queuelist, QueueComponentForm^ QComponent) {
	bool f = queuelist[QComponent->getCurrent()]->empty();
	String^ s = f ? "Черга пуста" : "Черга не пуста.";
	QComponent->LabelIActionQueue->Text = s;
}

//Функція на знаходження вказаного елементу черги
///find
template<class T>
inline void FindQueue(array<QueuePriority<T>*>^ queuelist, QueueComponentForm^ QComponent) {
	try {
		int item = Convert::ToInt32(QComponent->TextBoxFind->Text);
		int index = queuelist[QComponent->getCurrent()]->find(item);

		if (index == -1) {
			QComponent->LabelIActionQueue->Text = "Такого елементу немає";
		}
		else {
			QueuePriorityDraw::draw_item(queuelist, QComponent, Brushes::Purple, index, 0);
			queuelist[QComponent->getCurrent()]->infoItem(index);
		}
	}
	catch (FormatException ^e) {
		MessageBox::Show(e->Message);
	}
}

//інкрементування всіх елементів черги через метод for_each
///for_each
template <typename T>
void ForEachQueue(array<QueuePriority<T>*>^ queuelist, QueueComponentForm^ QComponent) {
	if (!queuelist[QComponent->getCurrent()]->empty()) {
		queuelist[QComponent->getCurrent()]->for_each([&](int& f) { f++; });
		SetQueue(queuelist, QComponent, 0);
		SetQueue(queuelist, QComponent, 1);
		QComponent->LabelIActionQueue->Text = "Інкрементувати всі елементи черги.";
	}
	else {
		MessageBox::Show("Черга пуста");
	}
}

//Очистка черги
///сlear
template <typename T>
void ClearQueue(array<QueuePriority<T>*>^ queuelist, QueueComponentForm^ QComponent) {
	queuelist[QComponent->getCurrent()]->cleaning_queue();
	SetQueue(queuelist, QComponent, 0);
	SetQueue(queuelist, QComponent, 1);
	EmptyQueue(queuelist, QComponent);
}

//перевірка на рівність вудх чреги
///==
template <typename T>
void CompareQueue(array<QueuePriority<T>*>^ queuelist, QueueComponentForm^ QComponent) {

	bool f = *queuelist[QComponent->getCurrent()] == *queuelist[QComponent->getCurrentTwo()];

	MessageBox::Show(f ? "true" : "false");
}

//перевірка на неравність двух черги
///!=
template <typename T>
void NotEqualQueue(array<QueuePriority<T>*>^ queuelist, QueueComponentForm^ QComponent) {
	bool f = *queuelist[QComponent->getCurrent()] != *queuelist[QComponent->getCurrentTwo()];
	MessageBox::Show(f ? "true" : "false");
}

//Додавання двух черги та творення нової
///+
template <typename T>
void PlusQueue(array<QueuePriority<T>*>^ queuelist, QueueComponentForm^ QComponent) {
	try {
		String ^ NameDictionary = Interaction::InputBox("Введіть назву для черги.", "Повідомлення", "",500,300);
		QComponent->TextBoxNameQueue->Text = NameDictionary;
		if (!check_text_box_name_queue(queuelist, QComponent)) {
			return;
		}
		
		queuelist[QComponent->getCounter()] = *queuelist[QComponent->getCurrent()] + *queuelist[QComponent->getCurrentTwo()];
		//вибрати сворену черги як поточну
		QComponent->setCurrent(QComponent->getCounter());
		//інкрементувати лічильник черг
		QComponent->incrementCounter();
		set_listbox(QComponent);
		QueuePriorityDraw::clear_component(QComponent, 0);
		QueuePriorityDraw::clear_component(QComponent, 1);
		SetQueue(queuelist, QComponent, 0);
		SetQueue(queuelist, QComponent, 1);
		QComponent->TextBoxCreateQueue->Text = "";
		QComponent->TextBoxNameQueue->Text = "";
	}
	catch (QueueException e) {
		MessageBox::Show(gcnew String(e.get_string_exception().c_str()));
	}
	catch (IndexOutOfRangeException^) {
		MessageBox::Show("Досягнута максимальная кількість черг.");
	}
}

//Сума елементів черги
///accumulate
template <typename T>
void AccumulateQueue(array<QueuePriority<T>*>^ queuelist, QueueComponentForm^ QComponent) {
	int sum = queuelist[QComponent->getCurrent()]->accumulate();
	QComponent->LabelIActionQueue->Text = "Сума черги = " + sum;
}

//присваювання правої черги лівій
///=
template <typename T>
void AssignQueue(array<QueuePriority<T>*>^ queuelist, QueueComponentForm^ QComponent) {
	try {
		*queuelist[QComponent->getCurrent()] = *queuelist[QComponent->getCurrentTwo()];
		SetQueue(queuelist, QComponent, 0);
	}
	catch (QueueException e) {
		MessageBox::Show(gcnew String(e.get_string_exception().c_str()));
	}
}

//Обмін даними між чергами
///swap
template <typename T>
void SwapQueue(array<QueuePriority<T>*>^ queuelist, QueueComponentForm^ QComponent) {
	try {
		*queuelist[QComponent->getCurrent()] | *queuelist[QComponent->getCurrentTwo()];
		SetQueue(queuelist, QComponent, 0);
		SetQueue(queuelist, QComponent, 1);
	}
	catch (QueueException e) {
		MessageBox::Show(gcnew String(e.get_string_exception().c_str()));
	}
}

//Зберегти чергу
template <typename T>
void SaveQueue(array<QueuePriority<T>*>^ queuelist, QueueComponentForm^ QComponent) {
	if (QComponent->getCounter() == 0) { MessageBox::Show("Спочатку створіть чергу."); return; }
	SaveFileDialog^ openDlg = gcnew SaveFileDialog();
	openDlg->Filter = "Files(*.txt;)|*.txt;";
	openDlg->FileName = QComponent->QListBox1->SelectedItem->ToString() + ".txt";;
	if (System::Windows::Forms::DialogResult::OK == openDlg->ShowDialog())
	{
		std::ofstream os(ConvertSlitoStlString(openDlg->FileName));
		os << queuelist[QComponent->getCurrent()];
		os.close();
	}
}

//Зберегти чергу і видалити
template <typename T>
void SaveAndDeleteQueue(array<QueuePriority<T>*>^ queuelist, QueueComponentForm^ QComponent) {
	SaveFileDialog^ openDlg = gcnew SaveFileDialog();
	openDlg->Filter = "Files(*.txt;)|*.txt;";
	openDlg->FileName = QComponent->QListBox1->SelectedItem->ToString() + ".txt";;
	if (System::Windows::Forms::DialogResult::OK == openDlg->ShowDialog())
	{
		std::ofstream os(ConvertSlitoStlString(openDlg->FileName));
		os >> queuelist[QComponent->getCurrent()];
		DeleteQueue(queuelist, QComponent);
		os.close();
	}
}

//відкрити чергу і створити нову
template <typename T>
void OpenQueueNew(array<QueuePriority<T>*>^ queuelist, QueueComponentForm^ QComponent, std::string full_file, String^ file) {
	try {
		std::ifstream ifs(full_file);
		if (ifs.is_open()) {
			queuelist[QComponent->getCounter()] = ifs >> queuelist[QComponent->getCounter()];
			//QComponent->LabelIActionQueue->Text = Convert::ToString(queuelist[QComponent->getCounter()]->pop());
			QComponent->TextBoxNameQueue->Text = file;
			after_create_queue(queuelist, QComponent);
		}
		else {
			MessageBox::Show("Сталась помилка " + gcnew String(full_file.c_str()));
		}
		ifs.close();
	}
	catch (QueueException e) {
		MessageBox::Show(gcnew String(e.get_string_exception().c_str()));
	}
	catch (IndexOutOfRangeException^) {
		MessageBox::Show("Досягнута максимальная кількість черг.");
	}

	SetQueue(queuelist, QComponent, 0);
	SetQueue(queuelist, QComponent, 1);
}

//Відкрити чергу и перезаписати поточну
template <typename T>
void OpenQueueRewrite(array<QueuePriority<T>*>^ queuelist, QueueComponentForm^ QComponent, std::string file) {
	if (QComponent->QListBox1->Items->Count > 0) {
		try {
			std::ifstream ifs(file);
			if (ifs.is_open()) {
				ifs << queuelist[QComponent->getCurrent()];
			}
			else {
				MessageBox::Show("Сталась помилка ");
			}
			ifs.close();
		}
		catch (QueueException e) {
			MessageBox::Show(gcnew String(e.get_string_exception().c_str()));
		}
		SetQueue(queuelist, QComponent, 0);
		SetQueue(queuelist, QComponent, 1);
	}
	else {
		MessageBox::Show("Створіть чергу");
	}
}

//Здвинути чергу
template <typename T>
void ShiftQueue(array<QueuePriority<T>*>^ queuelist, QueueComponentForm^ QComponent) {
	if (QComponent->getCounter() != QComponent->getCurrent()) {//якщо не остання черга

		for (int i = QComponent->getCurrent(); i < QComponent->getCounter() - 1; i++) {
			*queuelist[i] ^ *queuelist[i + 1];
		}
	}
		;//Видалити останній объект
	QComponent->decrementCounter();
}

//Видалити чергу
template <typename T>
void DeleteQueue(array<QueuePriority<T>*>^ queuelist, QueueComponentForm^ QComponent) {
	ShiftQueue(queuelist, QComponent);

	int QListBox1_item = QComponent->QListBox1->SelectedIndex;
	remove_field_list_box(QComponent, QComponent->getCurrent());

	if (!select_field_aftre_delete(QComponent)) {

		QComponent->setCounter(0);
	}
}

//Видалити поля з listbox
void remove_field_list_box(QueueComponentForm^ QComponent, int index) {
	QComponent->QListBox1->Items->RemoveAt(QComponent->QListBox1->SelectedIndex);
	QComponent->QListBox2->Items->RemoveAt(index);
}

//вибрати поля після видалення
bool select_field_aftre_delete(QueueComponentForm^ QComponent) {
	if (QComponent->QListBox1->Items->Count != 0) {
		if (QComponent->QListBox1->SelectedIndex != 0) {
			QComponent->QListBox1->SetSelected(0, true);
			QComponent->QListBox2->SetSelected(0, true);
		}
		else {
			QComponent->QListBox1->SetSelected(1, true);
			QComponent->QListBox2->SetSelected(1, true);
		}
		return true;
	}
	return false;
}
//конвертувати строку з sli в stl
static std::string ConvertSlitoStlString(System::String ^ s)
{
	const char* cstr = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	std::string sstr = cstr;
	Marshal::FreeHGlobal(System::IntPtr((void*)cstr));
	return sstr;
}