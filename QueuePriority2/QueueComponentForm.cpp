#include "QueueComponentForm.h"

QueueComponentForm::QueueComponentForm()
{
}

void QueueComponentForm::InitializeField(int * QCcounter_, int * QCcurrent_, int *QCcurrentTwo_, bool*flag_)
{
	QCcounter = QCcounter_;
	QCcurrent = QCcurrent_;
	QCcurrentTwo = QCcurrentTwo_;
	flag = flag_;
}

void QueueComponentForm::InitializeComponent(Label^ LabelStateQueue1, Label^ LabelStateQueue2, Label^ LabelShowQueue, Label^ LabelIActionQueue, Label^ LabelNumQueue1, Label^ LabelNumQueue2)
{
	this->LabelStateQueue1 = LabelStateQueue1;
	this->LabelStateQueue2 = LabelStateQueue2;
	this->LabelIActionQueue = LabelIActionQueue;
	this->LabelShowQueue = LabelShowQueue;
	this->LabelNumQueue1 = LabelNumQueue1;
	this->LabelNumQueue2 = LabelNumQueue2;
}

void QueueComponentForm::InitializeComponent(TextBox ^ TextBoxWait, TextBox ^ TextBoxPriority, TextBox ^ TextBoxCreateQueue, TextBox ^ TextBoxFind, TextBox^ TextBoxNameQueue)
{
	this->TextBoxWait = TextBoxWait;
	this->TextBoxPriority = TextBoxPriority;
	this->TextBoxCreateQueue = TextBoxCreateQueue;
	this->TextBoxFind = TextBoxFind;
	this->TextBoxNameQueue = TextBoxNameQueue;
}

void QueueComponentForm::InitializeComponent(PictureBox ^ PictureBox1, PictureBox ^ PictureBox2)
{
	this->PictureBox1 = PictureBox1;
	this->PictureBox2 = PictureBox2;
}

void QueueComponentForm::InitializeComponent(Panel^ ContainerPictureBox1, Panel^ ContainerPictureBox2, Panel^ ContainerPush, Panel^ ContainerListBox, Panel^ ContainerMethod, Panel^ ContainerSaveOpen, Panel^ ContainerLabelShow)
{
	this->ContainerPictureBox1 = ContainerPictureBox1;
	this->ContainerPictureBox2 = ContainerPictureBox2;
	this->ContainerPush = ContainerPush;
	this->ContainerListBox = ContainerListBox;
	this->ContainerMethod = ContainerMethod;
	this->ContainerSaveOpen = ContainerSaveOpen;
	this->ContainerLabelShow = ContainerLabelShow;
}

void QueueComponentForm::InitializeComponent(ProgressBar ^ ProgressBar1, ProgressBar ^ ProgressBar2)
{
	this->ProgressBar1 = ProgressBar1;
	this->ProgressBar2 = ProgressBar2;
}

void QueueComponentForm::InitializeComponent(ListBox ^ QListBox1, ListBox ^ QListBox2)
{
	this->QListBox1 = QListBox1;
	this->QListBox2 = QListBox2;
}

int QueueComponentForm::getCurrent()
{
	return *QCcurrent;
}

int QueueComponentForm::getCounter()
{
	return *QCcounter;
}

int QueueComponentForm::getCurrentTwo()
{
	return *QCcurrentTwo;
}

void QueueComponentForm::setCurrent(int n)
{
	*QCcurrent = n;
}

void QueueComponentForm::setCounter(int n)
{
	*QCcounter = n;
}

void QueueComponentForm::setCurrentTwo(int n)
{
	*QCcurrentTwo = n;
}


void QueueComponentForm::incrementCounter()
{
	(*QCcounter)++;
}

void QueueComponentForm::decrementCounter()
{
	(*QCcounter)--;
}

bool QueueComponentForm::getFlag()
{
	return *flag;
}

void QueueComponentForm::setFlag(bool f)
{
	*flag = f;
}