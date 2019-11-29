#include "CSVLoader.h"

#include"FilePass.h"

#include<fstream>
#include<cassert>
#include<iostream>
#include<sstream>

CSVLoader::CSVLoader(const std::string & fileName)
	: data()
{
	Load(FilePass::DataFile + fileName);
}

CSVLoader::~CSVLoader()
{
	data.clear();
}

CSVData CSVLoader::GetAllData() const
{
	return data;
}

int CSVLoader::GetNumOfRow(int rowIndex) const
{
	return data.at(rowIndex).size();
}

int CSVLoader::GetNumOfColumn() const
{
	return data.size();
}

void CSVLoader::Load(const std::string & fileName)
{
	std::ifstream file(fileName);

	if (!IsReadFile(file, fileName))
		return;

	LoadRaw(file);
}

bool CSVLoader::IsReadFile(std::ifstream& file, const std::string& fileName)
{
	if (!file.fail())
		return true;

	std::cerr << "Error Read File ->" << fileName << std::endl;
	assert(!"�t�@�C�����J���܂���ł����B");
	return false;
}

void CSVLoader::LoadRaw(std::ifstream & file)
{
	//�t�@�C���̖��[
	static const std::string EndOfFile = "FOE";
	//��
	static const std::string Space = "\r";
	//���s
	static const std::string LineBreak = "\n";

	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream stream(line);
		StringVector row;
		std::string value = "";
		while (std::getline(stream, value, ',')) {
			//�t�@�C���̖��[�Ȃ�I��
			if (value == EndOfFile)return;
			//�󔒁A���s�A�u""�v�Ȃ������x��蒼��
			if (value == "" || value == Space || value == LineBreak) continue;

			row.emplace_back(value);
		}
		data.emplace_back(row);
	}
}
