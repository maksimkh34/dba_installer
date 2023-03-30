#pragma once

namespace DBaInstaller {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для use_def_user_data_warn
	/// </summary>
	public ref class use_def_user_data_warn : public System::Windows::Forms::Form
	{
	public:
		use_def_user_data_warn(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~use_def_user_data_warn()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ button1;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(253, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Поля с данными пользователя были заполнены";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 22);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(227, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"неверно. Программа будет установлена со";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 35);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(133, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"стандартными данными:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 63);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(109, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Имя пользователя: ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 76);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(48, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Пароль:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(127, 63);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"admin";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(127, 76);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(31, 13);
			this->label7->TabIndex = 6;
			this->label7->Text = L"1234";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 92);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(252, 23);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Закрыть";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &use_def_user_data_warn::button1_Click);
			// 
			// use_def_user_data_warn
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(277, 125);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"use_def_user_data_warn";
			this->Text = L"Предупреждение";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
