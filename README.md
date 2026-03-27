# Multi-Client TCP Server in C

## 📌 Overview

This project implements a **multi-client TCP server** in C using low-level system calls.
The server can handle multiple clients simultaneously by creating a **separate process (using `fork()`) for each client**.

Each client can continuously send messages to the server, and the server responds by converting them to **uppercase**.

---

## 🚀 Features

* Handles multiple clients concurrently using `fork()`
* Continuous communication (not just one request)
* Converts client messages to uppercase
* Detects client disconnection
* Proper file descriptor and socket management

---

## 🧠 Concepts Used

* Socket Programming:

  * `socket()`, `bind()`, `listen()`, `accept()`
  * `connect()`, `recv()`, `send()`
* Process Management:

  * `fork()`
* File Descriptors:

  * Socket descriptor handling across processes
* System Calls:

  * `close()`, `exit()`

---

## 🏗️ Architecture

```text
Client1 ──▶ child process 1
Client2 ──▶ child process 2
Client3 ──▶ child process 3
            ↓
        TCP Server
```

* Parent process → accepts new connections
* Child process → handles communication with one client

---

## ⚙️ How to Run

### 1. Compile server

```bash
gcc server.c -o server
```

### 2. Run server

```bash
./server
```

---

### 3. Compile client

```bash
gcc client.c -o client
```

### 4. Run client

```bash
./client
```

---

## 🧪 Example

**Client Input:**

```text
hello
```

**Server Response:**

```text
HELLO
```

---

## 📂 Project Structure

```text
.
├── server.c
├── client.c
└── README.md
```

---

## ⚠️ Important Notes

* Each client is handled by a separate process → simple but not scalable for large systems
* This model demonstrates **process-based concurrency**
* In production systems, techniques like `select()` / `poll()` / threads are preferred

---

## 🔥 Key Learning

This project demonstrates:

* How operating system concepts (processes, file descriptors) integrate with networking
* How a server handles multiple clients concurrently
* Real-world use of system calls in C

---

## 📌 Future Improvements

* Implement `select()` or `poll()` for scalable I/O
* Add custom protocol (commands like TIME, EXIT)
* Add logging system
* Handle signals (`SIGCHLD`) to avoid zombie processes

---

## 👨‍💻 Author

Nandan Kumar
