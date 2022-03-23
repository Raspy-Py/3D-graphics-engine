#include "STLObject.h"

#define IS_NUM(N) ((N >= '0' && N <= '9') || N == '-' || N == '.')
#define VETRTEX(X,Y,Z) 	vBuffer.push_back(current.x);\
								vBuffer.push_back(current.y);\
								vBuffer.push_back(current.z);

STLObject::STLObject(const char* fileName)
{
	attributes = new int[2];
	attributes[0] = 3;
	attributes[1] = 0;

	std::ifstream file(fileName);
	std::string line = "";
	glm::vec3 first;
	glm::vec3 second;
	glm::vec3 current;

	for (size_t i = 0; i < 9; i++)
		std::getline(file, line);

	//std::getline(file, line);
	//first = strToVec(line);
	//VETRTEX(first.x, first.y, first.z);
	//std::getline(file, line);
	//second = strToVec(line);
	//VETRTEX(second.x, second.y, second.z);
	//
	while (std::getline(file, line))
	{
		if (line[0] == 'v' && line[1] == ' ')
		{
			current = strToVec(line);
			VETRTEX(current.x, current.y, current.z);
			vertices++;
		}
		else
		{
			break;
		}
	}
	
	vertices = vBuffer.size();
	buffer = &vBuffer[0];

	buffer = new float[vertices];

	memcpy(buffer, &vBuffer[0], vertices);
	vertices /= 3;
}

glm::vec3 STLObject::strToVec(std::string& line)
{
	float v[3]{};
	bool isNum = false;
	std::string strNum = "";
	
	for (int i = 0, lSize = line.size(), cv = 0; i < lSize; i++)
	{
		if (isNum)
		{
			if (!IS_NUM(line[i]))
			{
				isNum = false;
				v[cv] = std::stof(strNum);
				cv++;
				strNum = "";
			}
			else
				strNum += line[i];

			if (i == lSize - 1)
				v[cv] = std::stof(strNum);
		}
		else if (IS_NUM(line[i]))
		{
			isNum = true;
			strNum += line[i];
		}
	}

	return glm::vec3(v[0], v[1], v[2]);
}
