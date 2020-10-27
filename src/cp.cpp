#include "commands.h"

#include <array>
#include <cctype>
#include <fstream>
#include <iostream>

namespace seashell {

// Format: cp <src> <dest>
// inside quotes, you can put opposite quotes or spaces
void copy(const std::string & input) {
    // Find filenames
    std::string src, dest;
    bool append_to_src = true;

    const auto append = [&src, &dest, &append_to_src](char c) -> void {
        if (append_to_src) src += c;
        else
            dest += c;
    };

    char quote_style;
    bool inside_quotes = false;

    for (auto i = input.find('p') + 1; i < input.size(); i++) {
        if (const auto c = input[i]; isspace(c)) {
            // Where are we?
            if (src.empty()) {
                // 1. Before <src>
                // Do nothing if we are not in a quote
                // Otherwise append the space
                if (not inside_quotes) continue;
                else
                    append(c);
            } else if (not src.empty() and dest.empty()) {
                // 2. Between <src> and <dest>
                // If we are not in quotes, this is the end of src.
                // Else, we should append
                if (not inside_quotes) append_to_src = false;
                else
                    append(c);
            } else {
                // 3. After <dest>
                // If we are not inside quotes, we are done.
                // else, append.
                if (not inside_quotes) break;
                else
                    append(c);
            }
        } else if (c == '\'' or c == '"') {
            if (not inside_quotes) {
                inside_quotes = true;
                quote_style = c;
            } else if (c == quote_style) {
                inside_quotes = false;
            } else {
                // Append quote to the correct place
                append(c);
            }
        } else {
            append(c);
        }
    }

    // Actually do the copy

    std::ifstream src_file{src};
    std::ofstream dest_file{dest};

    if (not src_file) {
        std::cout << "Error opening " << src << std::endl;
        return;
    } else if (not dest_file) {
        std::cout << "Error opening " << dest << std::endl;
        return;
    }

    static constexpr auto buffer_size = 1024;
    std::array<char, buffer_size> buffer{};
    for (buffer.fill(0); src_file.getline(buffer.data(), buffer_size); buffer.fill(0)) {
        // Use the '\0' terminated string to work out the length of the buffer.
        dest_file << buffer.data() << '\n';
    }

    // Streams close on destruction
}
} // namespace seashell
