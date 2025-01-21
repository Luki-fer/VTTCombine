#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <iomanip>
#include <vector>


long TimestampToMS(const std::string& timestamp){
    int hr, min, sec, ms;
    char dot;
    std::sscanf(timestamp.c_str(),"%d:%d:%d%c%d", &hr, &min, &sec, &dot, &ms);
    
    return(hr*3600000L + min*60000L + sec*1000L + ms);
};

std::string MSToTimestamp(long ms){
    long  long hr = ms / 3600000;
    ms %= 3600000;
    long long min = ms / 60000;
    ms %= 60000;
    long long sec = ms / 1000;
    ms %= 1000;
    std::ostringstream oss; // output str stream
    oss << std::setfill('0') << std::setw(2) << hr << ":"
       << std::setw(2) << min << ":"
       << std::setw(2) << sec << "."
       << std::setw(3) << ms;
    return oss.str();
};

int main() {
    try{
        int fileCount{};
        std::cout << "Enter the number of .vtt files: ";
        std::cin >> fileCount;
        // File paths
        std::vector<std::string> VttPaths(fileCount);
        for (size_t i{1}; i <= fileCount; ++i){
            VttPaths.push_back(std::to_string(i) + ".vtt");
        }

        // Output
        std::string outputFile = "0.vtt";

        // variables for std::regex_match
        std::string line{};
        std::smatch sm;
        std::regex Timestamp(R"((\d{2}:\d{2}:\d{2}\.\d{3}) --> (\d{2}:\d{2}:\d{2}\.\d{3}))");

        // Combine Files
        std::ofstream output(outputFile);
        if (!output.is_open()){
            throw std::runtime_error("Failed to open file: " + outputFile);
        }
        output << "WEBVTT\n\n";

        long Temp = 0;
        long offset = 0;
        
        for (const auto& path : VttPaths){
            offset += Temp;
            // writes one file to output
            std::ifstream inputFile(path);
            
            while(std::getline(inputFile, line)){
                if (std::regex_match(line, sm, Timestamp)){
                    
                    long start = TimestampToMS(sm[1]);
                    long end = TimestampToMS(sm[2]);
                    Temp = TimestampToMS(sm[2]);    // temporary, to be added to offset

                    output << MSToTimestamp(start + offset) << " --> " << MSToTimestamp(end + offset) << "\n";
                    
                } else{
                    output << line << "\n";
                }
            }
        }

    // END
        std::cout << "VTT files combined successfully into " << outputFile << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }
    return 0;
}
