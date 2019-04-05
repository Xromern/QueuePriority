#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace MetroFramework::Components;
using namespace MetroFramework::Forms;
ref class QueueComponentForm
{
public:
	QueueComponentForm();

	int* QCcounter;
	int* QCcurrent;
	int* QCcurrentTwo;
	bool*flag;

	Label^ LabelStateQueue1;
	Label^ LabelStateQueue2;
	Label^ LabelShowQueue;
	Label^ LabelIActionQueue;
	Label^ LabelNumQueue1;
	Label^ LabelNumQueue2;
	//metroListView
	ListBox^ QListBox1;
	ListBox^ QListBox2;

	TextBox^ TextBoxWait;
	TextBox^ TextBoxPriority;
	TextBox^ TextBoxCreateQueue;
	TextBox^ TextBoxFind;
	TextBox^ TextBoxNameQueue;

	PictureBox^  PictureBox1;
	PictureBox^  PictureBox2;

	Panel^ ContainerPictureBox1;
	Panel^ ContainerPictureBox2;
	Panel^ ContainerPush;
	Panel^ ContainerListBox;
	Panel^ ContainerMethod;
	Panel^ ContainerSaveOpen;
	Panel^ ContainerLabelShow;

	ProgressBar^ ProgressBar1;
	ProgressBar^ ProgressBar2;

	String^buffer_name;

	void InitializeField(int*QCcounter, int*QCcurrent, int*QCcurrentTwo, bool*flag);
	void InitializeComponent(Label^ LabelStateQueue1, Label^ LabelStateQueue2, Label^ LabelShowQueue, Label^ LabelIActionQueue, Label^ LabelNumQueue1, Label^ LabelNumQueue12);
	void InitializeComponent(TextBox^ TextBoxWait, TextBox^ TextBoxPriority, TextBox^ TextBoxCreateQueue, TextBox^ TextBoxFind, TextBox^ TextBoxNameQueue);
	void InitializeComponent(PictureBox^  PictureBox1, PictureBox^  PictureBox2);
	void InitializeComponent(Panel^ ContainerPictureBox1, Panel^ ContainerPictureBox2, Panel^ ContainerPush, Panel^ ContainerListBox, Panel^ ContainerMethod, Panel^ ContainerSaveOpen, Panel^ ContainerLabelShow);
	void InitializeComponent(ProgressBar^ ProgressBar1, ProgressBar^ ProgressBar2);
	void InitializeComponent(ListBox^ QListBox1, ListBox^ QListBox2);

	int getCurrent();
	int getCounter();

	int getCurrentTwo();

	void setCurrent(int);
	void setCounter(int);
	void setCurrentTwo(int);

	void incrementCounter();
	void decrementCounter();

	bool getFlag();
	void setFlag(bool f);
};
