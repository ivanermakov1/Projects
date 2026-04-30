# Instagram Unfollower Checker

A C++ program that identifies which Instagram accounts you follow that don't follow you back.

## Project Overview

This utility program compares your Instagram followers list with your following list to determine who isn't following you back. It's useful for cleaning up your follow list and identifying unreciprocated follows.

## Features

- **Fast Lookup**: Uses unordered_set for O(1) average lookup time
- **Simple Usage**: Minimal setup required - just provide follower/following lists
- **Clear Output**: Displays all accounts not following you back
- **Efficient Algorithm**: Optimized for large follower/following lists
- **Error Handling**: Validates file opening and handles missing files

## How It Works

1. Reads your followers list from `followers.txt`
2. Reads your following list from `following.txt`
3. Compares the two lists
4. Outputs accounts you follow that don't follow you back

## Technologies Used

- **Language**: C++
- **Data Structures**:
  - `unordered_set<string>`: Fast O(1) lookup for followers
  - `vector<string>`: Dynamic array for following list
- **File I/O**: Reading from text files
- **Algorithm**: Set difference operation

## Input Format

### followers.txt
username1
username2
username3
...

### following.txt
username1
username2
username3
...


## Code Architecture

### Main Algorithm

Create unordered_set for followers (fast lookup)
Create vector for following (maintains order)
Create vector for not_following_back (results)
Read all followers into set
For each account in following:

Check if in followers set
If not found, add to not_following_back vector


Display results


### Time Complexity

- **Reading followers**: O(n)
- **Reading following**: O(m)
- **Comparison loop**: O(m) with O(1) average lookup
- **Total**: O(n + m)

### Space Complexity

- O(n) for followers set
- O(m) for following vector
- O(k) for results vector (k = number not following back)

## What I Learned

- **Unordered Sets**: Hash-based data structure for fast lookups
- **File I/O**: Reading from multiple files
- **Data Structure Selection**: Choosing appropriate data structures for performance
- **Algorithm Efficiency**: Understanding time complexity tradeoffs
- **Vector vs Set**: When to use each data structure
- **String Processing**: Handling strings and usernames
- **Error Handling**: Checking file operations

## Compilation & Execution

```bash
# Compile the program
g++ -o insta insta.cpp

# Run the program
./insta
```

## Sample Output
These are the people not following you back:
user1
user2
user3
...

## Why Unordered_Set?

The program uses `unordered_set` for followers because:
- **Fast Lookup**: O(1) average time to check if someone follows you
- **Memory Efficient**: More efficient than checking a vector each time
- **Optimal for Comparison**: Perfect for "is this item in this collection?" queries

If using a `vector` instead, each lookup would be O(n), making total time O(n*m) - much slower for large lists.

## Real-World Usage

This program demonstrates practical use of:
- Efficient algorithms for large datasets
- Data structure optimization
- Real-world problem solving
- File processing and parsing

## Limitations

- Requires manual export of followers/following lists from Instagram
- Instagram doesn't provide direct API access for followers in older versions
- Manual data collection needed

## Future Enhancements

- [ ] Automatic Instagram API integration
- [ ] Category tracking (friends, brands, celebrities)
- [ ] Historical tracking (who unfollowed you)
- [ ] Mutual follow verification
- [ ] Export results to CSV
- [ ] GUI interface
- [ ] Web version
- [ ] Scheduled automated checks

## Requirements

- C++ compiler (g++, clang, etc.)
- `followers.txt` file with your followers
- `following.txt` file with accounts you follow

## Author

Ivan Ermakov

## License

This project is open source and available under the MIT License.

---

## Tips for Using

1. **Export Lists**: Get your followers/following lists from Instagram
2. **Format**: One username per line in both files
3. **Accuracy**: Ensure lists are up-to-date before running
4. **Privacy**: Keep your follower lists private
