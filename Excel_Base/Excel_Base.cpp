#include "Excel_Base.h"
#include <Windows.h>

std::string UTF8_To_string(const std::string& str)
{
	// 计算wide char字符串长度
	int nwLen = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);

	// 分配wide char字符串内存
	wchar_t* pwBuf = new wchar_t[nwLen + 1];
	memset(pwBuf, 0, nwLen * 2 + 2);

	// 将UTF-8字符串转换为wide char字符串
	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), static_cast<int>(str.length()), pwBuf, nwLen);

	// 计算ansi字符串长度
	int nLen = WideCharToMultiByte(CP_ACP, 0, pwBuf, -1, NULL, NULL, NULL, NULL);

	// 分配ansi字符串内存
	char* pBuf = new char[nLen + 1];
	memset(pBuf, 0, nLen + 1);

	// 将wide char字符串转换为ansi字符串
	WideCharToMultiByte(CP_ACP, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

	// 将ansi字符串转换为std::string
	std::string retStr = pBuf;

	// 释放内存
	delete[]pBuf;
	delete[]pwBuf;

	pBuf = NULL;
	pwBuf = NULL;

	return retStr;

}

std::string string_To_UTF8(const std::string& str)
{
	// 计算wide char字符串长度
	int nwLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);

	// 分配wide char字符串内存
	wchar_t* pwBuf = new wchar_t[nwLen + 1];
	ZeroMemory(pwBuf, nwLen * 2 + 2);

	// 将wide char字符串转换为wide char
	::MultiByteToWideChar(CP_ACP, 0, str.c_str(), static_cast<int>(str.length()), pwBuf, nwLen);

	// 计算utf-8字符串长度
	int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL);

	// 分配utf-8字符串内存
	char* pBuf = new char[nLen + 1];
	ZeroMemory(pBuf, nLen + 1);

	// 将wide char字符串转换为utf-8字符串
	::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

	// 返回utf-8字符串
	std::string retStr(pBuf);

	// 释放内存
	delete[]pwBuf;
	delete[]pBuf;

	// 释放内存指针
	pwBuf = NULL;
	pBuf = NULL;

	return retStr;
}