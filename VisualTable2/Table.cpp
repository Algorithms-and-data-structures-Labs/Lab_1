#include "Table.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread] void Main() {
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);

  VisualTable2::Table form;
  Application::Run(% form);
}
