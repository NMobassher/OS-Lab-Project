# OS-Lab-Project  
Authors  
Group 9  
Matthew Cardy-100489683  
Muhtasim Chowdhury  
Nafis Mobassher-100587562  
Sakib Shahriyar  

<Usage>
- Invoke without a command line argument:
  ./myshell

- Invoked with a command line argument:
  ./myshell input_file
    <NOTE> input_file should contain a set of command lines for the shell to process.
    <NOTE> Shell will exit when the end-of-file is reached.

- I/O-redirection on either or both stdin and/or stdout:
  ./myshell input_file < input_file > output_file
    <NOTE> Output will only be written to file when program is terminated by typing quit or the end-of-file is reached.


<Commands>
  
- cd: <directory>
  Change the current default directory to <directory>.
  If the <directory> argument is not present, report the current directory.
  This command also changes the PWD environment variable.  
- clr:
  Clear the screen.    
- dir: <directory>
  List the contents of directory <directory>.  
  If the <directory> argument is not present, report contents of current directory.
- environ:
  List all the environment strings.    
- echo: <comment>
  Display <comment> on the display followed by a new line.    
- help:
  Display the user manual using the 'more' filter.    
- pause
  Pause operation of the shell until 'Enter' is pressed.    
- quit:
  Quit the shell.    
- SHELL environment variable is set to be shell=<pathname>/myshell where
  <pathname>/myshell is the full path for the shell executable
   
