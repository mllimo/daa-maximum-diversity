#ifndef PROGRAM_MD_H
#define PROGRAM_MD_H

#include <grasp_md.h>
#include <greedy_local_md.h>
#include <greedy_md.h>
#include <problem_md.h>
#include <program.h>
#include <stop_no_improvement_md.h>
#include <swap_entre_md.h>
#include <timer.h>

class ProgramMd : public Program {
 public:
  using Program::Program;
  ~ProgramMd();

  int Run();
  void ShowUsage() const;

 protected:
  std::vector<std::string> headers_;
  std::vector<std::vector<std::string>> data_;
  StrategyMd* algorithm;
  Timer timer;

  void Export();
};

#endif