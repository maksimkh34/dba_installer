#pragma once
#include <fstream>
#include <msclr/marshal_cppstd.h>
#include <direct.h>
#include <urlmon.h>
#include <vector>
#include <string>
#include <atlstr.h>
#include <filesystem>
#include <tchar.h>

#include "Already_installed.h"
#include "Done.h"
#include "use_def_user_data_warn.h"

#pragma comment(lib, "urlmon.lib")

using std::vector;
using std::string;

vector<string> split(string text, char delimeter)
{
	const size_t size = text.size();
	int pointer = 0;

	if (text[size - 1] != delimeter) text += delimeter;

	vector<string> result;
	for (int i = 0; i <= size; i++)
	{
		if (text[i] == delimeter && i != 0)
		{
			string temp = "";
			for (int j = pointer; j < i; j++)
			{
				temp += text[j];
			}

			string t;
			t = delimeter;

			if (temp != "" && temp != t)
				result.push_back(temp);
			pointer = i + 1;
		}
	}

	return result;
}

namespace DBaInstaller {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
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
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ version_tb;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ name_tb;
	private: System::Windows::Forms::TextBox^ pass_tb;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog1;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ homedir_tb;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->version_tb = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->name_tb = (gcnew System::Windows::Forms::TextBox());
			this->pass_tb = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->homedir_tb = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(104, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Доступная версия:";
			// 
			// version_tb
			// 
			this->version_tb->Enabled = false;
			this->version_tb->Location = System::Drawing::Point(12, 25);
			this->version_tb->Name = L"version_tb";
			this->version_tb->Size = System::Drawing::Size(258, 20);
			this->version_tb->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 67);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(258, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Выбрать домашнюю папку";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Main::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 147);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(167, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Имя начального пользователя:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 186);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(48, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Пароль:";
			// 
			// name_tb
			// 
			this->name_tb->Location = System::Drawing::Point(12, 163);
			this->name_tb->Name = L"name_tb";
			this->name_tb->Size = System::Drawing::Size(258, 20);
			this->name_tb->TabIndex = 5;
			// 
			// pass_tb
			// 
			this->pass_tb->Location = System::Drawing::Point(12, 202);
			this->pass_tb->Name = L"pass_tb";
			this->pass_tb->Size = System::Drawing::Size(257, 20);
			this->pass_tb->TabIndex = 6;
			this->pass_tb->UseSystemPasswordChar = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 244);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(258, 23);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Загрузить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Main::button2_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(12, 273);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(257, 23);
			this->progressBar1->TabIndex = 8;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(9, 93);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(143, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Текущая домашняя папка:";
			// 
			// homedir_tb
			// 
			this->homedir_tb->Enabled = false;
			this->homedir_tb->Location = System::Drawing::Point(12, 109);
			this->homedir_tb->Name = L"homedir_tb";
			this->homedir_tb->Size = System::Drawing::Size(258, 20);
			this->homedir_tb->TabIndex = 10;
			this->homedir_tb->TextChanged += gcnew System::EventHandler(this, &Main::textBox1_TextChanged);
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(278, 306);
			this->Controls->Add(this->homedir_tb);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->pass_tb);
			this->Controls->Add(this->name_tb);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->version_tb);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Main";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Установка";
			this->Load += gcnew System::EventHandler(this, &Main::Main_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
	private: System::Void Main_Load(System::Object^ sender, System::EventArgs^ e) {

		std::ifstream file;
		file.open("C:\\ProgramData\\dba\\pth");
		if (file.is_open())
		{
			Already_installed^ form = gcnew Already_installed;
			form->ShowDialog();
		}
		else
		{
			_mkdir("C:\\ProgramData\\dba");
			_mkdir("C:\\ProgramData\\dba\\workfolder");
		}

		if (trans::update) homedir_tb->Text = msclr::interop::marshal_as<System::String^>(trans::installed_path);
		else homedir_tb->Text = msclr::interop::marshal_as<System::String^>(trans::path);

		int code = _mkdir("C:\\ProgramData\\dba");
		URLDownloadToFile(NULL, _T("https://raw.githubusercontent.com/maksimkh34/dba_inst/main/info"), _T("C:\\ProgramData\\dba\\info"), 0, NULL);
		std::ifstream read("C:\\ProgramData\\dba\\info");
		string temp = "", text;

		while (!read.eof())
		{
			std::getline(read, temp);
			text += temp + '=';
		}

		vector<string> data = split(text, '=');
		trans::data = data;
		version_tb->Text = msclr::interop::marshal_as<System::String^>(data[0]);
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (name_tb->Text == "" || name_tb->Text == "")
		{
			use_def_user_data_warn^ form = gcnew use_def_user_data_warn;
			form->ShowDialog();
		}

		CString cstring_s(msclr::interop::marshal_as<System::String^>(trans::path + "\\DBa.exe"));
		URLDownloadToFile(NULL, _T("https://raw.githubusercontent.com/maksimkh34/dba_inst/main/dba.exe"), cstring_s, 0, NULL);
		
		if (trans::update)
		{
			trans::path = trans::installed_path;
		}

		progressBar1->Increment(10);

		int add_per_one = 70 / (trans::data.size()-1);
		int lost = 70 % (trans::data.size()-1);

		for (int i = 1; i < trans::data.size(); i++)
		{
			if (trans::data[i][0] != '\\')
			{
				string npath = trans::path + '\\' + trans::data[i];
				if (!(trans::update && std::filesystem::exists(npath)))
				{
					vector<string> vpath = split(npath, '\\');
					string temp_path_f = vpath[0];
					for (int j = 1; j < vpath.size() - 1; j++)
					{
						temp_path_f += '\\' + vpath[j];
						_mkdir(temp_path_f.c_str());
					}
					temp_path_f += '\\' + vpath[vpath.size() - 1];
					std::ofstream file(temp_path_f);
					file.close();
				}
			}
			else
			{
				string npath = trans::path + trans::data[i];
				if (!(trans::update && std::filesystem::exists(npath))) {
					vector<string> vpath = split(npath, '\\');
					string temp_path_f = vpath[0];
					for (int j = 1; j < vpath.size(); j++)
					{
						temp_path_f += '\\' + vpath[j];
						_mkdir(temp_path_f.c_str());
					}
				}
			}
			
			progressBar1->Increment(add_per_one);

		}

		progressBar1->Increment(lost);

		// 80

		if (!trans::update)
		{
			std::ofstream pth("C:\\ProgramData\\DBa\\pth");
			pth << trans::path;
			pth.close();

			progressBar1->Increment(10);

			std::string flush = "";

			if (name_tb->Text == "") flush += "admin";
			else flush += msclr::interop::marshal_as<std::string>(name_tb->Text);

			flush += '-';

			if (pass_tb->Text == "") flush += "1234";
			else flush += msclr::interop::marshal_as<std::string>(pass_tb->Text);

			std::ofstream usr(trans::path + "\\usr.zb");
			usr << flush;
			usr.close();

			progressBar1->Increment(10);
		}
		else progressBar1->Increment(20);

		DBaInstaller::Done^ form = gcnew DBaInstaller::Done;
		form->ShowDialog();

		progressBar1->Increment(-100);
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		folderBrowserDialog1->ShowDialog();
		System::String^ path = folderBrowserDialog1->SelectedPath;
		trans::path = msclr::interop::marshal_as<std::string>(path);

		homedir_tb->Text = path;
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
