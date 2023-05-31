[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=10869918&assignment_repo_type=AssignmentRepo)
# Project-CS180 Team Seg_Fault

### Instructions to compile the program
For our program we used Visual Studio Code to run it. There are two ways to run our program by entering the following into the terminal:
1) g++ -std=c++11 main.cpp -o datastore
2) make

Once executing one of the ways mentioned above, type ".\datastore.exe" to run the program.

### Instructions for Main Menu
- The main program menu is displayed upon running the executable.
- Assuming the repository was freshly cloned, this means there is no Accounts.csv file database with login credentials to login. A new account must be created to login to the system.
- After creating the new account, open the Accounts.csv file database to see the inputs for the created account along with an encryption key value. Keep this encryption value handy as it is also needed to login to the system.
- The user should be able to call the other main menu options and update these account attributes as necessary.

### Instructions for Document Management Menu 
- Upon logging in, the user is able to perform CRUD operations with .csv files which represent documents in our program.
- Creating a .csv file appends the current logged in user's username to it, allowing only the owner to access their created .csv files.
- To search a .csv file, a key or value can be inputted to search in the specified .csv file. The user has the option to print out the entire row of data where the search query was located if the query was found.
- For adding data to a .csv file, input "key1, value1, key2, value2..." and hit enter as needed to input data onto a new row. Type "done" to finish adding the data to a .csv file.
- To edit a .csv file, input the line number for the line to edit. 
  - When prompted to insert or replace, entering "0" replaces the entire line.
  - Entering "1" inserts a new row of data to the specified line and pushes existing data down a row.
  - Regardless of one's choice, input "key1, value1, key2, value2..." and hit enter when finished.

## Interface Design
- For our project interface, we used the terminal.
    * The user can use the functionalities of our system by inputting number values to select described menu options. 
    * Users can create documents, read existing documents, update existing documents, and delete documents that are no longer needed.

- If time permitted, we hoped to implement a frontend GUI for our project interface. 
    * Rather than inputting number values in a terminal, the user would have been presented with a webpage with the same menu options.
    * The user would have been able to click buttons that accomplished the same tasks as the terminal version described above.
    * When the user would be prompted to input values such as for renaming, an input field would have been shown for the user to input into.

## Missing Integrations to .csv Document System
Documents and collections were implemented in previous iterations of our document storage system, but were not fully integrated when we finalized our decision to use .csv files. Some implementations still exist in our current code, but remain unused.
- Users are able to search through their stored documents for a specific document using its name as a query.
  - Users are able to sort documents by document attributes such as name or last modified date.
  - Users are able to create documents with a name, location, type, and can add tags.
  - Users are able to search and find the most recently modified or oldest modified document in a collection.
  - Users are able to filter their documents by specified tag.
- Users are able to create collections that store documents. These collections have a name, can store documents, and can have tags added.
  - Collection attributes can be updated such as their name or last modified date and can also be sorted by their attributes.
  - Users can delete documents from collections by name.
  - Users are able to filter their collections by specified tag.
