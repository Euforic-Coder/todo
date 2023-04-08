<p align="center">
  <img src="logo.png" />
</p>

# UFORIA LIBRARY

### The uforia library is a library that makes working with C++ a lot easier and clearer.

### Functions

### <code>std::string colored(std::string, Color, Style)</code>

Color a string by giving the string first, then the color, then the style if necessary.
The colors to choose from are Red, Blue, Yellow, Green, Magenta, Cyan.
The styles to choose from are Regular, Bold, Italic, Underline.

### <code>std::vector\<std::string\> count(vector\<std::string\>)</code>

Sorts a vector<string> by count.

### <code>debug(std::string, bool)</code>

Print a debug message with an assert function. Which makes the text gray or red.

### <code>timer_start()</code>

Set a starting point for a timer.

### <code>timer_end()</code>

Set a end point for a timer.

### <code>timer_print()</code>

Print the elapsed time between the start and end point.

### <code>std::string from(std::vector\<std::string\>, char)</code>

Convert a vector to a string using a seperator.

### <code>std::vector\<std::string\> from(std::string, char)</code>

Convert a string to a vector using a delimiter.

### <code>std::vector\<std::string\> from(std::string, bool)</code>

Convert a file to a vector with a tree to indicate whether whole lines should be included.

### <code>bool has(std::string, const std::string&)</code>

Checks if a string contains another string.

### <code>bool has(char, const std::string&)</code>

Checks if a string contains a string.

### <code>bool has(std::string, const std::vector\<std::string\>& vec)</code>

Checks if a vector contains a string.

### <code>HelpMenu(std::string)</code>

A class that allows you to create a help menu.

### <code>bulletin(std::string, bool)</code>

Prints green text with a dor or red text with a cross depending on the bool.

### <code>error(std::string, bool)</code>

Prints a red error message and closes the program depending on the bool.

### <code>true_rand()</code>

Generates an interger thats truly random.

### <code>capitalized(std::string)</code>

Capitalizes a string.

### <code>lowercase(std::string)</code>

Makes a lowercase string.

### <code>uppercase(std::string)</code>

Makes a uppercase string.

### <code>spacer(std::string, int)</code>

Creates a string with spaces.

### <code>std::vector\<std::string\> funnel(const std::string&)</code>

Makes a vector from a string with all possible letter combinations.

### <code>bool has_number(std::string)</code>

Checks if a string has a number in it.

### <code>bool is_numeric(const std::string&)</code>

Checks if a string is numeric.

### <code>std::vector\<std::string\> unique(std::vector\<std::string\>)</code>

Makes a vector unique.
