# CSV Data Processor

This CSV data processor is a C program designed to read, manipulate, and sort CSV data from a given input file. It provides two sorting options: by host name and by price. The processed data can be saved in separate CSV files for further analysis.

## Usage

To use this CSV data processor, follow these steps:

1. **Compile the Program:** Compile the program using a C compiler.

   ```bash
   gcc listing.c -o listing
   ```

2. **Run the Program:** Execute the program with the input CSV file as an argument.

   ```bash
   ./listing input.csv
   ```

   Replace `input.csv` with the path to your CSV file.

3. **Output Files:**

   - The sorted data by host name will be saved in a file named `host_name_listing.csv`.
   - The sorted data by price will be saved in a file named `price_listing.csv`.

## Program Structure

The program is structured as follows:

- It reads the CSV file specified as a command-line argument and stores the data in a dynamically allocated array of `struct listing_obj`.

- It provides two sorting options using the `qsort` function:
   - Sorting by host name in ascending order.
   - Sorting by price in ascending order.

- The sorted data is written to separate CSV files for further analysis.

## File Descriptions

- `listing.c`: The main program source code.
- `listing_obj`: Defines the structure for storing CSV data.
- `getValues`: A function to parse a CSV row and extract values into a `struct listing_obj`.
- `printFiles`: A function to print sorted data to CSV files.
- `sortByHostName`: A comparison function for sorting by host name.
- `sortByPrice`: A comparison function for sorting by price.

## License

This CSV data processor is open-source software released under the MIT License. You are free to use, modify, and distribute it as needed. Please see the `LICENSE` file for more details.

## Contributing

If you have suggestions for improvements or find any issues, please feel free to open an issue or create a pull request. Contributions from the community are welcome and appreciated.

Thank you for using the CSV data processor!
