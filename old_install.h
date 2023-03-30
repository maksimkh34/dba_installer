/*
CString cstring_s(msclr::interop::marshal_as<System::String^>(trans::path + "\\DBa.exe"));
URLDownloadToFile(NULL, _T("https://raw.githubusercontent.com/maksimkh34/dba_inst/main/dba.exe"), cstring_s, 0, NULL);

progressBar1->Increment(20);

string path_ = trans::path + "\\export";
int code = _mkdir(path_.c_str());

progressBar1->Increment(16);

std::ofstream pthfile("C:\\ProgramData\\dba\\pth");
pthfile << trans::path << "\\";

progressBar1->Increment(17);

std::ofstream pfile2(trans::path + "\\usr.zb");
pfile2 << msclr::interop::marshal_as<std::string>(name_tb->Text) << "-" << msclr::interop::marshal_as<std::string>(pass_tb->Text);
progressBar1->Increment(16);


std::ofstream pfile3(trans::path + "\\schools.zb");

progressBar1->Increment(18);

pfile2.close();
pfile3.close();

progressBar1->Increment(13);

DBaInstaller::Done^ form = gcnew DBaInstaller::Done;
form->ShowDialog();
*/