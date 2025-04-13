#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <string>
#include <memory>
#include <cmath>

using namespace ftxui;


std::unique_ptr<Element[]> generate_hboxes(int size_of_grid, int quadrant_columns, const std::vector<Component>& inputs)
{
    std::unique_ptr<Element[]> hboxes = std::make_unique<Element[]>(size_of_grid);
    for (int j {0}; j < size_of_grid; ++j)
    {
        std::vector<Element> curr_hbox_args(2 * size_of_grid + 1);
        for (int i {0}; i < size_of_grid; ++i)
        {
            curr_hbox_args[2 * i + 1]   = inputs[size_of_grid * j + i]->Render();
            curr_hbox_args[2 * (i + 1)] = separator();
        }
        for (int i {0}; i <= quadrant_columns; ++i)
            curr_hbox_args[2 * size_of_grid * i / quadrant_columns] = separatorDouble();
        hboxes[j] = hbox(curr_hbox_args);
    }
    return hboxes;
}


int main(int argc, char* argv[])
{
    int N = std::stoi(argv[1]);
    int R = floor(sqrt(N));
    int C = ceil(sqrt(N));
    std::vector<std::string> CELLS (N * N, "");
    std::vector<Component> inputs;
    for (int i {0}; i < (N * N); ++i) 
        inputs.push_back(Input(&CELLS[i], "") | size(WIDTH, EQUAL, 3) | size(HEIGHT, EQUAL, 1));
    /*
    for (uint8_t i {0}; i < (N * N); ++i)
        inputs.push_back(Input(&CELLS[i], "  "));
    */
    auto screen = ScreenInteractive::Fullscreen();
    auto layout = Container::Vertical(inputs);
    auto component = Renderer(layout,  
                              [&] {
                                  auto hboxes = generate_hboxes(N, C, inputs);
                                  std::vector<Element> vbox_args(2 * N + 1);
                                  for (int i {0}; i < N; ++i)
                                  {
                                      vbox_args[2 * i + 1] = hboxes[i];
                                      vbox_args[2 * (i + 1)] = separator();
                                  }
                                  for (int i {0}; i <= R; ++i)
                                      vbox_args[2 * N * i / R] = separatorDouble();
                                  return vbox(vbox_args) | center;
                                  });
    screen.Loop(component);
    return 0;
}

