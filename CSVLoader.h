#pragma once

#include<string>
#include<vector>

/*
*	 R o w →　行
C[][][]
o[][][]
l[][][]
u[]
m
n
↓
列
*/

//１列 　　縦
using StringVector = std::vector < std::string >;
//ファイルのすべての列 = すべてのデータ
using CSVData = std::vector < StringVector >;

class CSVLoader {
public:

	/// <param name="fileName">ファイルネーム</param>
	CSVLoader(const std::string& fileName);

	~CSVLoader();

	/// <summary> 概要 : CSVファイルのデータをすべて取得　</summary>
	/// <returns>CSVData : 二次元配列</returns>
	CSVData GetAllData() const;

	/// <summary> 概要 : 指定した行のセルの数を取得 　</summary>
	/// <param name="rowIndex"> 何行目 </param>
	/// <returns>指定した行のセルの数</returns>
	int GetNumOfRow(int rowIndex = 0) const;

	/// <summary> 概要 : 0番目の列のセルの数を取得　</summary>
	/// <returns>0番目の列のセルの数 </returns>
	int GetNumOfColumn() const;

	/// <summary> 概要 : 指定した行・列のセルのデータを取得 　</summary>
	/// <param name="rowIndex">行番号</param>
	/// <param name="columnIndex">列番号</param>
	/// <returns>指定した行・列のセルのデータ</returns>
	std::string GetDataStr(int rowIndex, int columnIndex) const {
		return data.at(columnIndex).at(rowIndex);
	}

	/// <summary> 概要 : 指定した行・列のセルのデータを取得 　</summary>
	/// <param name="rowIndex">行番号</param>
	/// <param name="columnIndex">列番号</param>
	/// <returns>指定した行・列のセルのデータ</returns>
	int GetDataInt(int rowIndex, int columnIndex) const {
		return std::atoi(data.at(columnIndex).at(rowIndex).c_str());
	}

	/// <summary> 概要 : 指定した行・列のセルのデータを取得 　</summary>
	/// <param name="rowIndex">行番号</param>
	/// <param name="columnIndex">列番号</param>
	/// <returns>指定した行・列のセルのデータ</returns>
	float GetDataFloat(int rowIndex, int columnIndex) const {
		return (float)std::atof(data.at(columnIndex).at(rowIndex).c_str());
	}

private:
	/// <summary> 概要 : CSVファイルを読み込む　</summary>
	/// <param name="fileName">CSVファイルネーム</param>
	void Load(const std::string& fileName);
	/// <summary> 概要 : ファイルが正常に読み込めたか？　</summary>
	/// <returns>読み込めたか</returns>
	bool IsReadFile(std::ifstream& file, const std::string& fileName);
	/// <summary> 概要 : 1行ずつ読み込む　</summary>
	/// <param name="file">ファイル</param>
	void LoadRaw(std::ifstream& file);
private:
	CSVData data;
};
