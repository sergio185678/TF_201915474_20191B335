#pragma once
#include<fstream>
#include<string>
#include<iostream>
#include<conio.h>
#include<vector>
#include "MyForm1.h"
#include"Tabla.h"
namespace Project26 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		int cont;
	private: System::Windows::Forms::TextBox^  textBox1;
			 MyForm1 ^f = gcnew MyForm1();
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button3;
			 Tabla*tabla1 = new Tabla();
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			cont = 0;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::ListView^  listView1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(48, 70);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(171, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Seleccione el tipo de dato";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(308, 114);
			this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(140, 28);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Añadir columna";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(343, 304);
			this->button2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(105, 39);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Crear tabla";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Int", L"String", L"Float", L"Char" });
			this->comboBox1->Location = System::Drawing::Point(52, 114);
			this->comboBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(160, 24);
			this->comboBox1->TabIndex = 3;
			// 
			// listView1
			// 
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(527, 70);
			this->listView1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->listView1->MultiSelect = false;
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(277, 200);
			this->listView1->TabIndex = 4;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::List;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(48, 255);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(222, 17);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Número de columnas agregadas: ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(291, 255);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(18, 20);
			this->label3->TabIndex = 6;
			this->label3->Text = L"0";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(241, 178);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(132, 22);
			this->textBox1->TabIndex = 7;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(48, 182);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(150, 17);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Nombre de la columna";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(680, 304);
			this->button3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 28);
			this->button3->TabIndex = 9;
			this->button3->Text = L"Cargar tabla";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(847, 369);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"MyForm";
			this->Text = L"Creador de tablas";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		if (this->comboBox1->SelectedItem == nullptr || this->textBox1->Text == "")
			MessageBox::Show("Seleccione un tipo de dato", "Error", MessageBoxButtons::OK);
		else
		{
			ListViewItem ^item;
			if (comboBox1->SelectedItem == "Int") {
				item = gcnew ListViewItem("Se ha añadido una columna de enteros");
				tabla1->agregar_tipo('I');
			}
			if (comboBox1->SelectedItem == "String") {
				item = gcnew ListViewItem("Se ha añadido una columna de cadenas");
				tabla1->agregar_tipo('S');
			}
			if (comboBox1->SelectedItem == "Char") {
				item = gcnew ListViewItem("Se ha añadido una columna de caracteres");
				tabla1->agregar_tipo('C');
			}
			if (comboBox1->SelectedItem == "Float") {
				item = gcnew ListViewItem("Se ha añadido una columna de flotantes");
				tabla1->agregar_tipo('F');
			}
			listView1->Items->Add(item);
			label3->Text = (++cont).ToString();


			f->set_name(textBox1->Text);
			textBox1->Clear();


			comboBox1->SelectedIndex = -1;
		}
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		if (cont == 0)
			MessageBox::Show("Agregue columnas para crear una tabla", "Error", MessageBoxButtons::OK);
		else
		{
			f->set_tabla(tabla1);
			f->set_cant(cont);
			f->Show();


		}
	}
			 ///////cargar tabla
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		int cant_col; string*nameeeee=new string[10]; char*tipo=new char[10];
		ifstream archivoo("guardado.txt", ios::binary);
		archivoo.read((char*)&cant_col, sizeof(int));
		for (int i = 0; i < cant_col; i++) {
			archivoo.read((char*)&nameeeee[i], sizeof(string));
			archivoo.read((char*)&tipo[i], sizeof(char));
			tabla1->agregar_tipo(tipo[i]);
			f->set_name(msclr::interop::marshal_as<System::String^>(nameeeee[i]));
		}
		//////////
		int tamfilas; 
		archivoo.read((char*)&tamfilas, sizeof(int));
		/////////
		archivoo.close();
		////////
		ifstream archivoo2("guardado2.txt", ios::binary);
		int *tamints = new int[10]; int *tamfloats = new int[10];
		int *tamchars = new int[10]; int *tamstrings = new int[10];

		int *ints = new int[10];            short *ints_p = new short[10];
		float *floats = new float[10];      short *floats_p = new short[10];
		char *chars = new char[10];         short *chars_p = new short[10];
		string *strings = new string[10];   short *strings_p = new short[10];

		for (int i = 0; i < tamfilas; i++) {
			tabla1->agregar_fila();
			archivoo2.read((char*)&tamints[i], sizeof(int));
			archivoo2.read((char*)&tamfloats[i], sizeof(int));
			archivoo2.read((char*)&tamchars[i], sizeof(int));
			archivoo2.read((char*)&tamstrings[i], sizeof(int));
				for (int j = 0; j < tamints[i]; j++) {
					archivoo2.read((char*)&ints[j], sizeof(int));
					archivoo2.read((char*)&ints_p[j], sizeof(short));
					tabla1->fila(i)->agregar_valor_int(ints[j], ints_p[j]);
				}
				for (int j = 0; j < tamfloats[i]; j++) {
					archivoo2.read((char*)&floats[j], sizeof(float));
					archivoo2.read((char*)&floats_p[j], sizeof(short));
					tabla1->fila(i)->agregar_valor_float(floats[j], floats_p[j]);
				}
				for (int j = 0; j < tamchars[i]; j++) {
					archivoo2.read((char*)&chars[j], sizeof(char));
					archivoo2.read((char*)&chars_p[j], sizeof(short));
					tabla1->fila(i)->agregar_valor_char(chars[j], chars_p[j]);
				}
				for (int j = 0; j < tamstrings[i]; j++) {
					archivoo2.read((char*)&strings[j], sizeof(string));
					archivoo2.read((char*)&strings_p[j], sizeof(short));
					tabla1->fila(i)->agregar_valor_string(strings[j], strings_p[j]);
				}
		}

		archivoo2.close();
		//////
		f->set_tabla(tabla1);
		f->set_cant(cant_col);
		f->mostrar_datos();
		f->set_posfila(tabla1->tamañofila());
		f->Show();
	}
};
}
