cmake_minimum_required(VERSION 4.0)
project(testing_ui)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
  ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG v6.0.2 
)
FetchContent_MakeAvailable(ftxui)

add_executable(testing_ui main.cpp)
target_link_libraries(testing_ui ftxui::screen ftxui::dom ftxui::component)

