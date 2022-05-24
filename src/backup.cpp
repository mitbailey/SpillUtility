/**
 * @file backup.cpp
 * @author Mit Bailey (mitbailey99@gmail.com)
 * @brief Recursively copies a directory, generating an identical directory whose name is appended with the date and time.
 * @version See Git tags for version information.
 * @date 2021.11.26
 *
 * @copyright Copyright (c) 2021
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include <cstdio>
#include <iostream>
#include <filesystem>
#include <time.h>

// Spills the contents of files into the current directory.
// Currently has the issue of not being able to merge same-named directories.

int main(int argc, char *argv[])
{
    for (const auto &entry : std::filesystem::directory_iterator("."))
    {
        if (entry.is_directory())
        {
            std::cout << "Spilling " << entry.path() << " into " << std::filesystem::current_path() << std::endl;

            for (const auto &entry_2 : std::filesystem::directory_iterator(entry.path()))
            {
                std::string filename = entry_2.path().string();
                filename = filename.substr(filename.find_last_of("/\\"));

                std::cout << "Renaming " << entry_2.path() << " as " << std::filesystem::current_path().string() + filename << std::endl;

                std::filesystem::rename(entry_2.path(), std::filesystem::current_path().string() + filename);
            }
        }
    }

    // Operation complete.
    std::cout << "Everything is OK." << std::endl;

    return 0;
}