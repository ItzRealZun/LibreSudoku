#include <set>
#include <memory>
#include <cmath>
#include <array>
#include <algorithm>
#include <string>


namespace SudokuBackend
{
    using cell = uint8_t;
    constexpr uint8_t SIZES_COUNT {4};
    constexpr std::array<uint8_t, SIZES_COUNT> acceptable_sizes {6, 9, 12, 16};


    class InvalidGridSizeException
    {
        std::string message;
    public:
        InvalidGridSizeException(const std::string& message): message{message} {}
        const std::string& get_message() const {return this->message;}
    };


    class Grid
    {
        uint8_t grid_size {0};
        uint8_t quadrants_in_row {0};
        uint8_t quadrants_in_column {0};
        std::unique_ptr<cell[]> cells {nullptr};
    public:
        Grid(uint8_t size)
        {
            // Fill Sudoku grid with sevens
            if (std::find(acceptable_sizes.begin(), acceptable_sizes.end(), size) == acceptable_sizes.end())
                throw InvalidGridSizeException{"This size of sudoku grid is not valid! Choose from these options: 6, 9, 12, 16"};
            this->grid_size = size;
            this->quadrants_in_row = ceil(sqrt(size));
            this->quadrants_in_column = floor(sqrt(size));
            this->cells = std::make_unique<cell[]>(size * size);
            /*
            for (int i {0}; i < size; ++i)
                for (int j {0}; j < size; ++j)
                    cells[i * size + j] = 7;
            */
        }

        ~Grid() = default; 
        
        /*
        void print()
        {
            // Prints Sudoku Grid
            print_line(nullptr);
            uint8_t inner_counter {0};
            for (int i{0}; i < (grid_size / quadrants_in_column); ++i)
            {
                for (int j{0}; j < quadrants_in_column; ++j, ++inner_counter)
                    print_line(&(cells[inner_counter * grid_size]));
                print_line(nullptr);
            }
        }
        */
    private:
        /*
        void print_line(const cell* array)
        {
            // Print one line of grid with pipe as separator between quadrants
            std::cout << "| ";
            uint8_t inner_counter {0};
            for (int i {0}; i < (grid_size / quadrants_in_row); ++i)
            {
                for (int j {0}; j < quadrants_in_row; ++j, ++inner_counter)
                    if (array)
                        std::cout << +array[inner_counter] << ' ';
                    else
                        std::cout << "- ";
                std::cout << "| ";
            }
            std::cout << std::endl;
        }
        */
        std::set<cell> generate_neighbours_in_quadrant(uint8_t row_index, uint8_t column_index)
        {
            std::set<cell> neighbours;
            uint8_t quarant_index {0};
            return neighbours;    
        }
        bool check_cell(uint8_t cell_row_index, uint8_t cell_column_index)
        {
            bool is_correct_by_row {true};
            bool is_correct_by_column {true};
            bool is_correct_by_quadrant {true};
/*

*/
            return is_correct_by_row && is_correct_by_column && is_correct_by_quadrant;
        }
        /*
        bool check_quadrant(uint8_t quadrant_index)
        {
            // Four borders in current Sudoku quadrant
            uint8_t low_row_border = (quadrant_index / quadrants_in_column) * quadrants_in_column;
            uint8_t high_row_border = (quadrant_index / quadrants_in_column + 1) * quadrants_in_column;
            uint8_t low_column_border = (quadrant_index % quadrants_in_column) * quadrants_in_row;
            uint8_t high_column_border = (quadrant_index % quadrants_in_column + 1) * quadrants_in_row;

            for (int i {low_row_border}; i < high_row_border; ++i)
            {
                for (int j {low_column_border}; j < high_column_border; ++j)
                    std::cout << +cells[i * grid_size + j] << ' ';
                std::cout << std::endl;
            }
            return false;
        }
        */
    };
}

int main()
{
    /*
	int i {0};
	std::cin >> i;
    SudokuBackend::Grid my_obj {(uint8_t)i};
	my_obj.print();
    */
	return 0;
}
