#pragma once

#include<string>
#include<vector>

/*
*	 R o w ���@�s
C[][][]
o[][][]
l[][][]
u[]
m
n
��
��
*/

//�P�� �@�@�c
using StringVector = std::vector < std::string >;
//�t�@�C���̂��ׂĂ̗� = ���ׂẴf�[�^
using CSVData = std::vector < StringVector >;

class CSVLoader {
public:

	/// <param name="fileName">�t�@�C���l�[��</param>
	CSVLoader(const std::string& fileName);

	~CSVLoader();

	/// <summary> �T�v : CSV�t�@�C���̃f�[�^�����ׂĎ擾�@</summary>
	/// <returns>CSVData : �񎟌��z��</returns>
	CSVData GetAllData() const;

	/// <summary> �T�v : �w�肵���s�̃Z���̐����擾 �@</summary>
	/// <param name="rowIndex"> ���s�� </param>
	/// <returns>�w�肵���s�̃Z���̐�</returns>
	int GetNumOfRow(int rowIndex = 0) const;

	/// <summary> �T�v : 0�Ԗڂ̗�̃Z���̐����擾�@</summary>
	/// <returns>0�Ԗڂ̗�̃Z���̐� </returns>
	int GetNumOfColumn() const;

	/// <summary> �T�v : �w�肵���s�E��̃Z���̃f�[�^���擾 �@</summary>
	/// <param name="rowIndex">�s�ԍ�</param>
	/// <param name="columnIndex">��ԍ�</param>
	/// <returns>�w�肵���s�E��̃Z���̃f�[�^</returns>
	std::string GetDataStr(int rowIndex, int columnIndex) const {
		return data.at(columnIndex).at(rowIndex);
	}

	/// <summary> �T�v : �w�肵���s�E��̃Z���̃f�[�^���擾 �@</summary>
	/// <param name="rowIndex">�s�ԍ�</param>
	/// <param name="columnIndex">��ԍ�</param>
	/// <returns>�w�肵���s�E��̃Z���̃f�[�^</returns>
	int GetDataInt(int rowIndex, int columnIndex) const {
		return std::atoi(data.at(columnIndex).at(rowIndex).c_str());
	}

	/// <summary> �T�v : �w�肵���s�E��̃Z���̃f�[�^���擾 �@</summary>
	/// <param name="rowIndex">�s�ԍ�</param>
	/// <param name="columnIndex">��ԍ�</param>
	/// <returns>�w�肵���s�E��̃Z���̃f�[�^</returns>
	float GetDataFloat(int rowIndex, int columnIndex) const {
		return (float)std::atof(data.at(columnIndex).at(rowIndex).c_str());
	}

private:
	/// <summary> �T�v : CSV�t�@�C����ǂݍ��ށ@</summary>
	/// <param name="fileName">CSV�t�@�C���l�[��</param>
	void Load(const std::string& fileName);
	/// <summary> �T�v : �t�@�C��������ɓǂݍ��߂����H�@</summary>
	/// <returns>�ǂݍ��߂���</returns>
	bool IsReadFile(std::ifstream& file, const std::string& fileName);
	/// <summary> �T�v : 1�s���ǂݍ��ށ@</summary>
	/// <param name="file">�t�@�C��</param>
	void LoadRaw(std::ifstream& file);
private:
	CSVData data;
};
