#pragma once
#include"QueueComponentForm.h"
#include"QueuePriority.h"
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
using namespace System::Drawing::Imaging;
#pragma warning (disable: 4661)
class QueuePriorityDraw :private QueuePriority<int>
{
	//ширина комірки черги в picture box;
	static const int CELL_WIDTH_ = 40;

	//висота комірки черги в picture box;
	static const int CELL_HEIGHT_ = 50;

	//інтервал через який будуть малюватись комірки
	static const int CELL_INTERVAL_ = 10;

	//висота зображення
	static const int HEIGHT_IMG_ = 100;

	//Прокрутити до вказаного елемента черги
	static void scroll_panel_wait(QueueComponentForm^QComponen, int item);

public:

	QueuePriorityDraw();
	static void clear_component(QueueComponentForm ^ QComponent, int NumPcitureBox);
	template<class Type>
	static  void draw_item(array<QueuePriority<Type>*>^ queue, QueueComponentForm^QComponent, Brush^cell, int item, int NumPanel);
};

template<class Type>
inline void QueuePriorityDraw::draw_item(array<QueuePriority<Type>*>^ queue, QueueComponentForm^QComponent, Brush^brush, int item, int NumPanel)
{
	int currentQueue;
	if (NumPanel == 0) {
		currentQueue = QComponent->getCurrent();
	}
	else if (NumPanel == 1) {
		currentQueue = QComponent->getCurrentTwo();
	}

	if (queue[currentQueue]->size() != 0) {
		Bitmap^ bmp = gcnew Bitmap((CELL_WIDTH_ + CELL_INTERVAL_) * queue[currentQueue]->size(), HEIGHT_IMG_, PixelFormat::Format32bppArgb);
		//QComponent->LabelNumQueue1->Text= queue[QComponent->getCurrent()]->size();
		Graphics^ grfx = Graphics::FromImage(bmp);
		Font^ drawFont = gcnew Font("Verdana", 10);
		SolidBrush^ fontBrush = gcnew SolidBrush(Color::Blue);
		Pen^ pen = gcnew Pen(Color::Black);

		for (int i = 0; i < queue[currentQueue]->size(); i++) {
			if (item == i) {
				grfx->FillRectangle(brush, (CELL_WIDTH_ + CELL_INTERVAL_) * i, 0, CELL_WIDTH_, CELL_HEIGHT_);
				QComponent->LabelIActionQueue->Text = queue[QComponent->getCurrent()]->infoItem(i);
			}
			grfx->DrawString(Convert::ToString(queue[currentQueue]->getWait(i)), drawFont, fontBrush, float((CELL_WIDTH_ + CELL_INTERVAL_) * i), 0);
			grfx->DrawString(Convert::ToString(queue[currentQueue]->getPri(i)), drawFont, fontBrush, float((CELL_WIDTH_ + CELL_INTERVAL_) * i), 30);
			grfx->DrawString(Convert::ToString(i), drawFont, fontBrush, float((CELL_WIDTH_ + CELL_INTERVAL_) * i), 60);

			grfx->DrawRectangle(pen, (CELL_WIDTH_ + CELL_INTERVAL_) * i, 0, CELL_WIDTH_, CELL_HEIGHT_ / 2);
			grfx->DrawRectangle(pen, (CELL_WIDTH_ + CELL_INTERVAL_) * i, 25, CELL_WIDTH_, CELL_HEIGHT_ / 2);
		}

		if (NumPanel == 0) {
			QComponent->PictureBox1->Image = bmp;
			scroll_panel_wait(QComponent, item);
		}
		else if (NumPanel == 1) {
			QComponent->PictureBox2->Image = bmp;
		}
	}
	else {
		//clear_component(QComponent, NumPanel);
	}
}
