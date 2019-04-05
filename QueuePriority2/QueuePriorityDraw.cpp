#include "QueuePriorityDraw.h"

void QueuePriorityDraw::scroll_panel_wait(QueueComponentForm ^ QComponent, int item)
{	//если елемент не -1 начинаю скролл
	if (item != -1) {
		//длинна pciturebox
		int maximu = QComponent->ContainerPictureBox1->HorizontalScroll->Maximum;
		//если больше максимуму, беру максимальное значение
		int scroll = (CELL_WIDTH_ + CELL_INTERVAL_) * item > maximu ? maximu : 50 * item;

		QComponent->ContainerPictureBox1->HorizontalScroll->Value = scroll;
		QComponent->ContainerPictureBox1->HorizontalScroll->Value = scroll;
	}
}

void QueuePriorityDraw::clear_component(QueueComponentForm ^ QComponent, int NumPcitureBox)
{
	if (NumPcitureBox == 0) {
		QComponent->ProgressBar1->Value = 0;
		QComponent->LabelIActionQueue->Text = "";
		QComponent->LabelShowQueue->Text = "";
		QComponent->LabelNumQueue1->Text = "";
		QComponent->LabelStateQueue1->Text = "";
		QComponent->PictureBox1->Image = nullptr;
		QComponent->PictureBox1->Refresh();
	}
	else if (NumPcitureBox == 1) {
		QComponent->ProgressBar2->Value = 0;
		QComponent->LabelNumQueue2->Text = "";
		QComponent->LabelStateQueue2->Text = "";
		QComponent->PictureBox2->Image = nullptr;
		QComponent->PictureBox2->Refresh();
	}
}

QueuePriorityDraw::QueuePriorityDraw()
{
}

