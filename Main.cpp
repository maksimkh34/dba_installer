#include "Main.h"
#include "Logger.h"

using namespace DBaInstaller;

[STAThread]
void main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	LoggerCLR::Logger* log = new LoggerCLR::Logger("C:\\logs\\dbai.cl");
	log->flush();

	DBaInstaller::Main form;
	Application::Run(% form);

	delete log;
}