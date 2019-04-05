#include "FormQueuePrioritiy.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	QueuePriority2::FormQueuePrioritiy form;
	Application::Run(%form);
}