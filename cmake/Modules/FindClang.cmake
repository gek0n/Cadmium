find_library(Clang_LIBRARY
  NAMES clangBasic
  HINTS
  ENV LD_LIBRARY_PATH
  ENV DYLD_LIBRARY_PATH
  PATHS
  /usr/lib
  /usr/local/lib
  /usr/local/homebrew/lib
  /opt/local/lib)

get_filename_component(Clang_LIBRARY_DIR ${Clang_LIBRARY} DIRECTORY)

set(Clang_LIBRARIES "-Wl,--start-group -lclang -lclangFrontend -lclangDriver -lclangSerialization -lclangParse -lclangSema -lclangAnalysis -lclangEdit -lclangAST -lclangLex -lclangBasic -lclangCodeGen -Wl,--end-group")
set(Clang_INCLUDE_DIRS ${Clang_LIBRARY_DIR}/../include)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Clang REQUIRED_VARS Clang_LIBRARY)