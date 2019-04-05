#pragma once
#include"QueuePriority.h"
#include"QueueComponentForm.h"
#include"QueuePriorityDraw.h"
#include"ActionFromQueue.h"
#include "FormInfo.h"
namespace QueuePriority2 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;

	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MetroFramework::Components;
	using namespace MetroFramework::Forms;

	/// <summary>
	/// Сводка для FormQueuePrioritiy
	/// </summary>
	public ref class FormQueuePrioritiy : public MetroForm
	{
	public:
		FormQueuePrioritiy(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
#pragma region Windows Form Designer generated code
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~FormQueuePrioritiy()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  QButtonCreate;
	protected:

	protected:

	protected:

	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  TextBoxCreateQueue;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  QButtonPush;
	private: System::Windows::Forms::Panel^  ContainerPush;
	private: System::Windows::Forms::Button^  QButtonRandomFilling;
	private: System::Windows::Forms::TextBox^  TextBoxPriority;
	private: System::Windows::Forms::TextBox^  TextBoxWait;
	private: System::Windows::Forms::Panel^  ContainerListBox;
	private: System::Windows::Forms::Button^  QButtonPlus;
	private: System::Windows::Forms::Button^  QButtonUnequal;
	private: System::Windows::Forms::Button^  QButtonCompare;
	private: System::Windows::Forms::Button^  QButtonAssign;
	private: System::Windows::Forms::ListBox^  QListBox2;
	private: System::Windows::Forms::ListBox^  QListBox1;




	private: System::Windows::Forms::Panel^  ContainerMethod;
	private: System::Windows::Forms::TextBox^  TextBoxFind;
	private: System::Windows::Forms::Button^  QButtonFind;
	private: System::Windows::Forms::Button^  QButtonMin;
	private: System::Windows::Forms::Button^  QButtonBack;
	private: System::Windows::Forms::Button^  QButtonForEach;
	private: System::Windows::Forms::Button^  QButtonEmpty;
	private: System::Windows::Forms::Button^  QButtonMax;
	private: System::Windows::Forms::Button^  QButtonFront;
	private: System::Windows::Forms::Button^  QButtonPop;
	private: System::Windows::Forms::Panel^  ContainerPictureBox1;
	private: System::Windows::Forms::ProgressBar^  progressBar2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Panel^  ContainerPictureBox2;
	private: System::Windows::Forms::ProgressBar^  progressBar1;


	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Button^  button17;
	private: System::Windows::Forms::Button^  button18;
	private: System::Windows::Forms::Button^  button19;
	private: System::Windows::Forms::Panel^  ContainerSaveOpen;
	private: System::Windows::Forms::Panel^  ContainerLabelShow;
	private: System::Windows::Forms::Label^  LabelShowQueue;
	private: System::Windows::Forms::Label^  LabelIActionQueue;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  LabelNumQueue1;

	private: System::Windows::Forms::Label^  LabelNumQueue2;
	private: System::Windows::Forms::Label^  LabelStateQueue2;
	private: System::Windows::Forms::Button^  QButtonClear;
	private: System::Windows::Forms::Button^  QButtonAccumulate;

	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  файлToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  відкритиToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  зберегтиToolStripMenuItem;
	private: System::Windows::Forms::Button^  QButtonDelete;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  TextBoxNameQueue;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::ToolStripMenuItem^  вихідToolStripMenuItem;
	private: System::Windows::Forms::Panel^  panel1;

	private: System::Windows::Forms::Label^  LabelStateQueue1;
	private: System::Windows::Forms::ToolStripMenuItem^  довідкаToolStripMenuItem;














	private: System::ComponentModel::IContainer^  components;

#pragma endregion

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FormQueuePrioritiy::typeid));
			this->QButtonCreate = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->TextBoxCreateQueue = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->QButtonPush = (gcnew System::Windows::Forms::Button());
			this->ContainerPush = (gcnew System::Windows::Forms::Panel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->QButtonRandomFilling = (gcnew System::Windows::Forms::Button());
			this->TextBoxPriority = (gcnew System::Windows::Forms::TextBox());
			this->TextBoxWait = (gcnew System::Windows::Forms::TextBox());
			this->ContainerListBox = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->QButtonPlus = (gcnew System::Windows::Forms::Button());
			this->QButtonUnequal = (gcnew System::Windows::Forms::Button());
			this->QButtonCompare = (gcnew System::Windows::Forms::Button());
			this->QButtonAssign = (gcnew System::Windows::Forms::Button());
			this->QListBox2 = (gcnew System::Windows::Forms::ListBox());
			this->QListBox1 = (gcnew System::Windows::Forms::ListBox());
			this->ContainerMethod = (gcnew System::Windows::Forms::Panel());
			this->QButtonDelete = (gcnew System::Windows::Forms::Button());
			this->QButtonAccumulate = (gcnew System::Windows::Forms::Button());
			this->QButtonClear = (gcnew System::Windows::Forms::Button());
			this->TextBoxFind = (gcnew System::Windows::Forms::TextBox());
			this->QButtonFind = (gcnew System::Windows::Forms::Button());
			this->QButtonMin = (gcnew System::Windows::Forms::Button());
			this->QButtonBack = (gcnew System::Windows::Forms::Button());
			this->QButtonForEach = (gcnew System::Windows::Forms::Button());
			this->QButtonEmpty = (gcnew System::Windows::Forms::Button());
			this->QButtonMax = (gcnew System::Windows::Forms::Button());
			this->QButtonFront = (gcnew System::Windows::Forms::Button());
			this->QButtonPop = (gcnew System::Windows::Forms::Button());
			this->ContainerPictureBox1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->LabelNumQueue1 = (gcnew System::Windows::Forms::Label());
			this->progressBar2 = (gcnew System::Windows::Forms::ProgressBar());
			this->ContainerPictureBox2 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->LabelNumQueue2 = (gcnew System::Windows::Forms::Label());
			this->LabelStateQueue2 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->ContainerSaveOpen = (gcnew System::Windows::Forms::Panel());
			this->ContainerLabelShow = (gcnew System::Windows::Forms::Panel());
			this->LabelShowQueue = (gcnew System::Windows::Forms::Label());
			this->LabelIActionQueue = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->відкритиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->зберегтиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->довідкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->вихідToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->TextBoxNameQueue = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->LabelStateQueue1 = (gcnew System::Windows::Forms::Label());
			this->ContainerPush->SuspendLayout();
			this->ContainerListBox->SuspendLayout();
			this->ContainerMethod->SuspendLayout();
			this->ContainerPictureBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->ContainerPictureBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->ContainerSaveOpen->SuspendLayout();
			this->ContainerLabelShow->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// QButtonCreate
			// 
			this->QButtonCreate->BackColor = System::Drawing::Color::White;
			this->QButtonCreate->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"QButtonCreate.BackgroundImage")));
			this->QButtonCreate->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->QButtonCreate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->QButtonCreate->ImageAlign = System::Drawing::ContentAlignment::BottomRight;
			this->QButtonCreate->ImageKey = L"(отсутствует)";
			this->QButtonCreate->Location = System::Drawing::Point(6, 3);
			this->QButtonCreate->Name = L"QButtonCreate";
			this->QButtonCreate->Size = System::Drawing::Size(73, 26);
			this->QButtonCreate->TabIndex = 0;
			this->QButtonCreate->Text = L"Створити";
			this->QButtonCreate->UseVisualStyleBackColor = false;
			this->QButtonCreate->Click += gcnew System::EventHandler(this, &FormQueuePrioritiy::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1042, 249);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 13);
			this->label1->TabIndex = 1;
			// 
			// TextBoxCreateQueue
			// 
			this->TextBoxCreateQueue->Location = System::Drawing::Point(133, 7);
			this->TextBoxCreateQueue->Name = L"TextBoxCreateQueue";
			this->TextBoxCreateQueue->Size = System::Drawing::Size(113, 20);
			this->TextBoxCreateQueue->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::White;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ImageAlign = System::Drawing::ContentAlignment::BottomRight;
			this->button1->ImageKey = L"(отсутствует)";
			this->button1->Location = System::Drawing::Point(3, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(257, 27);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Відкрити чергу перезаписавши цю (<<)";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &FormQueuePrioritiy::button1_Click_1);
			// 
			// QButtonPush
			// 
			this->QButtonPush->BackColor = System::Drawing::Color::White;
			this->QButtonPush->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"QButtonPush.BackgroundImage")));
			this->QButtonPush->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->QButtonPush->ImageAlign = System::Drawing::ContentAlignment::BottomRight;
			this->QButtonPush->ImageKey = L"(отсутствует)";
			this->QButtonPush->Location = System::Drawing::Point(3, 3);
			this->QButtonPush->Name = L"QButtonPush";
			this->QButtonPush->Size = System::Drawing::Size(73, 27);
			this->QButtonPush->TabIndex = 4;
			this->QButtonPush->Text = L"push";
			this->QButtonPush->UseVisualStyleBackColor = false;
			this->QButtonPush->Click += gcnew System::EventHandler(this, &FormQueuePrioritiy::QButtonPush_Click);
			// 
			// ContainerPush
			// 
			this->ContainerPush->Controls->Add(this->label9);
			this->ContainerPush->Controls->Add(this->label8);
			this->ContainerPush->Controls->Add(this->QButtonRandomFilling);
			this->ContainerPush->Controls->Add(this->TextBoxPriority);
			this->ContainerPush->Controls->Add(this->TextBoxWait);
			this->ContainerPush->Controls->Add(this->QButtonPush);
			this->ContainerPush->Enabled = false;
			this->ContainerPush->Location = System::Drawing::Point(23, 137);
			this->ContainerPush->Name = L"ContainerPush";
			this->ContainerPush->Size = System::Drawing::Size(192, 138);
			this->ContainerPush->TabIndex = 6;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(8, 77);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(53, 13);
			this->label9->TabIndex = 17;
			this->label9->Text = L"Пріорітет";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(8, 45);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(55, 13);
			this->label8->TabIndex = 17;
			this->label8->Text = L"Значення";
			// 
			// QButtonRandomFilling
			// 
			this->QButtonRandomFilling->BackColor = System::Drawing::Color::White;
			this->QButtonRandomFilling->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"QButtonRandomFilling.BackgroundImage")));
			this->QButtonRandomFilling->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->QButtonRandomFilling->ImageAlign = System::Drawing::ContentAlignment::BottomRight;
			this->QButtonRandomFilling->ImageKey = L"(отсутствует)";
			this->QButtonRandomFilling->Location = System::Drawing::Point(3, 105);
			this->QButtonRandomFilling->Name = L"QButtonRandomFilling";
			this->QButtonRandomFilling->Size = System::Drawing::Size(176, 27);
			this->QButtonRandomFilling->TabIndex = 11;
			this->QButtonRandomFilling->Text = L"Рандомне заповнення черги";
			this->QButtonRandomFilling->UseVisualStyleBackColor = false;
			this->QButtonRandomFilling->Click += gcnew System::EventHandler(this, &FormQueuePrioritiy::QButtonRandomFilling_Click);
			// 
			// TextBoxPriority
			// 
			this->TextBoxPriority->Location = System::Drawing::Point(79, 77);
			this->TextBoxPriority->Name = L"TextBoxPriority";
			this->TextBoxPriority->Size = System::Drawing::Size(100, 20);
			this->TextBoxPriority->TabIndex = 10;
			// 
			// TextBoxWait
			// 
			this->TextBoxWait->Location = System::Drawing::Point(79, 42);
			this->TextBoxWait->Name = L"TextBoxWait";
			this->TextBoxWait->Size = System::Drawing::Size(100, 20);
			this->TextBoxWait->TabIndex = 9;
			// 
			// ContainerListBox
			// 
			this->ContainerListBox->Controls->Add(this->button3);
			this->ContainerListBox->Controls->Add(this->QButtonPlus);
			this->ContainerListBox->Controls->Add(this->QButtonUnequal);
			this->ContainerListBox->Controls->Add(this->QButtonCompare);
			this->ContainerListBox->Controls->Add(this->QButtonAssign);
			this->ContainerListBox->Controls->Add(this->QListBox2);
			this->ContainerListBox->Controls->Add(this->QListBox1);
			this->ContainerListBox->Enabled = false;
			this->ContainerListBox->Location = System::Drawing::Point(245, 128);
			this->ContainerListBox->Name = L"ContainerListBox";
			this->ContainerListBox->Size = System::Drawing::Size(350, 153);
			this->ContainerListBox->TabIndex = 7;
			this->ContainerListBox->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FormQueuePrioritiy::ContainerListBox_Paint);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::White;
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button3->ImageAlign = System::Drawing::ContentAlignment::BottomRight;
			this->button3->ImageKey = L"(отсутствует)";
			this->button3->Location = System::Drawing::Point(149, 124);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(52, 23);
			this->button3->TabIndex = 15;
			this->button3->Text = L"| (swap)";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &FormQueuePrioritiy::button3_Click);
			// 
			// QButtonPlus
			// 
			this->QButtonPlus->BackColor = System::Drawing::Color::White;
			this->QButtonPlus->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"QButtonPlus.BackgroundImage")));
			this->QButtonPlus->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->QButtonPlus->ImageAlign = System::Drawing::ContentAlignment::BottomRight;
			this->QButtonPlus->ImageKey = L"(отсутствует)";
			this->QButtonPlus->Location = System::Drawing::Point(149, 95);
			this->QButtonPlus->Name = L"QButtonPlus";
			this->QButtonPlus->Size = System::Drawing::Size(52, 23);
			this->QButtonPlus->TabIndex = 14;
			this->QButtonPlus->Text = L"+";
			this->QButtonPlus->UseVisualStyleBackColor = false;
			this->QButtonPlus->Click += gcnew System::EventHandler(this, &FormQueuePrioritiy::QButtonPlus_Click);
			// 
			// QButtonUnequal
			// 
			this->QButtonUnequal->BackColor = System::Drawing::Color::White;
			this->QButtonUnequal->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"QButtonUnequal.BackgroundImage")));
			this->QButtonUnequal->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->QButtonUnequal->ImageAlign = System::Drawing::ContentAlignment::BottomRight;
			this->QButtonUnequal->ImageKey = L"(отсутствует)";
			this->QButtonUnequal->Location = System::Drawing::Point(149, 66);
			this->QButtonUnequal->Name = L"QButtonUnequal";
			this->QButtonUnequal->Size = System::Drawing::Size(52, 23);
			this->QButtonUnequal->TabIndex = 13;
			this->QButtonUnequal->Text = L"!=";
			this->QButtonUnequal->UseVisualStyleBackColor = false;
			this->QButtonUnequal->Click += gcnew System::EventHandler(this, &FormQueuePrioritiy::QButtonUnequal_Click);
			// 
			// QButtonCompare
			// 
			this->QButtonCompare->BackColor = System::Drawing::Color::White;
			this->QButtonCompare->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"QButtonCompare.BackgroundImage")));
			this->QButtonCompare->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->QButtonCompare->ImageAlign = System::Drawing::ContentAlignment::BottomRight;
			this->QButtonCompare->ImageKey = L"(отсутствует)";
			this->QButtonCompare->Location = System::Drawing::Point(149, 37);
			this->QButtonCompare->Name = L"QButtonCompare";
			this->QButtonCompare->Size = System::Drawing::Size(52, 23);
			this->QButtonCompare->TabIndex = 12;
			this->QButtonCompare->Text = L"==";
			this->QButtonCompare->UseVisualStyleBackColor = false;
			this->QButtonCompare->Click += gcnew System::EventHandler(this, &FormQueuePrioritiy::QButtonCompare_Click);
			// 
			// QButtonAssign
			// 
			this->QButtonAssign->BackColor = System::Drawing::Color::White;
			this->QButtonAssign->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"QButtonAssign.BackgroundImage")));
			this->QButtonAssign->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->QButtonAssign->ImageAlign = System::Drawing::ContentAlignment::BottomRight;
			this->QButtonAssign->ImageKey = L"(отсутствует)";
			this->QButtonAssign->Location = System::Drawing::Point(149, 8);
			this->QButtonAssign->Name = L"QButtonAssign";
			this->QButtonAssign->Size = System::Drawing::Size(52, 23);
			this->QButtonAssign->TabIndex = 11;
			this->QButtonAssign->Text = L"=";
			this->QButtonAssign->UseVisualStyleBackColor = false;
			this->QButtonAssign->Click += gcnew System::EventHandler(this, &FormQueuePrioritiy::QButtonAssign_Click);
			// 
			// QListBox2
			// 
			this->QListBox2->FormattingEnabled = true;
			this->QListBox2->Location = System::Drawing::Point(207, 4);
			this->QListBox2->Name = L"QListBox2";
			this->QListBox2->Size = System::Drawing::Size(140, 147);
			this->QListBox2->TabIndex = 1;
			this->QListBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &FormQueuePrioritiy::QListBox2_SelectedIndexChanged);
			// 
			// QListBox1
			// 
			this->QListBox1->FormattingEnabled = true;
			this->QListBox1->Location = System::Drawing::Point(3, 3);
			this->QListBox1->Name = L"QListBox1";
			this->QListBox1->Size = System::Drawing::Size(140, 147);
			this->QListBox1->TabIndex = 0;
			this->QListBox1->SelectedValueChanged += gcnew System::EventHandler(this, &FormQueuePrioritiy::QListBox1_SelectedValueChanged);
			// 
			// ContainerMethod
			// 
			this->ContainerMethod->Controls->Add(this->QButtonDelete);
			this->ContainerMethod->Controls->Add(this->QButtonAccumulate);
			this->ContainerMethod->Controls->Add(this->QButtonClear);
			this->ContainerMethod->Controls->Add(this->TextBoxFind);
			this->ContainerMethod->Controls->Add(this->QButtonFind);
			this->ContainerMethod->Controls->Add(this->QButtonMin);
			this->ContainerMethod->Controls->Add(this->QButtonBack);
			this->ContainerMethod->Controls->Add(this->QButtonForEach);
			this->ContainerMethod->Controls->Add(this->QButtonEmpty);
			this->ContainerMethod->Controls->Add(this->QButtonMax);
			this->ContainerMethod->Controls->Add(this->QButtonFront);
			this->ContainerMethod->Controls->Add(this->QButtonPop);
			this->ContainerMethod->Enabled = false;
			this->ContainerMethod->Location = System::Drawing::Point(625, 128);
			this->ContainerMethod->Name = L"ContainerMethod";
			this->ContainerMethod->Size = System::Drawing::Size(212, 148);
			this->ContainerMethod->TabIndex = 8;
			// 
			// QButtonDelete
			// 
			this->QButtonDelete->BackColor = System::Drawing::Color::White;
			this->QButtonDelete->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->QButtonDelete->ImageAlign = System::Drawing::ContentAlignment::BottomRight;
			this->QButtonDelete->ImageKey = L"(отсутствует)";
			this->QButtonDelete->Location = System::Drawing::Point(3, 119);
			this->QButtonDelete->Name = L"QButtonDelete";
			this->QButtonDelete->Size = System::Drawing::Size(206, 23);
			this->QButtonDelete->TabIndex = 18;
			this->QButtonDelete->Text = L"Видалити чергу";
			this->QButtonDelete->UseVisualStyleBackColor = false;
			this->QButtonDelete->Click += gcnew System::EventHandler(this, &FormQueuePrioritiy::button4_Click);
			// 
			// QButtonAccumulate
			// 
			this->QButtonAccumulate->BackColor = System::Drawing::Color::White;
			this->QButtonAccumulate->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"QButtonAccumulate.BackgroundImage")));
			this->QButtonAccumulate->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->QButtonAccumulate->ImageAlign = System::Drawing::ContentAlignment::BottomRight;
			this->QButtonAccumulate->ImageKey = L"(отсутствует)";
			this->QButtonAccumulate->Location = System::Drawing::Point(133, 32);
			this->QButtonAccumulate->Name = L"QButtonAccumulate";
			this->QButtonAccumulate->Size = System::Drawing::Size(76, 23);
			this->QButtonAccumulate->TabIndex = 10;
			this->QButtonAccumulate->Text = L"Accumulate";
			this->QButtonAccumulate->UseVisualStyleBackColor = false;
			this->QButtonAccumulate->Click += gcnew System::EventHandler(this, &FormQueuePrioritiy::button2_Click);
			// 
			// QButtonClear
			// 
			this->QButtonClear->BackColor = System::Drawing::Color::White;
			this->QButtonClear->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"QButtonClear.BackgroundImage")));
			this->QButtonClear->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->QButtonClear->ForeColor = System::Drawing::SystemColors::ControlText;
			this->QButtonClear->ImageAlign = System::Drawing::ContentAlignment::BottomRight;
			this->QButtonClear->ImageKey = L"(отсутствует)";
			this->QButtonClear->Location = System::Drawing::Point(133, 4);
			this->QButtonClear->Name = L"QButtonClear";
			this->QButtonClear->Size = System::Drawing::Size(76, 23);
			this->QButtonClear->TabIndex = 9;
			this->QButtonClear->Text = L"clear";
			this->QButtonClear->UseVisualStyleBackColor = false;
			this->QButtonClear->Click += gcnew System::EventHandler(this, &FormQueuePrioritiy::QButtonClear_Click);
			// 
			// TextBoxFind
			// 
			this->TextBoxFind->Location = System::Drawing::Point(133, 92);
			this->TextBoxFind->Name = L"TextBoxFind";
			this->TextBoxFind->Size = System::Drawing::Size(76, 20);
			this->TextBoxFind->TabIndex = 8;
			// 
			// QButtonFind
			// 
			this->QButtonFind->BackColor = System::Drawing::Color::White;
			this->QButtonFind->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"QButtonFind.BackgroundImage")));
			this->QButtonFind->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->QButtonFind->ImageAlign = System::Drawing::ContentAlignment::BottomRight;
			this->QButtonFind->ImageKey = L"(отсутствует)";
			this->QButtonFind->Location = System::Drawing::Point(68, 90);
			this->QButtonFind->Name = L"QButtonFind";
			this->QButtonFind->Size = System::Drawing::Size(59, 23);
			this->QButtonFind->TabIndex = 7;
			this->QButtonFind->Text = L"find";
			this->QButtonFind->UseVisualStyleBackColor = false;
			this->QButtonFind->Click += gcnew System::EventHandler(this, &FormQueuePrioritiy::QButtonFind_Click);
			// 
			// QButtonMin
			// 
			this->QButtonMin->BackColor = System::Drawing::Color::White;
			this->QButtonMin->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"QButtonMin.BackgroundImage")));
			this->QButtonMin->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->QButtonMin->ImageAlign = System::Drawing::ContentAlignment::BottomRight;
			this->QButtonMin->ImageKey = L"(отсутствует)";
			this->QButtonMin->Location = System::Drawing::Point(68, 61);
			this->QButtonMin->Name = L"QButtonMin";
			this->QButtonMin->Size = System::Drawing::Size(59, 23);
			this->QButtonMin->TabIndex = 6;
			this->QButtonMin->Text = L"min";
			this->QButtonMin->UseVisualStyleBackColor = false;
			this->QButtonMin->Click += gcnew System::EventHandler(this, &FormQueuePrioritiy::QButtonMin_Click);
			// 
			// QButtonBack
			// 
			this->QButtonBack->BackColor = System::Drawing::Color::White;
			this->QButtonBack->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"QButtonBack.BackgroundImage")));
			this->QButtonBack->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->QButtonBack->ImageAlign = System::Drawing::ContentAlignment::BottomRight;
			this->QButtonBack->ImageKey = L"(отсутствует)";
			this->QButtonBack->Location = System::Drawing::Point(68, 32);
			this->QButtonBack->Name = L"QButtonBack";
			this->QButtonBack->Size = System::Drawing::Size(59, 23);
			this->QButtonBack->TabIndex = 5;
			this->QButtonBack->Text = L"back";
			this->QButtonBack->UseVisualStyleBackColor = false;
			this->QButtonBack->Click += gcnew System::EventHandler(this, &FormQueuePrioritiy::QButtonBack_Click);
			// 
			// QButtonForEach
			// 
			this->QButtonForEach->BackColor = System::Drawing::Color::White;
			this->QButtonForEach->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"QButtonForEach.BackgroundImage")));
			this->QButtonForEach->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->QButtonForEach->ImageAlign = System::Drawing::ContentAlignment::BottomRight;
			this->QButtonForEach->ImageKey = L"(отсутствует)";
			this->QButtonForEach->Location = System::Drawing::Point(68, 3);
			this->QButtonForEach->Name = L"QButtonForEach";
			this->QButtonForEach->Size = System::Drawing::Size(59, 23);
			this->QButtonForEach->TabIndex = 4;
			this->QButtonForEach->Tag = L"43";
			this->QButtonForEach->Text = L"for_each";
			this->QButtonForEach->UseVisualStyleBackColor = false;
			this->QButtonForEach->Click += gcnew System::EventHandler(this, &FormQueuePrioritiy::QButtonForEach_Click);
			// 
			// QButtonEmpty
			// 
			this->QButtonEmpty->BackColor = System::Drawing::Color::White;
			this->QButtonEmpty->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"QButtonEmpty.BackgroundImage")));
			this->QButtonEmpty->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->QButtonEmpty->ImageAlign = System::Drawing::ContentAlignment::BottomRight;
			this->QButtonEmpty->ImageKey = L"(отсутствует)";
			this->QButtonEmpty->Location = System::Drawing::Point(3, 90);
			this->QButtonEmpty->Name = L"QButtonEmpty";
			this->QButtonEmpty->Size = System::Drawing::Size(59, 23);
			this->QButtonEmpty->TabIndex = 3;
			this->QButtonEmpty->Text = L"empty";
			this->QButtonEmpty->UseVisualStyleBackColor = false;
			this->QButtonEmpty->Click += gcnew System::EventHandler(this, &FormQueuePrioritiy::QButtonEmpty_Click);
			// 
			// QButtonMax
			// 
			this->QButtonMax->BackColor = System::Drawing::Color::White;
			this->QButtonMax->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"QButtonMax.BackgroundImage")));
			this->QButtonMax->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->QButtonMax->ImageAlign = System::Drawing::ContentAlignment::BottomRight;
			this->QButtonMax->ImageKey = L"(отсутствует)";
			this->QButtonMax->Location = System::Drawing::Point(3, 61);
			this->QButtonMax->Name = L"QButtonMax";
			this->QButtonMax->Size = System::Drawing::Size(59, 23);
			this->QButtonMax->TabIndex = 2;
			this->QButtonMax->Text = L"max";
			this->QButtonMax->UseVisualStyleBackColor = false;
			this->QButtonMax->Click += gcnew System::EventHandler(this, &FormQueuePrioritiy::QButtonMax_Click);
			// 
			// QButtonFront
			// 
			this->QButtonFront->BackColor = System::Drawing::Color::White;
			this->QButtonFront->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"QButtonFront.BackgroundImage")));
			this->QButtonFront->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->QButtonFront->ImageAlign = System::Drawing::ContentAlignment::BottomRight;
			this->QButtonFront->ImageKey = L"(отсутствует)";
			this->QButtonFront->Location = System::Drawing::Point(3, 32);
			this->QButtonFront->Name = L"QButtonFront";
			this->QButtonFront->Size = System::Drawing::Size(59, 23);
			this->QButtonFront->TabIndex = 1;
			this->QButtonFront->Text = L"front";
			this->QButtonFront->UseVisualStyleBackColor = false;
			this->QButtonFront->Click += gcnew System::EventHandler(this, &FormQueuePrioritiy::button10_Click);
			// 
			// QButtonPop
			// 
			this->QButtonPop->BackColor = System::Drawing::Color::White;
			this->QButtonPop->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"QButtonPop.BackgroundImage")));
			this->QButtonPop->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->QButtonPop->ImageAlign = System::Drawing::ContentAlignment::BottomRight;
			this->QButtonPop->ImageKey = L"(отсутствует)";
			this->QButtonPop->Location = System::Drawing::Point(3, 3);
			this->QButtonPop->Name = L"QButtonPop";
			this->QButtonPop->Size = System::Drawing::Size(59, 23);
			this->QButtonPop->TabIndex = 0;
			this->QButtonPop->Text = L"pop";
			this->QButtonPop->UseVisualStyleBackColor = false;
			this->QButtonPop->Click += gcnew System::EventHandler(this, &FormQueuePrioritiy::QButtonPop_Click);
			// 
			// ContainerPictureBox1
			// 
			this->ContainerPictureBox1->AutoScroll = true;
			this->ContainerPictureBox1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ContainerPictureBox1->Controls->Add(this->pictureBox1);
			this->ContainerPictureBox1->Location = System::Drawing::Point(287, 323);
			this->ContainerPictureBox1->Name = L"ContainerPictureBox1";
			this->ContainerPictureBox1->Size = System::Drawing::Size(600, 120);
			this->ContainerPictureBox1->TabIndex = 9;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(0, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(573, 100);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// LabelNumQueue1
			// 
			this->LabelNumQueue1->AutoSize = true;
			this->LabelNumQueue1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelNumQueue1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->LabelNumQueue1->Location = System::Drawing::Point(286, 287);
			this->LabelNumQueue1->Name = L"LabelNumQueue1";
			this->LabelNumQueue1->Size = System::Drawing::Size(0, 18);
			this->LabelNumQueue1->TabIndex = 14;
			// 
			// progressBar2
			// 
			this->progressBar2->Location = System::Drawing::Point(778, 452);
			this->progressBar2->Name = L"progressBar2";
			this->progressBar2->Size = System::Drawing::Size(100, 23);
			this->progressBar2->TabIndex = 12;
			this->progressBar2->Visible = false;
			// 
			// ContainerPictureBox2
			// 
			this->ContainerPictureBox2->AutoScroll = true;
			this->ContainerPictureBox2->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ContainerPictureBox2->Controls->Add(this->pictureBox2);
			this->ContainerPictureBox2->Location = System::Drawing::Point(287, 478);
			this->ContainerPictureBox2->Name = L"ContainerPictureBox2";
			this->ContainerPictureBox2->Size = System::Drawing::Size(600, 120);
			this->ContainerPictureBox2->TabIndex = 10;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(0, 3);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(570, 100);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox2->TabIndex = 0;
			this->pictureBox2->TabStop = false;
			// 
			// LabelNumQueue2
			// 
			this->LabelNumQueue2->AutoSize = true;
			this->LabelNumQueue2->Location = System::Drawing::Point(293, 462);
			this->LabelNumQueue2->Name = L"LabelNumQueue2";
			this->LabelNumQueue2->Size = System::Drawing::Size(0, 13);
			this->LabelNumQueue2->TabIndex = 13;
			// 
			// LabelStateQueue2
			// 
			this->LabelStateQueue2->AutoSize = true;
			this->LabelStateQueue2->Location = System::Drawing::Point(787, 457);
			this->LabelStateQueue2->Name = L"LabelStateQueue2";
			this->LabelStateQueue2->Size = System::Drawing::Size(0, 13);
			this->LabelStateQueue2->TabIndex = 12;
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(778, 294);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(100, 23);
			this->progressBar1->TabIndex = 11;
			this->progressBar1->Visible = false;
			// 
			// button17
			// 
			this->button17->BackColor = System::Drawing::Color::White;
			this->button17->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button17.BackgroundImage")));
			this->button17->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button17->ImageAlign = System::Drawing::ContentAlignment::BottomRight;
			this->button17->ImageKey = L"(отсутствует)";
			this->button17->Location = System::Drawing::Point(3, 36);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(257, 27);
			this->button17->TabIndex = 11;
			this->button17->Text = L"Відкрити чергу и створити нову (>>)";
			this->button17->UseVisualStyleBackColor = false;
			this->button17->Click += gcnew System::EventHandler(this, &FormQueuePrioritiy::button17_Click);
			// 
			// button18
			// 
			this->button18->BackColor = System::Drawing::Color::White;
			this->button18->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button18.BackgroundImage")));
			this->button18->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button18->ImageAlign = System::Drawing::ContentAlignment::BottomRight;
			this->button18->ImageKey = L"(отсутствует)";
			this->button18->Location = System::Drawing::Point(3, 69);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(257, 27);
			this->button18->TabIndex = 12;
			this->button18->Text = L"Зберегти чергу (<<)";
			this->button18->UseVisualStyleBackColor = false;
			this->button18->Click += gcnew System::EventHandler(this, &FormQueuePrioritiy::button18_Click);
			// 
			// button19
			// 
			this->button19->BackColor = System::Drawing::Color::White;
			this->button19->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button19.BackgroundImage")));
			this->button19->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button19->ImageAlign = System::Drawing::ContentAlignment::BottomRight;
			this->button19->ImageKey = L"(отсутствует)";
			this->button19->Location = System::Drawing::Point(3, 102);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(257, 27);
			this->button19->TabIndex = 13;
			this->button19->Text = L"Зберегти і видалити чергу (>>)";
			this->button19->UseVisualStyleBackColor = false;
			this->button19->Click += gcnew System::EventHandler(this, &FormQueuePrioritiy::button19_Click);
			// 
			// ContainerSaveOpen
			// 
			this->ContainerSaveOpen->Controls->Add(this->button1);
			this->ContainerSaveOpen->Controls->Add(this->button19);
			this->ContainerSaveOpen->Controls->Add(this->button17);
			this->ContainerSaveOpen->Controls->Add(this->button18);
			this->ContainerSaveOpen->Enabled = false;
			this->ContainerSaveOpen->Location = System::Drawing::Point(857, 126);
			this->ContainerSaveOpen->Name = L"ContainerSaveOpen";
			this->ContainerSaveOpen->Size = System::Drawing::Size(265, 136);
			this->ContainerSaveOpen->TabIndex = 14;
			// 
			// ContainerLabelShow
			// 
			this->ContainerLabelShow->AutoScroll = true;
			this->ContainerLabelShow->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ContainerLabelShow->Controls->Add(this->LabelShowQueue);
			this->ContainerLabelShow->Location = System::Drawing::Point(20, 299);
			this->ContainerLabelShow->Name = L"ContainerLabelShow";
			this->ContainerLabelShow->Size = System::Drawing::Size(230, 310);
			this->ContainerLabelShow->TabIndex = 15;
			// 
			// LabelShowQueue
			// 
			this->LabelShowQueue->AutoSize = true;
			this->LabelShowQueue->Location = System::Drawing::Point(33, 3);
			this->LabelShowQueue->Name = L"LabelShowQueue";
			this->LabelShowQueue->Size = System::Drawing::Size(0, 13);
			this->LabelShowQueue->TabIndex = 17;
			// 
			// LabelIActionQueue
			// 
			this->LabelIActionQueue->AutoSize = true;
			this->LabelIActionQueue->BackColor = System::Drawing::SystemColors::Control;
			this->LabelIActionQueue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelIActionQueue->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->LabelIActionQueue->Location = System::Drawing::Point(365, 287);
			this->LabelIActionQueue->Name = L"LabelIActionQueue";
			this->LabelIActionQueue->Size = System::Drawing::Size(0, 16);
			this->LabelIActionQueue->TabIndex = 16;
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::White;
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->файлToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(20, 60);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->menuStrip1->Size = System::Drawing::Size(1087, 24);
			this->menuStrip1->TabIndex = 17;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &FormQueuePrioritiy::menuStrip1_ItemClicked);
			// 
			// файлToolStripMenuItem
			// 
			this->файлToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->відкритиToolStripMenuItem,
					this->зберегтиToolStripMenuItem, this->довідкаToolStripMenuItem, this->вихідToolStripMenuItem
			});
			this->файлToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->файлToolStripMenuItem->ForeColor = System::Drawing::Color::Black;
			this->файлToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::White;
			this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
			this->файлToolStripMenuItem->Size = System::Drawing::Size(51, 20);
			this->файлToolStripMenuItem->Text = L"Файл";
			// 
			// відкритиToolStripMenuItem
			// 
			this->відкритиToolStripMenuItem->Name = L"відкритиToolStripMenuItem";
			this->відкритиToolStripMenuItem->Size = System::Drawing::Size(204, 22);
			this->відкритиToolStripMenuItem->Text = L"Відкрити чергу як нову";
			this->відкритиToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormQueuePrioritiy::відкритиToolStripMenuItem_Click);
			// 
			// зберегтиToolStripMenuItem
			// 
			this->зберегтиToolStripMenuItem->Name = L"зберегтиToolStripMenuItem";
			this->зберегтиToolStripMenuItem->Size = System::Drawing::Size(204, 22);
			this->зберегтиToolStripMenuItem->Text = L"Зберегти";
			this->зберегтиToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormQueuePrioritiy::зберегтиToolStripMenuItem_Click);
			// 
			// довідкаToolStripMenuItem
			// 
			this->довідкаToolStripMenuItem->Name = L"довідкаToolStripMenuItem";
			this->довідкаToolStripMenuItem->Size = System::Drawing::Size(204, 22);
			this->довідкаToolStripMenuItem->Text = L"Довідка";
			this->довідкаToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormQueuePrioritiy::довідкаToolStripMenuItem_Click);
			// 
			// вихідToolStripMenuItem
			// 
			this->вихідToolStripMenuItem->Name = L"вихідToolStripMenuItem";
			this->вихідToolStripMenuItem->Size = System::Drawing::Size(204, 22);
			this->вихідToolStripMenuItem->Text = L"Вихід";
			this->вихідToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormQueuePrioritiy::вихідToolStripMenuItem_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(341, 60);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 13);
			this->label2->TabIndex = 18;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(85, 10);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(42, 13);
			this->label3->TabIndex = 19;
			this->label3->Text = L"Розмір";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(253, 10);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(39, 13);
			this->label4->TabIndex = 21;
			this->label4->Text = L"Назва";
			// 
			// TextBoxNameQueue
			// 
			this->TextBoxNameQueue->Location = System::Drawing::Point(301, 7);
			this->TextBoxNameQueue->Name = L"TextBoxNameQueue";
			this->TextBoxNameQueue->Size = System::Drawing::Size(113, 20);
			this->TextBoxNameQueue->TabIndex = 20;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(17, 283);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(202, 13);
			this->label5->TabIndex = 22;
			this->label5->Text = L"Елементи відсортовані за пріорітетом ";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->QButtonCreate);
			this->panel1->Controls->Add(this->TextBoxCreateQueue);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->TextBoxNameQueue);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Location = System::Drawing::Point(23, 91);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(423, 31);
			this->panel1->TabIndex = 23;
			// 
			// LabelStateQueue1
			// 
			this->LabelStateQueue1->AutoSize = true;
			this->LabelStateQueue1->Location = System::Drawing::Point(787, 299);
			this->LabelStateQueue1->Name = L"LabelStateQueue1";
			this->LabelStateQueue1->Size = System::Drawing::Size(0, 13);
			this->LabelStateQueue1->TabIndex = 13;
			// 
			// FormQueuePrioritiy
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BorderStyle = MetroFramework::Forms::MetroFormBorderStyle::FixedSingle;
			this->ClientSize = System::Drawing::Size(1127, 619);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->LabelStateQueue2);
			this->Controls->Add(this->LabelStateQueue1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->LabelNumQueue2);
			this->Controls->Add(this->progressBar2);
			this->Controls->Add(this->LabelNumQueue1);
			this->Controls->Add(this->LabelIActionQueue);
			this->Controls->Add(this->ContainerLabelShow);
			this->Controls->Add(this->ContainerSaveOpen);
			this->Controls->Add(this->ContainerPictureBox2);
			this->Controls->Add(this->ContainerPictureBox1);
			this->Controls->Add(this->ContainerMethod);
			this->Controls->Add(this->ContainerListBox);
			this->Controls->Add(this->ContainerPush);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Name = L"FormQueuePrioritiy";
			this->Text = L"Черга з пріорітетом.";
			this->Load += gcnew System::EventHandler(this, &FormQueuePrioritiy::FormQueuePrioritiy_Load);
			this->ContainerPush->ResumeLayout(false);
			this->ContainerPush->PerformLayout();
			this->ContainerListBox->ResumeLayout(false);
			this->ContainerMethod->ResumeLayout(false);
			this->ContainerMethod->PerformLayout();
			this->ContainerPictureBox1->ResumeLayout(false);
			this->ContainerPictureBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ContainerPictureBox2->ResumeLayout(false);
			this->ContainerPictureBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ContainerSaveOpen->ResumeLayout(false);
			this->ContainerLabelShow->ResumeLayout(false);
			this->ContainerLabelShow->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		////////////////////////////////////////////////////////////////////////////
		const int SIZE_QUEUE = 50;
		QueueComponentForm^ QComponent = gcnew QueueComponentForm;
		array<QueuePriority<int>*>^ QPList = gcnew array<QueuePriority<int>*>(SIZE_QUEUE);
		bool*flag = new bool(false);
		int*QCcounter = new int(0);
		int*QCcurrent = new int(0);
		int*QCcurrentTwo = new int(0);
		////////////////////////////////////////////////////////////////////////////

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

			CreateQueue(QPList, QComponent);
		
	}

	private: System::Void FormQueuePrioritiy_Load(System::Object^  sender, System::EventArgs^  e) {
		QComponent->InitializeComponent(LabelStateQueue1, LabelStateQueue2, LabelShowQueue, LabelIActionQueue, LabelNumQueue1, LabelNumQueue2);
		QComponent->InitializeComponent(TextBoxWait, TextBoxPriority, TextBoxCreateQueue, TextBoxFind, TextBoxNameQueue);
		QComponent->InitializeComponent(pictureBox1, pictureBox2);
		QComponent->InitializeComponent(ContainerPictureBox1, ContainerPictureBox2, ContainerPush, ContainerListBox, ContainerMethod, ContainerSaveOpen, ContainerLabelShow);
		QComponent->InitializeComponent(progressBar1, progressBar2);
		QComponent->InitializeField( QCcounter, QCcurrent, QCcurrentTwo, flag);
		QComponent->InitializeComponent(QListBox1, QListBox2);
		QPList[0] = nullptr;
		label2->Text = "Максимально можливий розмір черги може бути: " + Convert::ToString(QueuePriority<int>::MaximumPossibleQueueLength)+"; Максимальная кількість черг: "+SIZE_QUEUE+".";
	}

	private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
		FrontQueue(QPList, QComponent);
	}

	private: System::Void QButtonRandomFilling_Click(System::Object^  sender, System::EventArgs^  e) {
		RandomFillingQueue(QPList, QComponent);
	}

	private: System::Void QListBox1_SelectedValueChanged(System::Object^  sender, System::EventArgs^  e) {
		SelectedChangeLeft(QPList, QComponent);
	}
	private: System::Void QListBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		SelectedChangeRight(QPList, QComponent);
	}
	private: System::Void QButtonPop_Click(System::Object^  sender, System::EventArgs^  e) {
		PopQueue(QPList, QComponent);
	}
	private: System::Void QButtonPush_Click(System::Object^  sender, System::EventArgs^  e) {
		PushQueue(QPList, QComponent);
	}
	private: System::Void QButtonBack_Click(System::Object^  sender, System::EventArgs^  e) {
		BackQueue(QPList, QComponent);
	}
	private: System::Void QButtonMax_Click(System::Object^  sender, System::EventArgs^  e) {
		MaxQueue(QPList, QComponent);
	}
	private: System::Void QButtonMin_Click(System::Object^  sender, System::EventArgs^  e) {
		MinQueue(QPList, QComponent);
	}
	private: System::Void QButtonEmpty_Click(System::Object^  sender, System::EventArgs^  e) {
		EmptyQueue(QPList, QComponent);
	}
	private: System::Void QButtonFind_Click(System::Object^  sender, System::EventArgs^  e) {
		FindQueue(QPList, QComponent);
	}
	private: System::Void QButtonForEach_Click(System::Object^  sender, System::EventArgs^  e) {
		ForEachQueue(QPList, QComponent);
	}
	private: System::Void QButtonClear_Click(System::Object^  sender, System::EventArgs^  e) {
		ClearQueue(QPList, QComponent);
	}
	private: System::Void QButtonCompare_Click(System::Object^  sender, System::EventArgs^  e) {
		CompareQueue(QPList, QComponent);
	}
	private: System::Void QButtonUnequal_Click(System::Object^  sender, System::EventArgs^  e) {
		NotEqualQueue(QPList, QComponent);
	}
	private: System::Void QButtonPlus_Click(System::Object^  sender, System::EventArgs^  e) {
		//label1->Text = Convert::ToString(QPList[QComponent->getCurrentTwo()]);
		PlusQueue(QPList, QComponent);
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		AccumulateQueue(QPList, QComponent);
	}
	private: System::Void QButtonAssign_Click(System::Object^  sender, System::EventArgs^  e) {
		AssignQueue(QPList, QComponent);
	}
	private: System::Void ContainerListBox_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		SwapQueue(QPList, QComponent);
	}
	private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog^ openDlg = gcnew OpenFileDialog();
		openDlg->Filter = "Files(*.txt;)|*.txt;";
		if (System::Windows::Forms::DialogResult::OK == openDlg->ShowDialog())
		{
			OpenQueueRewrite(QPList, QComponent, ConvertSlitoStlString(openDlg->FileName));
		}
	}
	private: System::Void button18_Click(System::Object^  sender, System::EventArgs^  e) {
		SaveQueue(QPList, QComponent);
	}
	private: System::Void button19_Click(System::Object^  sender, System::EventArgs^  e) {
		SaveAndDeleteQueue(QPList, QComponent);
	}

	private: System::Void відкритиToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog^ openDlg = gcnew OpenFileDialog();
		openDlg->Filter = "Files(*.txt;)|*.txt;";
		if (System::Windows::Forms::DialogResult::OK == openDlg->ShowDialog())
		{
			OpenQueueNew(QPList, QComponent, ConvertSlitoStlString(openDlg->FileName), openDlg->SafeFileName);
		}
		
	}

	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		DeleteQueue(QPList, QComponent);
	}
	private: System::Void button17_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog^ openDlg = gcnew OpenFileDialog();
		openDlg->Filter = "Files(*.txt;)|*.txt;";
		if (System::Windows::Forms::DialogResult::OK == openDlg->ShowDialog())
		{
			OpenQueueNew(QPList, QComponent, ConvertSlitoStlString(openDlg->FileName), openDlg->SafeFileName);
		}
	}
	private: System::Void зберегтиToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		SaveQueue(QPList, QComponent);
	}
	private: System::Void menuStrip1_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
	}
	private: System::Void довідкаToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		FormInfo ^ form = gcnew FormInfo();
		form->ShowDialog();
	}
private: System::Void вихідToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}
};
}
