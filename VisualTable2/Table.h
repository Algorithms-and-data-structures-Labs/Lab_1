#pragma once
#include "Polinom\TPolinom.h"
#include "table\alltable.h"

#include <msclr\marshal_cppstd.h>


namespace VisualTable2 {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


public
ref class Table : public System::Windows::Forms::Form {
 public:
  Table(void) {
    InitializeComponent();
  }

 protected:

  ~Table() {
    if (components) {
      delete components;
    }
  }

 private:
  System::Windows::Forms::DataGridView ^ dataGridView1;

 protected:
 private:
  System::Windows::Forms::DataGridViewTextBoxColumn ^ Name;

 private:
  System::Windows::Forms::DataGridViewTextBoxColumn ^ Polinom;

 private:
  System::Windows::Forms::Button ^ button1;

 private:
  System::Windows::Forms::TextBox ^ textBox1;

 private:
  System::Windows::Forms::Button ^ button2;

 private:

  System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code

  void InitializeComponent(void) {
    this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
    this->Name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
    this->Polinom = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
    this->button1 = (gcnew System::Windows::Forms::Button());
    this->textBox1 = (gcnew System::Windows::Forms::TextBox());
    this->button2 = (gcnew System::Windows::Forms::Button());
    (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
         this->dataGridView1))
        ->BeginInit();
    this->SuspendLayout();
    //
    // dataGridView1
    //
    this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::
        DataGridViewColumnHeadersHeightSizeMode::AutoSize;
    this->dataGridView1->Columns->AddRange(
        gcnew cli::array<System::Windows::Forms::DataGridViewColumn ^>(2){
            this->Name, this->Polinom});
    this->dataGridView1->Location = System::Drawing::Point(12, 12);
    this->dataGridView1->Name = L"dataGridView1";
    this->dataGridView1->RowHeadersWidth = 51;
    this->dataGridView1->RowTemplate->Height = 24;
    this->dataGridView1->Size = System::Drawing::Size(477, 275);
    this->dataGridView1->TabIndex = 0;
    this->dataGridView1->CellContentClick +=
        gcnew System::Windows::Forms::DataGridViewCellEventHandler(
            this, &Table::dataGridView1_CellContentClick);
    //
    // Name
    //
    this->Name->HeaderText = L"Name";
    this->Name->MinimumWidth = 6;
    this->Name->Name = L"Name";
    this->Name->Width = 125;
    //
    // Polinom
    //
    this->Polinom->HeaderText = L"Polinom";
    this->Polinom->MinimumWidth = 6;
    this->Polinom->Name = L"Polinom";
    this->Polinom->Width = 125;
    //
    // button1
    //
    this->button1->Location = System::Drawing::Point(12, 327);
    this->button1->Name = L"button1";
    this->button1->Size = System::Drawing::Size(160, 23);
    this->button1->TabIndex = 1;
    this->button1->Text = L"Добавить Полином";
    this->button1->UseVisualStyleBackColor = true;
    this->button1->Click +=
        gcnew System::EventHandler(this, &Table::button1_Click);
    //
    // textBox1
    //
    this->textBox1->Location = System::Drawing::Point(15, 299);
    this->textBox1->Name = L"textBox1";
    this->textBox1->Size = System::Drawing::Size(290, 22);
    this->textBox1->TabIndex = 2;
    //
    // button2
    //
    this->button2->Location = System::Drawing::Point(12, 356);
    this->button2->Name = L"button2";
    this->button2->Size = System::Drawing::Size(160, 23);
    this->button2->TabIndex = 3;
    this->button2->Text = L"Удалить Полином";
    this->button2->UseVisualStyleBackColor = true;
    //
    // Table
    //
    this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->ClientSize = System::Drawing::Size(891, 454);
    this->Controls->Add(this->button2);
    this->Controls->Add(this->textBox1);
    this->Controls->Add(this->button1);
    this->Controls->Add(this->dataGridView1);
    this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
    this->Name = L"Table";
    this->Text = L"Table";
    this->Load += gcnew System::EventHandler(this, &Table::Table_Load);
    (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
         this->dataGridView1))
        ->EndInit();
    this->ResumeLayout(false);
    this->PerformLayout();
  }
#pragma endregion
 private:
  System::Void Table_Load(System::Object ^ sender, System::EventArgs ^ e) {}

 private:
  System::Void dataGridView1_CellContentClick(
      System::Object ^ sender,
      System::Windows::Forms::DataGridViewCellEventArgs ^ e) {}

 private:
  vector<int> convertToVector(const string& inputString) {
    vector<int> resultVector;

    for (char c : inputString) {
      resultVector.push_back(c - '0');
    }

    return resultVector;
  }

 private:
  System::Void button1_Click(System::Object ^ sender, System::EventArgs ^ e) {
    string PolSt =
        msclr::interop::marshal_as<string>(textBox1->Text);
    TPolinom polinom(convertToVector(PolSt));
    string polinomString = polinom.ToString();
    System::String ^ textBoxText =
        msclr::interop::marshal_as<System::String ^>(PolSt);
    dataGridView1->Rows->Add("1", textBoxText);
  }
};
}
