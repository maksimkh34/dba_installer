#pragma once
#include <msclr/marshal_cppstd.h>
#include "trans.h"

namespace DBaInstaller {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Already_installed
	/// </summary>
	public ref class Already_installed : public System::Windows::Forms::Form
	{
	public:
		Already_installed(void)
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
		~Already_installed()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::FolderBrowserDialog^ oldvers_fbd;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->oldvers_fbd = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(236, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Похоже, что DBa уже установлен. Обновить\?";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 25);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(118, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Да";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Already_installed::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(135, 25);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(113, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Закрыть";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Already_installed::button2_Click);
			// 
			// Already_installed
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(258, 56);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"Already_installed";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Предупреждение";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Already_installed::Already_installed_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Environment::Exit(0);
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		oldvers_fbd->ShowDialog();
		trans::installed_path = msclr::interop::marshal_as<std::string>(oldvers_fbd->SelectedPath);
		trans::update = true;
		this->Close();
	}
	private: System::Void Already_installed_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		if (!trans::update) Environment::Exit(0);
	}
};
}
