# Solutions Considered

### Approach 1: Load Full File into Memory
Pros: Easy to implement.
Cons: Not feasible for a 1TB file (will cause memory overflow).

### Approach 2:  Using Indexed Binary Search (Not used)
Pros: Faster if an index file exists.
Cons: Requires pre-built index and is complex.

### Approach 3: Line-by-Line Streaming with getline() (Final Choice)
Pros: Efficient, low memory usage.
Cons: Slightly slower than in-memory approaches but scalable.

## Final Solution Summary
The final solution reads logs line by line to avoid memory overflow. It checks whether each line starts with the given date and writes matching logs to an output file.

- Uses rfind(date, 0) == 0 for efficient prefix checking.
- Creates an output directory (output/) dynamically. 
- Deletes the output file if no logs are found to prevent empty files.

# Steps to Run

1️ Install Dependencies
Make sure you have GCC with C++20 support installed:

# Linux/macOS:
sudo apt install g++   # Ubuntu/Debian  
brew install gcc       # macOS  
# Windows:
Install MinGW or use WSL.

# 2️ Compile the Code

Run the following command inside the src/ directory:

g++ -std=c++20 extract_logs.cpp -o extract_logs

# 3️ Run the Program
./extract_logs YYYY-MM-DD
Example: ./extract_logs 2024-12-01

# 4️ Check Output

Logs are saved in the output/ folder:
output/output_2024-12-01.txt
