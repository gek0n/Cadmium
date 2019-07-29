#include "Data.hpp"
#include "Version.hpp"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#include <clang/CodeGen/CodeGenAction.h>
#pragma GCC diagnostic pop
#include <clang/Frontend/CompilerInstance.h>
#include <fstream>
#include <iostream>
#include <llvm/Bitcode/BitcodeWriter.h>
#include <string>

#ifndef CADMIUM_VERSION_MAJOR
#error("No version info")
#endif

const size_t width = 1024;
const size_t height = 768;

bool storePPM(std::string filename, FrameBuffer<Pixel<float>> fb) {
  std::ofstream fout("./" + filename + ".ppm", std::ios::binary);
  fout << "P6\n" << fb.getWidth() << " " << fb.getHeight() << "\n255\n";

  for (const auto &pixel : fb) {
    fout << (uint8_t)(255 * pixel.red) << (uint8_t)(255 * pixel.green)
         << (uint8_t)(255 * pixel.blue);
  }

  fout << std::flush;

  fout.close();
}

void compile(const std::string &source) {
  auto invocation = std::make_shared<clang::CompilerInvocation>();

  invocation->getTargetOpts().Triple = llvm::sys::getProcessTriple();

  // Tune invocation
  clang::CompilerInstance compiler;
  compiler.createDiagnostics();
  compiler.setInvocation(invocation);

  // Create and execute the frontend to generate an LLVM bitcode module.
  auto action = std::make_unique<clang::EmitLLVMOnlyAction>();
  auto success = compiler.ExecuteAction(*action);
  if (!success) {
    std::cerr << "Compilation error" << std::endl;
    return;
  }

  auto module = action->takeModule();
  if (!module) {
    std::cerr << "Module is not exist" << std::endl;
    return;
  }
  std::cout << "Success!" << std::endl;
  // Save to bitcode buffer
}

int32_t main(int32_t argc, char **argv) {
  std::cout << argv[0] << " " << CADMIUM_VERSION_MAJOR << "."
            << CADMIUM_VERSION_MINOR << " version" << std::endl;

  compile("");

  return 0;
}
