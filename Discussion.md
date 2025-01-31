# Solutions Considered

### Approach 1: Load Full File into Memory
- **Pros**: Easy to implement.
- **Cons**: Not feasible for a 1TB file (will cause memory overflow).

### Approach 2:  Using Indexed Binary Search (Not used)
- **Pros**: Faster if an index file exists.
- **Cons**: Requires pre-built index and is complex.

### Approach 3: Line-by-Line Streaming with getline() (Final Choice)
- **Pros**: Efficient, low memory usage.
- **Cons**: Slightly slower than in-memory approaches but scalable.

## Final Solution Summary
The final solution reads logs **line by line** to avoid memory overflow. It checks whether each line starts with the given date and writes matching logs to an output file.

- **Efficient prefix checking**: Uses `rfind(date, 0) == 0` for checking if the line starts with the given date.
- **Dynamic output directory creation**: Creates the `output/` directory if it doesn't exist.
- **Prevents empty files**: Deletes the output file if no logs match the given date.
# Steps to Run

## 1️ Install Dependencies
Make sure you have GCC with C++20 support installed:

### Linux/macOS:
```bash
sudo apt install g++   # Ubuntu/Debian  
brew install gcc       # macOS
```
### Windows:
Install MinGW or use WSL.

## 2 Download the log files 

Run the following command inside the src/ directory:
 ```curl
curl -L -o test_logs.log "https://limewire.com/d/0c95044f-d489-4101-bf1a-ca48839eea86#cVKnm0pKXpN6pjsDwav4f5MNssotyy0C8Xvaor1bA5U"
```
## 3 Compile the Code

Run the following command inside the src/ directory:
```bash
g++ -std=c++20 extract_logs.cpp -o extract_logs
```
# 4 Run the Program
```txt
./extract_logs YYYY-MM-DD
Example: ./extract_logs 2024-12-01
```
# 5 Check Output
```txt
Logs are saved in the output/ folder:
output/output_2024-12-01.txt
```
