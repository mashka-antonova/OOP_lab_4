#include "FileReader.h"
#include <fstream>
#include <sstream>
#include <stdexcept>


std::vector<float> FileReader::ParseLine(std::string line) const { //
  std::vector<float> row;
  for (size_t i = 0; i < line.size(); ++i)
    if (line[i] == ',' || line[i] == ';')
      line[i] = ' ';
  std::stringstream stream(line);
  float value;
  while (stream >> value)
    row.push_back(value);
  return row;
}

float FileReader::FindMin(const std::vector<std::vector<float>> &data) const {
  if (data.empty() || data[0].empty())
    return FLOAT_ZERO;

  float minVal = data[0][0];
  for (size_t i = 0; i < data.size(); ++i)
    for (size_t j = 0; j < data[i].size(); ++j)
      if (data[i][j] < minVal)
        minVal = data[i][j];
  return minVal;
}

float FileReader::FindMax(const std::vector<std::vector<float>> &data) const {
  if (data.empty() || data[0].empty())
    return FLOAT_ZERO;

  float maxVal = data[0][0];
  for (size_t i = 0; i < data.size(); ++i)
    for (size_t j = 0; j < data[i].size(); ++j)
      if (data[i][j] > maxVal)
        maxVal = data[i][j];
  return maxVal;
}

float FileReader::NormalizeValue(float value, float minVal, float maxVal,
                                 float outMin, float outMax) const {
  float range = maxVal - minVal;
  float result = outMin;
  if (range > EPSILON || range < -EPSILON)
    result = outMin + ((value - minVal) / range) * (outMax - outMin);
  return result;
}

Figure FileReader::BuildFigure(const std::vector<std::vector<float>> &data,
                               const NormalizationParameters &params) const {
  Figure figure;

  float minVal = FindMin(data);
  float maxVal = FindMax(data);
  int rows = data.size();
  int cols = data[0].size();

  figure.ReserveVertices(rows * cols);
  figure.SetDimensions(rows, cols);

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      float z =
          NormalizeValue(data[i][j], minVal, maxVal, params.GetMin(), params.GetMax());
      figure.AddVertex(Vertex(Point3D(j * params.GetDxStep(), i * params.GetDyStep(), z)));
    }
  }

  return figure;
}

void FileReader::EqualizeRowLengths(
    std::vector<std::vector<float>> &data) const {
  size_t maxCols = 0;
  for (size_t i = 0; i < data.size(); ++i)
    if (data[i].size() > maxCols)
      maxCols = data[i].size();

  for (size_t i = 0; i < data.size(); ++i)
    data[i].resize(maxCols, FLOAT_ZERO);
}

Scene FileReader::ReadScene(const std::string &path,
                            const NormalizationParameters &params) {
  if (path.empty())
    throw std::runtime_error("Empty path provided.");

  std::ifstream file(path);

  if (!file.is_open())
    throw std::runtime_error("Could not open file: " + path);

  std::vector<std::vector<float>> data;
  std::string line;

  while (std::getline(file, line)) {
    std::vector<float> row = ParseLine(line);
    if (row.size() > 0)
      data.push_back(row);
  }

  if (data.empty() || data[0].empty())
    throw std::runtime_error("File is empty or invalid format.");

  EqualizeRowLengths(data);
  Figure figure = BuildFigure(data, params);
  Scene scene;
  scene.AddFigure(figure);
  return scene;
}
