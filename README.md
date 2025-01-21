# VTTCombine
Combines multiple .VTT files and increments new files' timestamps with the last file's ending timestamp.

> This is a small project of mine designed to combine .VTT files in a way that preserves the timings of the subtitles in relation from one file to another. 
> Made in c++ shortly after I finished learning the ropes.
> Takes in user input amount of files in the naming convention "1.vtt", "2.vtt", "3.vtt", ...
> Output file : "0.vtt"

# Prerequisites
- [C++ compiler version 11 or newer](https://winlibs.com/)

# Building (windows)
Download the repo, and a C++ compiler and unzip in Downloads.
Enter the following in command prompt
```CMD
C:\Downloads\mingw64\bin\g++.exe -g C:\Downloads\VTTCombine\main.cpp -o C:\Downloads\VTTCombine\main.exe
```

# Usage
1. Place the `main.exe` file in the .vtt folder
2. Double click `main.exe`


## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License

This project is licensed under the AGPL-3.0 License - see the [LICENSE](LICENSE) file for details.
