# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Sandro\Documents\Programming\CPP\osu-hackathon-fall2018\osu-fall2018-hackathon

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Sandro\Documents\Programming\CPP\osu-hackathon-fall2018\osu-fall2018-hackathon\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\osu_fall2018_hackathon.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\osu_fall2018_hackathon.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\osu_fall2018_hackathon.dir\flags.make

CMakeFiles\osu_fall2018_hackathon.dir\main.cpp.obj: CMakeFiles\osu_fall2018_hackathon.dir\flags.make
CMakeFiles\osu_fall2018_hackathon.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Sandro\Documents\Programming\CPP\osu-hackathon-fall2018\osu-fall2018-hackathon\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/osu_fall2018_hackathon.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\osu_fall2018_hackathon.dir\main.cpp.obj /FdCMakeFiles\osu_fall2018_hackathon.dir\ /FS -c C:\Users\Sandro\Documents\Programming\CPP\osu-hackathon-fall2018\osu-fall2018-hackathon\main.cpp
<<

CMakeFiles\osu_fall2018_hackathon.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/osu_fall2018_hackathon.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe > CMakeFiles\osu_fall2018_hackathon.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Sandro\Documents\Programming\CPP\osu-hackathon-fall2018\osu-fall2018-hackathon\main.cpp
<<

CMakeFiles\osu_fall2018_hackathon.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/osu_fall2018_hackathon.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\osu_fall2018_hackathon.dir\main.cpp.s /c C:\Users\Sandro\Documents\Programming\CPP\osu-hackathon-fall2018\osu-fall2018-hackathon\main.cpp
<<

CMakeFiles\osu_fall2018_hackathon.dir\BankApp.cpp.obj: CMakeFiles\osu_fall2018_hackathon.dir\flags.make
CMakeFiles\osu_fall2018_hackathon.dir\BankApp.cpp.obj: ..\BankApp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Sandro\Documents\Programming\CPP\osu-hackathon-fall2018\osu-fall2018-hackathon\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/osu_fall2018_hackathon.dir/BankApp.cpp.obj"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\osu_fall2018_hackathon.dir\BankApp.cpp.obj /FdCMakeFiles\osu_fall2018_hackathon.dir\ /FS -c C:\Users\Sandro\Documents\Programming\CPP\osu-hackathon-fall2018\osu-fall2018-hackathon\BankApp.cpp
<<

CMakeFiles\osu_fall2018_hackathon.dir\BankApp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/osu_fall2018_hackathon.dir/BankApp.cpp.i"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe > CMakeFiles\osu_fall2018_hackathon.dir\BankApp.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Sandro\Documents\Programming\CPP\osu-hackathon-fall2018\osu-fall2018-hackathon\BankApp.cpp
<<

CMakeFiles\osu_fall2018_hackathon.dir\BankApp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/osu_fall2018_hackathon.dir/BankApp.cpp.s"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\osu_fall2018_hackathon.dir\BankApp.cpp.s /c C:\Users\Sandro\Documents\Programming\CPP\osu-hackathon-fall2018\osu-fall2018-hackathon\BankApp.cpp
<<

CMakeFiles\osu_fall2018_hackathon.dir\Checkings.cpp.obj: CMakeFiles\osu_fall2018_hackathon.dir\flags.make
CMakeFiles\osu_fall2018_hackathon.dir\Checkings.cpp.obj: ..\Checkings.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Sandro\Documents\Programming\CPP\osu-hackathon-fall2018\osu-fall2018-hackathon\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/osu_fall2018_hackathon.dir/Checkings.cpp.obj"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\osu_fall2018_hackathon.dir\Checkings.cpp.obj /FdCMakeFiles\osu_fall2018_hackathon.dir\ /FS -c C:\Users\Sandro\Documents\Programming\CPP\osu-hackathon-fall2018\osu-fall2018-hackathon\Checkings.cpp
<<

CMakeFiles\osu_fall2018_hackathon.dir\Checkings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/osu_fall2018_hackathon.dir/Checkings.cpp.i"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe > CMakeFiles\osu_fall2018_hackathon.dir\Checkings.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Sandro\Documents\Programming\CPP\osu-hackathon-fall2018\osu-fall2018-hackathon\Checkings.cpp
<<

CMakeFiles\osu_fall2018_hackathon.dir\Checkings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/osu_fall2018_hackathon.dir/Checkings.cpp.s"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\osu_fall2018_hackathon.dir\Checkings.cpp.s /c C:\Users\Sandro\Documents\Programming\CPP\osu-hackathon-fall2018\osu-fall2018-hackathon\Checkings.cpp
<<

# Object files for target osu_fall2018_hackathon
osu_fall2018_hackathon_OBJECTS = \
"CMakeFiles\osu_fall2018_hackathon.dir\main.cpp.obj" \
"CMakeFiles\osu_fall2018_hackathon.dir\BankApp.cpp.obj" \
"CMakeFiles\osu_fall2018_hackathon.dir\Checkings.cpp.obj"

# External object files for target osu_fall2018_hackathon
osu_fall2018_hackathon_EXTERNAL_OBJECTS =

osu_fall2018_hackathon.exe: CMakeFiles\osu_fall2018_hackathon.dir\main.cpp.obj
osu_fall2018_hackathon.exe: CMakeFiles\osu_fall2018_hackathon.dir\BankApp.cpp.obj
osu_fall2018_hackathon.exe: CMakeFiles\osu_fall2018_hackathon.dir\Checkings.cpp.obj
osu_fall2018_hackathon.exe: CMakeFiles\osu_fall2018_hackathon.dir\build.make
osu_fall2018_hackathon.exe: CMakeFiles\osu_fall2018_hackathon.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Sandro\Documents\Programming\CPP\osu-hackathon-fall2018\osu-fall2018-hackathon\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable osu_fall2018_hackathon.exe"
	"C:\Program Files\JetBrains\CLion 2018.2.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\osu_fall2018_hackathon.dir --manifests  -- C:\PROGRA~2\MICROS~1.0\VC\bin\link.exe /nologo @CMakeFiles\osu_fall2018_hackathon.dir\objects1.rsp @<<
 /out:osu_fall2018_hackathon.exe /implib:osu_fall2018_hackathon.lib /pdb:C:\Users\Sandro\Documents\Programming\CPP\osu-hackathon-fall2018\osu-fall2018-hackathon\cmake-build-debug\osu_fall2018_hackathon.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\osu_fall2018_hackathon.dir\build: osu_fall2018_hackathon.exe

.PHONY : CMakeFiles\osu_fall2018_hackathon.dir\build

CMakeFiles\osu_fall2018_hackathon.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\osu_fall2018_hackathon.dir\cmake_clean.cmake
.PHONY : CMakeFiles\osu_fall2018_hackathon.dir\clean

CMakeFiles\osu_fall2018_hackathon.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\Sandro\Documents\Programming\CPP\osu-hackathon-fall2018\osu-fall2018-hackathon C:\Users\Sandro\Documents\Programming\CPP\osu-hackathon-fall2018\osu-fall2018-hackathon C:\Users\Sandro\Documents\Programming\CPP\osu-hackathon-fall2018\osu-fall2018-hackathon\cmake-build-debug C:\Users\Sandro\Documents\Programming\CPP\osu-hackathon-fall2018\osu-fall2018-hackathon\cmake-build-debug C:\Users\Sandro\Documents\Programming\CPP\osu-hackathon-fall2018\osu-fall2018-hackathon\cmake-build-debug\CMakeFiles\osu_fall2018_hackathon.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\osu_fall2018_hackathon.dir\depend

