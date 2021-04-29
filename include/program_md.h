#ifndef PROGRAM_MD_H
#define PROGRAM_MD_H

#include <program.h>

class ProgramMd : public Program {
 public:
  using Program::Program;
  ~ProgramMd();

  int Run();
  void ShowUsage() const;
};

#endif