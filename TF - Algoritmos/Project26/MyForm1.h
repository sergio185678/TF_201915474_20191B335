#pragma once
#include <vector>
#include<iostream>
#include<conio.h>
#include<fstream>
#include"Tabla.h"
#include"MyForm2.h"
#include <msclr\marshal_cppstd.h>
using namespace msclr::interop;
using namespace std;
namespace Project26 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
		int cant_col, aux;
		int posfila = 0;
		char tipo;
		bool first = false, next = false;
		bool habilitado_fil = false;
		short i = 0;
		String ^temp1;
		String ^temp2;
		int pos1, pos2;
	private: System::Windows::Forms::Button^  button2;

			 ListViewItem ^item;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button4;

			 Tabla*tabla2 = new Tabla();

	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button5;
			 MyForm2 ^form2 = gcnew MyForm2();
	private: System::Windows::Forms::TextBox^  intro1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Button^  button6;


	private: System::Windows::Forms::TextBox^  intro2;
	public:
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		void set_posfila(int p) { posfila = p; }
		void set_name(String ^n)
		{
			listView1->View = View::Details;
			listView1->Columns->Add(n);
			form2->set_name2(n);
		}
		void set_cant(int c)
		{
			aux = 1;
			cant_col = c;
		}
		void change_name(int i)
		{
			label1->Text = listView1->Columns[i]->Text;
		}
		void set_tabla(Tabla*tabla1)
		{
			tabla2 = tabla1;
		}
		bool validarint(string a) {
			bool validar;
			for (int i = 0; i < a.size(); i++) {
				if (a[i] == '0' || a[i] == '1' || a[i] == '2' || a[i] == '3' || a[i] == '4' || a[i] == '5'
					|| a[i] == '6' || a[i] == '7' || a[i] == '8' || a[i] == '9') {
					validar = true;
				}
				else {
					validar = false;
					break;
				}
			}
			return validar;
		}
		bool validarfloat(string a) {
			bool validar;
			bool punto = false;
			for (int i = 0; i < a.size(); i++) {

				if (a[i] == '0' || a[i] == '1' || a[i] == '2' || a[i] == '3' || a[i] == '4' || a[i] == '5'
					|| a[i] == '6' || a[i] == '7' || a[i] == '8' || a[i] == '9') {
					validar = true;
				}
				else {
					if (a[i] == '.'&&punto == false) {
						punto = true;
					}
					else {
						validar = false;
						break;
					}
				}
			}
			return validar;
		}
		////////////
		void mostrar_datos() {

			ListViewItem ^item;
			int a, b, c, d;
			for (int z = 0; z < tabla2->tamañofila(); z++) {
				a = 0; b = 0; c = 0; d = 0;
				if (tabla2->ordentipo(0) == 'I' && tabla2->fila(z)->ints[a].p == 0)
				{
					item = gcnew ListViewItem(Convert::ToString(tabla2->fila(z)->ints[a].x));
					a++;
				}
				else if (tabla2->ordentipo(0) == 'C'&& tabla2->fila(z)->chars[b].p == 0)
				{
					String ^s; s += (wchar_t)tabla2->fila(z)->chars[b].x;
					item = gcnew ListViewItem(s);
					b++;
				}
				else if (tabla2->ordentipo(0) == 'F'&& tabla2->fila(z)->floats[c].p == 0)
				{
					item = gcnew ListViewItem(Convert::ToString(tabla2->fila(z)->floats[c].x));
					c++;
				}
				else if (tabla2->ordentipo(0) == 'S'&& tabla2->fila(z)->strings[d].p == 0)
				{
					item = gcnew ListViewItem(msclr::interop::marshal_as<System::String^>(tabla2->fila(z)->strings[d].x));
					d++;
				}
				listView1->Items->Add(item);
				///////////////
				for (int i = 1; i < cant_col; ++i)
				{
					if (tabla2->ordentipo(i) == 'I'&&tabla2->fila(z)->ints[a].p == i)
					{
						item->SubItems->Add(Convert::ToString(tabla2->fila(z)->ints[a].x));
						a++;
					}
					else if (tabla2->ordentipo(i) == 'C'&&tabla2->fila(z)->chars[b].p == i)
					{
						String ^s; s += (wchar_t)tabla2->fila(z)->chars[b].x;
						item->SubItems->Add(s);
						b++;
					}
					else if (tabla2->ordentipo(i) == 'F'&&tabla2->fila(z)->floats[c].p == i)
					{
						item->SubItems->Add(Convert::ToString(tabla2->fila(z)->floats[c].x));
						c++;
					}
					else if (tabla2->ordentipo(i) == 'S'&&tabla2->fila(z)->strings[d].p == i)
					{
						item->SubItems->Add(msclr::interop::marshal_as<System::String^>(tabla2->fila(z)->strings[d].x));
						d++;
					}
				}
			}
		}
		//////////////
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^  listView1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
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
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->intro1 = (gcnew System::Windows::Forms::TextBox());
			this->intro2 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->AllowColumnReorder = true;
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(43, 225);
			this->listView1->Margin = System::Windows::Forms::Padding(4);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(895, 446);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(189, 151);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(132, 22);
			this->textBox1->TabIndex = 1;
			this->textBox1->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(39, 155);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(61, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"columna";
			this->label1->Visible = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(381, 148);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 28);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Ingresar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(43, 63);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(105, 28);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Añadir fila";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm1::button2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(749, 73);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(212, 17);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Nombre de la columna a indexar";
			this->label3->Visible = false;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(1025, 69);
			this->textBox2->Margin = System::Windows::Forms::Padding(4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(197, 22);
			this->textBox2->TabIndex = 8;
			this->textBox2->Visible = false;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(1124, 124);
			this->button4->Margin = System::Windows::Forms::Padding(4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(100, 28);
			this->button4->TabIndex = 9;
			this->button4->Text = L"Indexar";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Visible = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm1::button4_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Ordenar", L"Mayor que", L"Menor que", L"Empieza con",
					L"Termina con", L"Está contenido en", L"No está contenido en"
			});
			this->comboBox1->Location = System::Drawing::Point(1067, 303);
			this->comboBox1->Margin = System::Windows::Forms::Padding(4);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(180, 24);
			this->comboBox1->TabIndex = 13;
			this->comboBox1->Visible = false;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Ordenar", L"Mayor que", L"Menor que", L"Empieza con",
					L"Termina con", L"Está contenido en", L"No está contenido en"
			});
			this->comboBox2->Location = System::Drawing::Point(1067, 503);
			this->comboBox2->Margin = System::Windows::Forms::Padding(4);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(180, 24);
			this->comboBox2->TabIndex = 14;
			this->comboBox2->Visible = false;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(1109, 412);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 28);
			this->button3->TabIndex = 15;
			this->button3->Text = L"Filtrar";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Visible = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm1::button3_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(1109, 618);
			this->button5->Margin = System::Windows::Forms::Padding(4);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(100, 28);
			this->button5->TabIndex = 16;
			this->button5->Text = L"Filtrar";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Visible = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm1::button5_Click);
			// 
			// intro1
			// 
			this->intro1->Location = System::Drawing::Point(1091, 367);
			this->intro1->Margin = System::Windows::Forms::Padding(4);
			this->intro1->Name = L"intro1";
			this->intro1->Size = System::Drawing::Size(132, 22);
			this->intro1->TabIndex = 17;
			this->intro1->Visible = false;
			// 
			// intro2
			// 
			this->intro2->Location = System::Drawing::Point(1091, 574);
			this->intro2->Margin = System::Windows::Forms::Padding(4);
			this->intro2->Name = L"intro2";
			this->intro2->Size = System::Drawing::Size(132, 22);
			this->intro2->TabIndex = 18;
			this->intro2->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(1124, 252);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(46, 17);
			this->label5->TabIndex = 19;
			this->label5->Text = L"label5";
			this->label5->Visible = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(1124, 469);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(46, 17);
			this->label6->TabIndex = 20;
			this->label6->Text = L"label6";
			this->label6->Visible = false;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(839, 177);
			this->button6->Margin = System::Windows::Forms::Padding(4);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(100, 28);
			this->button6->TabIndex = 21;
			this->button6->Text = L"Guardar";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm1::button6_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1279, 708);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->intro2);
			this->Controls->Add(this->intro1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->listView1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm1";
			this->Text = L"Tabla";
			this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (first == false)
		{
			tipo = tabla2->tipo(aux - 1);
			string texto_string = marshal_as<std::string>(textBox1->Text);
			bool escritura_correcta = false;
			///////              
			if (tipo == 'I' && validarint(texto_string) == true && texto_string.size() <= 10 && texto_string.size() != 0) {
				tabla2->fila(posfila)->agregar_valor_int(Convert::ToInt32(textBox1->Text), aux - 1);
				escritura_correcta = true;
			}
			else if (tipo == 'C' && texto_string.size() == 1 && validarint(texto_string) == false && texto_string.size() != 0) {
				tabla2->fila(posfila)->agregar_valor_char(Convert::ToChar(textBox1->Text), aux-1);
				escritura_correcta = true;
			}
			else if (tipo == 'F' && validarfloat(texto_string) == true && texto_string.size() <= 7 && texto_string.size() != 0) {
				tabla2->fila(posfila)->agregar_valor_float(Convert::ToDouble(textBox1->Text), aux-1);
				escritura_correcta = true;
			}
			else if (tipo == 'S'&& texto_string.size() != 0) {
				tabla2->fila(posfila)->agregar_valor_string(texto_string, aux-1);
				escritura_correcta = true;
			}
			else { MessageBox::Show("Escriba correctamente el tipo de dato", "Error", MessageBoxButtons::OK); }

			if (escritura_correcta == true) {
				item = gcnew ListViewItem(textBox1->Text);
				listView1->Items->Add(item);
				textBox1->Clear();
				++aux;
				first = true;
			}
			
		}
		else
			next = true;

		if (aux <= cant_col)
		{
			if (next == true)
			{
				tipo = tabla2->tipo(aux - 1);

				tipo = tabla2->tipo(aux - 1);
				string texto_string = marshal_as<std::string>(textBox1->Text);
				bool escritura_correcta = false;
				///////              
				if (tipo == 'I' && validarint(texto_string) == true && texto_string.size() <= 10&& texto_string.size()!=0) {
					tabla2->fila(posfila)->agregar_valor_int(Convert::ToInt32(textBox1->Text),aux-1);
					escritura_correcta = true;
				}
				else if (tipo == 'C' && texto_string.size() == 1&& validarint(texto_string) == false && texto_string.size() != 0) {
					tabla2->fila(posfila)->agregar_valor_char(Convert::ToChar(textBox1->Text),aux-1);
					escritura_correcta = true;
				}
				else if (tipo == 'F' && validarfloat(texto_string) == true && texto_string.size() <= 7 && texto_string.size() != 0) {
					tabla2->fila(posfila)->agregar_valor_float(Convert::ToDouble(textBox1->Text),aux-1);
					escritura_correcta = true;
				}
				else if (tipo == 'S'&& texto_string.size() != 0) {
					tabla2->fila(posfila)->agregar_valor_string(texto_string,aux-1);
					escritura_correcta = true;
				}
				else { MessageBox::Show("Escriba correctamente el tipo de dato", "Error", MessageBoxButtons::OK); }

				if (escritura_correcta == true) {
					item->SubItems->Add(textBox1->Text);
					textBox1->Clear();
					++aux;
				}
			}
		}

		if (aux > cant_col)
		{
			aux = 1;
			posfila++;
			first = false;
			next = false;
			label1->Visible = false;
			textBox1->Visible = false;
			button1->Visible = false;
			label3->Visible = true;
			textBox2->Visible = true;
			button4->Visible = true;
		}
		change_name(aux - 1);
	}
	private: System::Void MyForm1_Load(System::Object^  sender, System::EventArgs^  e) {
		label1->Text = listView1->Columns[0]->Text;
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		label1->Visible = true;
		textBox1->Visible = true;
		button1->Visible = true;
		label3->Visible = false;
		textBox2->Visible = false;
		button4->Visible = false;
		tabla2->agregar_fila();
	}
			 /////idexar
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		bool cadena = false;
		bool cadena2 = false;
		if (textBox2->Text == "") {
			MessageBox::Show("Ingrese el nombre de una columna", "Error", MessageBoxButtons::OK);
		}
		else 
		{
			for (int i = 0; i < cant_col; ++i)
			{
				if (listView1->Columns[i]->Text == textBox2->Text)
				{
					cadena2 = true; break;
				}
			}
			if (cadena2) {
				i++;
				if (i == 1) {
					intro1->Visible = true;   comboBox1->Visible = true;	button3->Visible = true;
					temp1 = textBox2->Text; label5->Text= textBox2->Text; label5->Visible = true;
					for (int i = 0; i < cant_col; ++i)
					{
						if (listView1->Columns[i]->Text == temp1)
						{
							cadena = true;
							pos1 = i; break;
						}
					}
					tabla2->indexar(tabla2->tipo(pos1));
					for (int i = 0; i < tabla2->tamañofila(); ++i)
					{
						tabla2->agregar_datos(tabla2->fila(i), pos1);
					}
					++tabla2->idx_col;
				}
				if (i == 2) {
					intro2->Visible = true;  comboBox2->Visible = true;  button5->Visible = true;
					temp2 = textBox2->Text; label6->Text = textBox2->Text; label6->Visible = true;
					for (int i = 0; i < cant_col; ++i)
					{
						if (listView1->Columns[i]->Text == temp2)
						{
							cadena = true;
							pos2 = i; break;
						}
					}
					tabla2->indexar(tabla2->tipo(pos2));
					for (int i = 0; i < tabla2->tamañofila(); ++i)
					{
						tabla2->agregar_datos(tabla2->fila(i), pos2);
					}
					++tabla2->idx_col;
				}
				if (i == 3) {
					MessageBox::Show("No se puede indexar más", "Aviso", MessageBoxButtons::OK);
				}
				textBox2->Clear();
			}
			else {
				MessageBox::Show("Ingrese correctamente el nombre de la columna", "Aviso", MessageBoxButtons::OK);
			}
		}
	}
			 /////////////nuevo
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

	form2->reset_list();
	if (comboBox1->SelectedIndex == -1) {
		MessageBox::Show("Ingrese el tipo de filtrado", "Error", MessageBoxButtons::OK);
	}
	else if (comboBox1->SelectedIndex == 0)
	{
		tabla2->ordenar(form2->get_list(), 0);
		form2->change_tablename("Tabla ordenada");
	}
	else if (comboBox1->SelectedIndex == 1)
	{
		tabla2->mayorQue(intro1->Text, form2->get_list(), 0, pos1);
		form2->change_tablename("Tabla mayor que");
	}
	else if (comboBox1->SelectedIndex == 2)
	{
		tabla2->menorQue(intro1->Text, form2->get_list(), 0, pos1);
		form2->change_tablename("Tabla ordenada");
	}
	else if (comboBox1->SelectedIndex == 3)
	{
		tabla2->empiezaCon(intro1->Text, form2->get_list(), 0, pos1);
		form2->change_tablename("Tabla empieza con");
	}
	else if (comboBox1->SelectedIndex == 4)
	{
		tabla2->terminaCon(intro1->Text, form2->get_list(), 0, pos1);
		form2->change_tablename("Tabla termina con");
	}
	else if (comboBox1->SelectedIndex == 5)
	{
		tabla2->contenidoEn(intro1->Text, form2->get_list(), 0, pos1);
		form2->change_tablename("Tabla está contenida en");
	}
	else if (comboBox1->SelectedIndex == 6)
	{
		tabla2->noContenidoEn(intro1->Text, form2->get_list(), 0, pos1);
		form2->change_tablename("Tabla no está contenida en");
	}
	form2->Show();
}
///
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	
	form2->reset_list();
	if (comboBox2->SelectedIndex == -1) {
		MessageBox::Show("Ingrese el tipo de filtrado", "Error", MessageBoxButtons::OK);
	}
	else if (comboBox2->SelectedIndex == 0)
	{
		tabla2->ordenar(form2->get_list(), 1);
		form2->change_tablename("Tabla ordenada");
	}
	else if (comboBox2->SelectedIndex == 1)
	{
		tabla2->mayorQue(intro2->Text, form2->get_list(), 1, pos2);
		form2->change_tablename("Tabla mayor que");
	}
	else if (comboBox2->SelectedIndex == 2)
	{
		tabla2->menorQue(intro2->Text, form2->get_list(), 1, pos2);
		form2->change_tablename("Tabla menor que");
	}
	else if (comboBox2->SelectedIndex == 3)
	{
		tabla2->empiezaCon(intro2->Text, form2->get_list(), 1, pos2);
		form2->change_tablename("Tabla empieza con");
	}
	else if (comboBox2->SelectedIndex == 4)
	{
		tabla2->terminaCon(intro2->Text, form2->get_list(), 1, pos2);
		form2->change_tablename("Tabla termina con");
	}
	else if (comboBox2->SelectedIndex == 5)
	{
		tabla2->contenidoEn(intro2->Text, form2->get_list(), 1, pos2);
		form2->change_tablename("Tabla está contenida en");
	}
	else if (comboBox2->SelectedIndex == 6)
	{
		tabla2->noContenidoEn(intro2->Text, form2->get_list(), 1, pos2);
		form2->change_tablename("Tabla no está contenida en");
	}
	form2->Show();
}
		 //////////boton guardar
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	ofstream archivo("guardado.txt", ios::binary, ios::trunc);
	int j = cant_col;
	archivo.write((char*)&j, sizeof(int));
	for (int i = 0; i < cant_col; i++) {
		string texto_string = marshal_as<std::string>(listView1->Columns[i]->Text);
		char t = tabla2->ordentipo(i);
		archivo.write((char*)&texto_string, sizeof(string));
		archivo.write((char*)&t, sizeof(char));
	}
	int cant_filas = tabla2->tamañofila();
	archivo.write((char*)&cant_filas, sizeof(int));
	tabla2->guardar_fila();
	archivo.close();
}
};
}
