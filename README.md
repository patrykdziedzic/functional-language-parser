# Functional language to assembly parser

This is a university assignment which puprose is to create a simple parser by using flex and bison.
The input language is a simple functional language. The output is assmebly-like language which uses a memory stack.

## Deployment

To run the application, Docker is required. Run the following script to start a required container:
```sh
Start-ParsingDevToolsContainer.sh
```
The sources also contain Remove-ParsingDevToolsContainer.sh which stops and removes the container.

To compile the application, run the following script which will invoke a makefile inside the container:
```sh
Start-Compilation.sh build
```
The above script can be also invoked with 'clean' target to remove the compilation output.
After compiling the application, it can be run with the following script:
```sh
Start-Application.sh [filepath]
```
Where **filepath** references to file which would be processed. Notice, that the file has to be inside the container

### Example

The sources come with a test file to process. To invoke the application with the test file, run the following script:
```sh
Start-Application.sh /aug-compiler/test/data/chars-count.txt
```

The application output should be:
```
# of lines = 3, # of chars = 142
```