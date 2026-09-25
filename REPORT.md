# Operating Systems Programming Assignment – 01

**Roll No:** BSDSF24M051  
**Repository:** BSDSF24M051-OS-A01

---

# Feature-2: Multi-file Project using Make Utility

## 1. Explain the linking rule in this part's Makefile:
## `$(TARGET): $(OBJECTS)`

This rule tells Make that the final target depends on all the object files.

The object files are compiled first from the source files. After that, the linker combines all object files to create the final executable.

In this project, the object files are:

- obj/main.o
- obj/mystrfunctions.o
- obj/myfilefunctions.o

A Makefile rule that links against a library is different because the executable is linked using a library path and library name, such as `-Llib -lmyutils`.

---

## 2. What is a git tag and why is it useful? Difference between simple and annotated tag.

A git tag is a name given to a specific commit. It is useful for marking important versions or stable points in a project.

A simple tag only points to a commit.

An annotated tag stores additional information such as the tag message, tagger and date. In this assignment, annotated tags were used for the project releases.

---

## 3. What is the purpose of creating a Release on GitHub?

A GitHub Release provides a formal version of the project that users can download.

Attaching binaries such as `bin/client` allows users to download and run the already compiled program without compiling the source code themselves.

---

# Feature-3: Static Library

## 1. Compare the Makefile from Part 2 and Part 3.

In Part 2, the object files were directly linked together to create the executable.

In Part 3, the utility object files were first combined into a static library named:

`lib/libmyutils.a`

The main object file was then linked with this library using:

`-Llib -lmyutils`

Therefore, Part 3 adds a library target and changes the executable linking rule.

---

## 2. What is the purpose of the ar command? Why is ranlib often used immediately after it?

The `ar` command is used to create and manage archive files.

In this project, `ar` was used to create:

`lib/libmyutils.a`

The archive contains the object files:

- mystrfunctions.o
- myfilefunctions.o

`ranlib` can be used to create or update the archive symbol index. This allows the linker to find symbols in the static library efficiently.

---

## 3. When you run nm on your client_static executable, are symbols such as mystrlen present?

Yes. Functions such as `mystrlen` are present in the statically linked executable when they are required by the program.

This shows that the required code from the static library is copied into the final executable during static linking.

Therefore, the executable contains the required library code instead of depending on the `.a` file at runtime.

---

# Feature-4: Dynamic Library

## 1. What is Position-Independent Code (-fPIC) and why is it required for shared libraries?

Position-Independent Code is code that can execute correctly regardless of where it is loaded into memory.

The `-fPIC` option tells GCC to generate position-independent code.

It is important for shared libraries because the operating system can load the same shared library at different memory addresses for different programs.

---

## 2. Explain the difference in file size between the static and dynamic clients.

In this project, both executables were approximately 17 KB:

- `client_static` = 17 KB
- `client_dynamic` = 17 KB

The difference was not significant in this small project.

With static linking, the required library code is included inside the executable.

With dynamic linking, the executable uses the shared library `libmyutils.so`, so the library code is kept separately.

The size difference can become more noticeable in larger projects and libraries.

---

## 3. What is LD_LIBRARY_PATH? Why was it necessary?

`LD_LIBRARY_PATH` is an environment variable that tells the dynamic loader additional directories where it should search for shared libraries.

The program initially produced this error:

`error while loading shared libraries: libmyutils.so: cannot open shared object file`

This happened because the loader did not know where our custom `libmyutils.so` was located.

We used:

`export LD_LIBRARY_PATH=$PWD/lib:$LD_LIBRARY_PATH`

After setting this variable, the loader was able to find `libmyutils.so` and the program ran successfully.

This shows that the dynamic loader is responsible for locating and loading required shared libraries when the program starts.

---

# Feature-5: Man Pages

## 1. Man page implementation

Man pages were created for all six functions:

- `mystrlen`
- `mystrcpy`
- `mystrncpy`
- `mystrcat`
- `wordCount`
- `mygrep`

Each man page contains standard sections including:

- `.TH`
- `.SH NAME`
- `.SH SYNOPSIS`
- `.SH DESCRIPTION`
- `.SH AUTHOR`

The pages were tested using the `man` command.

---

## 2. Installation

An `install` target was added to the Makefile.

The command:

`make install`

copies the man pages into:

`/usr/local/share/man/man3`

The manual database was then updated using `mandb`.

The installed pages were tested successfully using commands such as:

`man mystrlen`

and:

`man mygrep`

---

# Git Branches and Releases

The project was developed using separate Git branches:

- `multifile-build`
- `static-build`
- `dynamic-build`
- `man-pages`

The branches were merged into `main` after completing each feature.

The following annotated tags were created:

- `v0.1.1-multifile`
- `v0.2.1-static`
- `v0.3.1-dynamic`
- `v0.4.1-final`

GitHub Releases were created for the required versions, with compiled binaries attached where required.

---

# Conclusion

This assignment demonstrated the process of developing a multi-file C project using Make, creating static and dynamic libraries, linking executables, analyzing binaries using tools such as `ar`, `nm`, `readelf` and `ldd`, creating Linux man pages, and managing the project using Git branches, tags and GitHub Releases.
