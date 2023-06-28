# mycp
Some implementations of 'cp' learned from Linux commands (-i option)

## Implementation content
  - Format of use: "cp source_file copy_file" → using int main(intargc, char *argv[])
  - Assume that directory copying is not possible and that you only copy text files
  - If the source file or copy file is not specified and is omitted, print the following message and exit
    - “Usage: cp  <source file>  <destination file>”
  - If the original file fails to open, print the following message and exit
    - “cannot open the source file”
  - If the copy file fails to open, print the following message and exit
    - “cannot open the destination file”
  - If the file does not have a copy file, it is newly created and the access is set to 0644
  - If a copy file exists, it will be overwritten if it is asked as follows and answered with 'y'.
    - "want to write test.txt?" (if the name of the copy file is test.txt)
  - When asked above, if you answered 'n', print out the following message and exit
    - “copy is aborted”
  - When asked above, if you do not answer with 'y' or 'n', print out the following message and exit
    - “invalid option”





