#include <problem_md.h>

ProblemMd::ProblemMd(const std::string& file_path, StrategyMd* strategy, size_t m)
    : m_(m), strategy_(strategy) {
  std::fstream input_file(file_path, std::ios_base::in);
  input_file >> *this;
}

ProblemMd::~ProblemMd() {
  if (strategy_ != NULL) delete strategy_;
}

void ProblemMd::Solve() {
  (*strategy_)(solution_, data_, m_);
}

std::istream& operator>>(std::istream& is, ProblemMd& problem) {
  size_t dimensions, number_vectors;
  std::vector<float> vector_buffer;
  float data_buffer;

  is >> number_vectors >> dimensions;
  for (size_t i = 0; i < number_vectors; ++i) {
    for (size_t j = 0; j < dimensions; ++j) {
      is >> data_buffer;
      vector_buffer.push_back(data_buffer);
    }
    problem.data_.insert(vector_buffer);
    vector_buffer.clear();
  }
  return is;
}