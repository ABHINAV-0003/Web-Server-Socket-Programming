# EC3022D Computer Networks Winter 2023-24

### Webserver using Socket Programming

**Question:**  
Build a Web Server in C/Python using Socket programming. The web server should be able to respond to simple HTTP commands like GET, POST, etc. When a GET request is sent, the server should respond with a page containing your name and roll number. Submit a PDF report with the full code.

## Table of Contents

- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This repository contains a C socket program that establishes a communication protocol between a client and a server, facilitating message exchange over a network. When the client sends a request to the server, the server responds based on the request type (GET, POST, etc.). This assignment demonstrates the basics of socket programming, including creating sockets, binding, listening, accepting connections, and sending responses.

## Installation

To get started with the Socket Programming assignment repository, follow these steps:

1. Clone the repository:
    ```
    git clone https://github.com/ABHINAV-0003/Web-Server-Socket-Programming.git
    ```
   
2. Change into the project directory:
    ```
    cd Web-Server-Socket-Programming
    ```

3. Compile and run server and client programs:
    - Manually
      ```
      cd <foldername>
      gcc -o <server-object-name> <server-name>
      gcc -o <client-object-name> <client-name>
      ./<server-object-name>
      ./<client-object-name> <server-ip-address>
      ```
    - Using Makefile
      ```
      cd <foldername>
      make
      ./<server-object-name>
      ./<client-object-name> <server-ip-address>
      ```
    - Using shell script files `run_server` and `run_client`
      1. Save the server file you want to run:
         ```
         ./run_server.sh <port number if required>
         ```
      2. Save the client file you want to run:
         ```
         ./run_client.sh <port number if required>
         ```
      IP address will be taken using `hostname -I` command in the script file, so no need to give it as an argument.

## Usage

The Web-Server-Socket-Programming repository offers a variety of resources to enhance your understanding of networking. Here are a few ways you can make use of this repository:

- Explore the code examples in the directory to see practical implementations of networking concepts.
- Contribute your own code or documentation to help expand the repository and share your knowledge with others.

## Contributing

Contributions to the Web-Server-Socket-Programming repository are welcome! If you would like to contribute, please follow these guidelines:

1. Fork the repository and create a new branch for your contribution.
2. Make your changes and ensure they adhere to the repository's coding style and guidelines.
3. Test your changes thoroughly.
4. Submit a pull request, describing the changes you have made and why they should be merged.

## License

The Web-Server-Socket-Programming repository is licensed under the [MIT License](LICENSE)
