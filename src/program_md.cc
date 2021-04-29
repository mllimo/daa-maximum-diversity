#include <program_md.h>

ProgramMd::~ProgramMd() {}

int ProgramMd::Run() {
  if (arg_.size() == 1) {
    ShowUsage();
    return 1;
  }

  size_t m = (size_t)stoi(arg_[3]);

  if (arg_[1] == "GREEDY") {
    headers_ = {"m", "z", "S", "tiempo / segundos"};
    for (size_t m_index = 2; m_index <= m; ++m_index) {
      algorithm = new GreedyMd;
      ProblemMd problem(arg_[2], algorithm, m_index);
      timer.Play();
      problem.Solve();
      timer.Stop();
      std::cout << "Resultado: " << problem.Z() << std::endl;
      data_.push_back({std::to_string(m_index), std::to_string(problem.Z()), problem.ToString(),
                       std::to_string(timer.Get())});
    }
  }
  Export();
  return 0;
}

void ProgramMd::Export() {
  std::string file_name =
      std::string(arg_[2].begin(), arg_[2].begin() + arg_[2].size() - 3) + "csv";
  std::fstream file(file_name, std::ios_base::out);
  std::cout << "Exportando en: " << file_name << std::endl;

  // Imprimir cabeceras
  for (auto& element : headers_) file << element << "\t";
  file << '\n';

  // Imprimir info
  for (auto& row : data_) {
    for (auto& value : row) file << value << "\t";
    file << '\n';
  }

  file.close();
}

void ProgramMd::ShowUsage() const { std::cout << "./maximum-diversity <GREEDY> <file> <m>\n"; }