#pragma once
#define _HAS_STD_BYTE 0
#include <Polinom/TPolinom.h>
#include <msclr\marshal_cppstd.h>
#include <table/ListHashTable.h>
#include <table/ListTable.h>
#include <table/OpenAddressingHashTable.h>
#include <table/TreeTable.h>
#include <table/tablearr.h>
#include <table/tablearrsort.h>

namespace VisualTable2 {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public
ref class Table : public System::Windows::Forms::Form {
 private:
  ListTable<string, TPolinom>* listTable;
  ArrayTable<string, TPolinom>* arrayTable;
  TreeTable<string, TPolinom>* treeTable;
  ListHashTable<string, TPolinom>* listhashTable;
  OpenAddrHashTable<string, TPolinom>* openAddrHashTable;
  SortArrayTable<string, TPolinom>* sortArrayTable;
  int count;
  int lT, aT, tT, lhT, oahT, saT;

 private:
  System::Windows::Forms::DataGridViewTextBoxColumn ^ Column1;

 private:
  System::Windows::Forms::Label ^ label1;

 private:
  System::Windows::Forms::DataGridView ^ dataGridView2;

 private:
  System::Windows::Forms::Label ^ label2;

 private:
  System::Windows::Forms::DataGridViewTextBoxColumn ^ Column2;

 private:
  System::Windows::Forms::DataGridViewTextBoxColumn ^ Column3;

 private:
  System::Windows::Forms::Label ^ label3;

 private:
  System::Windows::Forms::DataGridView ^ dataGridView3;

 private:
  System::Windows::Forms::DataGridViewTextBoxColumn ^ Column4;

 private:
  System::Windows::Forms::DataGridViewTextBoxColumn ^ Column5;

 private:
  System::Windows::Forms::Label ^ label4;

 private:
  System::Windows::Forms::DataGridView ^ dataGridView4;

 private:
  System::Windows::Forms::DataGridViewTextBoxColumn ^ Column6;

 private:
  System::Windows::Forms::DataGridViewTextBoxColumn ^ Column7;

 private:
  System::Windows::Forms::DataGridView ^ dataGridView5;

 private:
  System::Windows::Forms::DataGridViewTextBoxColumn ^
      dataGridViewTextBoxColumn1;

 private:
  System::Windows::Forms::DataGridViewTextBoxColumn ^
      dataGridViewTextBoxColumn2;

 private:
  System::Windows::Forms::DataGridView ^ dataGridView6;

 private:
  System::Windows::Forms::DataGridViewTextBoxColumn ^
      dataGridViewTextBoxColumn3;

 private:
  System::Windows::Forms::DataGridViewTextBoxColumn ^
      dataGridViewTextBoxColumn4;

 private:
  System::Windows::Forms::Label ^ label5;

 private:
  System::Windows::Forms::Label ^ label6;

 private:
  System::Windows::Forms::Label ^ label7;

 private:
  System::Windows::Forms::TextBox ^ textBox2;

 private:
  System::Windows::Forms::DataGridViewTextBoxColumn ^ Polinom;

 private:
  System::Windows::Forms::TextBox ^ textBox3;

 private:
  System::Windows::Forms::ComboBox ^ comboBox1;

 private:
  System::Windows::Forms::Label ^ label8;

 private:
  System::Windows::Forms::TextBox ^ textBox5;

 private:
  System::Windows::Forms::TextBox ^ textBox6;

 private:
  System::Windows::Forms::TextBox ^ textBox7;

 private:
  System::Windows::Forms::Label ^ label9;

 private:
  System::Windows::Forms::TextBox ^ textBox8;

 private:
  System::Windows::Forms::Button ^ button4;

 private:
  System::Windows::Forms::Label ^ label11;

 private:
  System::Windows::Forms::TextBox ^ textBox9;

 private:
  System::Windows::Forms::Button ^ button5;

 private:
  System::Windows::Forms::Button ^ button6;

 private:
  System::Windows::Forms::Button ^ button7;

 private:
  System::Windows::Forms::Label ^ label10;

 private:
  System::Windows::Forms::TextBox ^ textBox4;

 public:
  Table(void) {
    InitializeComponent();
    listTable = new ListTable<string, TPolinom>();
    arrayTable = new ArrayTable<string, TPolinom>();
    treeTable = new TreeTable<string, TPolinom>();
    listhashTable = new ListHashTable<string, TPolinom>(25);
    openAddrHashTable = new OpenAddrHashTable<string, TPolinom>(25, 2);
    sortArrayTable = new SortArrayTable<string, TPolinom>();
    count = 0;
    aT = lT = tT = lhT = oahT = saT = 1;
  }

 protected:
  ~Table() {
    if (components) {
      delete components;
    }
  }

 private:
  System::Windows::Forms::DataGridView ^ dataGridView1;

 private:
  System::Windows::Forms::DataGridViewTextBoxColumn ^ Name;

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
    this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
    this->Polinom = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
    this->button1 = (gcnew System::Windows::Forms::Button());
    this->textBox1 = (gcnew System::Windows::Forms::TextBox());
    this->button2 = (gcnew System::Windows::Forms::Button());
    this->label1 = (gcnew System::Windows::Forms::Label());
    this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
    this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
    this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
    this->label2 = (gcnew System::Windows::Forms::Label());
    this->label3 = (gcnew System::Windows::Forms::Label());
    this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
    this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
    this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
    this->label4 = (gcnew System::Windows::Forms::Label());
    this->dataGridView4 = (gcnew System::Windows::Forms::DataGridView());
    this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
    this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
    this->dataGridView5 = (gcnew System::Windows::Forms::DataGridView());
    this->dataGridViewTextBoxColumn1 =
        (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
    this->dataGridViewTextBoxColumn2 =
        (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
    this->dataGridView6 = (gcnew System::Windows::Forms::DataGridView());
    this->dataGridViewTextBoxColumn3 =
        (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
    this->dataGridViewTextBoxColumn4 =
        (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
    this->label5 = (gcnew System::Windows::Forms::Label());
    this->label6 = (gcnew System::Windows::Forms::Label());
    this->label7 = (gcnew System::Windows::Forms::Label());
    this->textBox2 = (gcnew System::Windows::Forms::TextBox());
    this->textBox3 = (gcnew System::Windows::Forms::TextBox());
    this->textBox4 = (gcnew System::Windows::Forms::TextBox());
    this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
    this->label8 = (gcnew System::Windows::Forms::Label());
    this->textBox5 = (gcnew System::Windows::Forms::TextBox());
    this->textBox6 = (gcnew System::Windows::Forms::TextBox());
    this->textBox7 = (gcnew System::Windows::Forms::TextBox());
    this->label9 = (gcnew System::Windows::Forms::Label());
    this->textBox8 = (gcnew System::Windows::Forms::TextBox());
    this->button4 = (gcnew System::Windows::Forms::Button());
    this->label11 = (gcnew System::Windows::Forms::Label());
    this->textBox9 = (gcnew System::Windows::Forms::TextBox());
    this->button5 = (gcnew System::Windows::Forms::Button());
    this->button6 = (gcnew System::Windows::Forms::Button());
    this->button7 = (gcnew System::Windows::Forms::Button());
    this->label10 = (gcnew System::Windows::Forms::Label());
    (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
         this->dataGridView1))
        ->BeginInit();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
         this->dataGridView2))
        ->BeginInit();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
         this->dataGridView3))
        ->BeginInit();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
         this->dataGridView4))
        ->BeginInit();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
         this->dataGridView5))
        ->BeginInit();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
         this->dataGridView6))
        ->BeginInit();
    this->SuspendLayout();
    //
    // dataGridView1
    //
    this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::
        DataGridViewColumnHeadersHeightSizeMode::AutoSize;
    this->dataGridView1->Columns->AddRange(
        gcnew cli::array<System::Windows::Forms::DataGridViewColumn ^>(2){
            this->Column1, this->Polinom});
    this->dataGridView1->Location = System::Drawing::Point(12, 12);
    this->dataGridView1->Name = L"dataGridView1";
    this->dataGridView1->RowHeadersWidth = 51;
    this->dataGridView1->RowTemplate->Height = 24;
    this->dataGridView1->Size = System::Drawing::Size(378, 231);
    this->dataGridView1->TabIndex = 0;
    this->dataGridView1->CellContentClick +=
        gcnew System::Windows::Forms::DataGridViewCellEventHandler(
            this, &Table::dataGridView1_CellContentClick);
    //
    // Column1
    //
    this->Column1->HeaderText = L"Name";
    this->Column1->MinimumWidth = 6;
    this->Column1->Name = L"Column1";
    this->Column1->Width = 40;
    //
    // Polinom
    //
    this->Polinom->HeaderText = L"Polinom";
    this->Polinom->MinimumWidth = 6;
    this->Polinom->Name = L"Polinom";
    this->Polinom->Width = 284;
    //
    // button1
    //
    this->button1->Location = System::Drawing::Point(225, 585);
    this->button1->Name = L"button1";
    this->button1->Size = System::Drawing::Size(160, 23);
    this->button1->TabIndex = 1;
    this->button1->Text = L"Add Polinom";
    this->button1->UseVisualStyleBackColor = true;
    this->button1->Click +=
        gcnew System::EventHandler(this, &Table::button1_Click);
    //
    // textBox1
    //
    this->textBox1->Location = System::Drawing::Point(226, 557);
    this->textBox1->Name = L"textBox1";
    this->textBox1->Size = System::Drawing::Size(274, 22);
    this->textBox1->TabIndex = 2;
    //
    // button2
    //
    this->button2->Location = System::Drawing::Point(225, 614);
    this->button2->Name = L"button2";
    this->button2->Size = System::Drawing::Size(160, 23);
    this->button2->TabIndex = 3;
    this->button2->Text = L"Delete Polinom";
    this->button2->UseVisualStyleBackColor = true;
    this->button2->Click +=
        gcnew System::EventHandler(this, &Table::button2_Click);
    //
    // label1
    //
    this->label1->AutoSize = true;
    this->label1->Location = System::Drawing::Point(181, 652);
    this->label1->Name = L"label1";
    this->label1->Size = System::Drawing::Size(0, 16);
    this->label1->TabIndex = 4;
    //
    // dataGridView2
    //
    this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::
        DataGridViewColumnHeadersHeightSizeMode::AutoSize;
    this->dataGridView2->Columns->AddRange(
        gcnew cli::array<System::Windows::Forms::DataGridViewColumn ^>(2){
            this->Column2, this->Column3});
    this->dataGridView2->Location = System::Drawing::Point(464, 12);
    this->dataGridView2->Name = L"dataGridView2";
    this->dataGridView2->RowHeadersWidth = 51;
    this->dataGridView2->RowTemplate->Height = 24;
    this->dataGridView2->Size = System::Drawing::Size(378, 231);
    this->dataGridView2->TabIndex = 5;
    //
    // Column2
    //
    this->Column2->HeaderText = L"Name";
    this->Column2->MinimumWidth = 6;
    this->Column2->Name = L"Column2";
    this->Column2->Width = 40;
    //
    // Column3
    //
    this->Column3->HeaderText = L"Polinom";
    this->Column3->MinimumWidth = 6;
    this->Column3->Name = L"Column3";
    this->Column3->Width = 284;
    //
    // label2
    //
    this->label2->AutoSize = true;
    this->label2->Location = System::Drawing::Point(325, 252);
    this->label2->Name = L"label2";
    this->label2->Size = System::Drawing::Size(60, 16);
    this->label2->TabIndex = 6;
    this->label2->Text = L"ArrTable";
    this->label2->Click +=
        gcnew System::EventHandler(this, &Table::label2_Click);
    //
    // label3
    //
    this->label3->AutoSize = true;
    this->label3->Location = System::Drawing::Point(779, 249);
    this->label3->Name = L"label3";
    this->label3->Size = System::Drawing::Size(63, 16);
    this->label3->TabIndex = 7;
    this->label3->Text = L"ListTable";
    this->label3->Click +=
        gcnew System::EventHandler(this, &Table::label3_Click);
    //
    // dataGridView3
    //
    this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::
        DataGridViewColumnHeadersHeightSizeMode::AutoSize;
    this->dataGridView3->Columns->AddRange(
        gcnew cli::array<System::Windows::Forms::DataGridViewColumn ^>(2){
            this->Column4, this->Column5});
    this->dataGridView3->Location = System::Drawing::Point(903, 12);
    this->dataGridView3->Name = L"dataGridView3";
    this->dataGridView3->RowHeadersWidth = 51;
    this->dataGridView3->RowTemplate->Height = 24;
    this->dataGridView3->Size = System::Drawing::Size(378, 231);
    this->dataGridView3->TabIndex = 8;
    //
    // Column4
    //
    this->Column4->HeaderText = L"Name";
    this->Column4->MinimumWidth = 6;
    this->Column4->Name = L"Column4";
    this->Column4->Width = 40;
    //
    // Column5
    //
    this->Column5->HeaderText = L"Polinom";
    this->Column5->MinimumWidth = 6;
    this->Column5->Name = L"Column5";
    this->Column5->Width = 284;
    //
    // label4
    //
    this->label4->AutoSize = true;
    this->label4->Location = System::Drawing::Point(1186, 249);
    this->label4->Name = L"label4";
    this->label4->Size = System::Drawing::Size(95, 16);
    this->label4->TabIndex = 9;
    this->label4->Text = L"ListHashTable";
    this->label4->Click +=
        gcnew System::EventHandler(this, &Table::label4_Click);
    //
    // dataGridView4
    //
    this->dataGridView4->ColumnHeadersHeightSizeMode = System::Windows::Forms::
        DataGridViewColumnHeadersHeightSizeMode::AutoSize;
    this->dataGridView4->Columns->AddRange(
        gcnew cli::array<System::Windows::Forms::DataGridViewColumn ^>(2){
            this->Column6, this->Column7});
    this->dataGridView4->Location = System::Drawing::Point(15, 277);
    this->dataGridView4->Name = L"dataGridView4";
    this->dataGridView4->RowHeadersWidth = 51;
    this->dataGridView4->RowTemplate->Height = 24;
    this->dataGridView4->Size = System::Drawing::Size(378, 231);
    this->dataGridView4->TabIndex = 10;
    //
    // Column6
    //
    this->Column6->HeaderText = L"Name";
    this->Column6->MinimumWidth = 6;
    this->Column6->Name = L"Column6";
    this->Column6->Width = 40;
    //
    // Column7
    //
    this->Column7->HeaderText = L"Polinom";
    this->Column7->MinimumWidth = 6;
    this->Column7->Name = L"Column7";
    this->Column7->Width = 284;
    //
    // dataGridView5
    //
    this->dataGridView5->ColumnHeadersHeightSizeMode = System::Windows::Forms::
        DataGridViewColumnHeadersHeightSizeMode::AutoSize;
    this->dataGridView5->Columns->AddRange(
        gcnew cli::array<System::Windows::Forms::DataGridViewColumn ^>(2){
            this->dataGridViewTextBoxColumn1,
            this->dataGridViewTextBoxColumn2});
    this->dataGridView5->Location = System::Drawing::Point(464, 277);
    this->dataGridView5->Name = L"dataGridView5";
    this->dataGridView5->RowHeadersWidth = 51;
    this->dataGridView5->RowTemplate->Height = 24;
    this->dataGridView5->Size = System::Drawing::Size(378, 231);
    this->dataGridView5->TabIndex = 11;
    //
    // dataGridViewTextBoxColumn1
    //
    this->dataGridViewTextBoxColumn1->HeaderText = L"Name";
    this->dataGridViewTextBoxColumn1->MinimumWidth = 6;
    this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
    this->dataGridViewTextBoxColumn1->Width = 40;
    //
    // dataGridViewTextBoxColumn2
    //
    this->dataGridViewTextBoxColumn2->HeaderText = L"Polinom";
    this->dataGridViewTextBoxColumn2->MinimumWidth = 6;
    this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
    this->dataGridViewTextBoxColumn2->Width = 284;
    //
    // dataGridView6
    //
    this->dataGridView6->ColumnHeadersHeightSizeMode = System::Windows::Forms::
        DataGridViewColumnHeadersHeightSizeMode::AutoSize;
    this->dataGridView6->Columns->AddRange(
        gcnew cli::array<System::Windows::Forms::DataGridViewColumn ^>(2){
            this->dataGridViewTextBoxColumn3,
            this->dataGridViewTextBoxColumn4});
    this->dataGridView6->Location = System::Drawing::Point(903, 277);
    this->dataGridView6->Name = L"dataGridView6";
    this->dataGridView6->RowHeadersWidth = 51;
    this->dataGridView6->RowTemplate->Height = 24;
    this->dataGridView6->Size = System::Drawing::Size(378, 231);
    this->dataGridView6->TabIndex = 12;
    //
    // dataGridViewTextBoxColumn3
    //
    this->dataGridViewTextBoxColumn3->HeaderText = L"Name";
    this->dataGridViewTextBoxColumn3->MinimumWidth = 6;
    this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
    this->dataGridViewTextBoxColumn3->Width = 40;
    //
    // dataGridViewTextBoxColumn4
    //
    this->dataGridViewTextBoxColumn4->HeaderText = L"Polinom";
    this->dataGridViewTextBoxColumn4->MinimumWidth = 6;
    this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
    this->dataGridViewTextBoxColumn4->Width = 284;
    //
    // label5
    //
    this->label5->AutoSize = true;
    this->label5->Location = System::Drawing::Point(256, 517);
    this->label5->Name = L"label5";
    this->label5->Size = System::Drawing::Size(137, 16);
    this->label5->TabIndex = 13;
    this->label5->Text = L"OpenAddrHashTable";
    //
    // label6
    //
    this->label6->AutoSize = true;
    this->label6->Location = System::Drawing::Point(743, 517);
    this->label6->Name = L"label6";
    this->label6->Size = System::Drawing::Size(99, 16);
    this->label6->TabIndex = 14;
    this->label6->Text = L"SortArrayTable";
    //
    // label7
    //
    this->label7->AutoSize = true;
    this->label7->Location = System::Drawing::Point(1209, 517);
    this->label7->Name = L"label7";
    this->label7->Size = System::Drawing::Size(72, 16);
    this->label7->TabIndex = 15;
    this->label7->Text = L"TreeTable";
    this->label7->Click +=
        gcnew System::EventHandler(this, &Table::label7_Click);
    //
    // textBox2
    //
    this->textBox2->Location = System::Drawing::Point(15, 249);
    this->textBox2->Name = L"textBox2";
    this->textBox2->Size = System::Drawing::Size(290, 22);
    this->textBox2->TabIndex = 16;
    //
    // textBox3
    //
    this->textBox3->Location = System::Drawing::Point(464, 246);
    this->textBox3->Name = L"textBox3";
    this->textBox3->Size = System::Drawing::Size(290, 22);
    this->textBox3->TabIndex = 18;
    //
    // textBox4
    //
    this->textBox4->Location = System::Drawing::Point(903, 246);
    this->textBox4->Name = L"textBox4";
    this->textBox4->Size = System::Drawing::Size(267, 22);
    this->textBox4->TabIndex = 19;
    //
    // comboBox1
    //
    this->comboBox1->FormattingEnabled = true;
    this->comboBox1->Items->AddRange(gcnew cli::array<System::Object ^>(7){
        L"All", L"ArrTable", L"ListTable", L"ListHashTable",
        L"OpenAddrHashTable", L"SortArrTable", L"TreeTable"});
    this->comboBox1->Location = System::Drawing::Point(15, 585);
    this->comboBox1->Name = L"comboBox1";
    this->comboBox1->Size = System::Drawing::Size(176, 24);
    this->comboBox1->TabIndex = 20;
    this->comboBox1->Text = L"All\'";
    this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(
        this, &Table::comboBox1_SelectedIndexChanged);
    //
    // label8
    //
    this->label8->AutoSize = true;
    this->label8->Location = System::Drawing::Point(15, 563);
    this->label8->Name = L"label8";
    this->label8->Size = System::Drawing::Size(123, 16);
    this->label8->TabIndex = 21;
    this->label8->Text = L"Active Search table";
    //
    // textBox5
    //
    this->textBox5->Location = System::Drawing::Point(12, 514);
    this->textBox5->Name = L"textBox5";
    this->textBox5->Size = System::Drawing::Size(235, 22);
    this->textBox5->TabIndex = 22;
    //
    // textBox6
    //
    this->textBox6->Location = System::Drawing::Point(464, 514);
    this->textBox6->Name = L"textBox6";
    this->textBox6->Size = System::Drawing::Size(260, 22);
    this->textBox6->TabIndex = 23;
    //
    // textBox7
    //
    this->textBox7->Location = System::Drawing::Point(903, 514);
    this->textBox7->Name = L"textBox7";
    this->textBox7->Size = System::Drawing::Size(288, 22);
    this->textBox7->TabIndex = 24;
    //
    // label9
    //
    this->label9->AutoSize = true;
    this->label9->Location = System::Drawing::Point(15, 621);
    this->label9->Name = L"label9";
    this->label9->Size = System::Drawing::Size(73, 16);
    this->label9->TabIndex = 25;
    this->label9->Text = L"key search";
    //
    // textBox8
    //
    this->textBox8->Location = System::Drawing::Point(15, 646);
    this->textBox8->Name = L"textBox8";
    this->textBox8->Size = System::Drawing::Size(107, 22);
    this->textBox8->TabIndex = 26;
    //
    // button4
    //
    this->button4->Location = System::Drawing::Point(15, 674);
    this->button4->Name = L"button4";
    this->button4->Size = System::Drawing::Size(107, 28);
    this->button4->TabIndex = 27;
    this->button4->Text = L"Search";
    this->button4->UseVisualStyleBackColor = true;
    this->button4->Click +=
        gcnew System::EventHandler(this, &Table::button4_Click);
    //
    // label11
    //
    this->label11->AutoSize = true;
    this->label11->Location = System::Drawing::Point(586, 563);
    this->label11->Name = L"label11";
    this->label11->Size = System::Drawing::Size(67, 16);
    this->label11->TabIndex = 29;
    this->label11->Text = L"Input keys";
    //
    // textBox9
    //
    this->textBox9->Location = System::Drawing::Point(589, 587);
    this->textBox9->Name = L"textBox9";
    this->textBox9->Size = System::Drawing::Size(180, 22);
    this->textBox9->TabIndex = 30;
    //
    // button5
    //
    this->button5->Location = System::Drawing::Point(589, 615);
    this->button5->Name = L"button5";
    this->button5->Size = System::Drawing::Size(107, 28);
    this->button5->TabIndex = 31;
    this->button5->Text = L"Sum";
    this->button5->UseVisualStyleBackColor = true;
    this->button5->Click +=
        gcnew System::EventHandler(this, &Table::button5_Click);
    //
    // button6
    //
    this->button6->Location = System::Drawing::Point(589, 652);
    this->button6->Name = L"button6";
    this->button6->Size = System::Drawing::Size(196, 28);
    this->button6->TabIndex = 32;
    this->button6->Text = L"Mul by const";
    this->button6->UseVisualStyleBackColor = true;
    this->button6->Click +=
        gcnew System::EventHandler(this, &Table::button6_Click);
    //
    // button7
    //
    this->button7->Location = System::Drawing::Point(589, 686);
    this->button7->Name = L"button7";
    this->button7->Size = System::Drawing::Size(196, 28);
    this->button7->TabIndex = 33;
    this->button7->Text = L"calc at a point";
    this->button7->UseVisualStyleBackColor = true;
    this->button7->Click +=
        gcnew System::EventHandler(this, &Table::button7_Click);
    //
    // label10
    //
    this->label10->AutoSize = true;
    this->label10->Location = System::Drawing::Point(850, 580);
    this->label10->Name = L"label10";
    this->label10->Size = System::Drawing::Size(51, 16);
    this->label10->TabIndex = 34;
    this->label10->Text = L"label10";
    //
    // Table
    //
    this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->ClientSize = System::Drawing::Size(1924, 1000);
    this->Controls->Add(this->label10);
    this->Controls->Add(this->button7);
    this->Controls->Add(this->button6);
    this->Controls->Add(this->button5);
    this->Controls->Add(this->textBox9);
    this->Controls->Add(this->label11);
    this->Controls->Add(this->button4);
    this->Controls->Add(this->textBox8);
    this->Controls->Add(this->label9);
    this->Controls->Add(this->textBox7);
    this->Controls->Add(this->textBox6);
    this->Controls->Add(this->textBox5);
    this->Controls->Add(this->label8);
    this->Controls->Add(this->comboBox1);
    this->Controls->Add(this->textBox4);
    this->Controls->Add(this->textBox3);
    this->Controls->Add(this->textBox2);
    this->Controls->Add(this->label7);
    this->Controls->Add(this->label6);
    this->Controls->Add(this->label5);
    this->Controls->Add(this->dataGridView6);
    this->Controls->Add(this->dataGridView5);
    this->Controls->Add(this->dataGridView4);
    this->Controls->Add(this->label4);
    this->Controls->Add(this->dataGridView3);
    this->Controls->Add(this->label3);
    this->Controls->Add(this->label2);
    this->Controls->Add(this->dataGridView2);
    this->Controls->Add(this->label1);
    this->Controls->Add(this->button2);
    this->Controls->Add(this->textBox1);
    this->Controls->Add(this->button1);
    this->Controls->Add(this->dataGridView1);
    this->Margin = System::Windows::Forms::Padding(4);
    // this->Name = L"Table";
    this->Text = L"Table";
    this->Load += gcnew System::EventHandler(this, &Table::Table_Load);
    (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
         this->dataGridView1))
        ->EndInit();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
         this->dataGridView2))
        ->EndInit();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
         this->dataGridView3))
        ->EndInit();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
         this->dataGridView4))
        ->EndInit();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
         this->dataGridView5))
        ->EndInit();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
         this->dataGridView6))
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
  vector<int> convertToVector(const std::string& inputString) {
    vector<int> resultVector;
    string temp;
    int digitCount = 0;
    bool flag = true;
    for (char c : inputString) {
      temp += c;
      digitCount++;
      if (flag == true) {
        resultVector.push_back(std::stoi(temp));
        temp.clear();
        digitCount = 0;
        flag = false;
      } else {
        if (digitCount == 3) {
          resultVector.push_back(std::stoi(temp));
          temp.clear();
          digitCount = 0;
          flag = true;
        }
      }
    }
    return resultVector;
  }

  template <typename TableType>
  System::Void AddPolinom(TableType* table, int i,
                          DataGridView ^ dataGridView) {
    string String_from_textbox =
        msclr::interop::marshal_as<string>(textBox1->Text);
    TPolinom polinom(convertToVector(String_from_textbox));
    table->Insert(msclr::interop::marshal_as<string>(i.ToString()), polinom);
  }

  template <typename TableType>
  System::Void AddPolinom(TPolinom p, TableType* table, int i,
                          DataGridView ^ dataGridView) {
    table->Insert(msclr::interop::marshal_as<string>(i.ToString()), p);
  }

  template <typename TableType>
  System::Void DelPolinom(TableType* table) {
    string String_from_textbox =
        msclr::interop::marshal_as<string>(textBox1->Text);
    table->Delete(String_from_textbox);
  }

  template <typename TableType>
  System::Void Refresh(TableType* table, DataGridView ^ dataGridView, int key,
                       int count) {
    if (count > 0) {
      table->Reset();
      dataGridView->Rows->Clear();
      for (int i = 0; i < count; i++) {
        System::String ^ PolinomName1 =
            msclr::interop::marshal_as<System::String ^>(table->GetKey());
        System::String ^ PolinomText1 =
            msclr::interop::marshal_as<System::String ^>(
                table->GetValuePtr().ToString());
        dataGridView->Rows->Add(PolinomName1, PolinomText1);
        table->GoNext();
      }
    } else {
      dataGridView->Rows->Clear();
    }
  }

  template <typename TableType>
  System::Void FindPolinom(TableType* table, TextBox ^ textbox) {
    string Key = msclr::interop::marshal_as<string>(textBox8->Text);
    TPolinom* polPtr = table->Find(Key);
    if (polPtr != nullptr) {
      TPolinom pol = *polPtr;
      string PolinomText = pol.ToString();
      textbox->Text = msclr::interop::marshal_as<System::String ^>(PolinomText);
    } else {
      textbox->Text = "Polinom not found";
    }
  }

 private:
  System::Void button1_Click(System::Object ^ sender, System::EventArgs ^ e) {
    AddPolinom(arrayTable, aT, dataGridView1);
    AddPolinom(listTable, lT, dataGridView2);
    AddPolinom(listhashTable, lhT, dataGridView3);
    AddPolinom(openAddrHashTable, oahT, dataGridView4);
    AddPolinom(sortArrayTable, saT, dataGridView5);
    AddPolinom(treeTable, tT, dataGridView6);
    aT++;
    lT++;
    lhT++;
    oahT++;
    saT++;
    tT++;

    count++;
    Refresh(arrayTable, dataGridView1, aT, count);
    Refresh(listTable, dataGridView2, lT, count);
    Refresh(listhashTable, dataGridView3, lhT, count);
    Refresh(openAddrHashTable, dataGridView4, oahT, count);
    Refresh(sortArrayTable, dataGridView5, saT, count);
    Refresh(treeTable, dataGridView6, tT, count);
  }

 private:
  System::Void button2_Click(System::Object ^ sender, System::EventArgs ^ e) {
    DelPolinom(arrayTable);
    DelPolinom(listTable);
    DelPolinom(listhashTable);
    DelPolinom(openAddrHashTable);
    DelPolinom(sortArrayTable);
    DelPolinom(treeTable);

    count--;

    Refresh(arrayTable, dataGridView1, aT, count);
    Refresh(arrayTable, dataGridView2, lT, count);
    Refresh(arrayTable, dataGridView3, lhT, count);
    Refresh(arrayTable, dataGridView4, oahT, count);
    Refresh(arrayTable, dataGridView5, saT, count);
    Refresh(arrayTable, dataGridView6, tT, count);
  }

 private:
  System::Void label2_Click(System::Object ^ sender, System::EventArgs ^ e) {}

 private:
  System::Void label3_Click(System::Object ^ sender, System::EventArgs ^ e) {}

 private:
  System::Void label7_Click(System::Object ^ sender, System::EventArgs ^ e) {}

 private:
  System::Void button3_Click(System::Object ^ sender, System::EventArgs ^ e) {}

 private:
  System::Void label4_Click(System::Object ^ sender, System::EventArgs ^ e) {}

 private:
  System::Void comboBox1_SelectedIndexChanged(System::Object ^ sender,
                                              System::EventArgs ^ e) {}

 private:
  System::Void button4_Click(System::Object ^ sender, System::EventArgs ^ e) {
    String ^ selectedText = comboBox1->SelectedItem->ToString();

    if (selectedText == "ArrTable") {
      FindPolinom(arrayTable, textBox2);
    } else if (selectedText == "ListTable") {
      FindPolinom(listTable, textBox3);
    } else if (selectedText == "ListHashTable") {
      FindPolinom(listhashTable, textBox4);
    } else if (selectedText == "OpenAddrHashTable") {
      FindPolinom(openAddrHashTable, textBox5);
    } else if (selectedText == "SortArrTable") {
      FindPolinom(sortArrayTable, textBox6);
    } else if (selectedText == "TreeTable") {
      FindPolinom(treeTable, textBox7);
    } else if (selectedText == "All") {
      FindPolinom(arrayTable, textBox2);
      FindPolinom(listTable, textBox3);
      FindPolinom(listhashTable, textBox4);
      FindPolinom(openAddrHashTable, textBox5);
      FindPolinom(sortArrayTable, textBox6);
      FindPolinom(treeTable, textBox7);
    }
  }

 private:
  System::Void button5_Click(System::Object ^ sender, System::EventArgs ^ e) {
    string inputText = msclr::interop::marshal_as<string>(textBox9->Text);
    TPolinom sum;
    char c1 = inputText[0];
    char c2 = inputText[1];
    string k1(1, c1);
    string k2(1, c2);
    TPolinom* polPtr1 = arrayTable->Find(k1);
    TPolinom pol1 = *polPtr1;
    TPolinom* polPtr2 = arrayTable->Find(k2);
    TPolinom pol2 = *polPtr2;
    sum = pol1 + pol2;

    string PolinomText = sum.ToString();
    label10->Text = msclr::interop::marshal_as<String ^>(PolinomText);
    /*for (char c:inputText) {
      string k(1, c);
      TPolinom* polPtr = arrayTable->Find(k);
      TPolinom pol = *polPtr;
      sum = sum + pol;
    }*/
    AddPolinom(sum, arrayTable, aT, dataGridView1);
    AddPolinom(sum, listTable, lT, dataGridView2);
    AddPolinom(sum, listhashTable, lhT, dataGridView3);
    AddPolinom(sum, openAddrHashTable, oahT, dataGridView4);
    AddPolinom(sum, sortArrayTable, saT, dataGridView5);
    AddPolinom(sum, treeTable, tT, dataGridView6);
    aT++;
    lT++;
    lhT++;
    oahT++;
    saT++;
    tT++;

    count++;

    Refresh(arrayTable, dataGridView1, aT, count);
    Refresh(listTable, dataGridView2, lT, count);
    Refresh(listhashTable, dataGridView3, lhT, count);
    Refresh(openAddrHashTable, dataGridView4, oahT, count);
    Refresh(sortArrayTable, dataGridView5, saT, count);
    Refresh(treeTable, dataGridView6, tT, count);
  }

 private:
  System::Void button6_Click(System::Object ^ sender, System::EventArgs ^ e) {
    string constantaWithKey =
        msclr::interop::marshal_as<string>(textBox9->Text);
    char k = constantaWithKey[0];
    char c = constantaWithKey[1];
    string k1(1, k);
    string c1(1, c);
    TPolinom* polPtr1 = arrayTable->Find(k1);
    TPolinom pol1 = *polPtr1;
    TPolinom sum = pol1 * stoi(c1);
    string PolinomText = sum.ToString();
    label10->Text = msclr::interop::marshal_as<String ^>(PolinomText);

    AddPolinom(sum, arrayTable, aT, dataGridView1);
    AddPolinom(sum, listTable, lT, dataGridView2);
    AddPolinom(sum, listhashTable, lhT, dataGridView3);
    AddPolinom(sum, openAddrHashTable, oahT, dataGridView4);
    AddPolinom(sum, sortArrayTable, saT, dataGridView5);
    AddPolinom(sum, treeTable, tT, dataGridView6);
    aT++;
    lT++;
    lhT++;
    oahT++;
    saT++;
    tT++;

    count++;

    Refresh(arrayTable, dataGridView1, aT, count);
    Refresh(listTable, dataGridView2, lT, count);
    Refresh(listhashTable, dataGridView3, lhT, count);
    Refresh(openAddrHashTable, dataGridView4, oahT, count);
    Refresh(sortArrayTable, dataGridView5, saT, count);
    Refresh(treeTable, dataGridView6, tT, count);
  }

 private:
  System::Void button7_Click(System::Object ^ sender, System::EventArgs ^ e) {
    string inputText = msclr::interop::marshal_as<string>(textBox9->Text);
    char c0 = inputText[0];
    char c1 = inputText[1];
    char c2 = inputText[2];
    char c3 = inputText[3];
    string x(1, c1);
    string y(1, c2);
    string z(1, c3);
    string k(1, c0);

    TPolinom* polPtr1 = arrayTable->Find(k);
    TPolinom pol1 = *polPtr1;

    double result =
        pol1.Evaluate(atof(x.c_str()), atof(y.c_str()), atof(z.c_str()));
    label10->Text = msclr::interop::marshal_as<String ^>(to_string(result));
  }

 private:
  System::Void label12_Click(System::Object ^ sender, System::EventArgs ^ e) {}
};
}  // namespace VisualTable2
