#pragma once
#include <string>
#include <vector>
#include <xlnt/xlnt.hpp>
#include <iostream>
#include <sstream>

namespace Excel
{
	using std::string;
	using std::exception;
	using std::vector;
	using std::stringstream;
	template<typename T>
	class Excel_Base
	{
	public:
		Excel_Base(const string& _filename) : filename(_filename) {}
	protected:
		template <typename...Args>
		auto read_from_excel(Args&&... args)
		{
			using std::to_string;
			auto col_num = sizeof...(args);
			vector<T> res{};
			try
			{
				xlnt::workbook wb;
				wb.load(filename);

				// 数据在第一个工作表
				xlnt::worksheet ws = wb.active_sheet();

				auto row_num = ws.rows().length();

				// 第一次读取，获取标题行
				{
					char cellChar = 'A';
					if (titles.empty())
						for (auto i = 1; i <= col_num; i++, cellChar++)
						{
							auto index = cellChar + to_string(1);
							titles.push_back(ws.cell(index).to_string());
						}
				}
				
				
				// 读取数据
				for (auto i{ 2 }; i <= row_num; i++)
				{
					
					auto charCell = 'A';
					(StringToData(std::forward<Args>(args), ws.cell((charCell++) + std::to_string(i)).to_string()), ...);
					
					res.push_back({ std::forward<Args>(args)... });
					
				}
				
			}
			catch (const exception& e)
			{
				std::cout << "bad excel error: " << e.what() << std::endl;
			}
			
			return res;
		}
		vector<string> titles{};
	private:
		template<typename T>
		void StringToData(T& data, string s)
		{
			stringstream ss{ s };
			ss >> data;
		}

	private:
		string filename;
	};

}

