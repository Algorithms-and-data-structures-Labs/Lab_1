#pragma once
#include "C:\sema\Lab_1\Lab_1\include\Polinom\TPolinom.h"

namespace VisualTable2 {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// ������ ��� Table
/// </summary>
public
ref class Table : public System::Windows::Forms::Form {
 public:
  Table(void) {
    InitializeComponent();
    //
    // TODO: �������� ��� ������������
    //
  }

 protected:
  /// <summary>
  /// ���������� ��� ������������ �������.
  /// </summary>
  ~Table() {
    if (components) {
      delete components;
    }
  }

 private:
  /// <summary>
  /// ������������ ���������� ������������.
  /// </summary>
  System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
  /// <summary>
  /// ��������� ����� ��� ��������� ������������ � �� ���������
  /// ���������� ����� ������ � ������� ��������� ����.
  /// </summary>
  void InitializeComponent(void) {
    this->SuspendLayout();
    //
    // Table
    //
    this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->ClientSize = System::Drawing::Size(668, 369);
    this->Name = L"Table";
    this->Text = L"Table";
    this->Load += gcnew System::EventHandler(this, &Table::Table_Load);
    this->ResumeLayout(false);
  }
#pragma endregion
 private:
  System::Void Table_Load(System::Object ^ sender, System::EventArgs ^ e) {}
};
}  // namespace VisualTable
